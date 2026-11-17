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

#ifndef SNATCHER_SUBCODE_NATIVE_H
#define SNATCHER_SUBCODE_NATIVE_H

#include "common/scummsys.h"
#include "common/types.h"
#include "common/endian.h"
#include "snatcher/snatcher.h"

namespace Snatcher {

/**
 * Native C++ refactored implementation of the Sega CD SUBCODE executive.
 * Replaces the raw 68000 assembly routines with high-level C++ state logic:
 * - Word-RAM banking & Gate Array synchronization ($A12000-$A1202F)
 * - Main-CPU / Sub-CPU command mailboxes (0xFF8020-0xFF803F)
 * - Disc seek and CD-DA Redbook audio command dispatch
 * - Ricoh RF5C164 PCM audio ring buffer coordination
 * - Subcode font glyph streaming and text window render state
 */
class SubcodeExecutive {
public:
	enum SubcodeCommand {
		kCmdNone           = 0x00,
		kCmdInitSystem     = 0x01,
		kCmdLoadScene      = 0x02,
		kCmdPlayCdTrack    = 0x03,
		kCmdStopCdTrack    = 0x04,
		kCmdTransferPcm    = 0x05,
		kCmdSwapWordRam    = 0x06,
		kCmdFadeAudio      = 0x07,
		kCmdRenderGlyph    = 0x08
	};

	struct MailboxState {
		uint8 mainStatus;
		uint8 subStatus;
		uint16 command;
		uint16 param1;
		uint16 param2;
		uint32 dataPointer;
	};

public:
	SubcodeExecutive(SnatcherEngine *vm);
	~SubcodeExecutive();

	void reset();
	void processFrame();

	// Native implementations of disassembled 68K subroutines
	void execInitSystem();
	void execWordRamSwap();
	void execCdTrackPlay(uint8 track, bool loop);
	void execCdTrackStop();
	void execPcmStreamTransfer(const uint8 *src, uint32 size);
	void execGlyphRender(uint16 charCode, int x, int y, uint8 color);

	// Status queries
	bool isBusy() const { return _busy; }
	uint8 getSubCpuStatus() const { return _mailbox.subStatus; }

private:
	SnatcherEngine *_vm;
	MailboxState _mailbox;
	bool _busy;
	uint8 _wordRamBank; // 0: 2M mode owned by Main CPU, 1: 1M/1M banked
	uint32 _frameCounter;
};

} // End of namespace Snatcher

#endif // SNATCHER_SUBCODE_NATIVE_H
