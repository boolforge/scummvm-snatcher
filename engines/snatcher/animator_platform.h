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

#ifndef SNATCHER_ANIMATOR_PLATFORM_H
#define SNATCHER_ANIMATOR_PLATFORM_H

#include "snatcher/animator.h"
#include "snatcher/anim_object.h"
#include "graphics/pixelformat.h"

namespace Snatcher {

class Palette;
class TransitionManager;
class SoundEngine;

// Base platform animator managing standard linear framebuffers and AnimObject lifecycle
class Animator_PlatformBase : public Animator {
public:
	Animator_PlatformBase(const Graphics::PixelFormat *pxf, Common::Platform platform,
	                      GraphicsEngine::GfxState &state, Palette *pal,
	                      TransitionManager *scr, SoundEngine *snd,
	                      uint16 nativeWidth, uint16 nativeHeight);
	~Animator_PlatformBase() override;

	bool enqueueDrawCommands(ResourcePointer &res) override;
	void clearDrawCommands() override;
	void initData(ResourcePointer &res, uint8 mode) override;
	void initAnimations(ResourcePointer &res, uint16 len, bool dontUpdate) override;
	void linkAnimations(ResourcePointer &res, uint16 len) override;
	void clearAnimations(int mode = 0) override;
	void setPlaneMode(uint16 mode) override;

	void resetTextFields() override;
	void clearTextInputLine() override;
	uint8 *getTextRenderBuffer() const override;
	void renderTextBuffer(uint16 firstLine, uint8 numLines) override;

	void updateSaveLoadDialog(SaveInfo &saveInfo) override;
	void updateScreen(uint8 *screen) override;
	void updateAnimations() override;

	void setAnimParameter(uint8 animObjId, int param, int32 value) override;
	void setAnimGroupParameter(uint8 animObjId, int groupOp, int32 value = 0) override;
	int32 getAnimParameter(uint8 animObjId, int param) const override;
	uint8 getAnimScriptByte(uint8 animObjId, uint16 offset) const override;
	void animCopySpec(uint8 srcAnimObjId, uint8 dstAnimObjId) override;

	uint16 screenWidth() const override { return _width; }
	uint16 screenHeight() const override { return _height; }
	uint16 realScreenWidth() const override { return _width; }
	uint16 realScreenHeight() const override { return _height; }

	void createMouseCursor() override;
	int drawBootLogoFrame(uint8 *screen, int frameNo) override;

	// Framebuffer drawing helpers
	void blitRGB24(const uint8 *src, int w, int h, int dstX, int dstY);
	void blitBitmap16bpp(const uint16 *src, int w, int h, int dstX, int dstY);
	void blitBitmapCLUT8(const uint8 *src, int w, int h, int dstX, int dstY);
	void clearScreen(uint32 color = 0);
	uint8 *getFramebuffer() { return _framebuffer; }
	AnimObject *getAnimObject(uint8 id) { return (id < 64) ? _animations[id] : nullptr; }

protected:
	Common::Platform _platform;
	Graphics::PixelFormat _pixelFormat;
	Palette *_palette;

	uint16 _width;
	uint16 _height;
	uint8 *_framebuffer;
	uint8 *_textRenderBuffer;
	uint16 _planeMode;
	AnimObject *_animations[64];
};

// -----------------------------------------------------------------------------
// PLAYSTATION 1 ANIMATOR (Animator_PSX)
// Authentic PS1 1024x512 VRAM framebuffer & 15-bit direct BGR color
// -----------------------------------------------------------------------------
class Animator_PSX final : public Animator_PlatformBase {
public:
	Animator_PSX(const Graphics::PixelFormat *pxf, GraphicsEngine::GfxState &state,
	             Palette *pal, TransitionManager *scr, SoundEngine *snd);
	~Animator_PSX() override;

	void blitPS1BGR15(const uint16 *src, int w, int h, int dstX, int dstY);
	void loadPS1VRAM(const uint16 *src, int x, int y, int w, int h);
};

// -----------------------------------------------------------------------------
// SEGA SATURN ANIMATOR (Animator_Saturn)
// Authentic Sega Saturn VDP1/VDP2 16bpp RGB & TrueMotion frame blitting
// -----------------------------------------------------------------------------
class Animator_Saturn final : public Animator_PlatformBase {
public:
	Animator_Saturn(const Graphics::PixelFormat *pxf, GraphicsEngine::GfxState &state,
	                Palette *pal, TransitionManager *scr, SoundEngine *snd);
	~Animator_Saturn() override;

	void blitSaturnRGB16(const uint16 *src, int w, int h, int dstX, int dstY);
};

// -----------------------------------------------------------------------------
// PC ENGINE SUPER CD-ROM2 ANIMATOR (Animator_PCE)
// Authentic HuC6270 VDC planar 4bpp 8x8 tiles & HuC6260 VCE 16-color palettes
// -----------------------------------------------------------------------------
class Animator_PCE final : public Animator_PlatformBase {
public:
	Animator_PCE(const Graphics::PixelFormat *pxf, GraphicsEngine::GfxState &state,
	             Palette *pal, TransitionManager *scr, SoundEngine *snd);
	~Animator_PCE() override;

	void decodeAndBlitTiles4bpp(const uint8 *tileData, uint32 numTiles, const uint16 *palette16, int dstX, int dstY);
};

// -----------------------------------------------------------------------------
// MSX2 ANIMATOR (Animator_MSX2)
// Authentic Yamaha V9938 Screen 8 (256x212) GGGRRRBB direct color bitmap
// -----------------------------------------------------------------------------
class Animator_MSX2 final : public Animator_PlatformBase {
public:
	Animator_MSX2(const Graphics::PixelFormat *pxf, GraphicsEngine::GfxState &state,
	              Palette *pal, TransitionManager *scr, SoundEngine *snd);
	~Animator_MSX2() override;

	void blitScreen8Bitmap(const uint8 *screen8Data, int dstX = 32, int dstY = 6);
};

// -----------------------------------------------------------------------------
// PC-8801 ANIMATOR (Animator_PC88)
// Authentic NEC uPD7220 3-plane planar 8-color graphics
// -----------------------------------------------------------------------------
class Animator_PC88 final : public Animator_PlatformBase {
public:
	Animator_PC88(const Graphics::PixelFormat *pxf, GraphicsEngine::GfxState &state,
	              Palette *pal, TransitionManager *scr, SoundEngine *snd);
	~Animator_PC88() override;

	void blitPlanar8Color(const uint8 *bluePlane, const uint8 *redPlane, const uint8 *greenPlane, int w, int h, int dstX, int dstY);
};

} // End of namespace Snatcher

#endif // SNATCHER_ANIMATOR_PLATFORM_H
