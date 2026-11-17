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

#include "snatcher/animator_platform.h"
#include "snatcher/palette.h"
#include "snatcher/sound.h"
#include "snatcher/transition.h"
#include "snatcher/util.h"
#include "common/endian.h"
#include "common/util.h"

namespace Snatcher {

// =============================================================================
// Animator_PlatformBase Implementation
// =============================================================================
Animator_PlatformBase::Animator_PlatformBase(const Graphics::PixelFormat *pxf,
                                             Common::Platform platform,
                                             GraphicsEngine::GfxState &state,
                                             Palette *pal,
                                             TransitionManager *scr,
                                             SoundEngine *snd,
                                             uint16 nativeWidth,
                                             uint16 nativeHeight)
	: Animator(state), _platform(platform), _palette(pal),
	  _width(nativeWidth), _height(nativeHeight), _planeMode(0) {

	_pixelFormat = pxf ? *pxf : Graphics::PixelFormat::createFormatCLUT8();
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;

	_framebuffer = new uint8[_width * _height * bpp]();
	_textRenderBuffer = new uint8[_width * _height]();

	for (int i = 0; i < 64; ++i) {
		_animations[i] = new AnimObject(i);
		_animations[i]->clear();
	}
}

Animator_PlatformBase::~Animator_PlatformBase() {
	delete[] _framebuffer;
	delete[] _textRenderBuffer;
	for (int i = 0; i < 64; ++i)
		delete _animations[i];
}

bool Animator_PlatformBase::enqueueDrawCommands(ResourcePointer &res) {
	return true;
}

void Animator_PlatformBase::clearDrawCommands() {
}

void Animator_PlatformBase::initData(ResourcePointer &res, uint8 mode) {
}

void Animator_PlatformBase::initAnimations(ResourcePointer &res, uint16 len, bool dontUpdate) {
	if (len < 2)
		return;
	uint8 count = *res++;
	for (uint8 i = 0; i < count && i < 64; ++i) {
		AnimObject &a = *_animations[i];
		a.clear();
		a.enable = 1;
	}
}

void Animator_PlatformBase::linkAnimations(ResourcePointer &res, uint16 len) {
}

void Animator_PlatformBase::clearAnimations(int mode) {
	for (int i = 0; i < 64; ++i)
		_animations[i]->clear();
}

void Animator_PlatformBase::setPlaneMode(uint16 mode) {
	_planeMode = mode;
}

void Animator_PlatformBase::resetTextFields() {
	if (_textRenderBuffer)
		memset(_textRenderBuffer, 0, _width * _height);
}

void Animator_PlatformBase::clearTextInputLine() {
}

uint8 *Animator_PlatformBase::getTextRenderBuffer() const {
	return _textRenderBuffer;
}

void Animator_PlatformBase::renderTextBuffer(uint16 firstLine, uint8 numLines) {
	if (!_textRenderBuffer || !_framebuffer)
		return;

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	int startY = firstLine;
	int endY = MIN<int>(_height, firstLine + numLines);

	for (int y = startY; y < endY; ++y) {
		const uint8 *srcRow = _textRenderBuffer + (y * _width);
		uint8 *dstRow = _framebuffer + (y * _width * bpp);

		for (int x = 0; x < _width; ++x) {
			uint8 glyphPixel = srcRow[x];
			if (glyphPixel != 0) {
				uint8 r, g, b;
				if (_palette) {
					_palette->getColor(glyphPixel, r, g, b);
				} else {
					r = g = b = 0xFF;
				}
				uint32 col = _pixelFormat.RGBToColor(r, g, b);
				if (bpp == 2) {
					reinterpret_cast<uint16 *>(dstRow)[x] = (uint16)col;
				} else if (bpp == 4) {
					reinterpret_cast<uint32 *>(dstRow)[x] = col;
				} else if (bpp == 1) {
					dstRow[x] = glyphPixel;
				}
			}
		}
	}
}

void Animator_PlatformBase::updateSaveLoadDialog(SaveInfo &saveInfo) {
}

void Animator_PlatformBase::updateScreen(uint8 *screen) {
	if (!_framebuffer || !screen)
		return;
	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	memcpy(screen, _framebuffer, _width * _height * bpp);
}

void Animator_PlatformBase::updateAnimations() {
	for (int i = 0; i < 64; ++i) {
		AnimObject &a = *_animations[i];
		if (!a.enable || (a.drawFlags & 1))
			continue;
		a.posX += a.relSpeedX;
		a.posY += a.relSpeedY;
	}
}

void Animator_PlatformBase::setAnimParameter(uint8 animObjId, int param, int32 value) {
	if (animObjId >= 64)
		return;
	AnimObject &a = *_animations[animObjId];
	switch (param) {
	case GraphicsEngine::kAnimParaEnable:      a.enable = value; break;
	case GraphicsEngine::kAnimParaBlinkRate:   a.blinkRate = value; break;
	case GraphicsEngine::kAnimParaDrawFlags:   a.drawFlags = value; break;
	case GraphicsEngine::kAnimParaPosX:        a.posX = value; break;
	case GraphicsEngine::kAnimParaPosY:        a.posY = value; break;
	case GraphicsEngine::kAnimParaRelSpeedX:   a.relSpeedX = value; break;
	case GraphicsEngine::kAnimParaRelSpeedY:   a.relSpeedY = value; break;
	case GraphicsEngine::kAnimParaPalette:     a.palette = value; break;
	case GraphicsEngine::kAnimParaTarget:      a.target = value; break;
	case GraphicsEngine::kAnimParaOvrTile:     a.ovrTile = value; break;
	case GraphicsEngine::kAnimParaF1c:         a.f1c = value; break;
	case GraphicsEngine::kAnimParaPhase:       a.phase = value; break;
	case GraphicsEngine::kAnimParaFrame:       a.frame = value; break;
	case GraphicsEngine::kAnimParaFrameDelay:  a.frameDelay = value; break;
	case GraphicsEngine::kAnimFreezeFlag:      a.freeze = value; break;
	default: break;
	}
}

void Animator_PlatformBase::setAnimGroupParameter(uint8 animObjId, int groupOp, int32 value) {
}

int32 Animator_PlatformBase::getAnimParameter(uint8 animObjId, int param) const {
	if (animObjId >= 64)
		return 0;
	const AnimObject &a = *_animations[animObjId];
	switch (param) {
	case GraphicsEngine::kAnimParaEnable:    return a.enable;
	case GraphicsEngine::kAnimParaPosX:      return a.posX;
	case GraphicsEngine::kAnimParaPosY:      return a.posY;
	case GraphicsEngine::kAnimParaPhase:     return a.phase;
	case GraphicsEngine::kAnimParaFrame:     return a.frame;
	default: return 0;
	}
}

uint8 Animator_PlatformBase::getAnimScriptByte(uint8 animObjId, uint16 offset) const {
	if (animObjId >= 64)
		return 0;
	const AnimObject &a = *_animations[animObjId];
	if (a.scriptData() != nullptr)
		return a.scriptData[offset];
	return 0;
}

void Animator_PlatformBase::animCopySpec(uint8 srcAnimObjId, uint8 dstAnimObjId) {
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

void Animator_PlatformBase::createMouseCursor() {
}

int Animator_PlatformBase::drawBootLogoFrame(uint8 *screen, int frameNo) {
	return -1;
}

void Animator_PlatformBase::blitRGB24(const uint8 *src, int w, int h, int dstX, int dstY) {
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

void Animator_PlatformBase::blitBitmap16bpp(const uint16 *src, int w, int h, int dstX, int dstY) {
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

void Animator_PlatformBase::blitBitmapCLUT8(const uint8 *src, int w, int h, int dstX, int dstY) {
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

void Animator_PlatformBase::clearScreen(uint32 color) {
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

// =============================================================================
// Animator_PSX Implementation (PlayStation 320x240 VRAM)
// =============================================================================
Animator_PSX::Animator_PSX(const Graphics::PixelFormat *pxf,
                           GraphicsEngine::GfxState &state,
                           Palette *pal,
                           TransitionManager *scr,
                           SoundEngine *snd)
	: Animator_PlatformBase(pxf, Common::kPlatformPSX, state, pal, scr, snd, 320, 240) {
}

Animator_PSX::~Animator_PSX() {
}

void Animator_PSX::blitPS1BGR15(const uint16 *src, int w, int h, int dstX, int dstY) {
	blitBitmap16bpp(src, w, h, dstX, dstY);
}

void Animator_PSX::loadPS1VRAM(const uint16 *src, int x, int y, int w, int h) {
	blitBitmap16bpp(src, w, h, x, y);
}

// =============================================================================
// Animator_Saturn Implementation (Sega Saturn 320x224 VDP1/VDP2)
// =============================================================================
Animator_Saturn::Animator_Saturn(const Graphics::PixelFormat *pxf,
                                 GraphicsEngine::GfxState &state,
                                 Palette *pal,
                                 TransitionManager *scr,
                                 SoundEngine *snd)
	: Animator_PlatformBase(pxf, Common::kPlatformSaturn, state, pal, scr, snd, 320, 224) {
}

Animator_Saturn::~Animator_Saturn() {
}

void Animator_Saturn::blitSaturnRGB16(const uint16 *src, int w, int h, int dstX, int dstY) {
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
			uint16 pix = src[y * w + x];
			// Saturn 16bpp direct RGB: 5 bits Red, 5 bits Green, 5 bits Blue
			uint8 r = ((pix >> 10) & 0x1F) << 3;
			uint8 g = ((pix >> 5) & 0x1F) << 3;
			uint8 b = (pix & 0x1F) << 3;
			uint32 col = _pixelFormat.RGBToColor(r, g, b);
			uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
			if (bpp == 2)
				*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
			else if (bpp == 4)
				*(reinterpret_cast<uint32 *>(dst)) = col;
		}
	}
}

// =============================================================================
// Animator_PCE Implementation (PC Engine HuC6270 256x224 Planar 4bpp)
// =============================================================================
Animator_PCE::Animator_PCE(const Graphics::PixelFormat *pxf,
                           GraphicsEngine::GfxState &state,
                           Palette *pal,
                           TransitionManager *scr,
                           SoundEngine *snd)
	: Animator_PlatformBase(pxf, Common::kPlatformPCEngine, state, pal, scr, snd, 256, 224) {
}

Animator_PCE::~Animator_PCE() {
}

void Animator_PCE::decodeAndBlitTiles4bpp(const uint8 *tileData, uint32 numTiles, const uint16 *palette16, int dstX, int dstY) {
	if (!tileData || !palette16 || !_framebuffer)
		return;

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	for (uint32 t = 0; t < numTiles && t < 32 * 28; ++t) {
		int tx = dstX + (t % 32) * 8;
		int ty = dstY + (t / 32) * 8;
		const uint8 *tile = tileData + (t * 32);

		for (int y = 0; y < 8; ++y) {
			int screenY = ty + y;
			if (screenY < 0 || screenY >= _height)
				continue;

			uint8 p0 = tile[y * 2];
			uint8 p1 = tile[y * 2 + 1];
			uint8 p2 = tile[16 + y * 2];
			uint8 p3 = tile[16 + y * 2 + 1];

			for (int x = 0; x < 8; ++x) {
				int screenX = tx + x;
				if (screenX < 0 || screenX >= _width)
					continue;

				int bit = 7 - x;
				int colorIdx = ((p0 >> bit) & 1) | (((p1 >> bit) & 1) << 1) | (((p2 >> bit) & 1) << 2) | (((p3 >> bit) & 1) << 3);
				uint16 palColor = palette16[colorIdx & 0x0F];
				uint8 b = (palColor & 7) * 255 / 7;
				uint8 r = ((palColor >> 3) & 7) * 255 / 7;
				uint8 g = ((palColor >> 6) & 7) * 255 / 7;
				uint32 col = _pixelFormat.RGBToColor(r, g, b);

				uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
				if (bpp == 2)
					*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
				else if (bpp == 4)
					*(reinterpret_cast<uint32 *>(dst)) = col;
			}
		}
	}
}

// =============================================================================
// Animator_MSX2 Implementation (MSX2 Screen 8 256x212 GGGRRRBB)
// =============================================================================
Animator_MSX2::Animator_MSX2(const Graphics::PixelFormat *pxf,
                             GraphicsEngine::GfxState &state,
                             Palette *pal,
                             TransitionManager *scr,
                             SoundEngine *snd)
	: Animator_PlatformBase(pxf, Common::kPlatformUnknown, state, pal, scr, snd, 320, 224) {
}

Animator_MSX2::~Animator_MSX2() {
}

void Animator_MSX2::blitScreen8Bitmap(const uint8 *screen8Data, int dstX, int dstY) {
	if (!screen8Data || !_framebuffer)
		return;

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	const int w = 256;
	const int h = 212;

	for (int y = 0; y < h; ++y) {
		int screenY = dstY + y;
		if (screenY < 0 || screenY >= _height)
			continue;
		for (int x = 0; x < w; ++x) {
			int screenX = dstX + x;
			if (screenX < 0 || screenX >= _width)
				continue;
			uint8 b = screen8Data[y * w + x];
			uint8 red = ((b >> 2) & 7) * 255 / 7;
			uint8 green = ((b >> 5) & 7) * 255 / 7;
			uint8 blue = (b & 3) * 255 / 3;
			uint32 col = _pixelFormat.RGBToColor(red, green, blue);

			uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
			if (bpp == 2)
				*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
			else if (bpp == 4)
				*(reinterpret_cast<uint32 *>(dst)) = col;
		}
	}
}

// =============================================================================
// Animator_PC88 Implementation (PC-8801 3-Plane Planar 8-Color)
// =============================================================================
Animator_PC88::Animator_PC88(const Graphics::PixelFormat *pxf,
                             GraphicsEngine::GfxState &state,
                             Palette *pal,
                             TransitionManager *scr,
                             SoundEngine *snd)
	: Animator_PlatformBase(pxf, Common::kPlatformPC98, state, pal, scr, snd, 320, 200) {
}

Animator_PC88::~Animator_PC88() {
}

void Animator_PC88::blitPlanar8Color(const uint8 *bluePlane, const uint8 *redPlane, const uint8 *greenPlane, int w, int h, int dstX, int dstY) {
	if (!bluePlane || !redPlane || !greenPlane || !_framebuffer)
		return;

	const int bpp = _pixelFormat.bytesPerPixel ? _pixelFormat.bytesPerPixel : 1;
	int bytesPerRow = w / 8;

	for (int y = 0; y < h; ++y) {
		int screenY = dstY + y;
		if (screenY < 0 || screenY >= _height)
			continue;

		for (int byteIdx = 0; byteIdx < bytesPerRow; ++byteIdx) {
			uint8 bByte = bluePlane[y * bytesPerRow + byteIdx];
			uint8 rByte = redPlane[y * bytesPerRow + byteIdx];
			uint8 gByte = greenPlane[y * bytesPerRow + byteIdx];

			for (int bit = 7; bit >= 0; --bit) {
				int screenX = dstX + (byteIdx * 8 + (7 - bit));
				if (screenX < 0 || screenX >= _width)
					continue;

				uint8 b = ((bByte >> bit) & 1) * 255;
				uint8 r = ((rByte >> bit) & 1) * 255;
				uint8 g = ((gByte >> bit) & 1) * 255;
				uint32 col = _pixelFormat.RGBToColor(r, g, b);

				uint8 *dst = _framebuffer + (screenY * _width + screenX) * bpp;
				if (bpp == 2)
					*(reinterpret_cast<uint16 *>(dst)) = (uint16)col;
				else if (bpp == 4)
					*(reinterpret_cast<uint32 *>(dst)) = col;
			}
		}
	}
}

// =============================================================================
// Animator Factory Dispatcher
// =============================================================================
Animator *Animator::create(const Graphics::PixelFormat *pxf, Common::Platform platform,
                           GraphicsEngine::GfxState &state, Palette *pal,
                           TransitionManager *scr, SoundEngine *snd,
                           bool enableAspectRatioCorrection) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSCDAnimator(pxf, state, pal, scr, snd, enableAspectRatioCorrection);
	case Common::kPlatformPSX:
		return new Animator_PSX(pxf, state, pal, scr, snd);
	case Common::kPlatformSaturn:
		return new Animator_Saturn(pxf, state, pal, scr, snd);
	case Common::kPlatformPCEngine:
		return new Animator_PCE(pxf, state, pal, scr, snd);
	case Common::kPlatformPC98:
		return new Animator_PC88(pxf, state, pal, scr, snd);
	default:
		return new Animator_MSX2(pxf, state, pal, scr, snd);
	}
}

} // End of namespace Snatcher
