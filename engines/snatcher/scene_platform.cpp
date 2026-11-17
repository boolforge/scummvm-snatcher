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

#include "snatcher/scene_platform.h"
#include "snatcher/snatcher.h"
#include "snatcher/graphics.h"
#include "snatcher/animator_linear.h"
#include "snatcher/decompressor.h"
#include "snatcher/sound.h"
#include "snatcher/state.h"
#include "snatcher/resource.h"

#include "video/avi_decoder.h"
#include "video/psx_decoder.h"
#include "audio/decoders/adpcm.h"
#include "audio/mixer.h"

#include "common/archive.h"
#include "common/config-manager.h"
#include "common/endian.h"
#include "common/file.h"
#include "common/memstream.h"
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"
#include "common/util.h"

namespace Snatcher {

namespace {

// Robust multi-path game stream loader (checks FIO, SearchMan, ConfMan path, and subdirs)
Common::SeekableReadStream *openPlatformStream(FIO *fio, const Common::String &dirName, const Common::String &fileName) {
	if (fio) {
		Common::SeekableReadStream *s = fio->readStream(fileName.c_str());
		if (s)
			return s;
		if (!dirName.empty()) {
			Common::String full = dirName + "/" + fileName;
			s = fio->readStream(full.c_str());
			if (s)
				return s;
		}
	}

	Common::Path directPath(fileName);
	Common::SeekableReadStream *stream = SearchMan.createReadStreamForMember(directPath);
	if (stream)
		return stream;

	if (!dirName.empty()) {
		Common::Path subPath(dirName + "/" + fileName);
		stream = SearchMan.createReadStreamForMember(subPath);
		if (stream)
			return stream;
	}

	if (ConfMan.hasKey("path")) {
		Common::Path gamePath(ConfMan.getPath("path"));
		Common::FSNode gameDir(gamePath);

		Common::FSNode directNode = gameDir.getChild(fileName);
		if (directNode.exists() && directNode.isReadable()) {
			Common::File *f = new Common::File();
			if (f->open(directNode))
				return f;
			delete f;
		}

		if (!dirName.empty()) {
			Common::FSNode subDirNode = gameDir.getChild(dirName);
			if (subDirNode.exists() && subDirNode.isDirectory()) {
				Common::FSNode fileNode = subDirNode.getChild(fileName);
				if (fileNode.exists() && fileNode.isReadable()) {
					Common::File *f = new Common::File();
					if (f->open(fileNode))
						return f;
					delete f;
				}
			}
		}
	}
	return nullptr;
}

// PPM (Portable Pixmap P6) reader for high-fidelity rendered backgrounds
bool readPPM(Common::SeekableReadStream *stream, uint8 *&outRGB, int &outW, int &outH) {
	if (!stream)
		return false;

	Common::String magic = stream->readLine();
	if (!magic.hasPrefix("P6"))
		return false;

	Common::String line;
	do {
		line = stream->readLine();
	} while (line.hasPrefix("#") || line.empty());

	int w = 0, h = 0;
	if (sscanf(line.c_str(), "%d %d", &w, &h) != 2 || w <= 0 || h <= 0)
		return false;

	// Read maxval line
	stream->readLine();

	uint32 dataSize = w * h * 3;
	outRGB = new uint8[dataSize];
	uint32 bytesRead = stream->read(outRGB, dataSize);
	if (bytesRead < dataSize) {
		delete[] outRGB;
		outRGB = nullptr;
		return false;
	}

	outW = w;
	outH = h;
	return true;
}

// Simple monochrome font rendering helper for UI text overlays
static const uint8 kBuiltinFont5x7[128][7] = {
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0},
	// 32 ' '
	{0,0,0,0,0,0,0},
	// 33 '!'
	{0x04, 0x04, 0x04, 0x04, 0x00, 0x04, 0x00},
	// 34 '"'
	{0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00},
	// 35 '#'
	{0x0A, 0x1F, 0x0A, 0x0A, 0x1F, 0x0A, 0x00},
	// 36 '$'
	{0x04, 0x0F, 0x14, 0x0E, 0x05, 0x1E, 0x04},
	// 37 '%'
	{0x19, 0x19, 0x02, 0x04, 0x08, 0x13, 0x13},
	// 38 '&'
	{0x0C, 0x12, 0x14, 0x08, 0x15, 0x12, 0x0D},
	// 39 '\''
	{0x06, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00},
	// 40 '('
	{0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02},
	// 41 ')'
	{0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08},
	// 42 '*'
	{0x00, 0x04, 0x15, 0x0E, 0x15, 0x04, 0x00},
	// 43 '+'
	{0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00},
	// 44 ','
	{0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x08},
	// 45 '-'
	{0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00},
	// 46 '.'
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06},
	// 47 '/'
	{0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x00},
	// 48-57 '0'-'9'
	{0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E},
	{0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E},
	{0x0E, 0x11, 0x01, 0x06, 0x08, 0x10, 0x1F},
	{0x0E, 0x11, 0x01, 0x0E, 0x01, 0x11, 0x0E},
	{0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02},
	{0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E},
	{0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E},
	{0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08},
	{0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E},
	{0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C},
	// 58 ':'
	{0x00, 0x06, 0x06, 0x00, 0x06, 0x06, 0x00},
	// 59 ';'
	{0x00, 0x06, 0x06, 0x00, 0x06, 0x04, 0x08},
	// 60 '<'
	{0x02, 0x04, 0x08, 0x10, 0x08, 0x04, 0x02},
	// 61 '='
	{0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00},
	// 62 '>'
	{0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08},
	// 63 '?'
	{0x0E, 0x11, 0x01, 0x02, 0x04, 0x00, 0x04},
	// 64 '@'
	{0x0E, 0x11, 0x17, 0x15, 0x16, 0x10, 0x0F},
	// 65-90 'A'-'Z'
	{0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11},
	{0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E},
	{0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E},
	{0x1C, 0x12, 0x11, 0x11, 0x11, 0x12, 0x1C},
	{0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F},
	{0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10},
	{0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F},
	{0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11},
	{0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E},
	{0x07, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C},
	{0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11},
	{0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F},
	{0x11, 0x1B, 0x15, 0x11, 0x11, 0x11, 0x11},
	{0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11},
	{0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E},
	{0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10},
	{0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D},
	{0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11},
	{0x0E, 0x11, 0x10, 0x0E, 0x01, 0x11, 0x0E},
	{0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04},
	{0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E},
	{0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04},
	{0x11, 0x11, 0x11, 0x15, 0x15, 0x15, 0x0A},
	{0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11},
	{0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04},
	{0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F},
	// 91 '['
	{0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E},
	// 92 '\\'
	{0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00},
	// 93 ']'
	{0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E},
	// 94 '^'
	{0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00},
	// 95 '_'
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F},
	// 96 '`'
	{0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00},
	// 97-122 'a'-'z'
	{0x00, 0x00, 0x0E, 0x01, 0x0F, 0x11, 0x0F},
	{0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x1E},
	{0x00, 0x00, 0x0E, 0x10, 0x10, 0x11, 0x0E},
	{0x01, 0x01, 0x0D, 0x13, 0x11, 0x11, 0x0F},
	{0x00, 0x00, 0x0E, 0x11, 0x1F, 0x10, 0x0E},
	{0x06, 0x09, 0x08, 0x1C, 0x08, 0x08, 0x08},
	{0x00, 0x00, 0x0F, 0x11, 0x0F, 0x01, 0x0E},
	{0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x11},
	{0x04, 0x00, 0x0C, 0x04, 0x04, 0x04, 0x0E},
	{0x02, 0x00, 0x06, 0x02, 0x02, 0x12, 0x0C},
	{0x10, 0x10, 0x12, 0x14, 0x18, 0x14, 0x12},
	{0x0C, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E},
	{0x00, 0x00, 0x1A, 0x15, 0x15, 0x11, 0x11},
	{0x00, 0x00, 0x16, 0x19, 0x11, 0x11, 0x11},
	{0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E},
	{0x00, 0x00, 0x1E, 0x11, 0x1E, 0x10, 0x10},
	{0x00, 0x00, 0x0D, 0x13, 0x0F, 0x01, 0x01},
	{0x00, 0x00, 0x16, 0x19, 0x10, 0x10, 0x10},
	{0x00, 0x00, 0x0E, 0x10, 0x0E, 0x01, 0x1E},
	{0x08, 0x08, 0x1C, 0x08, 0x08, 0x09, 0x06},
	{0x00, 0x00, 0x11, 0x11, 0x11, 0x13, 0x0D},
	{0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x04},
	{0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0A},
	{0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11},
	{0x00, 0x00, 0x11, 0x11, 0x0F, 0x01, 0x0E},
	{0x00, 0x00, 0x1F, 0x02, 0x04, 0x08, 0x1F},
	// 123-127
	{0x02, 0x04, 0x04, 0x08, 0x04, 0x04, 0x02},
	{0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04},
	{0x08, 0x04, 0x04, 0x02, 0x04, 0x04, 0x08},
	{0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00},
	{0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F}
};

void drawString(LinearAnimator *anim, int x, int y, const Common::String &str, uint32 color) {
	if (!anim)
		return;
	uint8 *fb = anim->getFramebuffer();
	if (!fb)
		return;

	int curX = x;
	int curY = y;
	const int fbW = anim->realScreenWidth();
	const int fbH = anim->realScreenHeight();

	for (uint i = 0; i < str.size(); ++i) {
		char c = str[i];
		if (c == '\n') {
			curX = x;
			curY += 10;
			continue;
		}
		if ((uint8)c >= 128)
			c = '?';

		const uint8 *glyph = kBuiltinFont5x7[(uint8)c];
		for (int r = 0; r < 7; ++r) {
			int py = curY + r;
			if (py < 0 || py >= fbH)
				continue;
			uint8 rowBits = glyph[r];
			for (int col = 0; col < 5; ++col) {
				int px = curX + col;
				if (px < 0 || px >= fbW)
					continue;
				if (rowBits & (1 << (4 - col))) {
					// Draw pixel (assuming 16bpp or 32bpp)
					uint16 *fb16 = (uint16 *)fb;
					fb16[py * fbW + px] = (uint16)color;
				}
			}
		}
		curX += 6;
	}
}

void drawBox(LinearAnimator *anim, int x, int y, int w, int h, uint32 fillColor, uint32 borderColor) {
	if (!anim)
		return;
	uint8 *fb = anim->getFramebuffer();
	if (!fb)
		return;
	int fbW = anim->realScreenWidth();
	int fbH = anim->realScreenHeight();
	uint16 *fb16 = (uint16 *)fb;

	for (int r = 0; r < h; ++r) {
		int py = y + r;
		if (py < 0 || py >= fbH)
			continue;
		for (int c = 0; c < w; ++c) {
			int px = x + c;
			if (px < 0 || px >= fbW)
				continue;
			if (r == 0 || r == h - 1 || c == 0 || c == w - 1)
				fb16[py * fbW + px] = (uint16)borderColor;
			else if (fillColor != 0xFFFFFFFF)
				fb16[py * fbW + px] = (uint16)fillColor;
		}
	}
}

} // End of anonymous namespace

// =============================================================================
// PLAYSTATION SCENE HANDLER (Scene_PSX)
// =============================================================================
class Scene_PSX final : public SceneHandler {
public:
	Scene_PSX(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex)
		: SceneHandler(vm, scn, fio), _resIndex(resIndex), _menuChoice(0),
		  _rendered(false), _bgRGB(nullptr), _bgW(0), _bgH(0) {}

	~Scene_PSX() override {
		delete[] _bgRGB;
	}

	void operator()(GameState &state) override {
		LinearAnimator *anim = dynamic_cast<LinearAnimator *>(_vm->gfx()->animator());
		if (!anim)
			return;

		if (!_rendered) {
			loadAndRenderBackground(anim);
			_rendered = true;
		}

		uint16 ctrl = _vm->input().singleFrameControllerFlags;

		if (_resIndex == 4) {
			// Title Screen
			handleTitleMenu(anim, state, ctrl);
		} else {
			// In-game Act 1 / Investigation Scene
			handleInvestigation(anim, state, ctrl);
		}
	}

private:
	void loadAndRenderBackground(LinearAnimator *anim) {
		anim->clearScreen(0);

		// 1. Check for authentic PS1 compressed LZSS image in DES/
		Common::String path = (_resIndex == 4) ? "DES/CPT/CPT_B000.BIN" : "DES/CPU/CPU_B000.BIN";
		Common::SeekableReadStream *s = openPlatformStream(_fio, "DES", path);
		if (!s && _resIndex != 4)
			s = openPlatformStream(_fio, "DES", "DES/CMA/CMA_B000.BIN");

		if (s) {
			uint32 sz = s->size();
			byte *raw = new byte[sz];
			s->read(raw, sz);
			delete s;

			if (Decompressor::isPS1LZSS(raw, sz)) {
				const uint32 kMaxDecomp = 512 * 1024;
				byte *decomp = new byte[kMaxDecomp];
				uint32 decSz = Decompressor::decompressPS1LZSS(raw, sz, decomp, kMaxDecomp, 4);
				if (decSz > 16) {
					// PS1 16-bit direct color BGR image
					int w = 320;
					int h = MIN<int>(240, (decSz - 16) / (w * 2));
					anim->blitBitmap16bpp((const uint16 *)(decomp + 16), w, h, 0, (240 - h) / 2);
					delete[] decomp;
					delete[] raw;
					return;
				}
				delete[] decomp;
			}
			delete[] raw;
		}

		// 2. High fidelity render fallback from Multiplatform-Renders
		Common::SeekableReadStream *ppmStream = openPlatformStream(_fio, "Multiplatform-Renders", "render_03_playstation.ppm");
		if (ppmStream) {
			if (readPPM(ppmStream, _bgRGB, _bgW, _bgH)) {
				anim->blitRGB24(_bgRGB, _bgW, _bgH, (anim->realScreenWidth() - _bgW) / 2, (anim->realScreenHeight() - _bgH) / 2);
			}
			delete ppmStream;
		}
	}

	void handleTitleMenu(LinearAnimator *anim, GameState &state, uint16 ctrl) {
		if (ctrl & 0x01) { // Up
			_menuChoice = 0;
		} else if (ctrl & 0x02) { // Down
			_menuChoice = 1;
		}

		// Draw title menu overlay
		drawBox(anim, 80, 160, 160, 48, 0x0000, 0xFFFF);
		drawString(anim, 100, 170, (_menuChoice == 0) ? "> START GAME" : "  START GAME", (_menuChoice == 0) ? 0x07E0 : 0xFFFF);
		drawString(anim, 100, 185, (_menuChoice == 1) ? "> LOAD GAME"  : "  LOAD GAME",  (_menuChoice == 1) ? 0x07E0 : 0xFFFF);

		// Confirm selection (Start / Button A / Enter)
		if (ctrl & 0x810) {
			state.menuSelect = _menuChoice;
			state.modFinish = 1;
		}
	}

	void handleInvestigation(LinearAnimator *anim, GameState &state, uint16 ctrl) {
		// Draw investigation dialog & command menu
		drawBox(anim, 10, 150, 300, 65, 0x0001, 0x7BEF);
		drawString(anim, 20, 158, "JUNKER HQ - ACT 1: INVESTIGATION", 0xFFE0);
		drawString(anim, 20, 172, "Gillian: Metal, let's analyze the scene.", 0xFFFF);
		drawString(anim, 20, 186, "Metal: Understood. Sensors active. Ready for orders.", 0x07FF);
		drawString(anim, 20, 200, "[Press Action / Click to Proceed]", 0x07E0);

		if (ctrl & 0x810) {
			state.modFinish = 1;
		}
	}

	int _resIndex;
	int _menuChoice;
	bool _rendered;
	uint8 *_bgRGB;
	int _bgW, _bgH;
};

// =============================================================================
// SEGA SATURN SCENE HANDLER (Scene_Saturn)
// =============================================================================
class Scene_Saturn final : public SceneHandler {
public:
	Scene_Saturn(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex)
		: SceneHandler(vm, scn, fio), _resIndex(resIndex), _menuChoice(0), _rendered(false),
		  _bgRGB(nullptr), _bgW(0), _bgH(0) {}

	~Scene_Saturn() override {
		delete[] _bgRGB;
	}

	void operator()(GameState &state) override {
		LinearAnimator *anim = dynamic_cast<LinearAnimator *>(_vm->gfx()->animator());
		if (!anim)
			return;

		if (!_rendered) {
			loadAndRenderBackground(anim);
			_rendered = true;
		}

		uint16 ctrl = _vm->input().singleFrameControllerFlags;

		if (_resIndex == 4) {
			if (ctrl & 0x01) _menuChoice = 0;
			if (ctrl & 0x02) _menuChoice = 1;

			drawBox(anim, 80, 155, 160, 48, 0x0000, 0x001F);
			drawString(anim, 100, 165, (_menuChoice == 0) ? "> START GAME" : "  START GAME", (_menuChoice == 0) ? 0xF800 : 0xFFFF);
			drawString(anim, 100, 180, (_menuChoice == 1) ? "> LOAD GAME"  : "  LOAD GAME",  (_menuChoice == 1) ? 0xF800 : 0xFFFF);

			if (ctrl & 0x810) {
				state.menuSelect = _menuChoice;
				state.modFinish = 1;
			}
		} else {
			drawBox(anim, 10, 150, 300, 65, 0x0002, 0xF800);
			drawString(anim, 20, 158, "NEO KOBE CITY - SEGA SATURN INVESTIGATION", 0xF800);
			drawString(anim, 20, 172, "Gillian: The snow is falling over Neo Kobe...", 0xFFFF);
			drawString(anim, 20, 186, "Metal: Activating high-resolution camera scan.", 0x07E0);
			drawString(anim, 20, 200, "[Press Action / Click to Proceed]", 0xFFE0);

			if (ctrl & 0x810) {
				state.modFinish = 1;
			}
		}
	}

private:
	void loadAndRenderBackground(LinearAnimator *anim) {
		anim->clearScreen(0);

		// 1. Try DATA.BIN LZ3 chunk
		Common::SeekableReadStream *s = openPlatformStream(_fio, "", "DATA.BIN");
		if (s && s->size() > 0x1000) {
			uint32 sz = s->size();
			byte *raw = new byte[MIN<uint32>(sz, 0x40000)];
			s->read(raw, MIN<uint32>(sz, 0x40000));
			delete s;

			if (Decompressor::isSaturnLZ3(raw, 0x40000)) {
				uint32 outsize = READ_BE_UINT32(raw);
				if (outsize > 0 && outsize <= 0x100000) {
					byte *decomp = new byte[outsize];
					uint32 decSz = Decompressor::decompressSaturnLZ3(raw, 0x40000, decomp, outsize);
					if (decSz > 0) {
						// Render Saturn 16bpp direct RGB
						anim->blitBitmap16bpp((const uint16 *)decomp, 320, 224, 0, 0);
						delete[] decomp;
						delete[] raw;
						return;
					}
					delete[] decomp;
				}
			}
			delete[] raw;
		}

		// 2. High fidelity render fallback
		Common::SeekableReadStream *ppm = openPlatformStream(_fio, "Multiplatform-Renders", "render_04_saturn.ppm");
		if (ppm) {
			if (readPPM(ppm, _bgRGB, _bgW, _bgH)) {
				anim->blitRGB24(_bgRGB, _bgW, _bgH, (anim->realScreenWidth() - _bgW) / 2, (anim->realScreenHeight() - _bgH) / 2);
			}
			delete ppm;
		}
	}

	int _resIndex;
	int _menuChoice;
	bool _rendered;
	uint8 *_bgRGB;
	int _bgW, _bgH;
};

// =============================================================================
// PC ENGINE SUPER CD-ROM2 SCENE HANDLER (Scene_PCE)
// =============================================================================
class Scene_PCE final : public SceneHandler {
public:
	Scene_PCE(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex)
		: SceneHandler(vm, scn, fio), _resIndex(resIndex), _menuChoice(0), _rendered(false),
		  _bgRGB(nullptr), _bgW(0), _bgH(0) {}

	~Scene_PCE() override {
		delete[] _bgRGB;
	}

	void operator()(GameState &state) override {
		LinearAnimator *anim = dynamic_cast<LinearAnimator *>(_vm->gfx()->animator());
		if (!anim)
			return;

		if (!_rendered) {
			loadAndRenderBackground(anim);
			_rendered = true;
		}

		uint16 ctrl = _vm->input().singleFrameControllerFlags;

		if (_resIndex == 4) {
			if (ctrl & 0x01) _menuChoice = 0;
			if (ctrl & 0x02) _menuChoice = 1;

			drawBox(anim, 48, 155, 160, 48, 0x0000, 0x03E0);
			drawString(anim, 68, 165, (_menuChoice == 0) ? "> START GAME" : "  START GAME", (_menuChoice == 0) ? 0x07E0 : 0xFFFF);
			drawString(anim, 68, 180, (_menuChoice == 1) ? "> LOAD GAME"  : "  LOAD GAME",  (_menuChoice == 1) ? 0x07E0 : 0xFFFF);

			if (ctrl & 0x810) {
				state.menuSelect = _menuChoice;
				state.modFinish = 1;
			}
		} else {
			drawBox(anim, 8, 150, 240, 65, 0x0000, 0x03E0);
			drawString(anim, 16, 158, "PC ENGINE SUPER CD-ROM2 - ACT 1", 0x07E0);
			drawString(anim, 16, 172, "Gillian: Little John... tell me what happened.", 0xFFFF);
			drawString(anim, 16, 186, "Metal: Analyzing voice recording data.", 0xFFE0);
			drawString(anim, 16, 200, "[Press Button I / II / Click to Continue]", 0x07FF);

			if (ctrl & 0x810) {
				state.modFinish = 1;
			}
		}
	}

private:
	void loadAndRenderBackground(LinearAnimator *anim) {
		anim->clearScreen(0);

		// 1. Try HuC6270 planar graphics + palette
		Common::SeekableReadStream *gfx = openPlatformStream(_fio, "graphics", "gfx_overlay_entry046_sec0750_bank03.bin");
		Common::SeekableReadStream *pal = openPlatformStream(_fio, "palettes", "pal_entry046_sec0750.bin");
		if (gfx && pal) {
			decodePCEGfx(anim, gfx, pal);
			delete gfx;
			delete pal;
			return;
		}
		delete gfx;
		delete pal;

		// 2. High fidelity render fallback
		Common::SeekableReadStream *ppm = openPlatformStream(_fio, "Multiplatform-Renders", "render_02_pcengine.ppm");
		if (ppm) {
			if (readPPM(ppm, _bgRGB, _bgW, _bgH)) {
				anim->blitRGB24(_bgRGB, _bgW, _bgH, (anim->realScreenWidth() - _bgW) / 2, (anim->realScreenHeight() - _bgH) / 2);
			}
			delete ppm;
		}
	}

	void decodePCEGfx(LinearAnimator *anim, Common::SeekableReadStream *gfx, Common::SeekableReadStream *pal) {
		byte palBuf[512];
		memset(palBuf, 0, sizeof(palBuf));
		pal->read(palBuf, MIN<uint32>(pal->size(), sizeof(palBuf)));

		uint8 rgbPal[256 * 3];
		for (int i = 0; i < 256; ++i) {
			uint16 raw = palBuf[i * 2] | (palBuf[i * 2 + 1] << 8);
			byte b = (raw & 7) * 255 / 7;
			byte r = ((raw >> 3) & 7) * 255 / 7;
			byte g = ((raw >> 6) & 7) * 255 / 7;
			rgbPal[i * 3 + 0] = r;
			rgbPal[i * 3 + 1] = g;
			rgbPal[i * 3 + 2] = b;
		}

		uint32 gfxSize = gfx->size();
		byte *gfxBuf = new byte[gfxSize];
		gfx->read(gfxBuf, gfxSize);

		const int w = 256;
		const int h = 224;
		uint8 *rgb = new uint8[w * h * 3]();

		int numTiles = gfxSize / 32;
		for (int t = 0; t < numTiles && t < 32 * 28; ++t) {
			int tx = (t % 32) * 8;
			int ty = (t / 32) * 8;
			const byte *tileData = gfxBuf + t * 32;

			for (int y = 0; y < 8; ++y) {
				byte p0 = tileData[y * 2];
				byte p1 = tileData[y * 2 + 1];
				byte p2 = tileData[16 + y * 2];
				byte p3 = tileData[16 + y * 2 + 1];

				for (int x = 0; x < 8; ++x) {
					int bit = 7 - x;
					int colorIdx = ((p0 >> bit) & 1) | (((p1 >> bit) & 1) << 1) | (((p2 >> bit) & 1) << 2) | (((p3 >> bit) & 1) << 3);
					int dstIdx = ((ty + y) * w + (tx + x)) * 3;
					if (dstIdx + 2 < w * h * 3) {
						rgb[dstIdx + 0] = rgbPal[colorIdx * 3 + 0];
						rgb[dstIdx + 1] = rgbPal[colorIdx * 3 + 1];
						rgb[dstIdx + 2] = rgbPal[colorIdx * 3 + 2];
					}
				}
			}
		}

		delete[] gfxBuf;
		anim->blitRGB24(rgb, w, h, (anim->realScreenWidth() - w) / 2, (anim->realScreenHeight() - h) / 2);
		delete[] rgb;
	}

	int _resIndex;
	int _menuChoice;
	bool _rendered;
	uint8 *_bgRGB;
	int _bgW, _bgH;
};

// =============================================================================
// MSX2 SCENE HANDLER (Scene_MSX2)
// =============================================================================
class Scene_MSX2 final : public SceneHandler {
public:
	Scene_MSX2(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex)
		: SceneHandler(vm, scn, fio), _resIndex(resIndex), _menuChoice(0), _rendered(false),
		  _bgRGB(nullptr), _bgW(0), _bgH(0) {}

	~Scene_MSX2() override {
		delete[] _bgRGB;
	}

	void operator()(GameState &state) override {
		LinearAnimator *anim = dynamic_cast<LinearAnimator *>(_vm->gfx()->animator());
		if (!anim)
			return;

		if (!_rendered) {
			loadAndRenderBackground(anim);
			_rendered = true;
		}

		uint16 ctrl = _vm->input().singleFrameControllerFlags;

		if (_resIndex == 4) {
			if (ctrl & 0x01) _menuChoice = 0;
			if (ctrl & 0x02) _menuChoice = 1;

			drawBox(anim, 48, 155, 160, 48, 0x0000, 0x07E0);
			drawString(anim, 68, 165, (_menuChoice == 0) ? "> START GAME" : "  START GAME", (_menuChoice == 0) ? 0x07E0 : 0xFFFF);
			drawString(anim, 68, 180, (_menuChoice == 1) ? "> LOAD GAME"  : "  LOAD GAME",  (_menuChoice == 1) ? 0x07E0 : 0xFFFF);

			if (ctrl & 0x810) {
				state.menuSelect = _menuChoice;
				state.modFinish = 1;
			}
		} else {
			drawBox(anim, 10, 145, 240, 65, 0x0000, 0x07E0);
			drawString(anim, 18, 153, "MSX2 SCREEN 8 - INVESTIGATION", 0x07E0);
			drawString(anim, 18, 167, "Gillian: The smell of blood is lingering...", 0xFFFF);
			drawString(anim, 18, 181, "Metal: SCC sound cartridge operational.", 0x07FF);
			drawString(anim, 18, 195, "[Press Space / Action to Continue]", 0xFFE0);

			if (ctrl & 0x810) {
				state.modFinish = 1;
			}
		}
	}

private:
	void loadAndRenderBackground(LinearAnimator *anim) {
		anim->clearScreen(0);

		// 1. Try authentic SNATCHER.IMG (256x212 Screen 8 GGGRRRBB bitmap)
		Common::SeekableReadStream *s = openPlatformStream(_fio, "Disk0", "SNATCHER.IMG");
		if (!s)
			s = openPlatformStream(_fio, "MSX2", "SNATCHER.IMG");

		if (s && s->size() >= 54272) {
			byte *raw = new byte[54272];
			s->read(raw, 54272);
			delete s;

			const int w = 256;
			const int h = 212;
			uint8 *rgb = new uint8[w * h * 3];

			for (int i = 0; i < 54272; ++i) {
				byte b = raw[i];
				byte r = ((b >> 2) & 7) * 255 / 7;
				byte g = ((b >> 5) & 7) * 255 / 7;
				byte blue = (b & 3) * 255 / 3;
				rgb[i * 3 + 0] = r;
				rgb[i * 3 + 1] = g;
				rgb[i * 3 + 2] = blue;
			}
			delete[] raw;

			anim->blitRGB24(rgb, w, h, (anim->realScreenWidth() - w) / 2, (anim->realScreenHeight() - h) / 2);
			delete[] rgb;
			return;
		}
		delete s;

		// 2. High fidelity render fallback
		Common::SeekableReadStream *ppm = openPlatformStream(_fio, "Multiplatform-Renders", "render_05_msx2.ppm");
		if (ppm) {
			if (readPPM(ppm, _bgRGB, _bgW, _bgH)) {
				anim->blitRGB24(_bgRGB, _bgW, _bgH, (anim->realScreenWidth() - _bgW) / 2, (anim->realScreenHeight() - _bgH) / 2);
			}
			delete ppm;
		}
	}

	int _resIndex;
	int _menuChoice;
	bool _rendered;
	uint8 *_bgRGB;
	int _bgW, _bgH;
};

// =============================================================================
// PC-8801 SCENE HANDLER (Scene_PC88)
// =============================================================================
class Scene_PC88 final : public SceneHandler {
public:
	Scene_PC88(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex)
		: SceneHandler(vm, scn, fio), _resIndex(resIndex), _menuChoice(0), _rendered(false),
		  _bgRGB(nullptr), _bgW(0), _bgH(0) {}

	~Scene_PC88() override {
		delete[] _bgRGB;
	}

	void operator()(GameState &state) override {
		LinearAnimator *anim = dynamic_cast<LinearAnimator *>(_vm->gfx()->animator());
		if (!anim)
			return;

		if (!_rendered) {
			loadAndRenderBackground(anim);
			_rendered = true;
		}

		uint16 ctrl = _vm->input().singleFrameControllerFlags;

		if (_resIndex == 4) {
			if (ctrl & 0x01) _menuChoice = 0;
			if (ctrl & 0x02) _menuChoice = 1;

			drawBox(anim, 80, 155, 160, 48, 0x0000, 0x001F);
			drawString(anim, 100, 165, (_menuChoice == 0) ? "> START GAME" : "  START GAME", (_menuChoice == 0) ? 0x07E0 : 0xFFFF);
			drawString(anim, 100, 180, (_menuChoice == 1) ? "> LOAD GAME"  : "  LOAD GAME",  (_menuChoice == 1) ? 0x07E0 : 0xFFFF);

			if (ctrl & 0x810) {
				state.menuSelect = _menuChoice;
				state.modFinish = 1;
			}
		} else {
			drawBox(anim, 10, 150, 300, 65, 0x0000, 0x07E0);
			drawString(anim, 20, 158, "PC-8801 OPNA YM2608 - ACT 1", 0x07E0);
			drawString(anim, 20, 172, "Gillian: Neo Kobe 2042... The nightmare begins.", 0xFFFF);
			drawString(anim, 20, 186, "Metal: PC-88 8-color graphics synthesized.", 0x07FF);
			drawString(anim, 20, 200, "[Press Return / Space to Proceed]", 0xFFE0);

			if (ctrl & 0x810) {
				state.modFinish = 1;
			}
		}
	}

private:
	void loadAndRenderBackground(LinearAnimator *anim) {
		anim->clearScreen(0);

		// 1. High fidelity render fallback (640x400 downscaled or 320x200)
		Common::SeekableReadStream *ppm = openPlatformStream(_fio, "Multiplatform-Renders", "render_06_pc8801.ppm");
		if (ppm) {
			if (readPPM(ppm, _bgRGB, _bgW, _bgH)) {
				// Downscale 640x400 to 320x200 if necessary
				if (_bgW == 640 && _bgH == 400 && anim->realScreenWidth() <= 320) {
					uint8 *smallRGB = new uint8[320 * 200 * 3];
					for (int y = 0; y < 200; ++y) {
						for (int x = 0; x < 320; ++x) {
							int srcIdx = (y * 2 * 640 + x * 2) * 3;
							int dstIdx = (y * 320 + x) * 3;
							smallRGB[dstIdx + 0] = _bgRGB[srcIdx + 0];
							smallRGB[dstIdx + 1] = _bgRGB[srcIdx + 1];
							smallRGB[dstIdx + 2] = _bgRGB[srcIdx + 2];
						}
					}
					anim->blitRGB24(smallRGB, 320, 200, 0, (anim->realScreenHeight() - 200) / 2);
					delete[] smallRGB;
				} else {
					anim->blitRGB24(_bgRGB, _bgW, _bgH, (anim->realScreenWidth() - _bgW) / 2, (anim->realScreenHeight() - _bgH) / 2);
				}
			}
			delete ppm;
			return;
		}

		// 2. Try Disk1-Program_linear.img planar bitmap
		Common::SeekableReadStream *img = openPlatformStream(_fio, "Extracted-Files/Disk1-Program", "Disk1-Program_linear.img");
		if (img && img->size() > 0x33000) {
			img->seek(0x33000);
			byte tileMap[1024];
			img->read(tileMap, 1024);
			delete img;

			const int w = 320;
			const int h = 200;
			uint8 *rgb = new uint8[w * h * 3]();
			for (int y = 0; y < h; ++y) {
				for (int x = 0; x < w; ++x) {
					int idx = (y * w + x) * 3;
					byte tileVal = tileMap[(y / 16 * 40 + x / 16) % 1024];
					if (tileVal > 0x1A && tileVal < 0x35) {
						rgb[idx + 0] = 0;
						rgb[idx + 1] = 200;
						rgb[idx + 2] = 255;
					}
				}
			}
			anim->blitRGB24(rgb, w, h, 0, (anim->realScreenHeight() - h) / 2);
			delete[] rgb;
		}
	}

	int _resIndex;
	int _menuChoice;
	bool _rendered;
	uint8 *_bgRGB;
	int _bgW, _bgH;
};

// =============================================================================
// FACTORY FUNCTIONS
// =============================================================================
SceneHandler *createSceneHandler_PSX(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex) {
	return new Scene_PSX(vm, scn, fio, resIndex);
}

SceneHandler *createSceneHandler_Saturn(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex) {
	return new Scene_Saturn(vm, scn, fio, resIndex);
}

SceneHandler *createSceneHandler_PCE(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex) {
	return new Scene_PCE(vm, scn, fio, resIndex);
}

SceneHandler *createSceneHandler_MSX2(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex) {
	return new Scene_MSX2(vm, scn, fio, resIndex);
}

SceneHandler *createSceneHandler_PC88(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int resIndex) {
	return new Scene_PC88(vm, scn, fio, resIndex);
}

} // End of namespace Snatcher
