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

#include "snatcher/boot_logo.h"
#include "common/system.h"
#include "common/util.h"
#include "graphics/paletteman.h"

namespace Snatcher {

namespace {

// 5x7 glyphs, one byte per row (bit 4 = leftmost pixel).
struct Glyph {
	char c;
	uint8 rows[7];
};

const Glyph kFont[] = {
	{'A', {0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}}, {'B', {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}},
	{'C', {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E}}, {'D', {0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E}},
	{'E', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}}, {'F', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}},
	{'G', {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F}}, {'H', {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}},
	{'I', {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}}, {'J', {0x07, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C}},
	{'K', {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11}}, {'L', {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}},
	{'M', {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}}, {'N', {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}},
	{'O', {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}}, {'P', {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}},
	{'Q', {0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D}}, {'R', {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11}},
	{'S', {0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E}}, {'T', {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}},
	{'U', {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}}, {'V', {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04}},
	{'W', {0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11}}, {'X', {0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11}},
	{'Y', {0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04}}, {'Z', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F}},
	{'0', {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E}}, {'1', {0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E}},
	{'2', {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F}}, {'3', {0x1F, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0E}},
	{'4', {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02}}, {'5', {0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E}},
	{'6', {0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E}}, {'7', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08}},
	{'8', {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E}}, {'9', {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C}},
	{'(', {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02}}, {')', {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08}},
	{'.', {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C}}, {',', {0x00, 0x00, 0x00, 0x00, 0x0C, 0x04, 0x08}},
	{'-', {0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00}}
};

// Per-port boot data. Add a row (or a BootLogo subclass) to support a new port.
struct PlatformBanner {
	Common::Platform platform;
	const char *system;
	const char *copyright;
};

const PlatformBanner kBanners[] = {
	{Common::kPlatformPC98,      "PC-8801 VERSION",       "(C) 1988 KONAMI"},
	{Common::kPlatformUnknown,   "MSX2 / PC-88 VERSION",  "(C) 1988 KONAMI"},
	{Common::kPlatformPCEngine,  "SUPER CD-ROM2 VERSION", "(C) 1992 KONAMI"},
	{Common::kPlatformSaturn,    "SEGA SATURN VERSION",   "(C) 1996 KONAMI"},
	{Common::kPlatformPSX,       "PLAYSTATION VERSION",   "(C) 1996 KONAMI"}
};

const int kFadeFrames = 30;
const int kHoldFrames = 150;

class BannerBootLogo : public BootLogo {
public:
	BannerBootLogo(const PlatformBanner &b) : _b(b), _paletteSet(false) {}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		const int total = kFadeFrames * 2 + kHoldFrames;
		if (frameNo >= total)
			return -1;

		int level = 255;
		if (frameNo < kFadeFrames)
			level = frameNo * 255 / kFadeFrames;
		else if (frameNo >= kFadeFrames + kHoldFrames)
			level = (total - frameNo) * 255 / kFadeFrames;

		const int bpp = pxf.bytesPerPixel ? pxf.bytesPerPixel : 1;
		if (bpp == 1 && !_paletteSet) {
			// Index == gray level, so the same pixel value works for every fade step.
			byte pal[256 * 3];
			for (int i = 0; i < 256; ++i)
				pal[i * 3] = pal[i * 3 + 1] = pal[i * 3 + 2] = i;
			system->getPaletteManager()->setPalette(pal, 0, 256);
			_paletteSet = true;
		}

		const uint32 color = (bpp == 1) ? (uint32)level : pxf.RGBToColor(level, level, level);
		const uint32 konamiOrange = (bpp == 1) ? (uint32)(level * 210 / 255) : pxf.RGBToColor(level * 228 / 255, level * 94 / 255, 0);
		const uint32 konamiRed = (bpp == 1) ? (uint32)(level * 180 / 255) : pxf.RGBToColor(level * 196 / 255, 0, level * 26 / 255);
		memset(screen, 0, width * height * bpp);

		// Render authentic Konami Ribbon Logo (two stylized arcs / ribbons)
		const int cx = width / 2;
		const int cy = height / 3 - 8;
		const int rScale = MAX(1, width / 200);

		// Upper orange ribbon arc
		for (int dy = -16 * rScale; dy <= -4 * rScale; ++dy) {
			int y = cy + dy;
			int row = dy / rScale + 16;
			int xStart = cx - 28 * rScale + (row * 3 * rScale) / 2;
			int xEnd = xStart + 24 * rScale;
			for (int x = xStart; x < xEnd; ++x) {
				putPixel(screen, width, height, bpp, konamiOrange, x, y);
			}
		}

		// Lower red ribbon arc
		for (int dy = -2 * rScale; dy <= 10 * rScale; ++dy) {
			int y = cy + dy;
			int row = dy / rScale + 2;
			int xStart = cx - 22 * rScale + (row * 3 * rScale) / 2;
			int xEnd = xStart + 24 * rScale;
			for (int x = xStart; x < xEnd; ++x) {
				putPixel(screen, width, height, bpp, konamiRed, x, y);
			}
		}

		const int scale = MAX(1, width / 256);
		drawCentered(screen, width, height, bpp, color, "KONAMI", cy + 18 * rScale, scale * 3);
		drawCentered(screen, width, height, bpp, color, _b.system, height * 2 / 3, scale);
		drawCentered(screen, width, height, bpp, color, _b.copyright, height * 2 / 3 + 12 * scale, scale);
		return frameNo + 1;
	}

private:
	static const Glyph *findGlyph(char c) {
		for (uint i = 0; i < ARRAYSIZE(kFont); ++i)
			if (kFont[i].c == c)
				return &kFont[i];
		return nullptr;
	}

	static void putPixel(uint8 *screen, int width, int height, int bpp, uint32 color, int x, int y) {
		if (x < 0 || y < 0 || x >= width || y >= height)
			return;
		uint8 *p = screen + (y * width + x) * bpp;
		for (int i = 0; i < bpp; ++i)
			p[i] = (color >> (8 * i)) & 0xFF; // little-endian host layout matches ScummVM's native format
	}

	static void drawCentered(uint8 *screen, int width, int height, int bpp, uint32 color, const char *text, int y, int s) {
		const int len = strlen(text);
		const int x0 = (width - len * 6 * s) / 2;
		for (int n = 0; n < len; ++n) {
			const Glyph *g = findGlyph(text[n]);
			if (!g)
				continue;
			for (int row = 0; row < 7; ++row)
				for (int col = 0; col < 5; ++col)
					if (g->rows[row] & (0x10 >> col))
						for (int dy = 0; dy < s; ++dy)
							for (int dx = 0; dx < s; ++dx)
								putPixel(screen, width, height, bpp, color, x0 + (n * 6 + col) * s + dx, y + row * s + dy);
		}
	}

	PlatformBanner _b;
	bool _paletteSet;
};

} // End of anonymous namespace

BootLogo *BootLogo::create(Common::Platform platform) {
	if (platform == Common::kPlatformSegaCD)
		return nullptr;
	for (uint i = 0; i < ARRAYSIZE(kBanners); ++i)
		if (kBanners[i].platform == platform)
			return new BannerBootLogo(kBanners[i]);
	return nullptr;
}

} // End of namespace Snatcher
