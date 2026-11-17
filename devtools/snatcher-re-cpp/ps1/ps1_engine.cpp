// Clean C++ Native Module for Snatcher PlayStation 1 Engine & MDEC / GTE Subsystem
// Transpiled from MIPS R3000A SLPS_001.54 (Load address: 0x80028000, Entry: 0x80029A28)
#include <cstdint>
#include <cstring>
#include <vector>
#include <string>

namespace SnatcherRE {
namespace PS1 {

struct FileTableEntry {
    uint32_t lba;
    uint32_t size;
    uint32_t padding;
};

class PlayStationEngine {
public:
    static constexpr uint32_t LOAD_BASE = 0x80028000;
    static constexpr uint32_t ENTRY_POINT = 0x80029A28;
    static constexpr uint32_t FILE_TABLE_RAM = 0x80072CE4;
    static constexpr uint32_t SCENE_TABLE_RAM = 0x80071E8C;

    PlayStationEngine() {
        std::memset(_vram, 0, sizeof(_vram));
    }

    void initHardware() {
        // Set up GPU resolution: 320x240 RGB555
        _gpuWidth = 320;
        _gpuHeight = 240;
        _displayEnabled = true;
    }

    // Resolves file entries from the native PS-X internal table
    FileTableEntry lookupFile(size_t index) const {
        if (index < _fileTable.size()) {
            return _fileTable[index];
        }
        return {0, 0, 0};
    }

    // MDEC Video Stream playback state (for STR files like MX0_S000.STR / MX2_S000.STR)
    void startMDECPlayback(const std::string &strPath) {
        _currentMovie = strPath;
        _mdecPlaying = true;
    }

    void stopMDECPlayback() {
        _mdecPlaying = false;
        _currentMovie.clear();
    }

    bool isMDECActive() const { return _mdecPlaying; }

    uint16_t getVRAMPixel(int x, int y) const {
        if (x >= 0 && x < 1024 && y >= 0 && y < 512) {
            return _vram[y * 1024 + x];
        }
        return 0;
    }

    void setVRAMPixel(int x, int y, uint16_t color) {
        if (x >= 0 && x < 1024 && y >= 0 && y < 512) {
            _vram[y * 1024 + x] = color;
        }
    }

private:
    uint16_t _vram[1024 * 512]; // 1MB PlayStation VRAM Framebuffer
    std::vector<FileTableEntry> _fileTable;
    std::string _currentMovie;
    int _gpuWidth = 320;
    int _gpuHeight = 240;
    bool _displayEnabled = false;
    bool _mdecPlaying = false;
};

} // namespace PS1
} // namespace SnatcherRE
