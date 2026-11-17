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
#include <algorithm>

namespace SnatcherRE {
namespace Saturn {

/**
 * Sega Saturn DATA.BIN Chunk Table Record (639 records at 0x060E62F4 in MAIN_L.BIN).
 * Each record defines the starting 2048-byte sector and byte size / 2.
 */
struct ChunkRecord {
	uint16_t sector;
	uint16_t halfSize;

	uint32_t getSize() const { return static_cast<uint32_t>(halfSize) * 2; }
	uint32_t getFileOffset() const { return static_cast<uint32_t>(sector) * 2048; }
};

/**
 * Authentic 3-Stream LZ3 Decompressor.
 * Transpiled and refactored from Hitachi SH-2 routine at 0x060CB548 (setup at 0x060CB6FC).
 * Used by 561 out of 639 DATA.BIN chunks (graphics containers, fonts, bitmaps).
 * Format header:
 * - u32 outSize (Big-Endian)
 * - u16 nWords  (Big-Endian)
 * - u16 nHalf   (Big-Endian)
 */
class SaturnLZ3Decompressor {
public:
	static bool decompress(const uint8_t *src, size_t srcSize, uint8_t *dst, size_t maxDstSize) {
		if (srcSize < 8) return false;

		uint32_t outSize = (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3];
		uint16_t nWords  = (src[4] << 8) | src[5];
		uint16_t nHalf   = (src[6] << 8) | src[7];

		if (outSize > maxDstSize) return false;

		const uint8_t *bitStream = src + 8;
		const uint8_t *halfStream = bitStream + (nWords * 4);
		const uint8_t *byteStream = halfStream + (nHalf * 2);

		if (byteStream > src + srcSize) return false;

		uint32_t bitPos = 0;
		uint32_t halfPos = 0;
		uint32_t bytePos = 0;
		uint32_t dstPos = 0;

		auto getBit = [&]() -> int {
			uint32_t wordIdx = bitPos / 32;
			uint32_t bitIdx  = bitPos % 32;
			bitPos++;
			if (8 + wordIdx * 4 + 3 >= srcSize) return 0;
			uint32_t word = (bitStream[wordIdx * 4] << 24) |
			                (bitStream[wordIdx * 4 + 1] << 16) |
			                (bitStream[wordIdx * 4 + 2] << 8) |
			                bitStream[wordIdx * 4 + 3];
			return (word >> (31 - bitIdx)) & 1;
		};

		while (dstPos < outSize) {
			if (getBit() == 0) {
				// Literal byte
				if (byteStream + bytePos >= src + srcSize) break;
				dst[dstPos++] = byteStream[bytePos++];
			} else {
				// Dictionary reference
				if (halfStream + halfPos * 2 + 1 >= src + srcSize) break;
				uint16_t ref = (halfStream[halfPos * 2] << 8) | halfStream[halfPos * 2 + 1];
				halfPos++;

				uint32_t length = (ref & 0x0F) + 3;
				uint32_t offset = (ref >> 4) + 1;

				if (offset > dstPos) break;
				for (uint32_t i = 0; i < length && dstPos < outSize; ++i) {
					dst[dstPos] = dst[dstPos - offset];
					dstPos++;
				}
			}
		}

		return (dstPos == outSize);
	}
};

/**
 * Sega Saturn Video Subsystem (Dual VDP1 + VDP2).
 * VDP1 renders sprites, polygons, and texture mapping into 512KB VRAM.
 * VDP2 controls 4 scrolling background planes (NBG0-NBG3), rotation (RBG0),
 * and priority color mixing into 512KB VRAM + 4KB CRAM.
 */
class SaturnVideo : public IVideoDevice {
public:
	static constexpr int DEFAULT_WIDTH  = 320;
	static constexpr int DEFAULT_HEIGHT = 224;

	SaturnVideo() : _width(DEFAULT_WIDTH), _height(DEFAULT_HEIGHT) {
		std::memset(_framebuffer, 0, sizeof(_framebuffer));
		std::memset(_vdp1Vram, 0, sizeof(_vdp1Vram));
		std::memset(_vdp2Vram, 0, sizeof(_vdp2Vram));
		std::memset(_cram, 0, sizeof(_cram));
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

	// Resolves TrueMotion AVI video stream header (LOGO.TRM / Movies)
	bool isTrueMotionStream(const uint8_t *header, size_t size) const {
		if (size >= 12) {
			return (header[0] == 'R' && header[1] == 'I' && header[2] == 'F' && header[3] == 'F' &&
					header[8] == 'A' && header[9] == 'V' && header[10] == 'I' && header[11] == ' ');
		}
		return false;
	}

	// VDP2 Color RAM (CRAM) Palette Update (15-bit RGB + MSB)
	void setCRAMColor(uint16_t index, uint16_t saturnColor) {
		if (index < 2048) {
			_cram[index] = saturnColor;
		}
	}

	uint32_t getCRAMColorAsRGB888(uint16_t index) const {
		if (index < 2048) {
			uint16_t c = _cram[index];
			uint8_t r = ((c & 0x1F) * 255) / 31;
			uint8_t g = (((c >> 5) & 0x1F) * 255) / 31;
			uint8_t b = (((c >> 10) & 0x1F) * 255) / 31;
			return (0xFF << 24) | (r << 16) | (g << 8) | b;
		}
		return 0xFF000000;
	}

private:
	int _width;
	int _height;
	uint32_t _framebuffer[352 * 240];
	uint8_t _vdp1Vram[512 * 1024]; // 512KB VDP1 VRAM
	uint8_t _vdp2Vram[512 * 1024]; // 512KB VDP2 VRAM
	uint16_t _cram[2048];          // 4KB Color RAM (2048 entries)
};

/**
 * Sega Saturn Sound Subsystem (Yamaha SCSP YMF292-F + Motorola 68EC000).
 * 32 PCM/FM audio channels, hardware DSP, and CD-DA / AIFF audio streaming (SDAIF_*.AIF).
 */
class SaturnSound : public ISoundDevice {
public:
	SaturnSound() {
		reset();
	}

	void reset() {
		_cddaTrack = 0;
		_cddaPlaying = false;
		_pcmPlaying = false;
		_masterVolume = 255;
	}

	void playCDDA(int track) override {
		_cddaTrack = track;
		_cddaPlaying = true;
	}

	void stopCDDA() override {
		_cddaPlaying = false;
	}

	void playPCM(int soundId, int volume = 255) override {
		_pcmPlaying = true;
		(void)soundId;
		(void)volume;
	}

	void stopPCM() override {
		_pcmPlaying = false;
	}

	void setMasterVolume(int volume) override {
		_masterVolume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// SCSP ring buffer mixing & SH-1 CD-block transfer update
	}

	bool isCDDAPlaying() const { return _cddaPlaying; }
	int getCDDATrack() const { return _cddaTrack; }

private:
	int _cddaTrack;
	bool _cddaPlaying;
	bool _pcmPlaying;
	int _masterVolume;
};

/**
 * Sega Saturn Memory Subsystem.
 * Transpiled and refactored from Hitachi SH-2 MAIN_L.BIN (Entry: 0x06004000).
 * Memory layout:
 * - 0x06000000 - 0x060FFFFF: 1MB High Work RAM (Fast 32-bit SDRAM, Code execution)
 * - 0x00200000 - 0x002FFFFF: 1MB Low Work RAM (16-bit DRAM, Buffers & Textures)
 * All words/longwords stored in Big-Endian order (Hitachi SH-2 RISC).
 */
class SaturnMemory : public IMemoryController {
public:
	static constexpr uint32_t HW_RAM_BASE = 0x06000000;
	static constexpr uint32_t HW_RAM_SIZE = 0x00100000; // 1MB High Work RAM
	static constexpr uint32_t LW_RAM_BASE = 0x00200000;
	static constexpr uint32_t LW_RAM_SIZE = 0x00100000; // 1MB Low Work RAM

	SaturnMemory() {
		std::memset(_hwRam, 0, sizeof(_hwRam));
		std::memset(_lwRam, 0, sizeof(_lwRam));
	}

	uint8_t read8(uint32_t address) override {
		if (address >= HW_RAM_BASE && address < HW_RAM_BASE + HW_RAM_SIZE) {
			return _hwRam[address - HW_RAM_BASE];
		}
		if (address >= LW_RAM_BASE && address < LW_RAM_BASE + LW_RAM_SIZE) {
			return _lwRam[address - LW_RAM_BASE];
		}
		return 0;
	}

	void write8(uint32_t address, uint8_t value) override {
		if (address >= HW_RAM_BASE && address < HW_RAM_BASE + HW_RAM_SIZE) {
			_hwRam[address - HW_RAM_BASE] = value;
		} else if (address >= LW_RAM_BASE && address < LW_RAM_BASE + LW_RAM_SIZE) {
			_lwRam[address - LW_RAM_BASE] = value;
		}
	}

	uint16_t read16(uint32_t address) override {
		// Big-Endian (Hitachi SH-2)
		uint8_t hi = read8(address);
		uint8_t lo = read8(address + 1);
		return static_cast<uint16_t>((hi << 8) | lo);
	}

	void write16(uint32_t address, uint16_t value) override {
		write8(address, static_cast<uint8_t>((value >> 8) & 0xFF));
		write8(address + 1, static_cast<uint8_t>(value & 0xFF));
	}

	uint32_t read32(uint32_t address) override {
		uint16_t hi = read16(address);
		uint16_t lo = read16(address + 2);
		return static_cast<uint32_t>((hi << 16) | lo);
	}

	void write32(uint32_t address, uint32_t value) override {
		write16(address, static_cast<uint16_t>((value >> 16) & 0xFFFF));
		write16(address + 2, static_cast<uint16_t>(value & 0xFFFF));
	}

private:
	uint8_t _hwRam[HW_RAM_SIZE];
	uint8_t _lwRam[LW_RAM_SIZE];
};

/**
 * Sega Saturn Platform Module.
 */
class SaturnModule : public PlatformModule {
public:
	SaturnModule() : _video(), _sound(), _memory() {}

	PlatformType getPlatformType() const override { return kPlatformTypeSaturn; }
	const char *getPlatformName() const override { return "Sega Saturn (T-9508G)"; }

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

	// Decompresses and loads a DATA.BIN LZ3 chunk into RAM
	bool loadChunk(const uint8_t *chunkData, size_t chunkSize, uint32_t targetAddress, size_t maxTargetSize) {
		std::vector<uint8_t> decompressed(maxTargetSize);
		if (SaturnLZ3Decompressor::decompress(chunkData, chunkSize, decompressed.data(), maxTargetSize)) {
			for (size_t i = 0; i < decompressed.size(); ++i) {
				_memory.write8(targetAddress + i, decompressed[i]);
			}
			return true;
		}
		return false;
	}

private:
	SaturnVideo _video;
	SaturnSound _sound;
	SaturnMemory _memory;
};

} // namespace Saturn
} // namespace SnatcherRE
