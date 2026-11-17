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

#ifndef SNATCHER_TRANSITION_LINEAR_H
#define SNATCHER_TRANSITION_LINEAR_H

#include "snatcher/transition.h"

namespace Snatcher {

class LinearTransitionManager : public TransitionManager {
public:
	LinearTransitionManager(GraphicsEngine::GfxState &state);
	~LinearTransitionManager() override;

	void doCommand(int cmd) override;
	void scroll_setSingleStep(int mode, int16 step) override;
	void scroll_setDirectionAndSpeed(int mode, int16 incr) override;
	void clear() override;
	bool nextFrame() override;

	void saveState(Common::SeekableWriteStream *out, SaveFlags flags) override;
	void loadState(Common::SeekableReadStream *in, SaveFlags flags) override;
	void postLoadProcess() override;

private:
	int16 _speed[4];
	bool _active;
};

TransitionManager *createLinearTransitionManager(GraphicsEngine::GfxState &state);

} // End of namespace Snatcher

#endif // SNATCHER_TRANSITION_LINEAR_H
