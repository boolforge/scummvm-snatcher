// Ghidra 12.2 Headless Decompilation & Symbol Extraction Script for Snatcher
// @category SnatcherRE
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.data.DataType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.File;
import java.io.PrintWriter;

public class SnatcherGhidraExtractor extends GhidraScript {
    @Override
    public void run() throws Exception {
        String progName = currentProgram.getName();
        println("[+] Running Snatcher Ghidra Extractor on: " + progName);

        File outDir = new File("/storage/emulated/0/Download/Snatcher-Collection/Decompiled-CPP");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        File outFile = new File(outDir, progName + "_ghidra_decompiled.c");
        File symFile = new File(outDir, progName + "_ghidra_symbols.txt");

        PrintWriter writer = new PrintWriter(outFile);
        PrintWriter symWriter = new PrintWriter(symFile);

        writer.println("/*");
        writer.println(" * Authentically Decompiled via Ghidra 12.2 Headless (Java 25)");
        writer.println(" * Target Program: " + progName);
        writer.println(" * Processor: " + currentProgram.getLanguage().getProcessor().toString());
        writer.println(" * Endianness: " + (currentProgram.getLanguage().isBigEndian() ? "Big-Endian" : "Little-Endian"));
        writer.println(" */\n");

        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);

        int count = 0;
        FunctionIterator iter = currentProgram.getFunctionManager().getFunctions(true);
        while (iter.hasNext() && !monitor.isCancelled()) {
            Function func = iter.next();
            count++;
            symWriter.println(String.format("0x%s %s (size: %d)", func.getEntryPoint().toString(), func.getName(), func.getBody().getNumAddresses()));

            try {
                DecompileResults res = ifc.decompileFunction(func, 30, monitor);
                if (res != null && res.decompileCompleted() && res.getDecompiledFunction() != null) {
                    writer.println("// Function: " + func.getName() + " @ " + func.getEntryPoint().toString());
                    writer.println(res.getDecompiledFunction().getC());
                    writer.println();
                }
            } catch (Exception e) {
                writer.println("// Error decompiling " + func.getName() + ": " + e.getMessage());
            }

            if (count % 50 == 0) {
                println(String.format("[+] Processed %d functions...", count));
            }
        }

        writer.close();
        symWriter.close();
        ifc.dispose();
        println(String.format("[+] Finished! Decompiled %d functions to %s", count, outFile.getAbsolutePath()));
    }
}
