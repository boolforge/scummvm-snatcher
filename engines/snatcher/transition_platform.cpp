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

#include "snatcher/transition_platform.h"
#include "snatcher/graphics.h"
#include "common/stream.h"

namespace Snatcher {

// =============================================================================
// TransitionManager_PlatformBase Implementation
// =============================================================================
TransitionManager_PlatformBase::TransitionManager_PlatformBase(GraphicsEngine::GfxState &state)
	: TransitionManager(), _active(false) {
	(void)state;
	clear();
}

TransitionManager_PlatformBase::~TransitionManager_PlatformBase() {
}

void TransitionManager_PlatformBase::doCommand(int cmd) {
	(void)cmd;
}

void TransitionManager_PlatformBase::scroll_setSingleStep(int mode, int16 step) {
	if (mode >= 0 && mode < 4) {
		_result.realOffsets[mode] += step;
		_result.unmodifiedOffsets[mode] += step;
	}
}

void TransitionManager_PlatformBase::scroll_setDirectionAndSpeed(int mode, int16 incr) {
	if (mode >= 0 && mode < 4) {
		_speed[mode] = incr;
		if (incr != 0) {
			_active = true;
			_result.busy = true;
		}
	}
}

void TransitionManager_PlatformBase::clear() {
	for (int i = 0; i < 4; ++i) {
		_result.realOffsets[i] = 0;
		_result.unmodifiedOffsets[i] = 0;
		_speed[i] = 0;
	}
	_result.hScrollTable = nullptr;
	_result.hScrollTableNumEntries = 0;
	_result.disableVScroll = false;
	_result.lineScrollMode = false;
	_result.verbsTabVisible = false;
	_result.busy = false;
	_active = false;
}

bool TransitionManager_PlatformBase::nextFrame() {
	if (!_active)
		return false;

	bool stillMoving = false;
	for (int i = 0; i < 4; ++i) {
		if (_speed[i] != 0) {
			_result.realOffsets[i] += _speed[i];
			_result.unmodifiedOffsets[i] += _speed[i];
			stillMoving = true;
		}
	}

	_active = stillMoving;
	_result.busy = stillMoving;
	return stillMoving;
}

void TransitionManager_PlatformBase::saveState(Common::SeekableWriteStream *out, SaveFlags flags) {
	(void)out;
	(void)flags;
}

void TransitionManager_PlatformBase::loadState(Common::SeekableReadStream *in, SaveFlags flags) {
	(void)in;
	(void)flags;
}

void TransitionManager_PlatformBase::postLoadProcess() {
}

// =============================================================================
// Platform Specialized Transition Managers
// =============================================================================
TransitionManager_PSX::TransitionManager_PSX(GraphicsEngine::GfxState &state)
	: TransitionManager_PlatformBase(state) {
}

TransitionManager_PSX::~TransitionManager_PSX() {
}

TransitionManager_Saturn::TransitionManager_Saturn(GraphicsEngine::GfxState &state)
	: TransitionManager_PlatformBase(state) {
}

TransitionManager_Saturn::~TransitionManager_Saturn() {
}

TransitionManager_PCE::TransitionManager_PCE(GraphicsEngine::GfxState &state)
	: TransitionManager_PlatformBase(state) {
}

TransitionManager_PCE::~TransitionManager_PCE() {
}

TransitionManager_MSX2::TransitionManager_MSX2(GraphicsEngine::GfxState &state)
	: TransitionManager_PlatformBase(state) {
}

TransitionManager_MSX2::~TransitionManager_MSX2() {
}

TransitionManager_PC88::TransitionManager_PC88(GraphicsEngine::GfxState &state)
	: TransitionManager_PlatformBase(state) {
}

TransitionManager_PC88::~TransitionManager_PC88() {
}

// =============================================================================
// TransitionManager Factory Dispatcher
// =============================================================================
TransitionManager *TransitionManager::create(Common::Platform platform, GraphicsEngine::GfxState &state) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSegaTransitionManager(state);
	case Common::kPlatformPSX:
		return new TransitionManager_PSX(state);
	case Common::kPlatformSaturn:
		return new TransitionManager_Saturn(state);
	case Common::kPlatformPCEngine:
		return new TransitionManager_PCE(state);
	case Common::kPlatformPC98:
		return new TransitionManager_PC88(state);
	default:
		return new TransitionManager_MSX2(state);
	}
}

} // End of namespace Snatcher
