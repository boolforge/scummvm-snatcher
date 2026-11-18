#!/usr/bin/env python3
"""
=============================================================================
SNATCHER REVERSE ENGINEERING HARNESS (UNIFIED FORWARDER)
=============================================================================
Forwards directly to the consolidated, supercharged snatcher_mega_harness.py.
All capabilities (angr, Ghidra, Capstone, Unicorn, ScummVM Synth) are unified!
=============================================================================
"""
import os
import sys

TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
if TOOLS_DIR not in sys.path:
    sys.path.insert(0, TOOLS_DIR)

import snatcher_mega_harness

if __name__ == "__main__":
    snatcher_mega_harness.main()
