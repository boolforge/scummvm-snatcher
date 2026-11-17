// Clean C++ Native Module for Snatcher PC Engine Super CD-ROM²
// Transpiled from HuC6280 65C02 bytecode and Memory Mapping Registers (TAM/TMA)
#include <cstdint>
#include <cstring>

namespace SnatcherRE {
namespace PCEngine {

class PCEngineModule {
public:
    static constexpr size_t WRAM_SIZE = 0x30000; // 192KB Super CD-ROM² RAM

    PCEngineModule() {
        std::memset(_wram, 0, sizeof(_wram));
        std::memset(_mpr, 0, sizeof(_mpr));
    }

    // HuC6280 TMA (Transfer Memory to Accumulator) / TAM (Transfer Accumulator to Memory)
    void writeMPR(uint8_t mprIndex, uint8_t bank) {
        if (mprIndex < 8) {
            _mpr[mprIndex] = bank;
        }
    }

    uint8_t readMPR(uint8_t mprIndex) const {
        if (mprIndex < 8) return _mpr[mprIndex];
        return 0;
    }

    // Resolves logical 16-bit address through the 8KB banking MPR windows
    uint32_t mapAddress(uint16_t logicalAddr) const {
        uint8_t page = (logicalAddr >> 13) & 0x07;
        uint16_t offset = logicalAddr & 0x1FFF;
        return (_mpr[page] * 0x2000) + offset;
    }

    uint8_t readMemory(uint16_t logicalAddr) const {
        uint32_t physical = mapAddress(logicalAddr);
        if (physical < sizeof(_wram)) return _wram[physical];
        return 0xFF;
    }

    void writeMemory(uint16_t logicalAddr, uint8_t val) {
        uint32_t physical = mapAddress(logicalAddr);
        if (physical < sizeof(_wram)) _wram[physical] = val;
    }

private:
    uint8_t _wram[WRAM_SIZE];
    uint8_t _mpr[8]; // Memory Page Registers (0 to 7)
};

} // namespace PCEngine
} // namespace SnatcherRE
