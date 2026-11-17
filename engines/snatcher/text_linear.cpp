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

#include "snatcher/text_linear.h"
#include "snatcher/animator.h"
#include "common/util.h"

namespace Snatcher {

TextRenderer_Linear::TextRenderer_Linear(Animator *animator)
	: TextRenderer(), _animator(animator), _textPtr(nullptr), _needDraw(false),
	  _printDelay(0), _printDelayCounter(0), _color(15), _curX(24), _curY(176),
	  _font(nullptr), _fontSize(0), _charWidthTable(nullptr), _charWidthTableSize(0) {
}

TextRenderer_Linear::~TextRenderer_Linear() {
}

void TextRenderer_Linear::setFont(const uint8 *font, uint32 fontSize) {
	_font = font;
	_fontSize = fontSize;
}

void TextRenderer_Linear::setCharWidthTable(const uint8 *table, uint32 tableSize) {
	_charWidthTable = table;
	_charWidthTableSize = tableSize;
}

void TextRenderer_Linear::enqueuePrintJob(const uint8 *text) {
	_textPtr = text;
	_needDraw = true;
	_printDelayCounter = _printDelay = 0;
}

void TextRenderer_Linear::setPrintDelay(int delay) {
	_printDelay = delay;
}

void TextRenderer_Linear::reset() {
	_needDraw = false;
	_curX = 24;
	_curY = 176;
}

void TextRenderer_Linear::drawGlyph(uint16 ch) {
	if (!_animator)
		return;

	uint8 *renderBuf = _animator->getTextRenderBuffer();
	if (!renderBuf)
		return;

	uint16 screenW = _animator->screenWidth();
	int glyphW = 8;
	int glyphH = 8;

	if (_charWidthTable && ch < _charWidthTableSize) {
		glyphW = _charWidthTable[ch];
	}

	// Render 8x8 font glyph if available
	if (_font && (ch * 8 + 8 <= _fontSize)) {
		const uint8 *src = _font + (ch * 8);
		for (int row = 0; row < glyphH; ++row) {
			uint16 y = _curY + row;
			if (y >= 256)
				break;
			uint8 byte = src[row];
			for (int col = 0; col < glyphW && col < 8; ++col) {
				if (byte & (0x80 >> col)) {
					uint16 x = _curX + col;
					if (x < screenW) {
						renderBuf[y * screenW + x] = _color;
					}
				}
			}
		}
	} else {
		// Fallback simple square block
		for (int row = 0; row < 6; ++row) {
			uint16 y = _curY + row;
			if (y >= 256)
				break;
			for (int col = 0; col < 6; ++col) {
				uint16 x = _curX + col;
				if (x < screenW) {
					renderBuf[y * screenW + x] = _color;
				}
			}
		}
	}

	_curX += glyphW + 1;
}

void TextRenderer_Linear::draw() {
	if (!_needDraw || !_textPtr || !_animator)
		return;

	int firstRow = _curY;
	const uint8 *s = _textPtr;

	while (*s) {
		uint8 in = *s++;
		if (in == 0xFF) {
			_needDraw = false;
			break;
		} else if (in == 0xFE) {
			_color = *s++;
		} else if (in == 0xFD) {
			_curY += 12;
			_curX = 24;
		} else if (in == 0xFC) {
			// Pause / delay
			_textPtr = s;
			return;
		} else {
			drawGlyph(in);
		}
	}

	_textPtr = s;
	_needDraw = false;
	_animator->renderTextBuffer(firstRow, 24);
}

TextRenderer *createLinearTextRenderer(Animator *animator) {
	return new TextRenderer_Linear(animator);
}

TextRenderer *TextRenderer::create(Common::Platform platform, Animator *animator) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSegaTextRenderer(animator);
	case Common::kPlatformPSX:
	case Common::kPlatformSaturn:
	case Common::kPlatformPCEngine:
	default:
		return createLinearTextRenderer(animator);
	}
}

} // End of namespace Snatcher
