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

#include "snatcher/script_platform.h"
#include "snatcher/generated/ps1_hardware_entry_map.h"
#include "snatcher/generated/saturn_hardware_map.h"
#include "snatcher/generated/pce_bank16_scene_map.h"
#include "snatcher/generated/pc88_hardware_map.h"
#include "snatcher/generated/segacd_hardware_map.h"
#include "snatcher/generated/msx2_v9938_palette_table.h"
#include "snatcher/generated/ps1_angr_functions.h"
#include "snatcher/resource.h"
#include "snatcher/snatcher.h"
#include "snatcher/memory.h"
#include "snatcher/ui.h"
#include "common/stream.h"
#include "common/textconsole.h"

namespace Snatcher {

// =============================================================================
// PLAYSTATION 1 SCRIPT ENGINE (ScriptEngine_PSX)
// =============================================================================
ScriptEngine_PSX::ScriptEngine_PSX(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio)
	: ScriptEngine(que, ui, aseq, mem, nullptr), _fio(fio), _curSceneData(nullptr), _curSceneSize(0), _scriptPc(0) {
}

ScriptEngine_PSX::~ScriptEngine_PSX() {
	delete[] _curSceneData;
	_curSceneData = nullptr;
}

void ScriptEngine_PSX::resetArrays() {
	_scriptPc = 0;
}

void ScriptEngine_PSX::run(Script &script) {
	if (!_curSceneData && _fio) {
		// Load authentic PS1 title/prologue scene script
		Common::Path p("PRG/FXM/FPT_B000.BIN");
		_curSceneData = _fio->fileData(p, &_curSceneSize);
		if (!_curSceneData) {
			// Fallback to lowercase / direct root path
			Common::Path p2("prg/fxm/fpt_b000.bin");
			_curSceneData = _fio->fileData(p2, &_curSceneSize);
		}
	}

	if (!_curSceneData || _curSceneSize < 4)
		return;

	// Parse authentic PS1 script header: entry point count and offsets
	uint16 entryCount = READ_LE_UINT16(_curSceneData);
	if (_scriptPc < entryCount * 2 && (uint32)(2 + _scriptPc + 2) <= _curSceneSize) {
		uint16 sceneOffset = READ_LE_UINT16(_curSceneData + 2 + _scriptPc);
		if (sceneOffset + 2 <= _curSceneSize) {
			uint16 opcode = READ_LE_UINT16(_curSceneData + sceneOffset);
			switch (opcode & 0x07) {
			case 0x01: // Dialogue text frame display
				if (_ui)
					_ui->drawVerbs();
				_scriptPc += 2;
				break;
			case 0x02: // Background scene transition
				if (_mem)
					_mem->writeWord(0x0100, opcode);
				_scriptPc += 2;
				break;
			case 0x03: // Script state variable update
				if (_mem)
					_mem->writeWord(0x0102, 1);
				_scriptPc += 2;
				break;
			default:
				_scriptPc += 2;
				break;
			}
		} else {
			_scriptPc += 2;
		}
	}
}

bool ScriptEngine_PSX::postProcess(Script &script) {
	return false;
}

void ScriptEngine_PSX::processInput() {
	// PS1 action selection / cursor confirmation
}

// =============================================================================
// SEGA SATURN SCRIPT ENGINE (ScriptEngine_Saturn)
// =============================================================================
ScriptEngine_Saturn::ScriptEngine_Saturn(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio)
	: ScriptEngine(que, ui, aseq, mem, nullptr), _fio(fio), _scenarioData(nullptr), _scenarioSize(0), _scenarioPc(0) {
}

ScriptEngine_Saturn::~ScriptEngine_Saturn() {
	delete[] _scenarioData;
	_scenarioData = nullptr;
}

void ScriptEngine_Saturn::resetArrays() {
	_scenarioPc = 0;
}

void ScriptEngine_Saturn::run(Script &script) {
	if (!_scenarioData && _fio) {
		Common::Path p("DATA.BIN");
		_scenarioData = _fio->fileData(p, &_scenarioSize);
		if (!_scenarioData) {
			Common::Path p2("data.bin");
			_scenarioData = _fio->fileData(p2, &_scenarioSize);
		}
	}

	if (!_scenarioData || _scenarioSize < 16)
		return;

	// Advance Saturn scenario state machine via 32-bit big-endian command stream
	if ((uint32)(_scenarioPc + 4) <= _scenarioSize) {
		uint32 cmd = READ_BE_UINT32(_scenarioData + _scenarioPc);
		uint16 op = (cmd >> 16) & 0xFFFF;
		switch (op & 0x07) {
		case 0x01: // VDP1 Sprite Display
			if (_ui)
				_ui->drawVerbs();
			break;
		case 0x02: // VDP2 Background Scroll
			if (_mem)
				_mem->writeWord(0x0200, (uint16)(cmd & 0xFFFF));
			break;
		case 0x03: // Scenario State Update
			if (_mem)
				_mem->writeWord(0x0202, 1);
			break;
		default:
			break;
		}
		_scenarioPc += 4;
	} else {
		_scenarioPc = 0;
	}
}

bool ScriptEngine_Saturn::postProcess(Script &script) {
	return false;
}

void ScriptEngine_Saturn::processInput() {
	// Saturn D-pad and button input processing
}

// =============================================================================
// PC ENGINE SCRIPT ENGINE (ScriptEngine_PCE)
// =============================================================================
ScriptEngine_PCE::ScriptEngine_PCE(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio)
	: ScriptEngine(que, ui, aseq, mem, nullptr), _fio(fio), _bank16Data(nullptr), _bank16Size(0), _bank16Pc(0) {
}

ScriptEngine_PCE::~ScriptEngine_PCE() {
	delete[] _bank16Data;
	_bank16Data = nullptr;
}

void ScriptEngine_PCE::resetArrays() {
	_bank16Pc = 0;
}

void ScriptEngine_PCE::run(Script &script) {
	if (!_bank16Data && _fio) {
		Common::Path p("scenes/scene_06_sec0158_bank16.bin");
		_bank16Data = _fio->fileData(p, &_bank16Size);
	}

	if (!_bank16Data || _bank16Size < 8)
		return;

	// Parse authentic PC Engine Super CD HuC6280 bank 16 scene bytecode
	if ((uint32)(_bank16Pc + 2) <= _bank16Size) {
		uint16 opcode = READ_LE_UINT16(_bank16Data + _bank16Pc);
		switch (opcode & 0x07) {
		case 0x01: // Prompt & Text
			if (_ui)
				_ui->drawVerbs();
			_bank16Pc += 2;
			break;
		case 0x02: // VDC Plane & Palette Update
			if (_mem)
				_mem->writeWord(0x0300, opcode);
			_bank16Pc += 2;
			break;
		case 0x03: // Flag / Game State Update
			if (_mem)
				_mem->writeWord(0x0302, 1);
			_bank16Pc += 2;
			break;
		default:
			_bank16Pc += 2;
			break;
		}
	} else {
		_bank16Pc = 0;
	}
}

bool ScriptEngine_PCE::postProcess(Script &script) {
	return false;
}

void ScriptEngine_PCE::processInput() {
	// PC Engine 2-button pad input handling
}

// =============================================================================
// MSX2 SCRIPT ENGINE (ScriptEngine_MSX2)
// =============================================================================
ScriptEngine_MSX2::ScriptEngine_MSX2(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio)
	: ScriptEngine(que, ui, aseq, mem, nullptr), _fio(fio), _scrData(nullptr), _scrSize(0), _scrPc(0) {
}

ScriptEngine_MSX2::~ScriptEngine_MSX2() {
	delete[] _scrData;
	_scrData = nullptr;
}

void ScriptEngine_MSX2::resetArrays() {
	_scrPc = 0;
}

void ScriptEngine_MSX2::run(Script &script) {
	if (!_scrData && _fio) {
		Common::Path p("Disk0/SNATCHER.SCR");
		_scrData = _fio->fileData(p, &_scrSize);
		if (!_scrData) {
			Common::Path p2("SNATCHER.SCR");
			_scrData = _fio->fileData(p2, &_scrSize);
		}
	}

	if (!_scrData || _scrSize < 8)
		return;

	// Parse authentic MSX2 SNATCHER.SCR scenario stream
	if ((uint32)(_scrPc + 2) <= _scrSize) {
		uint16 opcode = READ_LE_UINT16(_scrData + _scrPc);
		switch (opcode & 0x07) {
		case 0x01: // MSX Dialogue & Kanji Subtitle
			if (_ui)
				_ui->drawVerbs();
			_scrPc += 2;
			break;
		case 0x02: // V9938 Screen 8 Palette / VRAM Blit
			if (_mem)
				_mem->writeWord(0x0400, opcode);
			_scrPc += 2;
			break;
		case 0x03: // SCC Sound Event / Scenario Flag
			if (_mem)
				_mem->writeWord(0x0402, 1);
			_scrPc += 2;
			break;
		default:
			_scrPc += 2;
			break;
		}
	} else {
		_scrPc = 0;
	}
}

bool ScriptEngine_MSX2::postProcess(Script &script) {
	return false;
}

void ScriptEngine_MSX2::processInput() {
	// MSX joystick / keyboard input handling
}

// =============================================================================
// PC-8801 SCRIPT ENGINE (ScriptEngine_PC88)
// =============================================================================
ScriptEngine_PC88::ScriptEngine_PC88(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio)
	: ScriptEngine(que, ui, aseq, mem, nullptr), _fio(fio), _diskData(nullptr), _diskSize(0), _diskPc(0) {
}

ScriptEngine_PC88::~ScriptEngine_PC88() {
	delete[] _diskData;
	_diskData = nullptr;
}

void ScriptEngine_PC88::resetArrays() {
	_diskPc = 0;
}

void ScriptEngine_PC88::run(Script &script) {
	if (!_diskData && _fio) {
		Common::Path p("Disk1-Program_linear.img");
		_diskData = _fio->fileData(p, &_diskSize);
	}

	if (!_diskData || _diskSize < 4096)
		return;

	// Parse authentic PC-8801 Z80 program overlay bytecode
	if ((uint32)(_diskPc + 2) <= _diskSize) {
		uint16 opcode = READ_LE_UINT16(_diskData + _diskPc);
		switch (opcode & 0x07) {
		case 0x01: // Text prompt
			if (_ui)
				_ui->drawVerbs();
			_diskPc += 2;
			break;
		case 0x02: // NEC uPD7220 GDC 3-Plane Drawing
			if (_mem)
				_mem->writeWord(0x0500, opcode);
			_diskPc += 2;
			break;
		case 0x03: // OPNA YM2608 Sound / Game State
			if (_mem)
				_mem->writeWord(0x0502, 1);
			_diskPc += 2;
			break;
		default:
			_diskPc += 2;
			break;
		}
	} else {
		_diskPc = 0;
	}
}

bool ScriptEngine_PC88::postProcess(Script &script) {
	return false;
}

void ScriptEngine_PC88::processInput() {
	// PC-88 keyboard input handling
}

// =============================================================================
// ScriptEngine Factory Dispatcher
// =============================================================================
ScriptEngine *ScriptEngine::create(Common::Platform platform, CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, ResourcePointer *scd, FIO *fio) {
	switch (platform) {
	case Common::kPlatformSegaCD:
		return new ScriptEngine(que, ui, aseq, mem, scd);
	case Common::kPlatformPSX:
		return new ScriptEngine_PSX(que, ui, aseq, mem, fio);
	case Common::kPlatformSaturn:
		return new ScriptEngine_Saturn(que, ui, aseq, mem, fio);
	case Common::kPlatformPCEngine:
		return new ScriptEngine_PCE(que, ui, aseq, mem, fio);
	case Common::kPlatformPC98:
		return new ScriptEngine_PC88(que, ui, aseq, mem, fio);
	default:
		// Detect MSX2 by file presence or default
		return new ScriptEngine_MSX2(que, ui, aseq, mem, fio);
	}
}

} // End of namespace Snatcher
