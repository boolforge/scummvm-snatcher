# 02: Bytecode VM & Scripting Engine Specification

Deterministic technical reference for the Konami Snatcher Bytecode Virtual Machine, execution registers, and complete 75-opcode instruction set.

---

## 1. Virtual Machine State Architecture

The Snatcher VM is a register-and-stack hybrid machine that executes bytecode compiled into scenario modules (`DATA_A0.BIN` through `DATA_Q8.BIN`).

### 1.1. VM State Struct
```c
struct SnatcherVMState {
    uint16 pc;                // Program counter (curPos)
    uint16 next_pc;           // Target branch address (newPos)
    uint8  cur_file_no;       // Active scene module file index (0..96)
    int16  cur_gfx_script;    // Active graphic script index
    uint16 result_reg;        // Arithmetic and logical accumulator (_result)
    uint8  sentence_done;     // Dialogue sentence termination flag
    uint8  sentence_pos;      // Active verb sentence recursion depth
    uint8  arrays[6][32];     // 6 internal script arrays (32 bytes each)
    uint8  flags_table[352];  // 2,816 global persistent game state bitflags
};
```

### 1.2. Command Execution Queue (`CmdQueue`)
The Script Engine separates high-level scenario logic from low-level multimedia presentation by emitting commands into a 256-word ring buffer (`CmdQueue`). The CmdQueue executes asynchronously alongside the display vertical blanking loop.

---

## 2. 100% Opcode Matrix (75 Opcodes)

| Hex | Dec | Mnemonic | Param Bytes | Execution Behavior | Port Availability |
|---|---|---|---|---|---|
| `0x00` | 0 | `o_animOps` | 4 | Queues animation operation cmd 0x09 with two uint16 params | All |
| `0x01` | 1 | `o_evalAdd` | 4 | Evaluates and adds operand to destination register/accumulator | All |
| `0x02` | 2 | `o_evalAdd` | 4 | Evaluates and adds variable/memory value to destination | All |
| `0x03` | 3 | `o_evalAdd` | 4 | Evaluates and adds immediate operand to destination | All |
| `0x04` | 4 | `o_chatWithPortraitAnim` | 4 | Displays dialogue with synchronised mouth/eye animations | All |
| `0x05` | 5 | `o_pcmSound` | 4 | Triggers voice/PCM audio playback for line index | All |
| `0x06` | 6 | `o_evalAnd` | 4 | Performs logical AND with operand 1 | All |
| `0x07` | 7 | `o_evalAnd` | 4 | Performs logical AND with operand 2 | All |
| `0x08` | 8 | `o_evalAnd` | 4 | Performs logical AND with operand 3 | All |
| `0x09` | 9 | `o_evalAnd` | 4 | Performs logical AND with immediate value | All |
| `0x0A` | 10 | `o_fmMusicStart` | 2 | Starts FM music track playback by track ID | All |
| `0x0B` | 11 | `o_runSubScript` | 4 | Executes secondary sub-script overlay | All |
| `0x0C` | 12 | `o_callSubroutine` | 4 | Calls script subroutine pushing return address to stack | All |
| `0x0D` | 13 | `o_cdaPlay` | 2 | Starts Redbook CD audio track playback | All |
| `0x0E` | 14 | `o_incrCounter` | 2 | Increments script counter / loop register | All |
| `0x0F` | 15 | `o_fmSoundEffect` | 2 | Triggers FM sound effect (SFX index) | All |
| `0x10` | 16 | `o_evalEquals` | 4 | Equality comparison test against operand 1 | All |
| `0x11` | 17 | `o_evalEquals` | 4 | Equality comparison test against operand 2 | All |
| `0x12` | 18 | `o_evalEquals` | 4 | Equality comparison test against immediate | All |
| `0x13` | 19 | `o_clearFlags` | 4 | Clears bitflag in global game state array | All |
| `0x14` | 20 | `o_setFlags` | 4 | Sets bitflag in global game state array | All |
| `0x15` | 21 | `o_getPrevPosition` | 2 | Restores previous script execution address | All |
| `0x16` | 22 | `o_evalLess` | 4 | Signed less-than comparison test | All |
| `0x17` | 23 | `o_evalLessOrEqual` | 4 | Signed less-than-or-equal comparison test | All |
| `0x18` | 24 | `o_doEitherOr` | 4 | Conditional branch: executes branch 1 or branch 2 | All |
| `0x19` | 25 | `o_doEitherOr` | 4 | Conditional branch alternate encoding | All |
| `0x1A` | 26 | `o_doIf` | 4 | Conditional branch: executes branch if condition is true | All |
| `0x1B` | 27 | `o_doIf` | 4 | Conditional branch alternate encoding | All |
| `0x1C` | 28 | `o_setResult` | 2 | Sets evaluation result accumulator register | All |
| `0x1D` | 29 | `o_setResult` | 2 | Sets evaluation result accumulator register (direct) | All |
| `0x1E` | 30 | `o_runFunction` | 4 | Calls built-in engine native function (index 0) | All |
| `0x1F` | 31 | `o_runFunction` | 4 | Calls built-in engine native function (index 1) | All |
| `0x20` | 32 | `o_runFunction` | 4 | Calls built-in engine native function (index 2) | All |
| `0x21` | 33 | `o_runFunction` | 4 | Calls built-in engine native function (index 3) | All |
| `0x22` | 34 | `o_runFunction` | 4 | Calls built-in engine native function (index 4) | All |
| `0x23` | 35 | `o_runFunction` | 4 | Calls built-in engine native function (index 5) | All |
| `0x24` | 36 | `o_runFunction` | 4 | Calls built-in engine native function (index 6) | All |
| `0x25` | 37 | `o_runFunction` | 4 | Calls built-in engine native function (index 7) | All |
| `0x26` | 38 | `o_runFunction` | 4 | Calls built-in engine native function (index 8) | All |
| `0x27` | 39 | `o_runFunction` | 4 | Calls built-in engine native function (index 9) | All |
| `0x28` | 40 | `o_evalGreater` | 4 | Signed greater-than comparison test | All |
| `0x29` | 41 | `o_evalGreater` | 4 | Signed greater-than comparison test alternate | All |
| `0x2A` | 42 | `o_evalGreaterOrEqual` | 4 | Signed greater-than-or-equal comparison test | All |
| `0x2B` | 43 | `o_break` | 2 | Breaks out of current loop or conditional block | All |
| `0x2C` | 44 | `o_break` | 2 | Breaks out of current loop alternate | All |
| `0x2D` | 45 | `o_nop` | 2 | No-operation / byte padding | All |
| `0x2E` | 46 | `o_evalTrue` | 2 | Evaluates true unconditionally | All |
| `0x2F` | 47 | `o_evalTrue` | 2 | Evaluates true unconditionally alternate | All |
| `0x30` | 48 | `o_start` | 2 | Initializes scenario execution context | All |
| `0x31` | 49 | `o_evalOr` | 4 | Performs logical OR test with operand 1 | All |
| `0x32` | 50 | `o_evalOr` | 4 | Performs logical OR test with operand 2 | All |
| `0x33` | 51 | `o_evalOr` | 4 | Performs logical OR test with immediate | All |
| `0x34` | 52 | `o_condExec` | 4 | Executes block if accumulator matches condition | All |
| `0x35` | 53 | `o_condExec` | 4 | Executes block if accumulator matches alternate | All |
| `0x36` | 54 | `o_sentenceRecurseBegin` | 4 | Pushes sentence recursion frame for verb dialogue | All |
| `0x37` | 55 | `o_sentenceRecurseBegin` | 4 | Pushes sentence recursion frame alternate | All |
| `0x38` | 56 | `o_verbOps` | 4 | Populates UI verb menu items (LOOK, TALK, MOVE, etc.) | All |
| `0x39` | 57 | `o_sentenceRecurseEnd` | 2 | Pops sentence recursion frame and commits verb choice | All |
| `0x3A` | 58 | `o_returnFromSubScript` | 2 | Returns from sub-script to parent scenario context | All |
| `0x3B` | 59 | `o_checkSubRecurseState` | 2 | Validates recursion stack depth and branch state | All |
| `0x3C` | 60 | `o_checkSubRecurseState` | 2 | Validates recursion stack depth alternate | All |
| `0x3D` | 61 | `o_loadModuleAndStartGfx` | 4 | Loads target scene module and initializes graphic layer | All |
| `0x3E` | 62 | `o_randomSwitch` | 4 | Evaluates pseudo-random branch selector | All |
| `0x3F` | 63 | `o_sequentialSwitch` | 4 | Cycles through sequential branch table on each visit | All |
| `0x40` | 64 | `o_64` | 2 | Extended opcode branch handler | All |
| `0x41` | 65 | `o_sysOps` | 4 | Executes system control operations (save/load/fade/input) | All |
| `0x42` | 66 | `o_sysOps` | 4 | Executes system control operations alternate | All |
| `0x43` | 67 | `o_displayDialog` | 4 | Renders dialogue box text buffer to screen | All |
| `0x44` | 68 | `o_displayDialog` | 4 | Renders dialogue box text buffer alternate | All |
| `0x45` | 69 | `o_animWait` | 2 | Pauses script execution until sprite animation finishes | All |
| `0x46` | 70 | `o_pcmSoundWait` | 2 | Pauses script execution until voice sample completes | All |
| `0x47` | 71 | `o_fmMusicWait` | 2 | Pauses script execution until FM music transition ends | All |
| `0x48` | 72 | `o_cdaWait` | 2 | Pauses script execution until CD track finishes | All |
| `0x49` | 73 | `o_fmSfxWait` | 2 | Pauses script execution until sound effect finishes | All |
| `0x4A` | 74 | `o_waitFrames` | 2 | Pauses script execution for N vertical blank frames | All |

---

## 3. Investigation Verb System (`o_verbOps`)

The verb system dynamically builds interactive investigation menus based on bitflags in `flags_table`:
1. **LOOK (0x01):** Inspect environment coordinates or visual clues.
2. **INVESTIGATE (0x02):** Detailed examination of physical evidence.
3. **TALK (0x03):** Query present NPC or Metal Gear navigator.
4. **ASK (0x04):** Topic-based interrogation tree.
5. **USE (0x05):** Inventory item application.
6. **MOVE (0x06):** Room graph traversal.

Selecting a verb executes `sentenceRecurseBegin`, recurses into dialogue trees, and terminates with `sentenceRecurseEnd` to refresh the prompt.