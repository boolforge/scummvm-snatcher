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

#ifndef SNATCHER_PALETTE_LINEAR_H
#define SNATCHER_PALETTE_LINEAR_H

#include "snatcher/palette.h"

namespace Snatcher {

class LinearPalette : public Palette {
public:
	LinearPalette(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);
	~LinearPalette() override;

	void setColor(int index, uint8 r, uint8 g, uint8 b) override;
	void getColor(int index, uint8 &r, uint8 &g, uint8 &b) const override;
	void adjustColor(int index, int8 r, int8 g, int8 b) override;
	void getPresetColor(int pal, int index, uint8 &r, uint8 &g, uint8 &b) const override;

	void setDefaults(int mode) override;
	void update() override;

protected:
	void updateSystemPalette() override;

private:
	uint8 _paletteData[256 * 3];
	bool _dirty;
};

Palette *createLinearPalette(const Graphics::PixelFormat *pxf, PaletteManager *pm, GraphicsEngine::GfxState &state);

} // End of namespace Snatcher

#endif // SNATCHER_PALETTE_LINEAR_H
