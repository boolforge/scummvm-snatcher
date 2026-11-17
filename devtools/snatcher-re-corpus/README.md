# Snatcher Multi-Platform Reverse Engineering Corpus & Analysis Documentation

This directory contains real decompiled C code, disassembled listings, memory map specifications, and reverse-engineering research documentation extracted from the authentic commercial ports of Konami's *Snatcher* (1988–1996).

---

## 1. Directory Structure

```text
devtools/snatcher-re-corpus/
├── docs/                 Detailed reverse-engineering specifications and hardware notes
│   ├── ps1.md            PlayStation SLPS-00154 technical documentation (pepasjc)
│   ├── saturn.md         Sega Saturn SH-2 engine and memory layout
│   ├── pce.md            PC Engine Super CD-ROM² HuC6280 bytecode and bank switching
│   ├── DISC_LAYOUT.md    Sega CD physical track, sector, and overlay format
│   ├── JOURNAL.md        Reverse engineering log for Sega CD (bgyss)
│   └── STRATEGY.md       Clean-room multiplatform porting strategy
├── ps1/                  Sony PlayStation (MIPS R3000A)
│   ├── ps1.c             Decompiled C code (1,080 functions, 914 KB)
│   └── ps1.asm           Disassembled MIPS assembly listing (1.6 MB)
├── segacd/               Sega Mega-CD (Motorola 68000)
│   ├── scd_subcode.c     Decompiled C code of SUBCODE.BIN (Sub-CPU audio/cda controller)
│   └── scd_subcode.asm   Disassembled 68000 assembly listing
├── msx2/                 MSX2 (Zilog Z80 @ 3.58 MHz)
│   ├── msx2_com.c        Decompiled C code of SNATCHER.COM (Ghidra Z80 P-Code engine)
│   └── msx2_com.asm      Native Z80 disassembly with BDOS and memory vector resolution
├── pcengine/             PC Engine Super CD-ROM² (HuC6280 @ 7.16 MHz)
│   ├── pce_overlay.c     Decompiled C code generated with native HuC6280 Ghidra processor
│   └── pce_overlay.asm   Disassembled 65C02/HuC6280 overlay listing
├── saturn/               Sega Saturn (Hitachi SH-2 @ 28.6 MHz)
│   ├── saturn_main.c     Decompiled C entry code of MAIN_L.BIN
│   └── saturn_main.asm   Disassembled SuperH SH-2 assembly
└── pc88/                 NEC PC-8801 mkII SR (Z80 @ 4 MHz)
    ├── pc88_boot.c       Decompiled C code of 1988 boot sector
    └── pc88_boot.asm     Z80 bootloader disassembly
```

---

## 2. Tools & Toolchains Used
- **Decompilation Engine:** Ghidra 12.2 running under OpenJDK 25 (ARM64 Linux).
  - Native ARM64 Decompiler (`ghidra_opt` compiled with Clang).
  - Native HuC6280 processor plugin (`TiCoKH/Ghidra_HuC6280`).
  - PSX Executable Loader & GTE analyzer (`lab313ru/ghidra_psx_ldr`).
  - Sega Saturn Loader (`VGKintsugi/Ghidra-SegaSaturn-Loader`).
- **Native Z80 Disassembler:** `z80dasm` 1.1.6.
- **Dynamic Emulation & Tracing:**
  - `openMSX 20.0` with Tcl automation console.
  - `mednafen 1.32.1` multi-system debugger.
  - `gdb-multiarch 16.3` (MIPS, SH-2, 68000, Z80).
  - `frida-server 17.26.4` native ARM64 under elevated Magisk root (`su`).
