# Snatcher High-Level Modern C++ Engine Modules

This directory contains human-readable, clean, object-oriented modern C++ (C++17) implementations transpiled directly from the reverse-engineered assembly routines and raw C decompilations of the 6 commercial ports of Konami's *Snatcher*.

---

## 1. Modules Overview

| Platform | File | Original Architecture | Purpose / Mapped Functionality |
| :--- | :--- | :--- | :--- |
| **PlayStation** | `ps1/ps1_engine.cpp` | MIPS R3000A | PlayStation 1 VRAM buffer, MDEC movie player state (`.STR`), and file table indexing. |
| **Sega CD** | `segacd/segacd_subcode.cpp` | Motorola 68000 | Sub-CPU audio controller (`SUBCODE.BIN`), CD-DA track player, PCM channel volume control. |
| **MSX2** | `msx2/msx2_engine.cpp` | Zilog Z80 | MSX-DOS BDOS vector handler (`0xF37D`), hard disk / floppy drive identification. |
| **PC Engine** | `pcengine/pce_engine.cpp` | HuC6280 (65C02) | Memory Page Registers (`MPR0`–`MPR7`), `TMA`/`TAM` dynamic bank switching. |
| **Sega Saturn** | `saturn/saturn_engine.cpp` | Dual Hitachi SH-2 | High/Low Work RAM architecture, TrueMotion RIFF AVI (`LOGO.TRM`) stream parsing. |
| **PC-8801** | `pc88/pc88_engine.cpp` | Zilog Z80 | Hardware I/O ports (`0x31` Memory Mode, `0x5F` VRAM, `0x53` Digital 8-color palette). |

---

## 2. Compilation & Verification
All files in this directory are clean, self-contained standard C++ modules compilable with any modern ISO C++17 compiler (`clang++`, `g++`):
```bash
clang++ -std=c++17 -c devtools/snatcher-re-cpp/*/*.cpp
```
