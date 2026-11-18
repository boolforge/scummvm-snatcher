// Ghidra 12.2 Headless Pre-Script for Snatcher Multi-Architecture Binaries
// Automatically seeds entry point and starts recursive auto-disassembly
// @category SnatcherRE

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.symbol.SourceType;

public class SnatcherGhidraPreScript extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address minAddr = currentProgram.getMinAddress();
        if (minAddr != null) {
            println("[SnatcherPreScript] Seeding entry point at " + minAddr.toString());
            disassemble(minAddr);
            createFunction(minAddr, "entry_point");
            addEntryPoint(minAddr);
        }
    }
}
