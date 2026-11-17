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

namespace {

#define FLAGS(id, a, b, c, f) { id, a, Common::UNK_LANG, Common::kPlatformUnknown, b, c, Common::UNK_LANG, f }

#define SNATCHER_FLAGS(a, b, c, f) FLAGS(Snatcher::GI_SNATCHER, a, b, c, f)

const SnatcherGameDescription adGameDescs[] = {
	// Sega CD - USA
	{
		{
			"snatcher",
			"US",
			AD_ENTRY2s(	"DATA_B0.BIN",	"63170d11da5ebc3a66ecf0fc2d23e78a", 24176,
						"SP05.BIN",		"e0486f6c73778cddd11f9618776125f4", 35756),
			Common::EN_ANY,
			Common::kPlatformSegaCD,
			ADGF_TESTING,
			GUIO2(GUIO_NOSPEECHVOLUME, GUIO_MIDISEGACD)
		},
		SNATCHER_FLAGS(MDT_SEGACD, true, false, 0)
	},
	// Sega CD - Europe
	{
		{
			"snatcher",
			"EU",
			AD_ENTRY2s(	"DATA_B0.BIN",	"63170d11da5ebc3a66ecf0fc2d23e78a", 24176,
						"SP05.BIN",		"a4ee2ea44629f64bd5d04e0d3160d7a5", 35756),
			Common::EN_ANY,
			Common::kPlatformSegaCD,
			ADGF_TESTING,
			GUIO2(GUIO_NOSPEECHVOLUME, GUIO_MIDISEGACD)
		},
		SNATCHER_FLAGS(MDT_SEGACD, true, true, 0)
	},
	// Sega CD - Spanish Translation (Proyecto Snatcher / Tradusquare)
	{
		{
			"snatcher",
			"Spanish",
			AD_ENTRY1s(	"DATA_B0.BIN",	"63170d11da5ebc3a66ecf0fc2d23e78a", 24176),
			Common::ES_ESP,
			Common::kPlatformSegaCD,
			ADGF_TESTING,
			GUIO2(GUIO_NOSPEECHVOLUME, GUIO_MIDISEGACD)
		},
		SNATCHER_FLAGS(MDT_SEGACD, true, false, Snatcher::GF_FAN_TRANSLATION)
	},
	// PlayStation 1 - Japan (SLPS-00154)
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY2s(	"SLPS_001.54",	"e6919cb9166eb9cf90e93c40570b489c", 495616,
						"SYSTEM.CNF",	"efd75590e55971866f594474b99cedb8", 68),
			Common::JA_JPN,
			Common::kPlatformPSX,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, 0)
	},
	// PlayStation 1 - English Translation (pepasjc v1.0.1)
	{
		{
			"snatcher",
			"English",
			AD_ENTRY1s(	"SYSTEM.CNF",	"efd75590e55971866f594474b99cedb8", 68),
			Common::EN_ANY,
			Common::kPlatformPSX,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, Snatcher::GF_FAN_TRANSLATION)
	},
	// PlayStation 1 - Uncensored Restoration
	{
		{
			"snatcher",
			"Uncensored",
			AD_ENTRY1s(	"CXK_B061.BIN",	"b17172feaa2df595cce2eb5b9f71ee52", 11224),
			Common::JA_JPN,
			Common::kPlatformPSX,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, Snatcher::GF_UNCENSORED | Snatcher::GF_RESTORED)
	},
	// Sega Saturn - Japan (T-9507G)
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY2s(	"MAIN_L.BIN",	"13f86239a6991536daaa2e6976c4bc9d", 259192,
						"A.BIN",		"817316186e0afbc8e4028480d4ef339c", 141792),
			Common::JA_JPN,
			Common::kPlatformSaturn,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, true, false, 0)
	},
	// Sega Saturn - English Translation
	{
		{
			"snatcher",
			"English",
			AD_ENTRY2s(	"MAIN_L.BIN",	"fad37148d6ecd6a4b1fb6672f421041a", 259192,
						"DATA.BIN",		"ff459bd721659f9d1f918f124c3193eb", 11008000),
			Common::EN_ANY,
			Common::kPlatformSaturn,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, true, false, Snatcher::GF_FAN_TRANSLATION)
	},
	// PC Engine Super CD-ROM - Japan (Redump)
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY1s(	"Snatcher CD-ROMantic (Japan) (Track 02).bin",	"fd6e66d66ac3ee8b594b7474254ee29f", 80779440),
			Common::JA_JPN,
			Common::kPlatformPCEngine,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, 0)
	},
	// PC Engine Super CD-ROM - English Translation (NintendoComplete 2026)
	{
		{
			"snatcher",
			"English",
			AD_ENTRY1s(	"Snatcher (English) (Track 02).bin",	"26a3770c487365caa207db08262a9f0c", 81779568),
			Common::EN_ANY,
			Common::kPlatformPCEngine,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, Snatcher::GF_FAN_TRANSLATION | Snatcher::GF_UNCENSORED)
	},
	// MSX2 - Japan
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY1s(	"SNATCHER.DSK",	"efe6a96a11ccc38925b7e9756272008a", 8192000),
			Common::JA_JPN,
			Common::kPlatformUnknown,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, 0)
	},
	// MSX2 - KYBT2 floppy
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY1s(	"DISK0.dsk",	"5de030c9171812086acab149b097adde", 737280),
			Common::JA_JPN,
			Common::kPlatformUnknown,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, 0)
	},
	// PC-8801 - Japan
	{
		{
			"snatcher",
			"Japan",
			AD_ENTRY1s(	"Snatcher (1988)(Konami)(Disk 1 of 5)(Program Disk).d88",	"bb64ffcef2b7c7e41c2eae92298549b0", 426240),
			Common::JA_JPN,
			Common::kPlatformUnknown,
			ADGF_TESTING,
			GUIO1(GUIO_NOSPEECHVOLUME)
		},
		SNATCHER_FLAGS(MDT_NONE, false, false, 0)
	},

	{ AD_TABLE_END_MARKER, FLAGS(0, MDT_NONE, false, false, 0) }
};

const PlainGameDescriptor gameList[] = {
	{ "snatcher", "Snatcher" },
	{ 0, 0 }
};

} // End of anonymous namespace
