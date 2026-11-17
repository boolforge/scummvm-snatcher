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
#include <vector>

namespace SnatcherRE {
namespace PCEngine {

/**
 * PC Engine Super CD-ROM² 8-Byte File Table Record.
 * Located in Stage 2 resident engine at $5505 (Group 0), $5535 (Group 1 - 33 scene modules),
 * $563D (Group 3 - ADPCM voice tables), and $566D (Group 2 - scene picture blocks).
 */
struct PCERecord {
	uint8_t recHi;
	uint8_t recLo;
	uint8_t recMid;
	uint8_t mode;
	uint8_t bank;
	uint8_t bh;
	uint8_t sectors;
	uint8_t pad;

	uint32_t getRecordNumber() const {
		return (static_cast<uint32_t>(recHi) << 16) |
		       (static_cast<uint32_t>(recMid) << 8) |
		       recLo;
	}

	// Track 2 starts at sector 4174
	uint32_t getAbsoluteSector(uint32_t track2Start = 4174) const {
		return track2Start + getRecordNumber();
	}
};

/**
 * PC Engine Video Subsystem (HuC6270 VDC + HuC6260 VCE).
 * Snatcher PCE runs at 256x224 (and 320x224 during select cinematic sequences)
 * using a 9-bit master color palette (512 colors total, 16 sub-palettes of 16 colors each).
 */
class PCEngineVideo : public IVideoDevice {
public:
	static constexpr int DEFAULT_WIDTH  = 256;
	static constexpr int DEFAULT_HEIGHT = 224;
	static constexpr size_t VDC_VRAM_SIZE = 64 * 1024; // 64KB VRAM

	PCEngineVideo() : _width(DEFAULT_WIDTH), _height(DEFAULT_HEIGHT) {
		std::memset(_framebuffer, 0, sizeof(_framebuffer));
		std::memset(_vram, 0, sizeof(_vram));
		std::memset(_paletteTable, 0, sizeof(_paletteTable));
		initDefaultPalette();
	}

	void initVideo(int width, int height) override {
		_width = width;
		_height = height;
		clearScreen(0);
	}

	void clearScreen(uint32_t color = 0) override {
		std::fill_n(_framebuffer, sizeof(_framebuffer) / sizeof(_framebuffer[0]), color);
	}

	void setPixel(int x, int y, uint32_t color) override {
		if (x >= 0 && x < _width && y >= 0 && y < _height) {
			_framebuffer[y * DEFAULT_WIDTH + x] = color;
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

	// HuC6260 9-bit Palette Register (Format: 0000000G GGRRRBBB)
	void setPaletteColor(uint8_t index, uint16_t vceColor) {
		uint8_t r = ((vceColor >> 3) & 0x07) * 36;
		uint8_t g = ((vceColor >> 6) & 0x07) * 36;
		uint8_t b = (vceColor & 0x07) * 36;
		_paletteTable[index] = (0xFF << 24) | (r << 16) | (g << 8) | b;
	}

	uint32_t getPaletteColor(uint8_t index) const {
		return _paletteTable[index];
	}

	// HuC6270 Tile Map Render: draws an 8x8 pattern from VRAM
	void drawPattern(int x, int y, uint16_t patternId, uint8_t paletteIndex) {
		uint32_t palOffset = (paletteIndex & 0x0F) * 16;
		uint32_t vramOffset = patternId * 32;

		if (vramOffset + 32 <= sizeof(_vram)) {
			for (int row = 0; row < 8; ++row) {
				uint8_t plane0 = _vram[vramOffset + row * 2];
				uint8_t plane1 = _vram[vramOffset + row * 2 + 1];
				uint8_t plane2 = _vram[vramOffset + 16 + row * 2];
				uint8_t plane3 = _vram[vramOffset + 16 + row * 2 + 1];

				for (int col = 0; col < 8; ++col) {
					int bit = 7 - col;
					uint8_t colorIdx = (((plane3 >> bit) & 1) << 3) |
					                   (((plane2 >> bit) & 1) << 2) |
					                   (((plane1 >> bit) & 1) << 1) |
					                   ((plane0 >> bit) & 1);
					if (colorIdx != 0) { // Color 0 is transparent
						setPixel(x + col, y + row, _paletteTable[palOffset + colorIdx]);
					}
				}
			}
		}
	}

private:
	void initDefaultPalette() {
		for (int i = 0; i < 512; ++i) {
			_paletteTable[i] = 0xFF000000 | (i << 16) | (i << 8) | i;
		}
	}

	int _width;
	int _height;
	uint32_t _framebuffer[512 * 240];
	uint8_t _vram[VDC_VRAM_SIZE];
	uint32_t _paletteTable[512];
};

/**
 * PC Engine Super CD-ROM² Sound Subsystem.
 * Includes HuC6280 6-channel PSG (wavetable synthesis), Oki MSM5205 ADPCM (32KB RAM),
 * and System Card CD-DA audio playback across tracks 3-24.
 */
class PCEngineSound : public ISoundDevice {
public:
	struct PSGChannel {
		uint8_t waveform[32];
		uint16_t frequency = 0;
		uint8_t volume = 0;
		uint8_t panLeft = 15;
		uint8_t panRight = 15;
		bool enabled = false;
	};

	PCEngineSound() {
		reset();
	}

	void reset() {
		_cddaTrack = 0;
		_cddaPlaying = false;
		_adpcmPlaying = false;
		_masterVolume = 255;
		std::memset(_adpcmBuffer, 0, sizeof(_adpcmBuffer));
		for (int i = 0; i < 6; ++i) {
			_psgChannels[i] = PSGChannel();
			std::memset(_psgChannels[i].waveform, 0, 32);
		}
	}

	void playCDDA(int track) override {
		_cddaTrack = track;
		_cddaPlaying = true;
	}

	void stopCDDA() override {
		_cddaPlaying = false;
	}

	void playPCM(int soundId, int volume = 255) override {
		_adpcmPlaying = true;
		(void)soundId;
		(void)volume;
	}

	void stopPCM() override {
		_adpcmPlaying = false;
	}

	void setMasterVolume(int volume) override {
		_masterVolume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// HuC6280 PSG wavetable buffer tick & ADPCM streaming update
	}

	bool isCDDAPlaying() const { return _cddaPlaying; }
	int getCDDATrack() const { return _cddaTrack; }

private:
	int _cddaTrack;
	bool _cddaPlaying;
	bool _adpcmPlaying;
	int _masterVolume;
	uint8_t _adpcmBuffer[32 * 1024]; // 32KB ADPCM Buffer
	PSGChannel _psgChannels[6];
};

/**
 * PC Engine Super CD-ROM² Memory Controller.
 * Transpiled and refactored from HuC6280 65C02 bytecode and Memory Mapping Registers (TAM/TMA).
 * Resolves 8 Memory Page Registers (MPR0-MPR7) mapping 8KB windows into:
 * - Bank 0x00-0x03: System Card 3.0 ROM (384KB)
 * - Bank 0x68-0x7F: Super CD-ROM² 192KB WRAM (Stage 2 resident engine at $4000)
 * - Bank 0xF7: 2KB Battery-backed Backup RAM (BRAM)
 * - Bank 0xF8-0xFB: 8KB Main RAM
 * - Bank 0xFF: I/O Hardware Registers (VDC, VCE, Timer, PSG, IRQ)
 */
class PCEngineMemory : public IMemoryController {
public:
	static constexpr size_t SUPER_CD_RAM_SIZE = 192 * 1024; // 192KB Super CD-ROM² RAM
	static constexpr size_t MAIN_RAM_SIZE     = 8 * 1024;   // 8KB Core HuCard RAM
	static constexpr size_t BRAM_SIZE         = 2 * 1024;   // 2KB BRAM

	PCEngineMemory() {
		std::memset(_superCdRam, 0, sizeof(_superCdRam));
		std::memset(_mainRam, 0, sizeof(_mainRam));
		std::memset(_bram, 0, sizeof(_bram));
		std::memset(_mpr, 0, sizeof(_mpr));
		// Default Super CD-ROM² bank mapping
		_mpr[0] = 0xFF; // I/O page
		_mpr[1] = 0xF8; // Main RAM
		_mpr[2] = 0x68; // Super RAM Bank 0 (Stage 2 Resident at $4000)
		_mpr[3] = 0x69; // Super RAM Bank 1 (Object walker at $6000)
		_mpr[4] = 0x6A; // Super RAM Bank 2 (Text decoder at $8000)
		_mpr[5] = 0x6B; // Super RAM Bank 3 (Scene module at $A000)
		_mpr[6] = 0x6C; // Super RAM Bank 4 (Scene graphics at $C000)
		_mpr[7] = 0x00; // System ROM / Boot
	}

	void writeMPR(uint8_t mprIndex, uint8_t bank) {
		if (mprIndex < 8) {
			_mpr[mprIndex] = bank;
		}
	}

	uint8_t readMPR(uint8_t mprIndex) const {
		if (mprIndex < 8) return _mpr[mprIndex];
		return 0;
	}

	uint8_t read8(uint32_t address) override {
		uint8_t page = (address >> 13) & 0x07;
		uint16_t offset = address & 0x1FFF;
		uint8_t bank = _mpr[page];

		if (bank >= 0x68 && bank <= 0x7F) {
			uint32_t superOffset = ((bank - 0x68) * 0x2000) + offset;
			if (superOffset < sizeof(_superCdRam)) {
				return _superCdRam[superOffset];
			}
		} else if (bank >= 0xF8 && bank <= 0xFB) {
			return _mainRam[offset % MAIN_RAM_SIZE];
		} else if (bank == 0xF7) {
			return _bram[offset % BRAM_SIZE];
		}
		return 0xFF;
	}

	void write8(uint32_t address, uint8_t value) override {
		uint8_t page = (address >> 13) & 0x07;
		uint16_t offset = address & 0x1FFF;
		uint8_t bank = _mpr[page];

		if (bank >= 0x68 && bank <= 0x7F) {
			uint32_t superOffset = ((bank - 0x68) * 0x2000) + offset;
			if (superOffset < sizeof(_superCdRam)) {
				_superCdRam[superOffset] = value;
			}
		} else if (bank >= 0xF8 && bank <= 0xFB) {
			_mainRam[offset % MAIN_RAM_SIZE] = value;
		} else if (bank == 0xF7) {
			_bram[offset % BRAM_SIZE] = value;
		}
	}

	uint16_t read16(uint32_t address) override {
		// Little-Endian (65C02 architecture)
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

private:
	uint8_t _superCdRam[SUPER_CD_RAM_SIZE];
	uint8_t _mainRam[MAIN_RAM_SIZE];
	uint8_t _bram[BRAM_SIZE];
	uint8_t _mpr[8];
};

/**
 * PC Engine Super CD-ROM² Platform Module.
 */
class PCEngineModule : public PlatformModule {
public:
	PCEngineModule() : _video(), _sound(), _memory() {}

	PlatformType getPlatformType() const override { return kPlatformTypePCEngine; }
	const char *getPlatformName() const override { return "NEC PC Engine Super CD-ROM²"; }

	IVideoDevice *getVideo() override { return &_video; }
	ISoundDevice *getSound() override { return &_sound; }
	IMemoryController *getMemory() override { return &_memory; }

	void reset() override {
		_video.clearScreen();
		_sound.stopCDDA();
		_sound.stopPCM();
	}

	void update(uint32_t deltaMillis) override {
		_sound.update();
		(void)deltaMillis;
	}

private:
	PCEngineVideo _video;
	PCEngineSound _sound;
	PCEngineMemory _memory;
};

} // namespace PCEngine
} // namespace SnatcherRE
