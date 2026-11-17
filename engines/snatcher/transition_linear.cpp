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

#include "snatcher/transition_linear.h"
#include "snatcher/graphics.h"
#include "common/stream.h"

namespace Snatcher {

LinearTransitionManager::LinearTransitionManager(GraphicsEngine::GfxState &state)
	: TransitionManager(), _active(false) {
	(void)state;
	clear();
}

LinearTransitionManager::~LinearTransitionManager() {
}

void LinearTransitionManager::doCommand(int cmd) {
	(void)cmd;
}

void LinearTransitionManager::scroll_setSingleStep(int mode, int16 step) {
	if (mode >= 0 && mode < 4) {
		_result.realOffsets[mode] += step;
		_result.unmodifiedOffsets[mode] += step;
	}
}

void LinearTransitionManager::scroll_setDirectionAndSpeed(int mode, int16 incr) {
	if (mode >= 0 && mode < 4) {
		_speed[mode] = incr;
		if (incr != 0) {
			_active = true;
			_result.busy = true;
		}
	}
}

void LinearTransitionManager::clear() {
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

bool LinearTransitionManager::nextFrame() {
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

void LinearTransitionManager::saveState(Common::SeekableWriteStream *out, SaveFlags flags) {
	(void)out;
	(void)flags;
}

void LinearTransitionManager::loadState(Common::SeekableReadStream *in, SaveFlags flags) {
	(void)in;
	(void)flags;
}

void LinearTransitionManager::postLoadProcess() {
}

TransitionManager *createLinearTransitionManager(GraphicsEngine::GfxState &state) {
	return new LinearTransitionManager(state);
}

TransitionManager *TransitionManager::create(Common::Platform platform, GraphicsEngine::GfxState &state) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return createSegaTransitionManager(state);
	case Common::kPlatformPSX:
	case Common::kPlatformSaturn:
	case Common::kPlatformPCEngine:
	default:
		return createLinearTransitionManager(state);
	}
}

} // End of namespace Snatcher
