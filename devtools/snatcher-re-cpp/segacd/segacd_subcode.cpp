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
namespace SegaCD {

/**
 * Sega Mega-CD Sub-CPU Gate Array Communication Controller.
 * Transpiled and refactored from SUBCODE.BIN (Load address: 0x0000D400).
 * Memory registers:
 * - 0x00FF8004: CDC Mode / Device Destination (0=Main, 1=Sub, 2=PCM, 3=PRG-RAM, 4=Word-RAM, 5=DMA wait)
 * - 0x00FF800A: CDC Host Data Transfer Counter
 * - 0x00FF800F: Memory Mode / Word-RAM Ret Flag (Bit 2: 2M mode vs 1M/1M ping-pong mode, Bit 0: Sub-CPU Ret)
 * - 0x00FF8010-0x00FF801F: Main-CPU Command Registers (COMM_CMD 0 to 7)
 * - 0x00FF8020-0x00FF802F: Sub-CPU Status Registers (COMM_STATUS 0 to 7)
 * - 0x00FF8030: Timer Interrupt Control
 */
class SegaCDGateArray {
public:
	SegaCDGateArray() {
		reset();
	}

	void reset() {
		_cdcMode = 0;
		_cdcCounter = 0;
		_memoryMode = 0; // Default 2M Word-RAM mapped to Sub-CPU
		std::memset(_commCmd, 0, sizeof(_commCmd));
		std::memset(_commStatus, 0, sizeof(_commStatus));
		_timerInterrupt = 0;
	}

	void writeRegister(uint32_t offset, uint8_t value) {
		switch (offset) {
		case 0x04:
			_cdcMode = value;
			break;
		case 0x0A:
			_cdcCounter = (_cdcCounter & 0x00FF) | (value << 8);
			break;
		case 0x0B:
			_cdcCounter = (_cdcCounter & 0xFF00) | value;
			break;
		case 0x0F:
			// Bit 2: 2M/1M mode, Bit 0: Ret
			_memoryMode = value;
			break;
		case 0x30:
			_timerInterrupt = value;
			break;
		default:
			if (offset >= 0x10 && offset < 0x20) {
				_commCmd[offset - 0x10] = value;
			} else if (offset >= 0x20 && offset < 0x30) {
				_commStatus[offset - 0x20] = value;
			}
			break;
		}
	}

	uint8_t readRegister(uint32_t offset) const {
		switch (offset) {
		case 0x04: return _cdcMode;
		case 0x0A: return static_cast<uint8_t>((_cdcCounter >> 8) & 0xFF);
		case 0x0B: return static_cast<uint8_t>(_cdcCounter & 0xFF);
		case 0x0F: return _memoryMode;
		case 0x30: return _timerInterrupt;
		default:
			if (offset >= 0x10 && offset < 0x20) {
				return _commCmd[offset - 0x10];
			} else if (offset >= 0x20 && offset < 0x30) {
				return _commStatus[offset - 0x20];
			}
			return 0;
		}
	}

	// Main-CPU sends command to Sub-CPU
	void setMainCommand(uint8_t regIndex, uint16_t cmd) {
		if (regIndex < 8) {
			_commCmd[regIndex * 2]     = static_cast<uint8_t>((cmd >> 8) & 0xFF);
			_commCmd[regIndex * 2 + 1] = static_cast<uint8_t>(cmd & 0xFF);
		}
	}

	// Sub-CPU responds with status to Main-CPU
	uint16_t getSubStatus(uint8_t regIndex) const {
		if (regIndex < 8) {
			return static_cast<uint16_t>((_commStatus[regIndex * 2] << 8) | _commStatus[regIndex * 2 + 1]);
		}
		return 0;
	}

	bool is2MMode() const { return (_memoryMode & 0x04) == 0; }
	bool isSubCPURet() const { return (_memoryMode & 0x01) != 0; }

private:
	uint8_t _cdcMode;
	uint16_t _cdcCounter;
	uint8_t _memoryMode;
	uint8_t _commCmd[16];
	uint8_t _commStatus[16];
	uint8_t _timerInterrupt;
};

/**
 * Ricoh RF5C164 8-Channel PCM Audio Subsystem.
 * Transpiled and refactored from Sub-CPU PCM audio driver routines in SUBCODE.BIN.
 * Hardware specifications:
 * - 8 independent PCM playback voices
 * - 64KB internal sample RAM
 * - Panning (4-bit left, 4-bit right per channel)
 * - Volume envelope attenuation
 */
class SegaCDPCM : public ISoundDevice {
public:
	struct Channel {
		uint32_t startAddr = 0;
		uint32_t loopAddr = 0;
		uint32_t currentAddr = 0;
		uint16_t step = 0;
		uint8_t volume = 255;
		uint8_t panLeft = 15;
		uint8_t panRight = 15;
		bool enabled = false;
	};

	SegaCDPCM() {
		reset();
	}

	void reset() {
		_cddaTrack = 0;
		_cddaPlaying = false;
		_channelMask = 0;
		_masterVolume = 255;
		std::memset(_sampleRam, 0, sizeof(_sampleRam));
		for (int i = 0; i < 8; ++i) {
			_channels[i] = Channel();
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
		int ch = soundId % 8;
		_channels[ch].enabled = true;
		_channels[ch].volume = volume;
		_channels[ch].currentAddr = _channels[ch].startAddr;
		_channelMask |= (1 << ch);
	}

	void stopPCM() override {
		for (int i = 0; i < 8; ++i) {
			_channels[i].enabled = false;
		}
		_channelMask = 0;
	}

	void setMasterVolume(int volume) override {
		_masterVolume = std::clamp(volume, 0, 255);
	}

	void update() override {
		// Update 8 PCM voices sample pointer steps
		for (int i = 0; i < 8; ++i) {
			if (_channels[i].enabled) {
				_channels[i].currentAddr += (_channels[i].step >> 11);
				if (_channels[i].currentAddr >= sizeof(_sampleRam)) {
					_channels[i].currentAddr = _channels[i].loopAddr;
				}
			}
		}
	}

	void loadWaveSample(uint32_t offset, const uint8_t *data, size_t size) {
		for (size_t i = 0; i < size && (offset + i) < sizeof(_sampleRam); ++i) {
			_sampleRam[offset + i] = data[i];
		}
	}

	bool isCDDAPlaying() const { return _cddaPlaying; }
	int getCDDATrack() const { return _cddaTrack; }

private:
	int _cddaTrack;
	bool _cddaPlaying;
	uint8_t _channelMask;
	int _masterVolume;
	uint8_t _sampleRam[64 * 1024]; // 64KB Ricoh Wave RAM
	Channel _channels[8];
};

/**
 * Sega Mega-CD Sub-CPU Memory Subsystem.
 * Manages 512KB PRG-RAM (0x00000000 to 0x0007FFFF) and 512KB Word-RAM (0x00080000 to 0x000FFFFF).
 * All words and longwords stored in Big-Endian order (Motorola 68000).
 */
class SegaCDMemory : public IMemoryController {
public:
	static constexpr uint32_t PRG_RAM_SIZE  = 512 * 1024; // 512KB Sub-CPU PRG-RAM
	static constexpr uint32_t WORD_RAM_SIZE = 512 * 1024; // 512KB Word-RAM

	SegaCDMemory() {
		std::memset(_prgRam, 0, sizeof(_prgRam));
		std::memset(_wordRam, 0, sizeof(_wordRam));
	}

	uint8_t read8(uint32_t address) override {
		if (address < PRG_RAM_SIZE) {
			return _prgRam[address];
		}
		if (address >= 0x080000 && address < 0x080000 + WORD_RAM_SIZE) {
			return _wordRam[address - 0x080000];
		}
		if (address >= 0xFF8000 && address <= 0xFF803F) {
			return _gateArray.readRegister(address - 0xFF8000);
		}
		return 0;
	}

	void write8(uint32_t address, uint8_t value) override {
		if (address < PRG_RAM_SIZE) {
			_prgRam[address] = value;
		} else if (address >= 0x080000 && address < 0x080000 + WORD_RAM_SIZE) {
			_wordRam[address - 0x080000] = value;
		} else if (address >= 0xFF8000 && address <= 0xFF803F) {
			_gateArray.writeRegister(address - 0xFF8000, value);
		}
	}

	uint16_t read16(uint32_t address) override {
		// Big-Endian (68000)
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

	SegaCDGateArray &getGateArray() { return _gateArray; }

private:
	uint8_t _prgRam[PRG_RAM_SIZE];
	uint8_t _wordRam[WORD_RAM_SIZE];
	SegaCDGateArray _gateArray;
};

/**
 * Sega Mega-CD / Sega CD Platform Module.
 */
class SegaCDModule : public PlatformModule {
public:
	SegaCDModule() : _pcm(), _memory() {}

	PlatformType getPlatformType() const override { return kPlatformTypeSegaCD; }
	const char *getPlatformName() const override { return "Sega Mega-CD / Sega CD"; }

	IVideoDevice *getVideo() override { return nullptr; } // Sega CD VDP handled via Genesis VDP core
	ISoundDevice *getSound() override { return &_pcm; }
	IMemoryController *getMemory() override { return &_memory; }
	SegaCDGateArray &getGateArray() { return _memory.getGateArray(); }

	void reset() override {
		_pcm.reset();
		_memory.getGateArray().reset();
	}

	void update(uint32_t deltaMillis) override {
		_pcm.update();
		(void)deltaMillis;
	}

	// Handles Main-CPU to Sub-CPU interrupt requests (Transpiled from FUN_0000e41a)
	void processMainCommand(uint8_t cmd, uint8_t param) {
		switch (cmd) {
		case 0xF0: // Stop audio / reset channel
			_pcm.stopPCM();
			_pcm.stopCDDA();
			break;
		case 0xF1: // Play CD-DA track
			_pcm.playCDDA(param);
			break;
		case 0xF2: // Play PCM sample
			_pcm.playPCM(param);
			break;
		case 0xF3: // Stop CD-DA playback
			_pcm.stopCDDA();
			break;
		case 0xF4: // Attenuate master volume
			_pcm.setMasterVolume(param);
			break;
		default:
			break;
		}
	}

private:
	SegaCDPCM _pcm;
	SegaCDMemory _memory;
};

} // namespace SegaCD
} // namespace SnatcherRE
