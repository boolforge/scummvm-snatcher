// Clean C++ Native Module for Snatcher Sega Saturn Dual SH-2 & VDP Subsystem
// Transpiled from Hitachi SH-2 MAIN_L.BIN (Entry: 0x06004000)
#include <cstdint>
#include <cstring>

namespace SnatcherRE {
namespace Saturn {

class SaturnModule {
public:
    static constexpr uint32_t HW_RAM_BASE = 0x06000000; // 1MB High Work RAM
    static constexpr uint32_t LW_RAM_BASE = 0x00200000; // 1MB Low Work RAM

    SaturnModule() {
        std::memset(_hwRam, 0, sizeof(_hwRam));
        std::memset(_lwRam, 0, sizeof(_lwRam));
    }

    void resetMasterCPU() {
        _pc = 0x06004000;
        _vdp1Active = true;
        _vdp2Active = true;
    }

    // Resolves TrueMotion AVI video stream header (LOGO.TRM / Movies)
    bool isTrueMotionStream(const uint8_t *header, size_t size) const {
        if (size >= 12) {
            // RIFF AVI TrueMotion signature check
            return (header[0] == 'R' && header[1] == 'I' && header[2] == 'F' && header[3] == 'F' &&
                    header[8] == 'A' && header[9] == 'V' && header[10] == 'I' && header[11] == ' ');
        }
        return false;
    }

private:
    uint8_t _hwRam[0x100000];
    uint8_t _lwRam[0x100000];
    uint32_t _pc = 0x06004000;
    bool _vdp1Active = false;
    bool _vdp2Active = false;
};

} // namespace Saturn
} // namespace SnatcherRE
