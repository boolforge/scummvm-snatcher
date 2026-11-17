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

#include "snatcher/palette_linear.h"
#include "graphics/paletteman.h"
#include "common/util.h"

namespace Snatcher {

LinearPalette::LinearPalette(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state)
	: Palette(pxf, pm, state), _dirty(false) {
	memset(_paletteData, 0, sizeof(_paletteData));
	setDefaults(0);
}

LinearPalette::~LinearPalette() {
}

void LinearPalette::setColor(int index, uint8 r, uint8 g, uint8 b) {
	if (index >= 0 && index < 256) {
		_paletteData[index * 3]     = r;
		_paletteData[index * 3 + 1] = g;
		_paletteData[index * 3 + 2] = b;
		_dirty = true;
	}
}

void LinearPalette::getColor(int index, uint8 &r, uint8 &g, uint8 &b) const {
	if (index >= 0 && index < 256) {
		r = _paletteData[index * 3];
		g = _paletteData[index * 3 + 1];
		b = _paletteData[index * 3 + 2];
	} else {
		r = g = b = 0;
	}
}

void LinearPalette::adjustColor(int index, int8 r, int8 g, int8 b) {
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

void LinearPalette::getPresetColor(int pal, int index, uint8 &r, uint8 &g, uint8 &b) const {
	getColor((pal * 16) + (index & 0x0F), r, g, b);
}

void LinearPalette::setDefaults(int mode) {
	// Initialize default 256-color linear palette
	for (int i = 0; i < 256; ++i) {
		_paletteData[i * 3]     = (uint8)i;
		_paletteData[i * 3 + 1] = (uint8)i;
		_paletteData[i * 3 + 2] = (uint8)i;
	}
	_dirty = true;
	updateSystemPalette();
	(void)mode;
}

void LinearPalette::update() {
	if (_dirty && !_blocked) {
		updateSystemPalette();
		_dirty = false;
	}
}

void LinearPalette::updateSystemPalette() {
	if (_blocked) {
		_restoreAfterUnblock = true;
		return;
	}

	if (_palMan && _pixelFormat.bytesPerPixel == 1) {
		_palMan->setPalette(_paletteData, 0, 256);
	}
}

Palette *createLinearPalette(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state) {
	return new LinearPalette(pxf, pm, state);
}

} // End of namespace Snatcher
