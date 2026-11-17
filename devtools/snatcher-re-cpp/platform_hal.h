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

#ifndef SNATCHER_RE_PLATFORM_HAL_H
#define SNATCHER_RE_PLATFORM_HAL_H

#include <cstdint>
#include <cstddef>
#include <string>

namespace SnatcherRE {

/**
 * Common hardware and platform enumeration matching ScummVM conventions.
 */
enum PlatformType {
	kPlatformTypePC88,
	kPlatformTypeMSX2,
	kPlatformTypePCEngine,
	kPlatformTypeSegaCD,
	kPlatformTypeSaturn,
	kPlatformTypePlayStation
};

/**
 * Abstract Video Output Interface (Hardware Abstraction Layer).
 * Decouples linear RGB framebuffers, planar VRAM (PC88/MSX2), VDP tiles (Sega CD),
 * and hardware textures (PS1/Saturn) into an engine-friendly abstraction.
 */
class IVideoDevice {
public:
	virtual ~IVideoDevice() {}

	virtual void initVideo(int width, int height) = 0;
	virtual void clearScreen(uint32_t color = 0) = 0;
	virtual void setPixel(int x, int y, uint32_t color) = 0;
	virtual uint32_t getPixel(int x, int y) const = 0;
	virtual void renderFrame(uint8_t *targetBuffer, int pitch, int bpp) = 0;

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
};

/**
 * Abstract Sound & CD-DA Interface.
 * Decouples Ricoh PCM/FM (Sega CD), SPU/XA (PS1), SCSP (Saturn), PSG/ADPCM (PCE),
 * and SCC/PSG/OPN (MSX2/PC88).
 */
class ISoundDevice {
public:
	virtual ~ISoundDevice() {}

	virtual void playCDDA(int track) = 0;
	virtual void stopCDDA() = 0;
	virtual void playPCM(int soundId, int volume = 255) = 0;
	virtual void stopPCM() = 0;
	virtual void setMasterVolume(int volume) = 0;
	virtual void update() = 0;
};

/**
 * Abstract Storage & Memory Controller.
 * Decouples Sega CD Sub-CPU Word-RAM, PS1 file tables, MSX-DOS BDOS / Floppy,
 * and PC Engine HuC6280 Memory Page Registers.
 */
class IMemoryController {
public:
	virtual ~IMemoryController() {}

	virtual uint8_t read8(uint32_t address) = 0;
	virtual void write8(uint32_t address, uint8_t value) = 0;
	virtual uint16_t read16(uint32_t address) = 0;
	virtual void write16(uint32_t address, uint16_t value) = 0;
	virtual uint32_t read32(uint32_t address) = 0;
	virtual void write32(uint32_t address, uint32_t value) = 0;
};

/**
 * Base Hardware Module representing a specific platform port.
 */
class PlatformModule {
public:
	virtual ~PlatformModule() {}

	virtual PlatformType getPlatformType() const = 0;
	virtual const char *getPlatformName() const = 0;

	virtual IVideoDevice *getVideo() = 0;
	virtual ISoundDevice *getSound() = 0;
	virtual IMemoryController *getMemory() = 0;

	virtual void reset() = 0;
	virtual void update(uint32_t deltaMillis) = 0;
};

} // namespace SnatcherRE

#endif // SNATCHER_RE_PLATFORM_HAL_H
