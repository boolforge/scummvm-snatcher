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

#ifndef SNATCHER_BOOT_LOGO_H
#define SNATCHER_BOOT_LOGO_H

#include "common/platform.h"
#include "graphics/pixelformat.h"
#include "common/scummsys.h"

class OSystem;

namespace Snatcher {

// A BootLogo renders the pre-game splash of one specific port into a linear
// framebuffer. It knows nothing about the Sega VDP, so it can be extended per
// platform (e.g. by a video-backed implementation for the STR/AVI intros).
class BootLogo {
public:
	virtual ~BootLogo() {}

	// Renders one frame into 'screen' (width * height * bytesPerPixel bytes).
	// Returns the next frame number, or -1 when the sequence has ended.
	virtual int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) = 0;

	// Returns nullptr for platforms whose boot logo is handled by their animator
	// (Sega CD runs its native VDP sequence).
	static BootLogo *create(Common::Platform platform);
};

} // End of namespace Snatcher

#endif // SNATCHER_BOOT_LOGO_H
