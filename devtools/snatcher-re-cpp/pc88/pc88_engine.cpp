// Clean C++ Native Module for Snatcher NEC PC-8801 mkII SR Boot & Video Engine
// Transpiled from Z80 1988 Original Bootloader (Entry: 0xC000)
#include <cstdint>
#include <cstring>

namespace SnatcherRE {
namespace PC88 {

class PC88Module {
public:
    static constexpr uint16_t BOOT_ENTRY = 0xC000;

    PC88Module() {
        std::memset(_mainRam, 0, sizeof(_mainRam));
        std::memset(_vram, 0, sizeof(_vram));
    }

    // Handles hardware I/O ports discovered in Z80 bootloader:
    // 0x31: Memory bank switching & ROM/RAM mode
    // 0x5F: Text/Graphics VRAM display mode
    // 0x53: Color palette selection (Digital 8-color)
    void writeIOPort(uint8_t port, uint8_t value) {
        switch (port) {
        case 0x31:
            _memoryMode = value;
            _textRomActive = (value & 0x02) != 0;
            break;
        case 0x5F:
            _vramDisplayMode = value;
            break;
        case 0x53:
            _paletteRegister = value;
            break;
        default:
            break;
        }
    }

    uint8_t readIOPort(uint8_t port) const {
        switch (port) {
        case 0x31: return _memoryMode;
        case 0x5F: return _vramDisplayMode;
        case 0x53: return _paletteRegister;
        default: return 0xFF;
        }
    }

    bool isTextRomActive() const { return _textRomActive; }

private:
    uint8_t _mainRam[0x10000]; // 64KB Main RAM
    uint8_t _vram[0x30000];    // 192KB PC-88 VRAM (3 planes R, G, B)
    uint8_t _memoryMode = 0;
    uint8_t _vramDisplayMode = 0;
    uint8_t _paletteRegister = 0;
    bool _textRomActive = true;
};

} // namespace PC88
} // namespace SnatcherRE
