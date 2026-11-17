// Clean C++ Native Module for Snatcher Sega-CD Sub-CPU Engine
// Transpiled and refactored from 68000 SUBCODE.BIN (Load address: 0x0000D400)
#include <cstdint>
#include <cstring>
#include <algorithm>

namespace SnatcherRE {
namespace SegaCD {

class SubCodeEngine {
public:
    static constexpr uint32_t BASE_ADDR = 0x0000D400;
    static constexpr size_t RAM_SIZE = 0x100000; // 1MB Word-RAM / PRG-RAM

    SubCodeEngine() {
        std::memset(_ram, 0, sizeof(_ram));
    }

    void reset() {
        _commFlags = 0;
        _cdaTrack = 0;
        _pcmVolume = 0xFF;
    }

    // Handles Main-CPU to Sub-CPU interrupt requests
    void processCommand(uint8_t cmd, uint8_t param) {
        switch (cmd) {
        case 0xF0: // Stop audio / reset channel
            stopAllAudio();
            break;
        case 0xF1: // Play CD-DA track
            playCDDATrack(param);
            break;
        case 0xF2: // Set PCM sample rate & channel
            setupPCMChannel(param);
            break;
        case 0xF3: // Stop CD-DA playback
            stopCDDA();
            break;
        case 0xF4: // Fade out audio
            fadeAudio(param);
            break;
        default:
            break;
        }
    }

    uint8_t readWordRAM(uint32_t addr) const {
        if (addr < RAM_SIZE) return _ram[addr];
        return 0;
    }

    void writeWordRAM(uint32_t addr, uint8_t val) {
        if (addr < RAM_SIZE) _ram[addr] = val;
    }

private:
    void stopAllAudio() {
        _cdaPlaying = false;
        _pcmPlaying = false;
    }

    void playCDDATrack(uint8_t track) {
        _cdaTrack = track;
        _cdaPlaying = true;
    }

    void stopCDDA() {
        _cdaPlaying = false;
    }

    void setupPCMChannel(uint8_t ch) {
        _pcmPlaying = true;
    }

    void fadeAudio(uint8_t steps) {
        // Linear volume attenuation
        if (_pcmVolume >= steps) _pcmVolume -= steps;
        else _pcmVolume = 0;
    }

    uint8_t _ram[RAM_SIZE];
    uint8_t _commFlags = 0;
    uint8_t _cdaTrack = 0;
    uint8_t _pcmVolume = 0xFF;
    bool _cdaPlaying = false;
    bool _pcmPlaying = false;
};

} // namespace SegaCD
} // namespace SnatcherRE
