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

#ifndef SNATCHER_PALETTE_PLATFORM_H
#define SNATCHER_PALETTE_PLATFORM_H

#include "snatcher/palette.h"

namespace Snatcher {

class Palette_PlatformBase : public Palette {
public:
	Palette_PlatformBase(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_PlatformBase() override;

	void setColor(int index, uint8 r, uint8 g, uint8 b) override;
	void getColor(int index, uint8 &r, uint8 &g, uint8 &b) const override;
	void adjustColor(int index, int8 r, int8 g, int8 b) override;
	void getPresetColor(int pal, int index, uint8 &r, uint8 &g, uint8 &b) const override;

	void setDefaults(int mode) override;
	void update() override;

protected:
	void updateSystemPalette() override;

	uint8 _paletteData[256 * 3];
	bool _dirty;
};

// -----------------------------------------------------------------------------
// PLAYSTATION 1 PALETTE (Palette_PSX)
// Authentic PS1 15-bit BGR555 CLUT (Color Look-Up Table)
// -----------------------------------------------------------------------------
class Palette_PSX final : public Palette_PlatformBase {
public:
	Palette_PSX(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_PSX() override;

	void loadCLUT16(const uint16 *clut, int bank);
	void loadCLUT256(const uint16 *clut);
};

// -----------------------------------------------------------------------------
// SEGA SATURN PALETTE (Palette_Saturn)
// Authentic Saturn 15-bit RGB555 CRAM (Color RAM)
// -----------------------------------------------------------------------------
class Palette_Saturn final : public Palette_PlatformBase {
public:
	Palette_Saturn(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_Saturn() override;

	void loadCRAM(const uint16 *cram, int count);
};

// -----------------------------------------------------------------------------
// PC ENGINE PALETTE (Palette_PCE)
// Authentic HuC6260 VCE 9-bit RGB palette RAM (512 master colors)
// -----------------------------------------------------------------------------
class Palette_PCE final : public Palette_PlatformBase {
public:
	Palette_PCE(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_PCE() override;

	void loadVCEPalette(const uint16 *vceData, int numEntries);
};

// -----------------------------------------------------------------------------
// MSX2 PALETTE (Palette_MSX2)
// Authentic Yamaha V9938 Screen 8 GGGRRRBB direct color & palette registers
// -----------------------------------------------------------------------------
class Palette_MSX2 final : public Palette_PlatformBase {
public:
	Palette_MSX2(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_MSX2() override;

	void setDefaults(int mode) override;
};

// -----------------------------------------------------------------------------
// PC-8801 PALETTE (Palette_PC88)
// Authentic NEC PC-8801 digital 8 colors & analog palette
// -----------------------------------------------------------------------------
class Palette_PC88 final : public Palette_PlatformBase {
public:
	Palette_PC88(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~Palette_PC88() override;

	void setDefaults(int mode) override;
};

} // End of namespace Snatcher

#endif // SNATCHER_PALETTE_PLATFORM_H
