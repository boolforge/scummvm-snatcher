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

#ifndef SNATCHER_SCENE_SP_H
#define SNATCHER_SCENE_SP_H

#include "snatcher/resource.h"
#include "snatcher/scene.h"

namespace Snatcher {

class SnatcherEngine;
class SceneModule;
class FIO;

/**
 * Universal native scene handler for playable gameplay scenes SP00 through SP38.
 * Executes bytecode scripts, handles interactive investigative choices, dialog,
 * animations, and shooting sequences across all 6 platform targets.
 */
class Scene_SP : public SceneHandler {
public:
	Scene_SP(SnatcherEngine *vm, SceneModule *scn, FIO *fio, int sceneNumber);
	~Scene_SP() override;

	void operator()(GameState &state) override;

private:
	int _sceneNumber;
	bool _initialized;
	uint32 _tickCounter;

	void stepScript(GameState &state);
	void updateActors(GameState &state);
	void checkTriggers(GameState &state);
};

// Factory macros for SP00..SP38
#define declSP(num) \
	SceneHandler *createSceneHandler_SP##num(SnatcherEngine *vm, SceneModule *scn, FIO *fio)

declSP(00); declSP(01); declSP(02); declSP(03); declSP(04);
declSP(05); declSP(06); declSP(07); declSP(08); declSP(09);
declSP(10); declSP(11); declSP(12); declSP(13); declSP(14);
declSP(15); declSP(16); declSP(17); declSP(18); declSP(19);
declSP(20); declSP(21); declSP(22); declSP(23); declSP(24);
declSP(25); declSP(26); declSP(27); declSP(28); declSP(29);
declSP(30); declSP(31); declSP(32); declSP(33); declSP(34);
declSP(35); declSP(36); declSP(37); declSP(38);

#undef declSP

SceneHandler *createSceneHandler_GenericScript(SnatcherEngine *vm, SceneModule *scn, FIO *fio);

} // End of namespace Snatcher

#endif // SNATCHER_SCENE_SP_H
