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

#ifndef SNATCHER_SCRIPT_PLATFORM_H
#define SNATCHER_SCRIPT_PLATFORM_H

#include "snatcher/script.h"
#include "snatcher/resource.h"
#include "common/platform.h"

namespace Snatcher {

class FIO;
class MemAccessHandler;

// -----------------------------------------------------------------------------
// PLAYSTATION 1 SCRIPT ENGINE (ScriptEngine_PSX)
// Native MIPS bytecode & scene event table interpreter (PRG/FXM/)
// -----------------------------------------------------------------------------
class ScriptEngine_PSX final : public ScriptEngine {
public:
	ScriptEngine_PSX(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio);
	~ScriptEngine_PSX() override;

	void resetArrays() override;
	void run(Script &script) override;
	bool postProcess(Script &script) override;
	void processInput() override;

private:
	FIO *_fio;
	uint8 *_curSceneData;
	uint32 _curSceneSize;
	int _scriptPc;
};

// -----------------------------------------------------------------------------
// SEGA SATURN SCRIPT ENGINE (ScriptEngine_Saturn)
// Native Hitachi SH-2 scenario chunk interpreter (MAIN_L.BIN / DATA.BIN)
// -----------------------------------------------------------------------------
class ScriptEngine_Saturn final : public ScriptEngine {
public:
	ScriptEngine_Saturn(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio);
	~ScriptEngine_Saturn() override;

	void resetArrays() override;
	void run(Script &script) override;
	bool postProcess(Script &script) override;
	void processInput() override;

private:
	FIO *_fio;
	uint8 *_scenarioData;
	uint32 _scenarioSize;
	int _scenarioPc;
};

// -----------------------------------------------------------------------------
// PC ENGINE SCRIPT ENGINE (ScriptEngine_PCE)
// Native HuC6280 bank 16 overlay bytecode interpreter (scenes/scene_*.bin)
// -----------------------------------------------------------------------------
class ScriptEngine_PCE final : public ScriptEngine {
public:
	ScriptEngine_PCE(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio);
	~ScriptEngine_PCE() override;

	void resetArrays() override;
	void run(Script &script) override;
	bool postProcess(Script &script) override;
	void processInput() override;

private:
	FIO *_fio;
	uint8 *_bank16Data;
	uint32 _bank16Size;
	int _bank16Pc;
};

// -----------------------------------------------------------------------------
// MSX2 SCRIPT ENGINE (ScriptEngine_MSX2)
// Native Z80 scenario & Screen 8 event interpreter (SNATCHER.SCR)
// -----------------------------------------------------------------------------
class ScriptEngine_MSX2 final : public ScriptEngine {
public:
	ScriptEngine_MSX2(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio);
	~ScriptEngine_MSX2() override;

	void resetArrays() override;
	void run(Script &script) override;
	bool postProcess(Script &script) override;
	void processInput() override;

private:
	FIO *_fio;
	uint8 *_scrData;
	uint32 _scrSize;
	int _scrPc;
};

// -----------------------------------------------------------------------------
// PC-8801 SCRIPT ENGINE (ScriptEngine_PC88)
// Native Z80 floppy sector scenario interpreter (Disk1-Program_linear.img)
// -----------------------------------------------------------------------------
class ScriptEngine_PC88 final : public ScriptEngine {
public:
	ScriptEngine_PC88(CmdQueue *que, UI *ui, ActionSequenceHandler *aseq, MemAccessHandler *mem, FIO *fio);
	~ScriptEngine_PC88() override;

	void resetArrays() override;
	void run(Script &script) override;
	bool postProcess(Script &script) override;
	void processInput() override;

private:
	FIO *_fio;
	uint8 *_diskData;
	uint32 _diskSize;
	int _diskPc;
};

} // End of namespace Snatcher

#endif // SNATCHER_SCRIPT_PLATFORM_H
