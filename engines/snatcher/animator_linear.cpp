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

#include "snatcher/animator_linear.h"
#include "snatcher/boot_logo.h"
#include "snatcher/palette.h"
#include "snatcher/transition.h"
#include "snatcher/sound.h"
#include "common/system.h"
#include "common/util.h"

namespace Snatcher {

LinearAnimator::LinearAnimator(const Graphics::PixelFormat *pxf, Common::Platform platform,
                               GraphicsEngine::GfxState &state, Palette *pal,
                               TransitionManager *scr, SoundEngine *snd,
                               bool enableAspectRatioCorrection)
	: Animator(state), _platform(platform),
	  _pixelFormat(pxf ? *pxf : Graphics::PixelFormat::createFormatCLUT8()),
	  _palette(pal) {
	(void)scr;
	(void)snd;
	(void)enableAspectRatioCorrection;

	switch (_platform) {
	case Common::kPlatformPSX:
		_width = 320;
		_height = 240;
		break;
	case Common::kPlatformSaturn:
		_width = 320;
		_height = 224;
		break;
	case Common::kPlatformPCEngine:
		_width = 256;
		_height = 224;
		break;
	default:
		_width = 320;
		_height = 224;
		break;
	}

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	_framebuffer = new uint8[_width * _height * bpp]();
	_textRenderBuffer = new uint8[_width * 256]();
}

LinearAnimator::~LinearAnimator() {
	delete[] _framebuffer;
	delete[] _textRenderBuffer;
}

bool LinearAnimator::enqueueDrawCommands(ResourcePointer &res) {
	(void)res;
	return true;
}

void LinearAnimator::clearDrawCommands() {
}

void LinearAnimator::initData(ResourcePointer &res, uint8 mode) {
	(void)res;
	(void)mode;
}

void LinearAnimator::initAnimations(ResourcePointer &res, uint16 len, bool dontUpdate) {
	(void)res;
	(void)len;
	(void)dontUpdate;
}

void LinearAnimator::linkAnimations(ResourcePointer &res, uint16 len) {
	(void)res;
	(void)len;
}

void LinearAnimator::clearAnimations(int mode) {
	(void)mode;
}

void LinearAnimator::setPlaneMode(uint16 mode) {
	(void)mode;
}

void LinearAnimator::resetTextFields() {
	if (_textRenderBuffer) {
		memset(_textRenderBuffer, 0, _width * 256);
	}
}

void LinearAnimator::clearTextInputLine() {
}

uint8 *LinearAnimator::getTextRenderBuffer() const {
	return _textRenderBuffer;
}

void LinearAnimator::renderTextBuffer(uint16 firstLine, uint8 numLines) {
	if (!_textRenderBuffer || !_framebuffer)
		return;

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	for (uint8 l = 0; l < numLines; ++l) {
		uint16 y = firstLine + l;
		if (y >= _height)
			break;
		const uint8 *src = _textRenderBuffer + (y * _width);
		uint8 *dst = _framebuffer + (y * _width * bpp);
		if (bpp == 1) {
			memcpy(dst, src, _width);
		} else {
			for (uint16 x = 0; x < _width; ++x) {
				uint8 c = src[x];
				if (c != 0) {
					uint8 r, g, b;
					if (_palette) {
						_palette->getColor(c, r, g, b);
					} else {
						r = g = b = c;
					}
					uint32 col = _pixelFormat.RGBToColor(r, g, b);
					if (bpp == 2) {
						*(reinterpret_cast<uint16 *>(dst + x * 2)) = (uint16)col;
					} else if (bpp == 4) {
						*(reinterpret_cast<uint32 *>(dst + x * 4)) = col;
					}
				}
			}
		}
	}
}

void LinearAnimator::updateSaveLoadDialog(SaveInfo &saveInfo) {
	(void)saveInfo;
}

void LinearAnimator::updateScreen(uint8 *screen) {
	if (!screen || !_framebuffer)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	memcpy(screen, _framebuffer, _width * _height * bpp);
}

void LinearAnimator::updateAnimations() {
}

void LinearAnimator::setAnimParameter(uint8 animObjId, int param, int32 value) {
	(void)animObjId;
	(void)param;
	(void)value;
}

void LinearAnimator::setAnimGroupParameter(uint8 animObjId, int groupOp, int32 value) {
	(void)animObjId;
	(void)groupOp;
	(void)value;
}

int32 LinearAnimator::getAnimParameter(uint8 animObjId, int param) const {
	(void)animObjId;
	(void)param;
	return 0;
}

uint8 LinearAnimator::getAnimScriptByte(uint8 animObjId, uint16 offset) const {
	(void)animObjId;
	(void)offset;
	return 0;
}

void LinearAnimator::animCopySpec(uint8 srcAnimObjId, uint8 dstAnimObjId) {
	(void)srcAnimObjId;
	(void)dstAnimObjId;
}

uint16 LinearAnimator::screenWidth() const {
	return _width;
}

uint16 LinearAnimator::screenHeight() const {
	return _height;
}

uint16 LinearAnimator::realScreenWidth() const {
	return _width;
}

uint16 LinearAnimator::realScreenHeight() const {
	return _height;
}

void LinearAnimator::createMouseCursor() {
}

int LinearAnimator::drawBootLogoFrame(uint8 *screen, int frameNo) {
	(void)screen;
	(void)frameNo;
	return -1;
}

Animator *createLinearAnimator(const Graphics::PixelFormat *pxf, Common::Platform platform,
                               GraphicsEngine::GfxState &state, Palette *pal,
                               TransitionManager *scr, SoundEngine *snd,
                               bool enableAspectRatioCorrection) {
	return new LinearAnimator(pxf, platform, state, pal, scr, snd, enableAspectRatioCorrection);
}

Animator *Animator::create(const Graphics::PixelFormat *pxf, Common::Platform platform,
                           GraphicsEngine::GfxState &state, Palette *pal,
                           TransitionManager *scr, SoundEngine *snd,
                           bool enableAspectRatioCorrection) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSCDAnimator(pxf, state, pal, scr, snd, enableAspectRatioCorrection);
	case Common::kPlatformPSX:
	case Common::kPlatformSaturn:
	case Common::kPlatformPCEngine:
	default:
		return createLinearAnimator(pxf, platform, state, pal, scr, snd, enableAspectRatioCorrection);
	}
}

} // End of namespace Snatcher
