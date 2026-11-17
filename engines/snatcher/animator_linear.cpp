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
#include "snatcher/anim_object.h"
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
	  _palette(pal), _planeMode(0) {
	(void)scr;
	(void)snd;
	(void)enableAspectRatioCorrection;

	for (int i = 0; i < 64; ++i)
		_animations[i] = new AnimObject(i);

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
	for (int i = 0; i < 64; ++i)
		delete _animations[i];
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
	ResourcePointer next = res + len;
	ResourcePointer in = res;
	while (in < next) {
		uint8 id = *in++;
		if (id >= 64)
			break;
		AnimObject *a = _animations[id];
		if ((a->enable & 0xF0) && dontUpdate)
			return;
		a->clear();
		a->enable = 1;
		a->res = res;
		a->controlFlags = *in++;
		a->posX = in.readIncrSINT16() << 16;
		a->posY = in.readIncrSINT16() << 16;
		a->spriteTableLocation = in.readIncrUINT32();
		int16 offs = in.readIncrSINT16();
		a->scriptData = in + offs;
		a->frame = 0xFFFF;
	}
}

void LinearAnimator::linkAnimations(ResourcePointer &res, uint16 len) {
	ResourcePointer next = res + len;
	ResourcePointer in = res;
	while (in < next) {
		uint16 p = *in++;
		uint16 c = *in++;
		if (p < 64 && c < 64) {
			AnimObject *pPr = _animations[p];
			AnimObject *pCh = _animations[c];
			pCh->next = pPr->children;
			pPr->children = c;
			pCh->parent = p;
		}
	}
}

void LinearAnimator::clearAnimations(int mode) {
	if (mode) {
		for (int i = 1; i < 64; ++i) {
			if (_animations[i]->enable && !(_animations[i]->scriptComFlags & 1))
				_animations[i]->clear();
		}
	} else {
		for (int i = 0; i < 64; ++i)
			_animations[i]->clear();
	}
}

void LinearAnimator::setPlaneMode(uint16 mode) {
	_planeMode = mode;
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
			for (uint16 x = 0; x < _width; ++x) {
				if (src[x] != 0)
					dst[x] = src[x];
			}
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
	for (int i = 0; i < 64; ++i) {
		AnimObject *s = _animations[i];
		if (!s || !s->enable)
			continue;
		s->posX += s->absSpeedX ? s->absSpeedX : s->relSpeedX;
		s->posY += s->absSpeedY ? s->absSpeedY : s->relSpeedY;
		if (s->frameDelay > 0)
			--s->frameDelay;
		if (s->blinkRate > 0) {
			if (++s->blinkCounter >= s->blinkRate) {
				s->blinkCounter = 0;
				s->blink ^= 1;
			}
		}
	}
}

void LinearAnimator::setAnimParameter(uint8 animObjId, int param, int32 value) {
	if (animObjId >= 64)
		return;
	AnimObject &a = *_animations[animObjId];
	switch (param) {
	case GraphicsEngine::kAnimParaEnable:
		a.enable = value ? 1 : 0;
		break;
	case GraphicsEngine::kAnimParaBlinkRate:
		a.blinkRate = value;
		break;
	case GraphicsEngine::kAnimParaDrawFlags:
		a.drawFlags = value;
		break;
	case GraphicsEngine::kAnimParaPosX:
		a.posX = value << 16;
		break;
	case GraphicsEngine::kAnimParaPosY:
		a.posY = value << 16;
		break;
	case GraphicsEngine::kAnimParaRelSpeedX:
		a.relSpeedX = value << 16;
		break;
	case GraphicsEngine::kAnimParaRelSpeedY:
		a.relSpeedY = value << 16;
		break;
	case GraphicsEngine::kAnimParaPalette:
		a.palette = value;
		break;
	case GraphicsEngine::kAnimParaTarget:
		a.target = value;
		break;
	case GraphicsEngine::kAnimParaOvrTile:
		a.ovrTile = value;
		break;
	case GraphicsEngine::kAnimParaF1c:
		a.f1c = value;
		break;
	case GraphicsEngine::kAnimParaTimeStamp:
		a.timeStamp = (uint32)value;
		break;
	case GraphicsEngine::kAnimParaPhase:
		a.phase = value;
		break;
	case GraphicsEngine::kAnimParaControlFlags:
		a.controlFlags = value;
		break;
	case GraphicsEngine::kAnimParaAllowFrameDrop:
		a.allowFrameDrop = value;
		break;
	case GraphicsEngine::kAnimParaFrameSeqCounter:
		a.frameSeqCounter = value;
		break;
	case GraphicsEngine::kAnimParaFrame:
		a.frame = value;
		break;
	case GraphicsEngine::kAnimParaFrameDelay:
		a.frameDelay = value;
		break;
	case GraphicsEngine::kAnimParaActionTimer:
		a.actionTimer = value;
		break;
	case GraphicsEngine::kAnimParaBlink:
		a.blink = value;
		break;
	case GraphicsEngine::kAnimParaBlinkCounter:
		a.blinkCounter = value;
		break;
	case GraphicsEngine::kAnimParaBlinkDuration:
		a.blinkDuration = value;
		break;
	case GraphicsEngine::kAnimParaAbsSpeedX:
		a.absSpeedX = value << 16;
		break;
	case GraphicsEngine::kAnimParaAbsSpeedY:
		a.absSpeedY = value << 16;
		break;
	case GraphicsEngine::kAnimParaScriptComFlags:
		a.scriptComFlags = value;
		break;
	case GraphicsEngine::kAnimFreezeFlag:
		a.freeze = value;
		break;
	default:
		break;
	}
}

void LinearAnimator::setAnimGroupParameter(uint8 animObjId, int groupOp, int32 value) {
	if (animObjId >= 64)
		return;
	AnimObject &a = *_animations[animObjId];
	switch (groupOp) {
	case 0:
		a.controlFlags &= ~GraphicsEngine::kAnimHide;
		a.controlFlags &= ~GraphicsEngine::kAnimPause;
		break;
	case 1:
		a.controlFlags |= GraphicsEngine::kAnimHide;
		break;
	case 2:
		a.absSpeedX = a.relSpeedX;
		break;
	case 3:
		a.absSpeedY = a.relSpeedY;
		break;
	case 4:
		a.controlFlags &= GraphicsEngine::kAnimHide;
		break;
	case 5:
		a.controlFlags |= GraphicsEngine::kAnimPause;
		break;
	case 6:
		a.controlFlags = GraphicsEngine::kAnimPause | GraphicsEngine::kAnimHide;
		a.scriptComFlags = 0;
		break;
	case 7:
		a.controlFlags = a.scriptComFlags = 0;
		a.frameDelay = -1;
		a.frame = 0xFFFF;
		break;
	default:
		break;
	}
	(void)value;
}

int32 LinearAnimator::getAnimParameter(uint8 animObjId, int param) const {
	if (animObjId >= 64)
		return 0;
	const AnimObject &a = *_animations[animObjId];
	switch (param) {
	case GraphicsEngine::kAnimParaEnable:
		return a.enable;
	case GraphicsEngine::kAnimParaBlinkRate:
		return a.blinkRate;
	case GraphicsEngine::kAnimParaDrawFlags:
		return a.drawFlags;
	case GraphicsEngine::kAnimParaPosX:
		return a.posX >> 16;
	case GraphicsEngine::kAnimParaPosY:
		return a.posY >> 16;
	case GraphicsEngine::kAnimParaRelSpeedX:
		return a.relSpeedX >> 16;
	case GraphicsEngine::kAnimParaRelSpeedY:
		return a.relSpeedY >> 16;
	case GraphicsEngine::kAnimParaPalette:
		return a.palette;
	case GraphicsEngine::kAnimParaTarget:
		return a.target;
	case GraphicsEngine::kAnimParaOvrTile:
		return a.ovrTile;
	case GraphicsEngine::kAnimParaF1c:
		return a.f1c;
	case GraphicsEngine::kAnimParaTimeStamp:
		return (int32)a.timeStamp;
	case GraphicsEngine::kAnimParaPhase:
		return a.phase;
	case GraphicsEngine::kAnimParaControlFlags:
		return a.controlFlags;
	case GraphicsEngine::kAnimParaAllowFrameDrop:
		return a.allowFrameDrop;
	case GraphicsEngine::kAnimParaFrameSeqCounter:
		return a.frameSeqCounter;
	case GraphicsEngine::kAnimParaFrame:
		return a.frame;
	case GraphicsEngine::kAnimParaFrameDelay:
		return a.frameDelay;
	case GraphicsEngine::kAnimParaActionTimer:
		return a.actionTimer;
	case GraphicsEngine::kAnimParaBlink:
		return a.blink;
	case GraphicsEngine::kAnimParaBlinkCounter:
		return a.blinkCounter;
	case GraphicsEngine::kAnimParaBlinkDuration:
		return a.blinkDuration;
	case GraphicsEngine::kAnimParaAbsSpeedX:
		return a.absSpeedX >> 16;
	case GraphicsEngine::kAnimParaAbsSpeedY:
		return a.absSpeedY >> 16;
	case GraphicsEngine::kAnimParaScriptComFlags:
		return a.scriptComFlags;
	case GraphicsEngine::kAnimFreezeFlag:
		return a.freeze;
	default:
		return 0;
	}
}

uint8 LinearAnimator::getAnimScriptByte(uint8 animObjId, uint16 offset) const {
	if (animObjId >= 64)
		return 0;
	const AnimObject &a = *_animations[animObjId];
	if (a.scriptData())
		return a.scriptData[offset];
	return 0;
}

void LinearAnimator::animCopySpec(uint8 srcAnimObjId, uint8 dstAnimObjId) {
	if (srcAnimObjId < 64 && dstAnimObjId < 64) {
		AnimObject &src = *_animations[srcAnimObjId];
		AnimObject &dst = *_animations[dstAnimObjId];
		dst.palette = src.palette;
		dst.frameDelay = src.frameDelay;
		dst.spriteTableLocation = src.spriteTableLocation;
		dst.scriptData = src.scriptData;
		dst.spriteData = src.spriteData;
	}
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

void LinearAnimator::blitBitmap16bpp(const uint16 *src, int w, int h, int dstX, int dstY) {
	if (!src || !_framebuffer)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 2;
	for (int y = 0; y < h; ++y) {
		int screenY = dstY + y;
		if (screenY < 0 || screenY >= _height)
			continue;
		for (int x = 0; x < w; ++x) {
			int screenX = dstX + x;
			if (screenX < 0 || screenX >= _width)
				continue;
			uint16 pix = src[y * w + x];
			uint8 r = (pix & 0x1F) << 3;
			uint8 g = ((pix >> 5) & 0x1F) << 3;
			uint8 b = ((pix >> 10) & 0x1F) << 3;
			uint32 col = _pixelFormat.RGBToColor(r, g, b);
			uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
			if (bpp == 2) {
				*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
			} else if (bpp == 4) {
				*(reinterpret_cast<uint32 *>(dst)) = col;
			} else if (bpp == 1) {
				*dst = (r * 30 + g * 59 + b * 11) / 100;
			}
		}
	}
}

void LinearAnimator::blitBitmapCLUT8(const uint8 *src, int w, int h, int dstX, int dstY) {
	if (!src || !_framebuffer)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	for (int y = 0; y < h; ++y) {
		int screenY = dstY + y;
		if (screenY < 0 || screenY >= _height)
			continue;
		for (int x = 0; x < w; ++x) {
			int screenX = dstX + x;
			if (screenX < 0 || screenX >= _width)
				continue;
			uint8 c = src[y * w + x];
			uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
			if (bpp == 1) {
				*dst = c;
			} else {
				uint8 r, g, b;
				if (_palette) {
					_palette->getColor(c, r, g, b);
				} else {
					r = g = b = c;
				}
				uint32 col = _pixelFormat.RGBToColor(r, g, b);
				if (bpp == 2) {
					*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
				} else if (bpp == 4) {
					*(reinterpret_cast<uint32 *>(dst)) = col;
				}
			}
		}
	}
}

void LinearAnimator::blitRGB24(const uint8 *src, int w, int h, int dstX, int dstY) {
	if (!src || !_framebuffer)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	for (int y = 0; y < h; ++y) {
		int screenY = dstY + y;
		if (screenY < 0 || screenY >= _height)
			continue;
		for (int x = 0; x < w; ++x) {
			int screenX = dstX + x;
			if (screenX < 0 || screenX >= _width)
				continue;
			uint8 r = src[(y * w + x) * 3];
			uint8 g = src[(y * w + x) * 3 + 1];
			uint8 b = src[(y * w + x) * 3 + 2];
			uint32 col = _pixelFormat.RGBToColor(r, g, b);
			uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
			if (bpp == 2) {
				*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
			} else if (bpp == 4) {
				*(reinterpret_cast<uint32 *>(dst)) = col;
			} else if (bpp == 1) {
				*dst = (r * 30 + g * 59 + b * 11) / 100;
			}
		}
	}
}

void LinearAnimator::clearScreen(uint32 color) {
	if (!_framebuffer)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	if (color == 0 || bpp == 1) {
		memset(_framebuffer, (uint8)color, _width * _height * bpp);
	} else if (bpp == 2) {
		uint16 *fb16 = reinterpret_cast<uint16 *>(_framebuffer);
		for (int i = 0; i < _width * _height; ++i)
			fb16[i] = (uint16)color;
	} else if (bpp == 4) {
		uint32 *fb32 = reinterpret_cast<uint32 *>(_framebuffer);
		for (int i = 0; i < _width * _height; ++i)
			fb32[i] = color;
	}
}

Animator *createLinearAnimator(const Graphics::PixelFormat *pxf, Common::Platform platform,
                               GraphicsEngine::GfxState &state, Palette *pal,
                               TransitionManager *scr, SoundEngine *snd,
                               bool enableAspectRatioCorrection) {
	return new LinearAnimator(pxf, platform, state, pal, scr, snd, enableAspectRatioCorrection);
}

} // End of namespace Snatcher
