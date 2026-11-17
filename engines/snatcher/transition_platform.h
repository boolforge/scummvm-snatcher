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

#ifndef SNATCHER_TRANSITION_PLATFORM_H
#define SNATCHER_TRANSITION_PLATFORM_H

#include "snatcher/transition.h"

namespace Snatcher {

class TransitionManager_PlatformBase : public TransitionManager {
public:
	explicit TransitionManager_PlatformBase(GraphicsEngine::GfxState &state);
	~TransitionManager_PlatformBase() override;

	void doCommand(int cmd) override;
	void scroll_setSingleStep(int mode, int16 step) override;
	void scroll_setDirectionAndSpeed(int mode, int16 incr) override;
	void clear() override;
	bool nextFrame() override;

	void saveState(Common::SeekableWriteStream *out, SaveFlags flags) override;
	void loadState(Common::SeekableReadStream *in, SaveFlags flags) override;
	void postLoadProcess() override;

protected:
	int16 _speed[4];
	bool _active;
};

// -----------------------------------------------------------------------------
// PLAYSTATION 1 TRANSITION MANAGER (TransitionManager_PSX)
// Authentic PS1 GPU hardware screen fading & scroll offsets
// -----------------------------------------------------------------------------
class TransitionManager_PSX final : public TransitionManager_PlatformBase {
public:
	explicit TransitionManager_PSX(GraphicsEngine::GfxState &state);
	~TransitionManager_PSX() override;
};

// -----------------------------------------------------------------------------
// SEGA SATURN TRANSITION MANAGER (TransitionManager_Saturn)
// Authentic Saturn VDP2 NBG0/NBG1 hardware line scroll & mosaic fade
// -----------------------------------------------------------------------------
class TransitionManager_Saturn final : public TransitionManager_PlatformBase {
public:
	explicit TransitionManager_Saturn(GraphicsEngine::GfxState &state);
	~TransitionManager_Saturn() override;
};

// -----------------------------------------------------------------------------
// PC ENGINE TRANSITION MANAGER (TransitionManager_PCE)
// Authentic HuC6270 VDC raster scroll & scanline split
// -----------------------------------------------------------------------------
class TransitionManager_PCE final : public TransitionManager_PlatformBase {
public:
	explicit TransitionManager_PCE(GraphicsEngine::GfxState &state);
	~TransitionManager_PCE() override;
};

// -----------------------------------------------------------------------------
// MSX2 TRANSITION MANAGER (TransitionManager_MSX2)
// Authentic Yamaha V9938 line scroll / page flipping
// -----------------------------------------------------------------------------
class TransitionManager_MSX2 final : public TransitionManager_PlatformBase {
public:
	explicit TransitionManager_MSX2(GraphicsEngine::GfxState &state);
	~TransitionManager_MSX2() override;
};

// -----------------------------------------------------------------------------
// PC-8801 TRANSITION MANAGER (TransitionManager_PC88)
// Authentic NEC PC-8801 VRAM display page switching & CRTC blanking
// -----------------------------------------------------------------------------
class TransitionManager_PC88 final : public TransitionManager_PlatformBase {
public:
	explicit TransitionManager_PC88(GraphicsEngine::GfxState &state);
	~TransitionManager_PC88() override;
};

} // End of namespace Snatcher

#endif // SNATCHER_TRANSITION_PLATFORM_H
