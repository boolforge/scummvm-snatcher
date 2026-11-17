// Clean C++ Native Module for Snatcher MSX2 Bootloader & Disk Subsystem
// Reverse-engineered and transpiled from Z80 SNATCHER.COM (Base: 0x0100)
#include <cstdint>
#include <cstring>
#include <string>
#include <iostream>

namespace SnatcherRE {
namespace MSX2 {

class MSX2BootLoader {
public:
    static constexpr uint16_t TPA_START = 0x0100;
    static constexpr uint16_t BDOS_VECTOR = 0xF37D;

    struct BDOSRegisters {
        uint8_t a = 0;
        uint8_t f = 0;
        uint8_t b = 0;
        uint8_t c = 0;
        uint16_t de = 0;
        uint16_t hl = 0;
    };

    MSX2BootLoader() {
        std::memset(_ram, 0, sizeof(_ram));
    }

    void loadBinary(const uint8_t *data, size_t size, uint16_t dest = TPA_START) {
        if (dest + size <= 0x10000) {
            std::memcpy(&_ram[dest], data, size);
        }
    }

    // Emulates BDOS call 0x09 (Print String) and 0x6F (MSX-DOS 2 Disk Check)
    void executeBDOS(BDOSRegisters &regs) {
        switch (regs.c) {
        case 0x09: { // Print $-terminated string at DE
            uint16_t addr = regs.de;
            while (addr < 0xFFFF && _ram[addr] != '$') {
                std::cout << static_cast<char>(_ram[addr++]);
            }
            break;
        }
        case 0x6F: { // MSX-DOS 2 Get Disk Parameters
            // If running on Hard Disk or RAM disk, return drive parameters
            regs.a = 0; // Success
            regs.b = 2; // Drive B/Hard Disk drive ID
            break;
        }
        case 0x11: { // Find first file
            regs.a = 0;
            break;
        }
        default:
            regs.a = 0xFF; // Unhandled BDOS call
            break;
        }
    }

    // Translates the native Z80 boot entry logic:
    // 0100: ld de, 05bbh; ld c, 09h; call 0f37dh
    // 0109: ld c, 6fh; call 0f37dh
    void runBootSequence() {
        BDOSRegisters regs;
        
        // 1. Print Snatcher MSX2 Boot Banner
        regs.de = 0x05BB;
        regs.c = 0x09;
        executeBDOS(regs);

        // 2. Query Disk Controller & Hardware Environment
        regs.c = 0x6F;
        executeBDOS(regs);

        if (regs.a == 0 && regs.b >= 2) {
            _driveId = regs.b;
            _isHardDisk = true;
        } else {
            _driveId = 0; // Floppy Drive A:
            _isHardDisk = false;
        }
    }

    bool isHardDisk() const { return _isHardDisk; }
    uint8_t getDriveId() const { return _driveId; }

private:
    uint8_t _ram[0x10000];
    uint8_t _driveId = 0;
    bool _isHardDisk = false;
};

} // namespace MSX2
} // namespace SnatcherRE
