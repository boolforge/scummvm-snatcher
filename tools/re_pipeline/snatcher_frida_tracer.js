/**
 * Snatcher Dynamic Instrumentation Tracer via Frida
 * ==================================================
 * Instruments OpenMSX, Mednafen, or ScummVM native processes to:
 * 1. Hook file I/O operations (open, read, seek) to log accessed Snatcher assets.
 * 2. Trace VDP/GPU register writes and DMA transfers.
 * 3. Log sound engine events (SCC, PSG, SPU, ADPCM).
 */

console.log("[*] Snatcher Frida Tracer Loaded!");

// Hook libc open / openat to detect asset loading
Interceptor.attach(Module.getExportByName(null, "open"), {
    onEnter: function(args) {
        var path = Memory.readUtf8String(args[0]);
        if (path && (path.indexOf("SNATCHER") !== -1 || path.indexOf("SLPS") !== -1 || path.indexOf("MAIN_L") !== -1 || path.indexOf(".BIN") !== -1 || path.indexOf(".AIF") !== -1)) {
            console.log("[FRIDA] open() -> " + path);
        }
    }
});

// Hook read to measure sector and asset stream transfers
Interceptor.attach(Module.getExportByName(null, "read"), {
    onEnter: function(args) {
        this.fd = args[0].toInt32();
        this.count = args[2].toInt32();
    },
    onLeave: function(retval) {
        var bytesRead = retval.toInt32();
        if (bytesRead > 2048) {
            // Significant asset stream transfer detected
            // console.log("[FRIDA] read(fd=" + this.fd + ", count=" + this.count + ") -> " + bytesRead + " bytes");
        }
    }
});
