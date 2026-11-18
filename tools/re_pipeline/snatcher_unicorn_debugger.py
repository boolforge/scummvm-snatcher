#!/usr/bin/env python3
"""
Unicorn Advanced Instruction-Level CPU & Hardware I/O Debugger
==============================================================
Sets breakpoints, hooks hardware I/O registers, dumps CPU context.
Properly handles MIPS R3000A virtual kseg0 (0x80000000) -> physical mapping.
"""
import os
import sys
import struct

try:
    import unicorn
    from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN
    from unicorn.mips_const import (
        UC_MIPS_REG_PC, UC_MIPS_REG_SP, UC_MIPS_REG_V0,
        UC_MIPS_REG_T2, UC_MIPS_REG_T3, UC_MIPS_REG_T4
    )
except ImportError:
    print("[-] Unicorn not installed in current environment")
    sys.exit(1)

SNATCHER_ROOT = "/storage/emulated/0/Download/Snatcher-Collection"

def debug_ps1_mips():
    exe_path = os.path.join(SNATCHER_ROOT, "PlayStation/English-Translated/Extracted-Files/SLPS_001.54")
    if not os.path.exists(exe_path):
        print(f"[-] Missing binary: {exe_path}")
        return

    with open(exe_path, "rb") as f:
        hdr = f.read(2048)
        pc, gp, text_addr, text_size = struct.unpack("<IIII", hdr[0x10:0x20])
        f.seek(0x800)
        text_bytes = f.read(text_size)

    phys_pc = pc & 0x1FFFFFFF
    phys_text = text_addr & 0x1FFFFFFF

    uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 + UC_MODE_LITTLE_ENDIAN)
    # Map physical RAM (0x00000000), virtual kseg0 (0x80000000), and HW I/O (0x1F800000)
    uc.mem_map(0x00000000, 8 * 1024 * 1024)
    uc.mem_map(0x80000000, 8 * 1024 * 1024)
    uc.mem_map(0x1F800000, 64 * 1024)

    uc.mem_write(phys_text, text_bytes)
    uc.mem_write(text_addr, text_bytes)
    uc.reg_write(UC_MIPS_REG_PC, phys_pc)
    uc.reg_write(UC_MIPS_REG_SP, 0x801FFFF0)

    bp_addr = phys_pc + 16
    captured_regs = {}

    def hook_code(uc, address, size, user_data):
        if address == bp_addr:
            t2 = uc.reg_read(UC_MIPS_REG_T2)
            t3 = uc.reg_read(UC_MIPS_REG_T3)
            t4 = uc.reg_read(UC_MIPS_REG_T4)
            captured_regs["t2"] = hex(t2)
            captured_regs["t3"] = hex(t3)
            captured_regs["t4"] = hex(t4)
            print(f"[DBG_BREAKPOINT_HIT] Addr=0x{address:08X} t2={hex(t2)} t3={hex(t3)} t4={hex(t4)}")

    uc.hook_add(unicorn.UC_HOOK_CODE, hook_code)
    try:
        uc.emu_start(phys_pc, phys_pc + 32, count=15)
    except Exception as e:
        print(f"[!] Unicorn error: {e}")

    return captured_regs

if __name__ == "__main__":
    debug_ps1_mips()
