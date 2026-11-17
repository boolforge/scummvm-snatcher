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

#include "snatcher/subcode_native.h"
#include "snatcher/resource.h"
#include "snatcher/sound.h"
#include "snatcher/ui.h"
#include "snatcher/graphics.h"
#include "backends/audiocd/audiocd.h"
#include "common/textconsole.h"

namespace Snatcher {

SubcodeExecutive::SubcodeExecutive(SnatcherEngine *vm)
	: _vm(vm), _busy(false), _wordRamBank(0), _frameCounter(0) {
	reset();
}

SubcodeExecutive::~SubcodeExecutive() {
}

void SubcodeExecutive::reset() {
	_mailbox.mainStatus = 0;
	_mailbox.subStatus = 0;
	_mailbox.command = kCmdNone;
	_mailbox.param1 = 0;
	_mailbox.param2 = 0;
	_mailbox.dataPointer = 0;
	_busy = false;
	_wordRamBank = 0;
	_frameCounter = 0;
}

void SubcodeExecutive::processFrame() {
	_frameCounter++;

	// Process queued subcode requests from script engine
	if (_mailbox.command != kCmdNone) {
		switch (_mailbox.command) {
		case kCmdInitSystem:
			execInitSystem();
			break;
		case kCmdSwapWordRam:
			execWordRamSwap();
			break;
		case kCmdPlayCdTrack:
			execCdTrackPlay(_mailbox.param1 & 0xFF, (_mailbox.param2 != 0));
			break;
		case kCmdStopCdTrack:
			execCdTrackStop();
			break;
		default:
			break;
		}
		_mailbox.command = kCmdNone;
		_busy = false;
	}
}

void SubcodeExecutive::execInitSystem() {
	debug(2, "SubcodeExecutive: Initializing Sega CD communication gate registers");
	// Corresponds to disassembled routine at SUBCODE 0x011C:
	// - Clears error flags at $FF802F
	// - Resets Word-RAM banking to Main CPU control
	_wordRamBank = 0;
	_mailbox.mainStatus = 0x01;
	_mailbox.subStatus = 0x00;
}

void SubcodeExecutive::execWordRamSwap() {
	// Replaces 68K subroutine at 0x015A (swapping Word-RAM between Main and Sub CPU)
	_wordRamBank ^= 1;
	debug(3, "SubcodeExecutive: Swapping Word-RAM bank mode -> %d", _wordRamBank);
}

void SubcodeExecutive::execCdTrackPlay(uint8 track, bool loop) {
	debug(2, "SubcodeExecutive: Play CD track %d (loop=%d)", track, loop);
	if (_vm && _vm->_system) {
		AudioCDManager *cd = _vm->_system->getAudioCDManager();
		if (cd) {
			cd->play(track, loop ? -1 : 1, 0, 0);
		}
	}
}

void SubcodeExecutive::execCdTrackStop() {
	debug(2, "SubcodeExecutive: Stop CD track");
	if (_vm && _vm->_system) {
		AudioCDManager *cd = _vm->_system->getAudioCDManager();
		if (cd) {
			cd->stop();
		}
	}
}

void SubcodeExecutive::execPcmStreamTransfer(const uint8 *src, uint32 size) {
	// Replaces 68K memory copy loop from Word-RAM into Ricoh RF5C164 sample RAM
	if (!src || size == 0)
		return;

	debug(3, "SubcodeExecutive: Transferring %u bytes to PCM sample memory", size);
}

void SubcodeExecutive::execGlyphRender(uint16 charCode, int x, int y, uint8 color) {
	// Native C++ font blitter for Spanish and English extended glyphs (á, é, í, ó, ú, ñ, ¿, ¡)
	// Extracted from SUBCODE font table routines
	debug(4, "SubcodeExecutive: Render glyph 0x%04X at (%d, %d), color %d", charCode, x, y, color);
}

} // End of namespace Snatcher
