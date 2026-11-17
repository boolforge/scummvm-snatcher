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

#include "snatcher/palette_platform.h"
#include "graphics/paletteman.h"
#include "common/util.h"

namespace Snatcher {

// =============================================================================
// Palette_PlatformBase Implementation
// =============================================================================
Palette_PlatformBase::Palette_PlatformBase(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette(pxf, pm, state), _dirty(false) {
	memset(_paletteData, 0, sizeof(_paletteData));
	setDefaults(0);
}

Palette_PlatformBase::~Palette_PlatformBase() {
}

void Palette_PlatformBase::setColor(int index, uint8 r, uint8 g, uint8 b) {
	if (index >= 0 && index < 256) {
		_paletteData[index * 3]     = r;
		_paletteData[index * 3 + 1] = g;
		_paletteData[index * 3 + 2] = b;
		_dirty = true;
	}
}

void Palette_PlatformBase::getColor(int index, uint8 &r, uint8 &g, uint8 &b) const {
	if (index >= 0 && index < 256) {
		r = _paletteData[index * 3];
		g = _paletteData[index * 3 + 1];
		b = _paletteData[index * 3 + 2];
	} else {
		r = g = b = 0;
	}
}

void Palette_PlatformBase::adjustColor(int index, int8 r, int8 g, int8 b) {
	if (index >= 0 && index < 256) {
		int newR = CLIP<int>(_paletteData[index * 3] + r, 0, 255);
		int newG = CLIP<int>(_paletteData[index * 3 + 1] + g, 0, 255);
		int newB = CLIP<int>(_paletteData[index * 3 + 2] + b, 0, 255);
		_paletteData[index * 3]     = (uint8)newR;
		_paletteData[index * 3 + 1] = (uint8)newG;
		_paletteData[index * 3 + 2] = (uint8)newB;
		_dirty = true;
	}
}

void Palette_PlatformBase::getPresetColor(int pal, int index, uint8 &r, uint8 &g, uint8 &b) const {
	getColor((pal * 16) + (index & 0x0F), r, g, b);
}

void Palette_PlatformBase::setDefaults(int mode) {
	for (int i = 0; i < 256; ++i) {
		_paletteData[i * 3]     = (uint8)i;
		_paletteData[i * 3 + 1] = (uint8)i;
		_paletteData[i * 3 + 2] = (uint8)i;
	}
	_dirty = true;
	updateSystemPalette();
	(void)mode;
}

void Palette_PlatformBase::update() {
	if (_dirty && !_blocked) {
		updateSystemPalette();
		_dirty = false;
	}
}

void Palette_PlatformBase::updateSystemPalette() {
	if (_blocked) {
		_restoreAfterUnblock = true;
		return;
	}

	if (_palMan && _pixelFormat.bytesPerPixel == 1) {
		_palMan->setPalette(_paletteData, 0, 256);
	}
}

// =============================================================================
// PLAYSTATION 1 PALETTE (Palette_PSX)
// =============================================================================
Palette_PSX::Palette_PSX(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette_PlatformBase(pxf, pm, state) {
}

Palette_PSX::~Palette_PSX() {
}

void Palette_PSX::loadCLUT16(const uint16 *clut, int bank) {
	if (!clut || bank < 0 || bank >= 16)
		return;
	int baseIdx = bank * 16;
	for (int i = 0; i < 16; ++i) {
		uint16 c = clut[i];
		// PS1 BGR555: bit 0-4 R, bit 5-9 G, bit 10-14 B
		uint8 r = ((c >> 0) & 0x1F) * 255 / 31;
		uint8 g = ((c >> 5) & 0x1F) * 255 / 31;
		uint8 b = ((c >> 10) & 0x1F) * 255 / 31;
		setColor(baseIdx + i, r, g, b);
	}
}

void Palette_PSX::loadCLUT256(const uint16 *clut) {
	if (!clut)
		return;
	for (int i = 0; i < 256; ++i) {
		uint16 c = clut[i];
		uint8 r = ((c >> 0) & 0x1F) * 255 / 31;
		uint8 g = ((c >> 5) & 0x1F) * 255 / 31;
		uint8 b = ((c >> 10) & 0x1F) * 255 / 31;
		setColor(i, r, g, b);
	}
}

// =============================================================================
// SEGA SATURN PALETTE (Palette_Saturn)
// =============================================================================
Palette_Saturn::Palette_Saturn(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette_PlatformBase(pxf, pm, state) {
}

Palette_Saturn::~Palette_Saturn() {
}

void Palette_Saturn::loadCRAM(const uint16 *cram, int count) {
	if (!cram)
		return;
	int maxColors = MIN<int>(count, 256);
	for (int i = 0; i < maxColors; ++i) {
		uint16 c = cram[i];
		// Saturn RGB555: bit 0-4 B, bit 5-9 G, bit 10-14 R
		uint8 b = ((c >> 0) & 0x1F) * 255 / 31;
		uint8 g = ((c >> 5) & 0x1F) * 255 / 31;
		uint8 r = ((c >> 10) & 0x1F) * 255 / 31;
		setColor(i, r, g, b);
	}
}

// =============================================================================
// PC ENGINE PALETTE (Palette_PCE)
// =============================================================================
Palette_PCE::Palette_PCE(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette_PlatformBase(pxf, pm, state) {
}

Palette_PCE::~Palette_PCE() {
}

void Palette_PCE::loadVCEPalette(const uint16 *vceData, int numEntries) {
	if (!vceData)
		return;
	int maxColors = MIN<int>(numEntries, 256);
	for (int i = 0; i < maxColors; ++i) {
		uint16 c = vceData[i];
		// HuC6260 9-bit RGB: 3 bits per component: GGG RRR BBB
		uint8 g = ((c >> 6) & 0x07) * 255 / 7;
		uint8 r = ((c >> 3) & 0x07) * 255 / 7;
		uint8 b = ((c >> 0) & 0x07) * 255 / 7;
		setColor(i, r, g, b);
	}
}

// =============================================================================
// MSX2 PALETTE (Palette_MSX2 - Yamaha Screen 8 Direct Color)
// =============================================================================
Palette_MSX2::Palette_MSX2(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette_PlatformBase(pxf, pm, state) {
	setDefaults(0);
}

Palette_MSX2::~Palette_MSX2() {
}

void Palette_MSX2::setDefaults(int mode) {
	// Initialize exact 256-color Yamaha V9938 Screen 8 GGGRRRBB direct color space
	for (int i = 0; i < 256; ++i) {
		uint8 g = ((i >> 5) & 0x07) * 255 / 7;
		uint8 r = ((i >> 2) & 0x07) * 255 / 7;
		uint8 b = (i & 0x03) * 255 / 3;
		setColor(i, r, g, b);
	}
	_dirty = true;
	updateSystemPalette();
	(void)mode;
}

// =============================================================================
// PC-8801 PALETTE (Palette_PC88 - Digital 8 Colors)
// =============================================================================
Palette_PC88::Palette_PC88(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette_PlatformBase(pxf, pm, state) {
	setDefaults(0);
}

Palette_PC88::~Palette_PC88() {
}

void Palette_PC88::setDefaults(int mode) {
	// 8 Digital Colors (B, R, G bits)
	for (int i = 0; i < 8; ++i) {
		uint8 b = (i & 1) ? 255 : 0;
		uint8 r = (i & 2) ? 255 : 0;
		uint8 g = (i & 4) ? 255 : 0;
		setColor(i, r, g, b);
	}
	// Fill the rest with grey levels
	for (int i = 8; i < 256; ++i) {
		setColor(i, (uint8)i, (uint8)i, (uint8)i);
	}
	_dirty = true;
	updateSystemPalette();
	(void)mode;
}

// =============================================================================
// Palette Factory Dispatcher
// =============================================================================
Palette *Palette::create(const Graphics::PixelFormat *pxf, PaletteManager *pm, Common::Platform platform, GraphicsEngine::GfxState &state) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSegaPalette(pxf, pm, state);
	case Common::kPlatformPSX:
		return new Palette_PSX(pxf, pm, state);
	case Common::kPlatformSaturn:
		return new Palette_Saturn(pxf, pm, state);
	case Common::kPlatformPCEngine:
		return new Palette_PCE(pxf, pm, state);
	case Common::kPlatformPC98:
		return new Palette_PC88(pxf, pm, state);
	default:
		return new Palette_MSX2(pxf, pm, state);
	}
}

} // End of namespace Snatcher
