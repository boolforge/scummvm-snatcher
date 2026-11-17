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

#ifndef SNATCHER_TEXT_LINEAR_H
#define SNATCHER_TEXT_LINEAR_H

#include "snatcher/text.h"

namespace Snatcher {

class Animator;

class TextRenderer_Linear : public TextRenderer {
public:
	TextRenderer_Linear(Animator *animator);
	~TextRenderer_Linear() override;

	void setFont(const uint8 *font, uint32 fontSize) override;
	void setCharWidthTable(const uint8 *table, uint32 tableSize) override;

	void enqueuePrintJob(const uint8 *text) override;
	void setPrintDelay(int delay) override;

	void draw() override;
	void reset() override;
	bool needsPrint() const override { return _needDraw; }

private:
	void drawGlyph(uint16 ch);

	Animator *_animator;
	const uint8 *_textPtr;
	bool _needDraw;
	uint16 _printDelay;
	uint16 _printDelayCounter;
	uint8 _color;
	uint16 _curX;
	uint16 _curY;

	const uint8 *_font;
	uint32 _fontSize;
	const uint8 *_charWidthTable;
	uint32 _charWidthTableSize;
};

TextRenderer *createLinearTextRenderer(Animator *animator);

} // End of namespace Snatcher

#endif // SNATCHER_TEXT_LINEAR_H
