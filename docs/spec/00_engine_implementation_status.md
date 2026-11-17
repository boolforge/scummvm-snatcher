# 00: Engine Implementation Status & Source Audit

Deterministic technical audit of all source files in `engines/snatcher/` as of current commit.

---

## 1. Source Inventory

Total Header Files (`.h`): 35
Total Implementation Files (`.cpp`): 38

| File | Size (Bytes) | Lines | Purpose / Architecture | Key Classes & Structs |
|---|---|---|---|---|
| `action.cpp` | 24,722 | 879 | Core Engine | `-` |
| `action.h` | 2,630 | 107 | Core Engine | `ResourcePointer, SnatcherEngine, ActionSequenceHandler (+1)` |
| `animator.h` | 3,493 | 89 | Graphics & Animation | `SoundEngine, Animator` |
| `animator_linear.cpp` | 6,446 | 242 | Graphics & Animation | `-` |
| `animator_linear.h` | 3,328 | 92 | Graphics & Animation | `Palette, TransitionManager, SoundEngine (+1)` |
| `animator_scd.cpp` | 52,621 | 1835 | Graphics & Animation | `AnimObject, GraphicsEngine, Animator_SCD (+3)` |
| `boot_logo.cpp` | 16,432 | 481 | Boot & Logos | `PSXRawSectorReadStream, PS1BootLogo, SaturnBootLogo (+3)` |
| `boot_logo.h` | 1,869 | 51 | Boot & Logos | `OSystem, BootLogo` |
| `decompressor.cpp` | 7,848 | 328 | Compression | `-` |
| `decompressor.h` | 3,485 | 88 | Compression | `Decompressor` |
| `detection.cpp` | 7,014 | 189 | Core Engine | `SnatcherMetaEngineDetection` |
| `detection.h` | 1,610 | 64 | Core Engine | `GameDescription, SnatcherGameDescription` |
| `detection_tables.h` | 7,175 | 256 | Core Engine | `-` |
| `fantranslations.cpp` | 20,496 | 608 | Core Engine | `-` |
| `fantranslations.h` | 3,067 | 98 | Core Engine | `FanTranslationHandler, FontProperties, PerFileTranslateableData` |
| `graphics.cpp` | 15,564 | 546 | Graphics & Animation | `-` |
| `graphics.h` | 6,028 | 247 | Graphics & Animation | `OSystem, SeekableWriteStream, PixelFormat (+8)` |
| `info.h` | 1,158 | 39 | Core Engine | `VMInfo` |
| `mem_mapping.cpp` | 7,861 | 203 | Core Engine | `-` |
| `mem_mapping.h` | 3,730 | 121 | Core Engine | `-` |
| `memory.cpp` | 3,410 | 135 | Core Engine | `-` |
| `memory.h` | 2,133 | 65 | Core Engine | `ActionSequenceHandler, SaveLoadManager, SnatcherEngine (+3)` |
| `metaengine.cpp` | 13,691 | 312 | Core Engine | `SnatcherMetaEngine, SnatcherOptionsWidget` |
| `palette.cpp` | 2,016 | 66 | Color & Palette | `-` |
| `palette.h` | 2,768 | 87 | Color & Palette | `PaletteManager, SeekableWriteStream, SeekableReadStream (+2)` |
| `palette_linear.cpp` | 3,143 | 106 | Color & Palette | `-` |
| `palette_linear.h` | 1,821 | 54 | Color & Palette | `LinearPalette` |
| `palette_scd.cpp` | 18,548 | 640 | Color & Palette | `GraphicsEngine, SCDPalette` |
| `palevent_scd.h` | 1,585 | 57 | Core Engine | `PalEventSCD` |
| `resource.cpp` | 16,277 | 469 | File I/O & Archives | `-` |
| `resource.h` | 4,123 | 147 | File I/O & Archives | `SeekableReadStream, SeekableReadStreamEndian, SnatcherEngine (+7)` |
| `saveflags.h` | 1,169 | 38 | Core Engine | `-` |
| `saveload.cpp` | 11,803 | 356 | Core Engine | `-` |
| `saveload.h` | 2,965 | 104 | Core Engine | `SeekableReadStream, OutSaveFile, Surface (+3)` |
| `scene.h` | 1,264 | 46 | Scene Handling | `SceneHandler, SnatcherEngine, SceneModule (+1)` |
| `scene_d0.cpp` | 6,100 | 262 | Scene Handling | `-` |
| `scene_d1.cpp` | 5,332 | 228 | Scene Handling | `-` |
| `scene_d2.cpp` | 16,289 | 554 | Scene Handling | `-` |
| `scene_imp.h` | 2,435 | 63 | Scene Handling | `Scene_` |
| `scene_sp.cpp` | 4,164 | 123 | Scene Handling | `-` |
| `scene_sp.h` | 2,382 | 73 | Scene Handling | `SnatcherEngine, SceneModule, FIO (+1)` |
| `scene_y16.cpp` | 5,637 | 258 | Scene Handling | `-` |
| `script.cpp` | 38,070 | 1635 | Bytecode VM | `SFunc` |
| `script.h` | 7,799 | 274 | Bytecode VM | `SeekableReadStream, SeekableWriteStream, ActionSequenceHandler (+9)` |
| `snatcher.cpp` | 24,685 | 839 | Core Engine | `InputEvent` |
| `snatcher.h` | 3,969 | 153 | Core Engine | `SnatcherMetaEngine, ActionSequenceHandler, CmdQueue (+14)` |
| `sound.cpp` | 5,750 | 215 | Audio / Synthesis | `NullSoundDevice` |
| `sound.h` | 2,598 | 103 | Audio / Synthesis | `Mixer, SeekableReadStream, SeekableWriteStream (+5)` |
| `sound_device.h` | 2,412 | 83 | Audio / Synthesis | `Mixer, FIO, SoundDevice` |
| `sound_device_msx2.cpp` | 3,764 | 149 | Audio / Synthesis | `SoundDeviceMSX2` |
| `sound_device_pc88.cpp` | 3,715 | 148 | Audio / Synthesis | `SoundDevicePC88` |
| `sound_device_pce.cpp` | 4,379 | 171 | Audio / Synthesis | `SoundDevicePCE` |
| `sound_device_psx.cpp` | 4,369 | 171 | Audio / Synthesis | `SoundDevicePSX` |
| `sound_device_saturn.cpp` | 4,356 | 168 | Audio / Synthesis | `SoundDeviceSaturn` |
| `sound_device_scd.cpp` | 65,381 | 2308 | Audio / Synthesis | `MessageHandler, KonamiMCDAudioDriver, SegaSoundDevice (+12)` |
| `state.h` | 3,198 | 117 | Core Engine | `SnatcherEngine, SceneModule, FIO (+6)` |
| `staticres.cpp` | 35,662 | 358 | Core Engine | `-` |
| `staticres.h` | 1,275 | 42 | Core Engine | `-` |
| `staticres_types.h` | 1,200 | 44 | Core Engine | `FMSoundTrackDef` |
| `subcode_native.cpp` | 3,780 | 128 | Core Engine | `-` |
| `subcode_native.h` | 2,777 | 93 | Core Engine | `SubcodeExecutive, MailboxState` |
| `text.h` | 1,737 | 61 | Core Engine | `Animator, TextRenderer` |
| `text_linear.cpp` | 3,990 | 161 | Core Engine | `-` |
| `text_linear.h` | 1,898 | 68 | Core Engine | `Animator, TextRenderer_Linear` |
| `text_scd.cpp` | 5,529 | 228 | Core Engine | `TextRenderer_SCD` |
| `transition.h` | 2,477 | 91 | Core Engine | `SeekableWriteStream, SeekableReadStream, TransitionManager (+2)` |
| `transition_linear.cpp` | 3,207 | 120 | Core Engine | `-` |
| `transition_linear.h` | 1,774 | 53 | Core Engine | `LinearTransitionManager` |
| `transition_scd.cpp` | 33,760 | 1325 | Core Engine | `ScrollInternalState, TransitionManager_SCD` |
| `ui.cpp` | 32,691 | 1205 | User Interface | `-` |
| `ui.h` | 4,921 | 174 | User Interface | `SeekableReadStream, SeekableWriteStream, CmdQueue (+6)` |
| `util.cpp` | 3,496 | 160 | Core Engine | `-` |
| `util.h` | 1,462 | 49 | Core Engine | `-` |

---

## 2. Runtime Call Graph & Execution Flow

```
SnatcherEngine::run()
  ├── SnatcherEngine::initResource()        -> FIO::FIO() & loads SUBCODE.BIN (index 96)
  ├── SnatcherEngine::initSound()           -> SoundEngine -> SoundDevice::create(platform)
  ├── SnatcherEngine::initGfx()             -> GraphicsEngine -> Animator::create(platform), Palette::create(platform)
  ├── SnatcherEngine::initSaveLoad()        -> SaveLoadManager()
  ├── SnatcherEngine::initScriptEngine()    -> CmdQueue(), UI(), ActionSequenceHandler(), ScriptEngine()
  └── SnatcherEngine::start()               [MAIN GAMEPLAY LOOP]
        ├── playBootLogoAnimation()         -> GraphicsEngine::displayBootLogoFrame() -> BootLogo::drawFrame()
        └── while (!shouldQuit())
              ├── updateMainState()         -> GameState phase 0..4 transitions
              ├── updateModuleState()       -> Intro cutscenes (modPhaseTop 0..2) & in-game (modPhaseTop 5)
              │     └── SceneModule::run()  -> (*_updateHandler)(state) [Scene_D0, Scene_D1, Scene_D2, Scene_Y16, Scene_SP]
              ├── CmdQueue::run()           -> Dispatches queued graphical/audio commands
              ├── UI::moveFlashLight()      -> Interactive flashlight / mouse position tracking
              ├── UI::drawVerbs()           -> Renders verb window / choices (LOOK, INVESTIGATE, etc.)
              ├── ScriptEngine::run()       -> Executes scenario bytecode instructions
              ├── GraphicsEngine::updateAnimations()
              ├── GraphicsEngine::updateText()
              ├── GraphicsEngine::nextFrame()
              └── SoundEngine::update()
```

---

## 3. Platform Branch Audit (`Common::Platform`)

| Subsystem | Source File | Implemented Architectures | Multiplatform Fallback & Status |
|---|---|---|---|
| **Boot Logos** | `boot_logo.cpp` | `kPlatformPSX` (PSX STR video stream), `kPlatformSaturn` (Saturn Cinepak AVI), `kPlatformSegaCD` (Native VDP sequence) | Unpacks and streams video sector data; gracefully falls through to main title. |
| **Graphics & Rendering** | `animator.cpp`, `animator_linear.cpp`, `animator_scd.cpp` | `kPlatformSegaCD` -> `Animator_SCD` (320x224 tile planes); `kPlatformPSX`, `kPlatformSaturn`, `kPlatformPCEngine` -> `LinearAnimator` (Direct framebuffer) | Cleanly abstracted via `Animator` base interface. Native PS1 and Saturn resolutions mapped. |
| **Palette Management** | `palette.cpp`, `palette_linear.cpp`, `palette_scd.cpp` | `kPlatformSegaCD` -> `SCDPalette` (CRAM 64 colors); Non-SCD -> `LinearPalette` (256-color direct CLUT) | Direct color updates dispatched via `updateSystemPalette()`. |
| **Sound Synthesis** | `sound.cpp`, `sound_device_*.cpp` | `SoundDeviceSCD` (RF5C164 + YM2612), `SoundDevicePSX` (SPU ADPCM), `SoundDeviceSaturn` (SCSP), `SoundDevicePCE` (MSM5205 + HuC6280), `SoundDeviceMSX2` (SCC + PSG), `SoundDevicePC88` (OPN) | Platform-specific drivers created via `SoundDevice::create(platform)`. |
| **Asset Filesystem** | `resource.cpp` | Sega CD (`DATA_*.BIN`, `SP*.BIN`), PS1 (`ISZ_B*.BIN`, `DES/CXD/*.BIN`, `DES/CC3/*.BIN`), PCE (`scenes/scene_*.bin`), Saturn (`DATA.BIN`) | Transparent decompression in `FIO::fileData` for PS1 LZSS (`Decompressor::decompressPS1LZSS`) and Saturn LZ3 (`Decompressor::decompressSaturnLZ3`). |

---

## 4. Scene Execution Architecture: Specialized Handlers vs. Bytecode VM

In `engines/snatcher/`, scenes fall into two distinct execution paradigms:

1. **Specialized Hardcoded Cutscene Handlers (`Scene_D0`, `Scene_D1`, `Scene_D2`, `Scene_Y16`):**
   - **`Scene_D0` (`DATA_D0.BIN`):** Handles the Act 1 Opening Cutscene. It reads 35 exact timestamps from `MEM_TIMERDATA_02` within `DATA_D0.BIN` to synchronize graphics frames to CD-DA audio track 5 via `SoundEngine::cdaGetTime()`.
   - **`Scene_D1` (`DATA_D1.BIN`):** Handles the Act 2 narrative intermission cutscene with timed palette fades.
   - **`Scene_D2` (`DATA_D2.BIN`):** Handles the Act 3 intro cutscene.
   - **`Scene_Y16` (`DATA_Y16.BIN`):** Handles the final ending credits crawl and music synchronization.

2. **Universal Bytecode Script Handler (`Scene_SP`):**
   - Wired to `createSceneHandler_GenericScript` across `SceneModule::_shList` for modules `DATA_A0`, `DATA_B0`, and `DATA_F0` through `DATA_Y15`, as well as playable scenes `SP00` through `SP38`.
   - At runtime, `Scene_SP` initializes the scene graphics by executing the embedded graphics script at `SceneModule::getGfxData()`.
   - On each tick, `Scene_SP::stepScript()` invokes `ScriptEngine::run(state.script)`, which interprets the 75 bytecode instructions, manages the evaluation stack and registers, populates verb menus via `UI::drawVerbs()`, and initiates shooting gallery sequences via `ActionSequenceHandler::run()`.