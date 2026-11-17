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

#ifndef SNATCHER_ANIMATOR_LINEAR_H
#define SNATCHER_ANIMATOR_LINEAR_H

#include "snatcher/animator.h"
#include "graphics/pixelformat.h"

namespace Snatcher {

class Palette;
class TransitionManager;
class SoundEngine;

class LinearAnimator : public Animator {
public:
	LinearAnimator(const Graphics::PixelFormat *pxf, Common::Platform platform,
	               GraphicsEngine::GfxState &state, Palette *pal,
	               TransitionManager *scr, SoundEngine *snd,
	               bool enableAspectRatioCorrection);
	~LinearAnimator() override;

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

	uint16 screenWidth() const override;
	uint16 screenHeight() const override;
	uint16 realScreenWidth() const override;
	uint16 realScreenHeight() const override;

	void createMouseCursor() override;
	int drawBootLogoFrame(uint8 *screen, int frameNo) override;

private:
	Common::Platform _platform;
	Graphics::PixelFormat _pixelFormat;
	Palette *_palette;

	uint16 _width;
	uint16 _height;
	uint8 *_framebuffer;
	uint8 *_textRenderBuffer;
};

Animator *createLinearAnimator(const Graphics::PixelFormat *pxf, Common::Platform platform,
                               GraphicsEngine::GfxState &state, Palette *pal,
                               TransitionManager *scr, SoundEngine *snd,
                               bool enableAspectRatioCorrection);

} // End of namespace Snatcher

#endif // SNATCHER_ANIMATOR_LINEAR_H
