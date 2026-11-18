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

#ifndef SNATCHER_VLA_HEADLESS_H
#define SNATCHER_VLA_HEADLESS_H

#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "common/scummsys.h"
#include "common/textconsole.h"
#include "graphics/pixelformat.h"

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

namespace Snatcher {

#define SNATCHER_VLA_MAGIC 0x534E4154U // "SNAT"
#define SNATCHER_VLA_SHM_SIZE 1048576U  // 1 MB exactly
#define SNATCHER_VLA_DEFAULT_PATH "/data/user/0/com.agy/files/snatcher_vla_shm.bin"

#pragma pack(push, 4)
struct SnatcherVlaShm {
	uint32 magic;             // 0x534E4154
	uint32 version;           // 1
	uint32 frame_count;       // Incremented on every rendered frame
	uint64 timestamp_us;      // Microsecond timestamp

	uint16 width;             // Framebuffer width (e.g. 320)
	uint16 height;            // Framebuffer height (e.g. 224)
	uint16 bpp;               // Bytes per pixel (3 for RGB24)
	uint16 format;            // 0 = RGB24

	// Controls: Written by VLA Agent (Manos Rápidas), read by ScummVM
	uint32 input_reg;         // Bitmask: 0x01=UP, 0x02=DOWN, 0x04=LEFT, 0x08=RIGHT, 0x10=A, 0x20=B, 0x40=C, 0x80=START, 0x100=GUN
	uint16 mouse_x;           // Lightgun/mouse X
	uint16 mouse_y;           // Lightgun/mouse Y
	uint8  turbo_mode;        // 1 = Uncapped Hyper-Speed (500+ FPS), 0 = 60 FPS real-time
	uint8  quit_flag;         // 1 = Order ScummVM to quit cleanly
	uint8  capture_trigger;   // 1 = Request frame dump to disk
	uint8  reserved;

	// Audio Buffer
	uint32 audio_write_pos;
	uint32 audio_read_pos;
	uint32 audio_rate;        // 44100
	uint16 audio_channels;    // 2
	uint16 reserved2;

	int16  audio_ring[16384]; // 16k 16-bit PCM samples circular ring buffer

	// Video Buffer: Raw RGB24 pixels (320*240*3 = 230400 bytes, up to 640*480*3)
	uint8  frame_buffer[640 * 480 * 3];
};
#pragma pack(pop)

class VlaHeadlessManager {
public:
	static VlaHeadlessManager &instance() {
		static VlaHeadlessManager mgr;
		return mgr;
	}

	void init() {
		if (_initialized)
			return;

		const char *shmPath = SNATCHER_VLA_DEFAULT_PATH;
		_fd = open(shmPath, O_RDWR | O_CREAT, 0666);
		if (_fd < 0) {
			fprintf(stderr, "[VlaHeadlessManager] Failed to open %s: %s\n", shmPath, strerror(errno));
			fflush(stderr);
			_active = false;
			_initialized = true;
			return;
		}

		if (ftruncate(_fd, SNATCHER_VLA_SHM_SIZE) != 0) {
			close(_fd);
			_fd = -1;
			_active = false;
			_initialized = true;
			return;
		}

		void *ptr = mmap(NULL, SNATCHER_VLA_SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, _fd, 0);
		if (ptr == MAP_FAILED) {
			close(_fd);
			_fd = -1;
			_active = false;
			_initialized = true;
			return;
		}

		_shm = (SnatcherVlaShm *)ptr;
		if (_shm->magic != SNATCHER_VLA_MAGIC) {
			memset(_shm, 0, sizeof(SnatcherVlaShm));
			_shm->magic = SNATCHER_VLA_MAGIC;
			_shm->version = 1;
			_shm->width = 320;
			_shm->height = 224;
			_shm->bpp = 3;
			_shm->audio_rate = 44100;
			_shm->audio_channels = 2;
			_shm->turbo_mode = 1; // Default to turbo hyper-speed for automated testing!
		}

		_active = true;
		_initialized = true;
		_turbo = (_shm->turbo_mode != 0);

		fprintf(stderr, "[VlaHeadlessManager] Ultra-Fast Zero-Copy SHM initialized at %s (Active=1, Turbo=%d)\n", shmPath, _turbo ? 1 : 0);
		fflush(stderr);
	}

	bool isActive() const { return _active; }
	bool isTurbo() const { return _active && (_turbo || (_shm && _shm->turbo_mode != 0)); }
	bool shouldQuit() const { return _active && _shm && (_shm->quit_flag != 0); }

	void postFrame(const uint8 *screen, uint16 width, uint16 height, const Graphics::PixelFormat &pxf) {
		if (!_active || !_shm || !screen)
			return;

		struct timeval tv;
		gettimeofday(&tv, NULL);
		_shm->timestamp_us = (uint64)tv.tv_sec * 1000000ULL + tv.tv_usec;
		_shm->width = width;
		_shm->height = height;
		_shm->bpp = 3;
		_shm->format = 0; // RGB24

		uint8 *dst = _shm->frame_buffer;
		uint32 pixelCount = (uint32)width * height;
		if (pixelCount > 640 * 480)
			pixelCount = 640 * 480;

		if (pxf.bytesPerPixel == 2) {
			const uint16 *src16 = (const uint16 *)screen;
			for (uint32 i = 0; i < pixelCount; ++i) {
				uint16 p = src16[i];
				uint8 r, g, b;
				pxf.colorToRGB(p, r, g, b);
				*dst++ = r;
				*dst++ = g;
				*dst++ = b;
			}
		} else if (pxf.bytesPerPixel == 4) {
			const uint32 *src32 = (const uint32 *)screen;
			for (uint32 i = 0; i < pixelCount; ++i) {
				uint32 p = src32[i];
				uint8 r, g, b;
				pxf.colorToRGB(p, r, g, b);
				*dst++ = r;
				*dst++ = g;
				*dst++ = b;
			}
		} else {
			for (uint32 i = 0; i < pixelCount; ++i) {
				uint8 v = screen[i];
				*dst++ = v;
				*dst++ = v;
				*dst++ = v;
			}
		}

		_shm->frame_count++;

		// Real frame dump to disk for Multiplatform-Renders and web dashboard
		const char *dumpPath = "/storage/emulated/0/Download/Snatcher-Collection/Multiplatform-Renders/live_scummvm.ppm";
		dumpPPM(dumpPath, _shm->frame_buffer, width, height);
	}

	void dumpPPM(const char *path, const uint8 *rgb, uint16 width, uint16 height) {
		FILE *f = fopen(path, "wb");
		if (f) {
			fprintf(f, "P6\n%d %d\n255\n", width, height);
			fwrite(rgb, 1, width * height * 3, f);
			fclose(f);
		}
	}

	void postAudio(const int16 *samples, uint32 count) {
		if (!_active || !_shm || !samples || count == 0)
			return;

		uint32 writePos = _shm->audio_write_pos;
		for (uint32 i = 0; i < count; ++i) {
			_shm->audio_ring[writePos % 16384] = samples[i];
			writePos++;
		}
		_shm->audio_write_pos = writePos;
	}

	uint32 readInput(int &outMouseX, int &outMouseY) {
		if (!_active || !_shm)
			return 0;

		uint32 in = _shm->input_reg;
		outMouseX = _shm->mouse_x;
		outMouseY = _shm->mouse_y;
		return in;
	}

	void clearInput(uint32 mask) {
		if (_active && _shm) {
			_shm->input_reg &= ~mask;
		}
	}

	~VlaHeadlessManager() {
		if (_shm && _shm != MAP_FAILED) {
			munmap(_shm, SNATCHER_VLA_SHM_SIZE);
			_shm = nullptr;
		}
		if (_fd >= 0) {
			close(_fd);
			_fd = -1;
		}
	}

private:
	VlaHeadlessManager() : _initialized(false), _active(false), _turbo(false), _fd(-1), _shm(nullptr) {}
	bool _initialized;
	bool _active;
	bool _turbo;
	int _fd;
	SnatcherVlaShm *_shm;
};

} // namespace Snatcher

#endif // SNATCHER_VLA_HEADLESS_H
