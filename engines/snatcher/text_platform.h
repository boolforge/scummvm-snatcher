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

#ifndef SNATCHER_TEXT_PLATFORM_H
#define SNATCHER_TEXT_PLATFORM_H

#include "snatcher/text.h"
#include "snatcher/animator.h"

namespace Snatcher {

class TextRenderer_PlatformBase : public TextRenderer {
public:
	explicit TextRenderer_PlatformBase(Animator *animator, uint16 defaultX, uint16 defaultY, uint16 defaultColor);
	~TextRenderer_PlatformBase() override;

	void setFont(const uint8 *font, uint32 fontSize) override;
	void setCharWidthTable(const uint8 *table, uint32 tableSize) override;

	void enqueuePrintJob(const uint8 *text) override;
	void setPrintDelay(int delay) override;

	void draw() override;
	void reset() override;
	bool needsPrint() const override { return _needDraw; }

protected:
	virtual void drawGlyph(uint8 glyphCode);

	Animator *_animator;
	const uint8 *_textPtr;
	bool _needDraw;
	int _printDelay;
	int _printDelayCounter;
	uint16 _color;
	uint16 _curX;
	uint16 _curY;
	uint16 _startX;
	uint16 _startY;

	const uint8 *_font;
	uint32 _fontSize;
	const uint8 *_charWidthTable;
	uint32 _charWidthTableSize;
};

// -----------------------------------------------------------------------------
// PLAYSTATION 1 TEXT RENDERER (TextRenderer_PSX)
// Authentic PS1 dialog text with CLUT shadow/border
// -----------------------------------------------------------------------------
class TextRenderer_PSX final : public TextRenderer_PlatformBase {
public:
	explicit TextRenderer_PSX(Animator *animator);
	~TextRenderer_PSX() override;

protected:
	void drawGlyph(uint8 glyphCode) override;
};

// -----------------------------------------------------------------------------
// SEGA SATURN TEXT RENDERER (TextRenderer_Saturn)
// Authentic Sega Saturn NBG1 dialog text overlay
// -----------------------------------------------------------------------------
class TextRenderer_Saturn final : public TextRenderer_PlatformBase {
public:
	explicit TextRenderer_Saturn(Animator *animator);
	~TextRenderer_Saturn() override;

protected:
	void drawGlyph(uint8 glyphCode) override;
};

// -----------------------------------------------------------------------------
// PC ENGINE TEXT RENDERER (TextRenderer_PCE)
// Authentic HuC6270 8x8 font tile rendering with 16-color subpalette
// -----------------------------------------------------------------------------
class TextRenderer_PCE final : public TextRenderer_PlatformBase {
public:
	explicit TextRenderer_PCE(Animator *animator);
	~TextRenderer_PCE() override;

protected:
	void drawGlyph(uint8 glyphCode) override;
};

// -----------------------------------------------------------------------------
// MSX2 TEXT RENDERER (TextRenderer_MSX2)
// Authentic Yamaha V9938 Screen 8 font rendering from SNATCHER.FNT
// -----------------------------------------------------------------------------
class TextRenderer_MSX2 final : public TextRenderer_PlatformBase {
public:
	explicit TextRenderer_MSX2(Animator *animator);
	~TextRenderer_MSX2() override;

protected:
	void drawGlyph(uint8 glyphCode) override;
};

// -----------------------------------------------------------------------------
// PC-8801 TEXT RENDERER (TextRenderer_PC88)
// Authentic 16x16 / 8x16 font rendering for NEC PC-8801
// -----------------------------------------------------------------------------
class TextRenderer_PC88 final : public TextRenderer_PlatformBase {
public:
	explicit TextRenderer_PC88(Animator *animator);
	~TextRenderer_PC88() override;

protected:
	void drawGlyph(uint8 glyphCode) override;
};

} // End of namespace Snatcher

#endif // SNATCHER_TEXT_PLATFORM_H
