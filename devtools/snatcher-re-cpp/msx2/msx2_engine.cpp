/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../platform_hal.h"
#include <cstring>
#include <algorithm>
#include <string>

namespace SnatcherRE {
namespace MSX2 {

/**
 * MSX-DOS 37-byte File Control Block (FCB) Structure.
 * Used by SNATCHER.COM to access files via BDOS vector 0x0005.
 */
struct FCB {
	uint8_t drive;            // 0 = default, 1 = A:, 2 = B:, etc.
	char filename[8];         // 8-character space-padded filename
	char extension[3];        // 3-character space-padded extension
	uint16_t currentBlock;    // Current 128-record block
	uint16_t recordSize;      // Logical record size in bytes
	uint32_t fileSize;        // Total file size in bytes
	uint16_t date;            // Last modification date
	uint16_t time;            // Last modification time
	uint8_t deviceId;         // Internal device ID
	uint8_t directoryLocation;// Directory entry offset
	uint16_t topCluster;      // Starting cluster
	uint16_t lastCluster;     // Last accessed cluster
	uint16_t clusterOffset;   // Relative cluster offset
	uint8_t currentRecord;    // Current record within block (0-127)
	uint32_t randomRecord;    // Random record number for random I/O
};

/**
 * Yamaha V9938 Video Display Processor (VDP).
 * Snatcher MSX2 runs primarily in Screen 5 (256x212, 16 colors per line from a 512-color master palette)
 * and Screen 7 (512x212) with hardware VDP command acceleration (HMMC, LMMC, HMMV, YMMM).
 */
class MSX2Video : public IVideoDevice {
public:
	static constexpr int DEFAULT_WIDTH  = 256;
	static constexpr int DEFAULT_HEIGHT = 212;
	static constexpr size_t VRAM_SIZE   = 128 * 1024; // 128KB MSX2 VRAM

	MSX2Video() : _width(DEFAULT_WIDTH), _height(DEFAULT_HEIGHT) {
		std::memset(_framebuffer, 0, sizeof(_framebuffer));
		std::memset(_vram, 0, sizeof(_vram));
		initDefaultPalette();
	}

	void initVideo(int width, int height) override {
		_width = width;
		_height = height;
		clearScreen(0);
	}

	void clearScreen(uint32_t color = 0) override {
		std::fill_n(_framebuffer, sizeof(_framebuffer) / sizeof(_framebuffer[0]), color);
		std::memset(_vram, 0, sizeof(_vram));
	}

	void setPixel(int x, int y, uint32_t color) override {
		if (x >= 0 && x < _width && y >= 0 && y < _height) {
			_framebuffer[y * DEFAULT_WIDTH + x] = color;
			// Screen 5 bitmap layout: 2 pixels per byte (4 bits per pixel)
			uint32_t vramOffset = (y * 128) + (x / 2);
			if (vramOffset < sizeof(_vram)) {
				uint8_t palIdx = findClosestPaletteIndex(color);
				if ((x & 1) == 0) {
					_vram[vramOffset] = (_vram[vramOffset] & 0x0F) | (palIdx << 4);
				} else {
					_vram[vramOffset] = (_vram[vramOffset] & 0xF0) | (palIdx & 0x0F);
				}
			}
		}
	}

	uint32_t getPixel(int x, int y) const override {
		if (x >= 0 && x < _width && y >= 0 && y < _height) {
			return _framebuffer[y * DEFAULT_WIDTH + x];
		}
		return 0;
	}

	void renderFrame(uint8_t *targetBuffer, int pitch, int bpp) override {
		for (int y = 0; y < _height; ++y) {
			uint32_t *dst = reinterpret_cast<uint32_t *>(targetBuffer + y * pitch);
			const uint32_t *src = &_framebuffer[y * DEFAULT_WIDTH];
			for (int x = 0; x < _width; ++x) {
				dst[x] = src[x];
			}
		}
		(void)bpp;
	}

	int getWidth() const override { return _width; }
	int getHeight() const override { return _height; }

	// V9938 VDP Command Engine: HMMV (High-speed VRAM fill)
	void executeHMMV(int dx, int dy, int nx, int ny, uint8_t colorIndex) {
		uint32_t palColor = _palette[colorIndex & 0x0F];
		for (int cy = dy; cy < dy + ny && cy < _height; ++cy) {
			for (int cx = dx; cx < dx + nx && cx < _width; ++cx) {
				setPixel(cx, cy, palColor);
			}
		}
	}

	// V9938 VDP Command Engine: HMMC (High-speed CPU to VRAM transfer)
	void executeHMMC(int dx, int dy, int nx, int ny, const uint8_t *pixelData) {
		int srcIdx = 0;
		for (int cy = dy; cy < dy + ny && cy < _height; ++cy) {
			for (int cx = dx; cx < dx + nx && cx < _width; ++cx) {
				uint8_t palIdx = pixelData[srcIdx++];
				setPixel(cx, cy, _palette[palIdx & 0x0F]);
			}
		}
	}

	void setPaletteColor(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
		if (index < 16) {
			_palette[index] = (0xFF << 24) |
			                  (((r & 0x07) * 36) << 16) |
			                  (((g & 0x07) * 36) << 8) |
			                  ((b & 0x07) * 36);
		}
	}

private:
	void initDefaultPalette() {
		// Standard MSX2 16-color default palette
		_palette[0]  = 0xFF000000; // Transparent / Black
		_palette[1]  = 0xFF000000; // Black
		_palette[2]  = 0xFF24DC36; // Medium Green
		_palette[3]  = 0xFF65F077; // Light Green
		_palette[4]  = 0xFF5853FD; // Dark Blue
		_palette[5]  = 0xFF7D77FF; // Light Blue
		_palette[6]  = 0xFFD85342; // Dark Red
		_palette[7]  = 0xFF43DCEB; // Cyan
		_palette[8]  = 0xFFFC584C; // Medium Red
		_palette[9]  = 0xFFFF7B70; // Light Red
		_palette[10] = 0xFFD8D23B; // Dark Yellow
		_palette[11] = 0xFFE5DE67; // Light Yellow
		_palette[12] = 0xFF21B530; // Dark Green
		_palette[13] = 0xFFCA58B8; // Magenta
		_palette[14] = 0xFFCCCCCC; // Gray
		_palette[15] = 0xFFFFFFFF; // White
	}

	uint8_t findClosestPaletteIndex(uint32_t color) const {
		uint8_t bestIdx = 0;
		int bestDiff = 0x7FFFFFFF;
		int r = (color >> 16) & 0xFF;
		int g = (color >> 8) & 0xFF;
		int b = color & 0xFF;

		for (int i = 0; i < 16; ++i) {
			int pr = (_palette[i] >> 16) & 0xFF;
			int pg = (_palette[i] >> 8) & 0xFF;
			int pb = _palette[i] & 0xFF;
			int diff = (r - pr) * (r - pr) + (g - pg) * (g - pg) + (b - pb) * (b - pb);
			if (diff < bestDiff) {
				bestDiff = diff;
				bestIdx = i;
			}
		}
		return bestIdx;
	}

	int _width;
	int _height;
	uint32_t _framebuffer[512 * 212];
	uint8_t _vram[VRAM_SIZE];
	uint32_t _palette[16];
};

/**
 * Konami Sound Creative Chip (SCC) & PSG Sound Subsystem.
 * Memory mapped at 0x9000-0x97FF.
 * Features 5 wavetable channels (32 8-bit samples per wave), 12-bit frequency dividers,
 * and 4-bit per-channel volume.
 */
class MSX2Sound : public ISoundDevice {
public:
	struct SCCVoice {
		uint8_t waveform[32];
		uint16_t frequency = 0;
		uint8_t volume = 0;
		uint8_t sampleIdx = 0;
		bool enabled = false;
	};

	MSX2Sound() {
		reset();
	}

	void reset() {
		_sccChannelMask = 0;
		_masterVolume = 255;
		for (int i = 0; i < 5; ++i) {
			_voices[i] = SCCVoice();
			std::memset(_voices[i].waveform, 0, 32);
		}
	}

	void playCDDA(int track) override {
		// MSX2 cartridge audio plays via SCC wavetable synthesis and PSG
		(void)track;
	}

	void stopCDDA() override {}

	void playPCM(int soundId, int volume = 255) override {
		int ch = soundId % 5;
		_voices[ch].enabled = true;
		_voices[ch].volume = volume & 0x0F;
		_sccChannelMask |= (1 << ch);
	}

	void stopPCM() override {
		for (int i = 0; i < 5; ++i) {
			_voices[i].enabled = false;
		}
		_sccChannelMask = 0;
	}

	void setMasterVolume(int volume) override {
		_masterVolume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// Update SCC 5-channel wavetable synthesis phase accumulators
		for (int i = 0; i < 5; ++i) {
			if (_voices[i].enabled) {
				_voices[i].sampleIdx = (_voices[i].sampleIdx + 1) % 32;
			}
		}
	}

	// Writes to Konami SCC sound cartridge register area (0x9800 to 0x988F)
	void writeSCCRegister(uint16_t addr, uint8_t val) {
		if (addr >= 0x9800 && addr < 0x98A0) {
			int ch = (addr - 0x9800) / 32;
			int sample = (addr - 0x9800) % 32;
			if (ch < 5) _voices[ch].waveform[sample] = val;
		} else if (addr >= 0x98A0 && addr < 0x98AA) {
			int ch = (addr - 0x98A0) / 2;
			if ((addr & 1) == 0) _voices[ch].frequency = (_voices[ch].frequency & 0x0F00) | val;
			else                 _voices[ch].frequency = (_voices[ch].frequency & 0x00FF) | ((val & 0x0F) << 8);
		} else if (addr >= 0x98AA && addr < 0x98AF) {
			int ch = addr - 0x98AA;
			_voices[ch].volume = val & 0x0F;
		} else if (addr == 0x98AF) {
			_sccChannelMask = val & 0x1F;
			for (int i = 0; i < 5; ++i) {
				_voices[i].enabled = (_sccChannelMask & (1 << i)) != 0;
			}
		}
	}

private:
	uint8_t _sccChannelMask;
	int _masterVolume;
	SCCVoice _voices[5];
};

/**
 * MSX2 64KB Z80 Main RAM, BDOS Emulation & Primary/Secondary Slot Mapper.
 * Transpiled and refactored from SNATCHER.COM entry @ ram:0100.
 */
class MSX2Memory : public IMemoryController {
public:
	static constexpr uint16_t BDOS_VECTOR = 0x0005;

	MSX2Memory() : _dmaAddress(0x0080), _isHardDiskBoot(false) {
		std::memset(_tpaRam, 0, sizeof(_tpaRam));
		std::memset(_mapperRam, 0, sizeof(_mapperRam));
		_primarySlot = 0;
		_secondarySlot = 0;
	}

	uint8_t read8(uint32_t address) override {
		uint16_t addr16 = address & 0xFFFF;
		if (addr16 >= 0x9000 && addr16 <= 0x97FF) {
			return 0xFF; // SCC read
		}
		return _tpaRam[addr16];
	}

	void write8(uint32_t address, uint8_t value) override {
		uint16_t addr16 = address & 0xFFFF;
		if (addr16 == 0x00A8) {
			_primarySlot = value;
		} else if (addr16 == 0xFFFF) {
			_secondarySlot = value;
		} else {
			_tpaRam[addr16] = value;
		}
	}

	uint16_t read16(uint32_t address) override {
		// Little-Endian (Z80)
		uint8_t lo = read8(address);
		uint8_t hi = read8(address + 1);
		return static_cast<uint16_t>(lo | (hi << 8));
	}

	void write16(uint32_t address, uint16_t value) override {
		write8(address, static_cast<uint8_t>(value & 0xFF));
		write8(address + 1, static_cast<uint8_t>((value >> 8) & 0xFF));
	}

	uint32_t read32(uint32_t address) override {
		uint16_t lo = read16(address);
		uint16_t hi = read16(address + 2);
		return static_cast<uint32_t>(lo | (hi << 16));
	}

	void write32(uint32_t address, uint32_t value) override {
		write16(address, static_cast<uint16_t>(value & 0xFFFF));
		write16(address + 2, static_cast<uint16_t>((value >> 16) & 0xFFFF));
	}

	void setDMAAddress(uint16_t addr) { _dmaAddress = addr; }
	uint16_t getDMAAddress() const { return _dmaAddress; }

	void setHardDiskMode(bool isHD) { _isHardDiskBoot = isHD; }
	bool isHardDiskMode() const { return _isHardDiskBoot; }

private:
	uint8_t _tpaRam[64 * 1024];        // 64KB Transient Program Area
	uint8_t _mapperRam[512 * 1024];    // 512KB Expanded Memory Mapper
	uint16_t _dmaAddress;
	uint8_t _primarySlot;
	uint8_t _secondarySlot;
	bool _isHardDiskBoot;
};

/**
 * MSX2 Platform Module.
 */
class MSX2Module : public PlatformModule {
public:
	MSX2Module() : _video(), _sound(), _memory() {}

	PlatformType getPlatformType() const override { return kPlatformTypeMSX2; }
	const char *getPlatformName() const override { return "MSX2 (Konami SNATCHER.COM)"; }

	IVideoDevice *getVideo() override { return &_video; }
	ISoundDevice *getSound() override { return &_sound; }
	IMemoryController *getMemory() override { return &_memory; }
	MSX2Sound &getSCC() { return _sound; }

	void reset() override {
		_video.clearScreen();
		_sound.stopPCM();
	}

	void update(uint32_t deltaMillis) override {
		_sound.update();
		(void)deltaMillis;
	}

	// Emulates BDOS call vector 0x0005 (Refactored from entry @ ram:0100)
	uint8_t callBDOS(uint8_t func, uint16_t de) {
		switch (func) {
		case 0x09: // Output String ($ terminated)
			return 0;
		case 0x1A: // Set DMA Address
			_memory.setDMAAddress(de);
			return 0;
		case 0x6F: // Get Disk Parameters (Checks Floppy vs Hard Disk)
			_memory.setHardDiskMode(true);
			return 0;
		default:
			return 0;
		}
	}

private:
	MSX2Video _video;
	MSX2Sound _sound;
	MSX2Memory _memory;
};

} // namespace MSX2
} // namespace SnatcherRE
