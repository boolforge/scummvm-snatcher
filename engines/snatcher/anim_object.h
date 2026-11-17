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

#ifndef SNATCHER_ANIM_OBJECT_H
#define SNATCHER_ANIM_OBJECT_H

#include "common/scummsys.h"
#include "snatcher/resource.h"

namespace Snatcher {

struct AnimObject {
	AnimObject(int num = 0) : id(num) {}

	void clear() {
		enable = blinkRate = drawFlags = 0;
		posX = posY = 0;
		relSpeedX = relSpeedY = 0;
		palette = 0;
		target = ovrTile = 0;
		f1c = 0;
		timeStamp = 0;
		phase = 0;
		controlFlags = allowFrameDrop = frameSeqCounter = 0;
		frame = 0;
		frameDelay = 0;
		actionTimer = 0;
		spriteTableLocation = 0;
		res = ResourcePointer();
		scriptData = ResourcePointer();
		spriteData = nullptr;
		absSpeedX = absSpeedY = 0;
		parent = children = next = 0;
		scriptComFlags = freeze = 0;
		blink = blinkCounter = blinkDuration = 0;
	}

	uint16 enable = 0;
	uint16 blinkRate = 0;
	uint16 drawFlags = 0;
	int32 posX = 0;
	int32 posY = 0;
	int32 relSpeedX = 0;
	int32 relSpeedY = 0;
	uint8 palette = 0;
	uint16 target = 0;
	uint16 ovrTile = 0;
	uint8 f1c = 0;
	uint32 timeStamp = 0;
	uint8 phase = 0;
	uint8 controlFlags = 0;
	uint8 allowFrameDrop = 0;
	uint8 frameSeqCounter = 0;
	uint16 frame = 0;
	int16 frameDelay = 0;
	int16 actionTimer = 0;
	uint32 spriteTableLocation = 0;
	ResourcePointer res;
	ResourcePointer scriptData;
	const uint16 *spriteData = nullptr;
	uint16 blink = 0;
	uint16 blinkCounter = 0;
	uint16 blinkDuration = 0;
	int32 absSpeedX = 0;
	int32 absSpeedY = 0;
	uint16 parent = 0;
	uint16 children = 0;
	uint16 next = 0;
	uint8 scriptComFlags = 0;
	uint8 freeze = 0;

	const uint8 id = 0;
};

} // End of namespace Snatcher

#endif // SNATCHER_ANIM_OBJECT_H
