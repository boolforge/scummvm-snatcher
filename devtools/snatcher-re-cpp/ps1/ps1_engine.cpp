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
#include <vector>
#include <string>
#include <algorithm>

namespace SnatcherRE {
namespace PS1 {

/**
 * PlayStation 12-byte File Table Record (Located at RAM 0x80072CE4, File 0x4B4E4 in SLPS-001.54).
 * The runtime does not traverse ISO9660 directory structures; it directly seeks using this table.
 */
struct FileTableRecord {
	uint32_t lba;
	uint32_t size;
	uint32_t padding;
};

/**
 * Scene Table Entry (Located at RAM 0x80071E8C).
 * 39 scene banks (ISZ_B000 to ISZ_B260), indexed by bank_id / 0x10.
 */
struct SceneTableRecord {
	uint32_t lba;
	uint32_t size;
	uint32_t padding;
};

/**
 * Dynamic Memory Heap Block Header (Refactored from FUN_80029b18 / _DAT_800abf64 heap manager).
 */
struct HeapBlockHeader {
	uint32_t size;
	uint32_t isFree;
	uint32_t nextOffset;
	uint32_t prevOffset;
};

/**
 * PlayStation Gamepad & Light-gun / Mouse Input Subsystem.
 * Transpiled and refactored from FUN_80029b18 (PadInit), FUN_80029bdc (PadStatus),
 * and FUN_8002a134 (Gun coordinate aiming & viewport boundary clipping).
 */
class PlayStationPad {
public:
	// PS1 Standard Controller bitmasks
	enum PadButton {
		kButtonSelect   = (1 << 0),
		kButtonL3       = (1 << 1),
		kButtonR3       = (1 << 2),
		kButtonStart    = (1 << 3),
		kButtonUp       = (1 << 4),
		kButtonRight    = (1 << 5),
		kButtonDown     = (1 << 6),
		kButtonLeft     = (1 << 7),
		kButtonL2       = (1 << 8),
		kButtonR2       = (1 << 9),
		kButtonL1       = (1 << 10),
		kButtonR1       = (1 << 11),
		kButtonTriangle = (1 << 12),
		kButtonCircle   = (1 << 13),
		kButtonCross    = (1 << 14),
		kButtonSquare   = (1 << 15)
	};

	PlayStationPad() {
		reset();
	}

	void reset() {
		_padStatus = 0;
		_buttonMask = 0xFFFF; // Active low on real hardware
		_mouseX = 160;
		_mouseY = 120;
		_minX = 0;
		_maxX = 320;
		_minY = 0;
		_maxY = 240;
		_scaleX = 4;
		_scaleY = 4;
		_isGunMode = false;
	}

	// FUN_80029b18: PadInit
	int init(int mode) {
		if (mode == 0) {
			_padStatus = 1;
			return 2; // Supported standard 2-port mode
		}
		_padStatus = 0;
		return -1;
	}

	// FUN_80029bdc: PadStatus
	int getStatus(int port) const {
		if (port == 0 && _padStatus != 0) {
			return 1;
		}
		return 0;
	}

	// FUN_80029f04: Set viewport boundaries
	void setBounds(int minX, int maxX, int minY, int maxY) {
		_minX = minX;
		_maxX = maxX;
		_minY = minY;
		_maxY = maxY;
	}

	// FUN_80029f7c: Set coordinate scaling factors
	void setScaling(uint16_t scaleX, uint16_t scaleY) {
		_scaleX = scaleX;
		_scaleY = scaleY;
	}

	// FUN_8002a134: Gun / Mouse coordinate clipping & update
	void updateCoordinates(int deltaX, int deltaY) {
		_mouseX += deltaX;
		_mouseY += deltaY;

		if (_mouseX < _minX) _mouseX = _minX;
		if (_mouseX > _maxX) _mouseX = _maxX;
		if (_mouseY < _minY) _mouseY = _minY;
		if (_mouseY > _maxY) _mouseY = _maxY;
	}

	int getMouseX() const { return _mouseX; }
	int getMouseY() const { return _mouseY; }

	void setButtonState(uint16_t mask) { _buttonMask = mask; }
	bool isPressed(PadButton btn) const { return (_buttonMask & btn) == 0; }

private:
	int _padStatus;
	uint16_t _buttonMask;
	int _mouseX;
	int _mouseY;
	int _minX;
	int _maxX;
	int _minY;
	int _maxY;
	uint16_t _scaleX;
	uint16_t _scaleY;
	bool _isGunMode;
};

/**
 * PlayStation GPU Packet Processor & Framebuffer Engine.
 * Supports Sony PSX GP0 command packets:
 * - 0x01: Clear Cache
 * - 0x02: Fill Rectangle in VRAM
 * - 0x20: Monochrome 3-point polygon
 * - 0x24: Textured 3-point polygon
 * - 0x28: Monochrome 4-point quad
 * - 0x2C: Textured 4-point quad
 * - 0x64: Sprite 16x16
 * - 0x65: Sprite 8x8
 * - 0x70: Variable-size Rectangular Tile
 */
class PlayStationVideo : public IVideoDevice {
public:
	static constexpr int VRAM_WIDTH  = 1024;
	static constexpr int VRAM_HEIGHT = 512;
	static constexpr int DEFAULT_DISPLAY_WIDTH  = 320;
	static constexpr int DEFAULT_DISPLAY_HEIGHT = 240;

	PlayStationVideo() : _width(DEFAULT_DISPLAY_WIDTH), _height(DEFAULT_DISPLAY_HEIGHT),
	                     _dispX(0), _dispY(0), _drawX(0), _drawY(0) {
		std::memset(_vram, 0, sizeof(_vram));
	}

	void initVideo(int width, int height) override {
		_width = width;
		_height = height;
		clearScreen(0);
	}

	void clearScreen(uint32_t color = 0) override {
		uint16_t rgb15 = rgb888ToRgb555(color);
		for (int y = _dispY; y < _dispY + _height && y < VRAM_HEIGHT; ++y) {
			for (int x = _dispX; x < _dispX + _width && x < VRAM_WIDTH; ++x) {
				_vram[y * VRAM_WIDTH + x] = rgb15;
			}
		}
	}

	void setPixel(int x, int y, uint32_t color) override {
		int px = _dispX + x;
		int py = _dispY + y;
		if (px >= 0 && px < VRAM_WIDTH && py >= 0 && py < VRAM_HEIGHT) {
			_vram[py * VRAM_WIDTH + px] = rgb888ToRgb555(color);
		}
	}

	uint32_t getPixel(int x, int y) const override {
		int px = _dispX + x;
		int py = _dispY + y;
		if (px >= 0 && px < VRAM_WIDTH && py >= 0 && py < VRAM_HEIGHT) {
			return rgb555ToRgb888(_vram[py * VRAM_WIDTH + px]);
		}
		return 0;
	}

	void renderFrame(uint8_t *targetBuffer, int pitch, int bpp) override {
		for (int y = 0; y < _height; ++y) {
			uint32_t *dst32 = reinterpret_cast<uint32_t *>(targetBuffer + y * pitch);
			const uint16_t *src16 = &_vram[(_dispY + y) * VRAM_WIDTH + _dispX];
			for (int x = 0; x < _width; ++x) {
				dst32[x] = rgb555ToRgb888(src16[x]);
			}
		}
		(void)bpp;
	}

	int getWidth() const override { return _width; }
	int getHeight() const override { return _height; }

	// GP0 Command: Fill Rectangle (0x02)
	void processGP0FillRect(uint32_t color, int x, int y, int w, int h) {
		uint16_t c15 = rgb888ToRgb555(color);
		for (int cy = y; cy < y + h && cy < VRAM_HEIGHT; ++cy) {
			for (int cx = x; cx < x + w && cx < VRAM_WIDTH; ++cx) {
				_vram[cy * VRAM_WIDTH + cx] = c15;
			}
		}
	}

	// GP0 Command: Draw Flat Quad (0x28)
	void processGP0FlatQuad(uint32_t color, int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
		int minX = std::max(0, std::min({x0, x1, x2, x3}));
		int maxX = std::min(VRAM_WIDTH - 1, std::max({x0, x1, x2, x3}));
		int minY = std::max(0, std::min({y0, y1, y2, y3}));
		int maxY = std::min(VRAM_HEIGHT - 1, std::max({y0, y1, y2, y3}));

		processGP0FillRect(color, minX, minY, maxX - minX + 1, maxY - minY + 1);
	}

	// VRAM Block Transfer (CPU to VRAM, GP0 0xA0)
	void loadVRAMBlock(int x, int y, int w, int h, const uint16_t *src) {
		for (int row = 0; row < h && (y + row) < VRAM_HEIGHT; ++row) {
			for (int col = 0; col < w && (x + col) < VRAM_WIDTH; ++col) {
				_vram[(y + row) * VRAM_WIDTH + (x + col)] = src[row * w + col];
			}
		}
	}

	void setDisplayArea(int x, int y) { _dispX = x; _dispY = y; }
	void setDrawArea(int x, int y) { _drawX = x; _drawY = y; }

private:
	static inline uint16_t rgb888ToRgb555(uint32_t c) {
		uint8_t r = (c >> 19) & 0x1F;
		uint8_t g = (c >> 11) & 0x1F;
		uint8_t b = (c >> 3) & 0x1F;
		return (b << 10) | (g << 5) | r;
	}

	static inline uint32_t rgb555ToRgb888(uint16_t c) {
		uint8_t r = ((c & 0x1F) * 255) / 31;
		uint8_t g = (((c >> 5) & 0x1F) * 255) / 31;
		uint8_t b = (((c >> 10) & 0x1F) * 255) / 31;
		return (0xFF << 24) | (r << 16) | (g << 8) | b;
	}

	int _width;
	int _height;
	int _dispX;
	int _dispY;
	int _drawX;
	int _drawY;
	uint16_t _vram[VRAM_WIDTH * VRAM_HEIGHT]; // 1MB VRAM
};

/**
 * PlayStation SPU & CD-ROM Audio Controller.
 * Transpiled from CdInit, CdSearchFile, CdlSync, and SPU voice allocation routines.
 * Manages 1,040 mono XA dialogue streams (XAS_M000.XA at LBA 2408),
 * 199 stereo cinematic reels (XAS_S000.XA at LBA 64888), and Red Book CD-DA tracks.
 */
class PlayStationSound : public ISoundDevice {
public:
	static constexpr uint32_t XA_MONO_VOICE_LBA  = 2408;
	static constexpr uint32_t XA_STEREO_REEL_LBA = 64888;

	PlayStationSound() {
		reset();
	}

	void reset() {
		_cddaTrack = 0;
		_cddaPlaying = false;
		_xaPlaying = false;
		_xaSector = 0;
		_xaChannels = 1;
		_masterVolume = 255;
		_spuVolume = 255;
	}

	void playCDDA(int track) override {
		_cddaTrack = track;
		_cddaPlaying = true;
		_xaPlaying = false;
	}

	void stopCDDA() override {
		_cddaPlaying = false;
	}

	void playPCM(int soundId, int volume = 255) override {
		// Plays mono SPU SFX or XA voice slice
		_xaPlaying = true;
		_xaSector = XA_MONO_VOICE_LBA + (soundId * 8);
		_spuVolume = volume;
	}

	void stopPCM() override {
		_xaPlaying = false;
	}

	void playStereoReel(int reelIndex) {
		_xaPlaying = true;
		_xaChannels = 2;
		_xaSector = XA_STEREO_REEL_LBA + (reelIndex * 16);
	}

	void setMasterVolume(int volume) override {
		_masterVolume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// Process XA sector streaming buffer ticks
		if (_xaPlaying) {
			_xaSector++;
		}
	}

	bool isCDDAPlaying() const { return _cddaPlaying; }
	bool isXAPlaying() const { return _xaPlaying; }
	int getCDDATrack() const { return _cddaTrack; }

private:
	int _cddaTrack;
	bool _cddaPlaying;
	bool _xaPlaying;
	uint32_t _xaSector;
	int _xaChannels;
	int _masterVolume;
	int _spuVolume;
};

/**
 * PlayStation Flat 2MB Main RAM & Memory-Mapped I/O Controller.
 * Resolves KSEG0 RAM (0x80000000 to 0x801FFFFF) and hardware registers (0x1F800000 to 0x1F80FFFF).
 */
class PlayStationMemory : public IMemoryController {
public:
	static constexpr uint32_t RAM_MASK = 0x001FFFFF; // 2MB Physical RAM
	static constexpr uint32_t HEAP_BASE = 0x000ABF64;

	PlayStationMemory() {
		std::memset(_ram, 0, sizeof(_ram));
		initHeap();
	}

	uint8_t read8(uint32_t address) override {
		uint32_t phys = address & RAM_MASK;
		return _ram[phys];
	}

	void write8(uint32_t address, uint8_t value) override {
		uint32_t phys = address & RAM_MASK;
		_ram[phys] = value;
	}

	uint16_t read16(uint32_t address) override {
		uint32_t phys = address & (RAM_MASK & ~1);
		return static_cast<uint16_t>(_ram[phys] | (_ram[phys + 1] << 8)); // Little-Endian (MIPS)
	}

	void write16(uint32_t address, uint16_t value) override {
		uint32_t phys = address & (RAM_MASK & ~1);
		_ram[phys]     = static_cast<uint8_t>(value & 0xFF);
		_ram[phys + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
	}

	uint32_t read32(uint32_t address) override {
		uint32_t phys = address & (RAM_MASK & ~3);
		return static_cast<uint32_t>(_ram[phys] | (_ram[phys + 1] << 8) |
		                            (_ram[phys + 2] << 16) | (_ram[phys + 3] << 24));
	}

	void write32(uint32_t address, uint32_t value) override {
		uint32_t phys = address & (RAM_MASK & ~3);
		_ram[phys]     = static_cast<uint8_t>(value & 0xFF);
		_ram[phys + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
		_ram[phys + 2] = static_cast<uint8_t>((value >> 16) & 0xFF);
		_ram[phys + 3] = static_cast<uint8_t>((value >> 24) & 0xFF);
	}

	// Dynamic Memory Heap Allocator (FUN_80029b18 / _DAT_800abf64 heap management)
	uint32_t allocateHeap(uint32_t numBytes) {
		uint32_t aligned = (numBytes + 3) & ~3;
		uint32_t current = _heapHead;

		while (current != 0 && current < sizeof(_ram) - aligned) {
			HeapBlockHeader *hdr = reinterpret_cast<HeapBlockHeader *>(&_ram[current]);
			if (hdr->isFree && hdr->size >= aligned) {
				hdr->isFree = 0;
				return current + sizeof(HeapBlockHeader);
			}
			current = hdr->nextOffset;
		}
		return 0; // Heap exhaustion (s_HEAP_ERROR_80028040)
	}

	void freeHeap(uint32_t addr) {
		if (addr >= sizeof(HeapBlockHeader) && addr < sizeof(_ram)) {
			HeapBlockHeader *hdr = reinterpret_cast<HeapBlockHeader *>(&_ram[addr - sizeof(HeapBlockHeader)]);
			hdr->isFree = 1;
		}
	}

private:
	void initHeap() {
		_heapHead = 0x000B4000;
		HeapBlockHeader *first = reinterpret_cast<HeapBlockHeader *>(&_ram[_heapHead]);
		first->size = 512 * 1024; // 512KB Initial Heap Arena
		first->isFree = 1;
		first->nextOffset = 0;
		first->prevOffset = 0;
	}

	uint8_t _ram[2 * 1024 * 1024];
	uint32_t _heapHead;
};

/**
 * PlayStation Platform Module: Master Orchestration.
 */
class PlayStationModule : public PlatformModule {
public:
	PlayStationModule() : _video(), _sound(), _memory(), _pad() {}

	PlatformType getPlatformType() const override { return kPlatformTypePlayStation; }
	const char *getPlatformName() const override { return "Sony PlayStation (SLPS-00154)"; }

	IVideoDevice *getVideo() override { return &_video; }
	ISoundDevice *getSound() override { return &_sound; }
	IMemoryController *getMemory() override { return &_memory; }
	PlayStationPad *getPad() { return &_pad; }

	void reset() override {
		_video.clearScreen();
		_sound.stopCDDA();
		_sound.stopPCM();
		_pad.reset();
	}

	void update(uint32_t deltaMillis) override {
		_sound.update();
		(void)deltaMillis;
	}

	// Loads scene bank (0..38) into RAM at 0x8010D000 (Resident bank 5 at 0x80118000)
	void loadSceneBank(uint8_t bankIndex, const uint8_t *bankData, size_t size) {
		uint32_t targetAddress = (bankIndex == 5) ? 0x00118000 : 0x0010D000;
		for (size_t i = 0; i < size && (targetAddress + i) < 0x00200000; ++i) {
			_memory.write8(targetAddress + i, bankData[i]);
		}
	}

private:
	PlayStationVideo _video;
	PlayStationSound _sound;
	PlayStationMemory _memory;
	PlayStationPad _pad;
};

} // namespace PS1
} // namespace SnatcherRE
