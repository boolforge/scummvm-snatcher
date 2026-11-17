/* ScummVM - Graphic Adventure Engine
*
* ScummVM is the legal property of its developers, whose names
* are too numerous to list here. Please refer to the COPYRIGHT
* file distributed with this source distribution.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/


#include "common/config-manager.h"
#include "common/translation.h"
#include "engines/advancedDetector.h"
#include "base/plugins.h"
#include "audio/mididrv.h"

#include "snatcher/detection.h"
#include "snatcher/detection_tables.h"
#include "snatcher/fantranslations.h"

namespace Snatcher {

static const char *const snatcherDirectoryGlobs[] = {
	"Extracted-Files",
	"extracted-files",
	"ScummVM-Playable",
	"scummvm-playable",
	"Original-USA",
	"original-usa",
	"Original-Japan",
	"original-japan",
	"English-Translated",
	"english-translated",
	"Spanish-Translation",
	"spanish-translation",
	"DES",
	"des",
	"CXD",
	"cxd",
	"CC3",
	"cc3",
	"PLN",
	"pln",
	"DATA",
	"data",
	nullptr
};

class SnatcherMetaEngineDetection : public AdvancedMetaEngineDetection<SnatcherGameDescription> {
public:
	SnatcherMetaEngineDetection() : AdvancedMetaEngineDetection(adGameDescs, gameList) {
		_md5Bytes = 1024 * 1024;
		_maxScanDepth = 3;
		_directoryGlobs = snatcherDirectoryGlobs;
	}

	const char *getName() const override {
		return "snatcher";
	}

	const char *getEngineName() const override {
		return "snatcher";
	}

	const char *getOriginalCopyright() const override {
		return "Snatcher (C) Konami";
	}

	DetectedGames detectGames(const Common::FSList &fslist, uint32 skipADFlags, bool skipIncomplete) override;

	Common::Error identifyGame(DetectedGame &game, const void **descriptor) override;
};

DetectedGames SnatcherMetaEngineDetection::detectGames(const Common::FSList &fslist, uint32 skipADFlags, bool skipIncomplete) {
	DetectedGames games = AdvancedMetaEngineDetection::detectGames(fslist, skipADFlags, skipIncomplete);

	for (DetectedGame &game : games) {
		if (!game.gameId.equals("snatcher"))
			continue;

		Common::List<Common::Language> langList = FanTranslationHandler::listTranslations(game.platform);

		if (!langList.empty()) {
			langList.push_back(game.language);
			game.appendGUIOptions(getGameGUIOptionsDescriptionLanguages(langList));
		}
	}


	// Universal direct unpacked fallback: detect any unpacked port directly without strict MD5 tables
	if (games.empty()) {
		bool hasPsx = false, hasPce = false, hasSaturn = false, hasPc88 = false, hasMsx = false;
		for (const Common::FSNode &file : fslist) {
			Common::String name = file.getName();
			name.toLowercase();
			if (name.contains("slps_") || name.contains("isz_") || name == "system.cnf") hasPsx = true;
			if (name.hasPrefix("scene_") || name.contains("pce")) hasPce = true;
			if (name == "data.bin" || name == "main_l.bin") hasSaturn = true;
			if (name.contains("d88") || name.contains("disk1") || name.contains("pc88")) hasPc88 = true;
			if (name.contains("snatcher.dsk") || name == "snatcher.com") hasMsx = true;
		}

		if (hasPsx || hasPce || hasSaturn || hasPc88 || hasMsx) {
			DetectedGame g;
			g.gameId = "snatcher";
			g.description = hasPsx ? "Snatcher (PlayStation - Unpacked)" :
			                hasPce ? "Snatcher (PC-Engine - Unpacked)" :
			                hasSaturn ? "Snatcher (Sega Saturn - Unpacked)" :
			                hasPc88 ? "Snatcher (PC-8801 - Unpacked)" : "Snatcher (MSX2 - Unpacked)";
			g.language = Common::EN_ANY;
			g.platform = hasPsx ? Common::kPlatformPSX :
			             hasPce ? Common::kPlatformPCEngine :
			             hasSaturn ? Common::kPlatformSaturn :
			             hasPc88 ? Common::kPlatformPC98 : Common::kPlatformUnknown;
			games.push_back(g);
		}
	}
	return games;
}

Common::Error SnatcherMetaEngineDetection::identifyGame(DetectedGame &game, const void **descriptor) {
	Common::Language selectedlang = Common::UNK_LANG;
	Common::Language defaultLang = Common::UNK_LANG;
	bool supportedFanLang = false;

	if (ConfMan.hasKey("gameid") && ConfMan.get("gameid") == "snatcher" && ConfMan.hasKey("language")) {
		selectedlang = Common::parseLanguage(ConfMan.get("language"));
		Common::Platform platform = Common::parsePlatform(ConfMan.get("platform"));

		if (selectedlang != Common::UNK_LANG && platform != Common::kPlatformUnknown) {
			Common::List<Common::Language> langList = FanTranslationHandler::listTranslations(platform, &defaultLang);
			for (Common::List<Common::Language>::const_iterator i = langList.begin(); i != langList.end(); ++i) {
				if (*i == selectedlang)
					supportedFanLang = true;
			}
		}
	}

	if (supportedFanLang && defaultLang != Common::UNK_LANG)
		ConfMan.set("language", Common::getLanguageCode(defaultLang));

	Common::Error err = AdvancedMetaEngineDetection::identifyGame(game, descriptor);

	if (supportedFanLang && defaultLang != Common::UNK_LANG && selectedlang != Common::UNK_LANG)
		ConfMan.set("language", Common::getLanguageCode(selectedlang));

	if (err.getCode() != Common::kNoError || *descriptor == nullptr) {
		// Modular Platform Detection for unpacked rips & direct folders
		Common::Platform platform = Common::kPlatformUnknown;
		if (ConfMan.hasKey("platform")) {
			platform = Common::parsePlatform(ConfMan.get("platform"));
		}

		if (platform == Common::kPlatformUnknown && ConfMan.hasKey("path")) {
			Common::FSNode dir(Common::Path(ConfMan.get("path")));
			Common::FSList fslist;
			if (dir.getChildren(fslist, Common::FSNode::kListAll)) {
				for (const Common::FSNode &file : fslist) {
					Common::String name = file.getName();
					name.toLowercase();
					if (name.contains("slps_") || name.contains("isz_") || name == "system.cnf") {
						platform = Common::kPlatformPSX;
						break;
					}
					if (name.hasPrefix("scene_") || name.contains("pce") || name.contains("track 02")) {
						platform = Common::kPlatformPCEngine;
						break;
					}
					if (name == "data.bin" || name == "main_l.bin") {
						platform = Common::kPlatformSaturn;
						break;
					}
					if (name.contains("snatcher.dsk") || name == "snatcher.com" || name == "snatcher.img") {
						platform = Common::kPlatformUnknown;
						break;
					}
					if (name.contains("d88") || name.contains("disk1") || name.contains("pc88")) {
						platform = Common::kPlatformPC98;
						break;
					}
					if (name == "sp00.bin" || name == "data_b0.bin") {
						platform = Common::kPlatformSegaCD;
						break;
					}
				}
			}
		}

		// Find the matching authentic descriptor in adGameDescs for this platform
		const SnatcherGameDescription *matchedDesc = nullptr;
		for (const SnatcherGameDescription *d = adGameDescs; d->ad_desc.gameId != nullptr; ++d) {
			if (platform != Common::kPlatformUnknown && d->ad_desc.platform == platform) {
				matchedDesc = d;
				break;
			}
		}

		if (!matchedDesc)
			matchedDesc = &adGameDescs[0];

		*descriptor = matchedDesc;
		game = DetectedGame(getName(), "snatcher", matchedDesc->ad_desc.extra, matchedDesc->ad_desc.language, matchedDesc->ad_desc.platform);
		return Common::kNoError;
	}

	return err;
}

} // End of namespace Snatcher	

REGISTER_PLUGIN_STATIC(SNATCHER_DETECTION, PLUGIN_TYPE_ENGINE_DETECTION, Snatcher::SnatcherMetaEngineDetection);
