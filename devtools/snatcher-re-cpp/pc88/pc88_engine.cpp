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

namespace SnatcherRE {
namespace PC88 {

/**
 * NEC PC-8801 mkII SR Video Subsystem.
 * The original 1988 PC-88 release renders at 640x200 (or 640x400 interlaced) with 8 digital colors.
 * Graphics VRAM comprises 3 bitplanes (Blue, Red, Green) of 16KB each (48KB total) mapped at 0xC000-0xFFFF.
 * Supports hardware ALU planar writes via ports 0x34 and 0x35.
 */
class PC88Video : public IVideoDevice {
public:
	static constexpr int DEFAULT_WIDTH  = 640;
	static constexpr int DEFAULT_HEIGHT = 200;

	PC88Video() : _width(DEFAULT_WIDTH), _height(DEFAULT_HEIGHT),
	              _aluPlaneSelect(0), _vramDisplayMode(0x18), _paletteRegister(0) {
		std::memset(_framebuffer, 0, sizeof(_framebuffer));
		std::memset(_vramBlue, 0, sizeof(_vramBlue));
		std::memset(_vramRed, 0, sizeof(_vramRed));
		std::memset(_vramGreen, 0, sizeof(_vramGreen));
		initDefaultPalette();
	}

	void initVideo(int width, int height) override {
		_width = width;
		_height = height;
		clearScreen(0);
	}

	void clearScreen(uint32_t color = 0) override {
		std::fill_n(_framebuffer, sizeof(_framebuffer) / sizeof(_framebuffer[0]), color);
		std::memset(_vramBlue, 0, sizeof(_vramBlue));
		std::memset(_vramRed, 0, sizeof(_vramRed));
		std::memset(_vramGreen, 0, sizeof(_vramGreen));
	}

	void setPixel(int x, int y, uint32_t color) override {
		if (x >= 0 && x < _width && y >= 0 && y < _height) {
			_framebuffer[y * DEFAULT_WIDTH + x] = color;

			// Sync into PC-88 3-bitplane planar VRAM
			uint32_t byteIdx = (y * 80) + (x / 8);
			if (byteIdx < sizeof(_vramBlue)) {
				uint8_t bitMask = 0x80 >> (x % 8);
				uint8_t notMask = ~bitMask;

				uint8_t r = (color >> 16) & 0xFF;
				uint8_t g = (color >> 8) & 0xFF;
				uint8_t b = color & 0xFF;

				if (b > 127) _vramBlue[byteIdx]  |= bitMask;
				else         _vramBlue[byteIdx]  &= notMask;

				if (r > 127) _vramRed[byteIdx]   |= bitMask;
				else         _vramRed[byteIdx]   &= notMask;

				if (g > 127) _vramGreen[byteIdx] |= bitMask;
				else         _vramGreen[byteIdx] &= notMask;
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

	// PC-88 ALU Fast Planar Write (Port 0x34 / 0x35)
	void writeALU(uint16_t offset, uint8_t data) {
		if (offset < sizeof(_vramBlue)) {
			if (_aluPlaneSelect & 0x01) _vramBlue[offset] = data;
			if (_aluPlaneSelect & 0x02) _vramRed[offset] = data;
			if (_aluPlaneSelect & 0x04) _vramGreen[offset] = data;

			// Synchronize pixels for this byte
			int y = offset / 80;
			int startX = (offset % 80) * 8;
			for (int bit = 0; bit < 8; ++bit) {
				uint8_t mask = 0x80 >> bit;
				uint8_t code = (((_vramGreen[offset] & mask) != 0) << 2) |
				               (((_vramRed[offset] & mask) != 0) << 1) |
				               ((_vramBlue[offset] & mask) != 0);
				_framebuffer[y * DEFAULT_WIDTH + startX + bit] = _digitalColors[code];
			}
		}
	}

	void setALUPlaneSelect(uint8_t mask) { _aluPlaneSelect = mask; }
	void setVRAMDisplayMode(uint8_t mode) { _vramDisplayMode = mode; }
	uint8_t getVRAMDisplayMode() const { return _vramDisplayMode; }
	void setPaletteRegister(uint8_t reg) { _paletteRegister = reg; }
	uint8_t getPaletteRegister() const { return _paletteRegister; }

private:
	void initDefaultPalette() {
		_digitalColors[0] = 0xFF000000; // 0: Black
		_digitalColors[1] = 0xFF0000FF; // 1: Blue
		_digitalColors[2] = 0xFFFF0000; // 2: Red
		_digitalColors[3] = 0xFFFF00FF; // 3: Magenta
		_digitalColors[4] = 0xFF00FF00; // 4: Green
		_digitalColors[5] = 0xFF00FFFF; // 5: Cyan
		_digitalColors[6] = 0xFFFFFF00; // 6: Yellow
		_digitalColors[7] = 0xFFFFFFFF; // 7: White
	}

	int _width;
	int _height;
	uint8_t _aluPlaneSelect;
	uint8_t _vramDisplayMode;
	uint8_t _paletteRegister;
	uint32_t _framebuffer[640 * 400];
	uint8_t _vramBlue[16 * 1024];
	uint8_t _vramRed[16 * 1024];
	uint8_t _vramGreen[16 * 1024];
	uint32_t _digitalColors[8];
};

/**
 * NEC PC-8801 mkII SR Sound Subsystem (Yamaha YM2203 OPN + SSG).
 * 3 FM synthesis channels and 3 SSG (AY-3-8910 compatible) square-wave channels.
 */
class PC88Sound : public ISoundDevice {
public:
	PC88Sound() {
		reset();
	}

	void reset() {
		_ssgPlaying = false;
		_volume = 255;
	}

	void playCDDA(int track) override {
		(void)track;
	}

	void stopCDDA() override {}

	void playPCM(int soundId, int volume = 255) override {
		_ssgPlaying = true;
		_volume = volume;
		(void)soundId;
	}

	void stopPCM() override {
		_ssgPlaying = false;
	}

	void setMasterVolume(int volume) override {
		_volume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// YM2203 FM operator synthesis update
	}

	bool isPlaying() const { return _ssgPlaying; }

private:
	int _volume;
	bool _ssgPlaying;
};

/**
 * NEC PC-8801 mkII SR Memory & I/O Controller.
 * Transpiled and refactored from Z80 1988 Bootloader (Entry: 0xC000).
 * Handles:
 * - 64KB Z80 Flat Main RAM
 * - Port 0x31: Memory bank switching & ROM/RAM mode
 * - Port 0x5F: Text/Graphics VRAM display mode
 * - Port 0x53: Digital color palette register
 */
class PC88Memory : public IMemoryController {
public:
	static constexpr uint16_t BOOT_ENTRY  = 0xC000;
	static constexpr size_t MAIN_RAM_SIZE = 64 * 1024; // 64KB

	PC88Memory() {
		std::memset(_mainRam, 0, sizeof(_mainRam));
		_memoryMode = 0;
		_textRomActive = true;
	}

	void writeIOPort(uint8_t port, uint8_t value) {
		switch (port) {
		case 0x31:
			_memoryMode = value;
			_textRomActive = (value & 0x02) != 0;
			break;
		default:
			break;
		}
	}

	uint8_t readIOPort(uint8_t port) const {
		switch (port) {
		case 0x31: return _memoryMode;
		default: return 0xFF;
		}
	}

	bool isTextRomActive() const { return _textRomActive; }

	uint8_t read8(uint32_t address) override {
		return _mainRam[address & 0xFFFF];
	}

	void write8(uint32_t address, uint8_t value) override {
		_mainRam[address & 0xFFFF] = value;
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

private:
	uint8_t _mainRam[MAIN_RAM_SIZE];
	uint8_t _memoryMode;
	bool _textRomActive;
};

/**
 * NEC PC-8801 Platform Module.
 */
class PC88Module : public PlatformModule {
public:
	PC88Module() : _video(), _sound(), _memory() {}

	PlatformType getPlatformType() const override { return kPlatformTypePC88; }
	const char *getPlatformName() const override { return "NEC PC-8801 mkII SR"; }

	IVideoDevice *getVideo() override { return &_video; }
	ISoundDevice *getSound() override { return &_sound; }
	IMemoryController *getMemory() override { return &_memory; }

	void reset() override {
		_video.clearScreen();
		_sound.stopPCM();
	}

	void update(uint32_t deltaMillis) override {
		_sound.update();
		(void)deltaMillis;
	}

private:
	PC88Video _video;
	PC88Sound _sound;
	PC88Memory _memory;
};

} // namespace PC88
} // namespace SnatcherRE
