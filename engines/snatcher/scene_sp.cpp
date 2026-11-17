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

#include "snatcher/action.h"
#include "snatcher/graphics.h"
#include "snatcher/mem_mapping.h"
#include "snatcher/scene_sp.h"
#include "snatcher/script.h"
#include "snatcher/snatcher.h"
#include "snatcher/sound.h"
#include "snatcher/ui.h"
#include "common/textconsole.h"

namespace Snatcher {

Scene_SP::Scene_SP(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int sceneNumber)
	: SceneHandler(vm, scn, fio), _sceneNumber(sceneNumber), _initialized(false), _tickCounter(0) {
}

Scene_SP::~Scene_SP() {
}

void Scene_SP::operator()(GameState &state) {
	if (!_initialized) {
		_initialized = true;
		_tickCounter = 0;
		debug(1, "Scene_SP: Initializing gameplay scene SP%02d", _sceneNumber);
		_vm->gfx()->reset(GraphicsEngine::kResetSetDefaultsExt);
		ResourcePointer gfxData = _module->getGfxData();
		if (gfxData()) {
			_vm->gfx()->runScript(gfxData, 0);
		}
	}

	stepScript(state);
	updateActors(state);
	checkTriggers(state);
	++_tickCounter;
}

void Scene_SP::stepScript(GameState &state) {
	// If script execution is requested or command queue has finished
	if (_vm->_cmdQueue && !_vm->_cmdQueue->enabled()) {
		if (state.updateFlags & 0x40) {
			if (_vm->_scriptEngine->postProcess(state.script)) {
				for (int i = 5; i < 15; ++i)
					_vm->_gfx->setAnimParameter(i, GraphicsEngine::kAnimParaEnable, 0);
				_vm->_cmdQueue->writeUInt16(0x22);
				_vm->_cmdQueue->writeUInt32(MemMapping::MEM_PALDATA_06);
				_vm->_cmdQueue->start();
				state.updateFlags |= 0xA0;
			}
			state.updateFlags &= ~0x40;
		} else if (state.updateFlags & 0x20) {
			_vm->_gfx->setVar(11, 0xFF);
			if (!_vm->_ui->drawVerbs() || !_vm->_ui->verbsTabInputPrompt(_vm->input())) {
				state.updateFlags |= 0x80;
			} else {
				_vm->_scriptEngine->processInput();
				state.updateFlags &= ~0x20;
			}
		} else if (state.updateFlags == 0) {
			_vm->_scriptEngine->run(state.script);
			_vm->_cmdQueue->start();
			state.updateFlags |= 0xC0;
		}
	}
}

void Scene_SP::updateActors(GameState &state) {
	(void)state;
	// Step ambient animation cycles and portrait lip sync
	if (_vm->gfx()) {
		_vm->gfx()->updateAnimations();
	}
}

void Scene_SP::checkTriggers(GameState &state) {
	// Handle gun shooting sequences when triggered by scene script
	if (_vm->_aseq && (state.updateFlags & 0x10)) {
		bool finished = _vm->_aseq->run(state.conf.useLightGun != 0);
		if (finished) {
			state.updateFlags &= ~0x10;
		}
	}
}

// Scene Handler Factory Implementations for SP00..SP38
#define implSP(num, val) \
	SceneHandler *createSceneHandler_SP##num(SnatcherEngine *vm, SceneModule *scn, FIO *fio) { \
		return new Scene_SP(vm, scn, fio, val); \
	}

implSP(00, 0);  implSP(01, 1);  implSP(02, 2);  implSP(03, 3);  implSP(04, 4);
implSP(05, 5);  implSP(06, 6);  implSP(07, 7);  implSP(08, 8);  implSP(09, 9);
implSP(10, 10); implSP(11, 11); implSP(12, 12); implSP(13, 13); implSP(14, 14);
implSP(15, 15); implSP(16, 16); implSP(17, 17); implSP(18, 18); implSP(19, 19);
implSP(20, 20); implSP(21, 21); implSP(22, 22); implSP(23, 23); implSP(24, 24);
implSP(25, 25); implSP(26, 26); implSP(27, 27); implSP(28, 28); implSP(29, 29);
implSP(30, 30); implSP(31, 31); implSP(32, 32); implSP(33, 33); implSP(34, 34);
implSP(35, 35); implSP(36, 36); implSP(37, 37); implSP(38, 38);

#undef implSP

SceneHandler *createSceneHandler_GenericScript(SnatcherEngine *vm, SceneModule *scn, FIO *fio) {
	return new Scene_SP(vm, scn, fio, 999);
}

} // End of namespace Snatcher
