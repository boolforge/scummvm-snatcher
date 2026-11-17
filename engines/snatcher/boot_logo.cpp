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

#include "snatcher/boot_logo.h"
#include "snatcher/resource.h"
#include "video/psx_decoder.h"
#include "video/avi_decoder.h"
#include "audio/decoders/adpcm.h"
#include "audio/audiostream.h"
#include "audio/mixer.h"
#include "common/archive.h"
#include "common/config-manager.h"
#include "common/file.h"
#include "common/stream.h"
#include "common/memstream.h"
#include "common/system.h"
#include "common/util.h"
#include "graphics/paletteman.h"
#include "graphics/surface.h"

namespace Snatcher {

namespace {

// Helper to open a game stream either via SearchMan or via direct path in ConfMan("path")
Common::SeekableReadStream *openGameStream(const Common::String &dirName, const Common::String &fileName) {
	Common::Path directPath(fileName);
	Common::SeekableReadStream *stream = SearchMan.createReadStreamForMember(directPath);
	if (stream)
		return stream;

	Common::Path subPath(dirName.empty() ? fileName : dirName + "/" + fileName);
	stream = SearchMan.createReadStreamForMember(subPath);
	if (stream)
		return stream;

	if (ConfMan.hasKey("path")) {
		Common::Path gamePath(ConfMan.getPath("path"));
		Common::FSNode gameDir(gamePath);

		Common::FSNode directNode = gameDir.getChild(fileName);
		if (directNode.exists() && directNode.isReadable()) {
			Common::File *f = new Common::File();
			if (f->open(directNode))
				return f;
			delete f;
		}

		if (!dirName.empty()) {
			Common::FSNode subDirNode = gameDir.getChild(dirName);
			if (subDirNode.exists() && subDirNode.isDirectory()) {
				Common::FSNode fileNode = subDirNode.getChild(fileName);
				if (fileNode.exists() && fileNode.isReadable()) {
					Common::File *f = new Common::File();
					if (f->open(fileNode))
						return f;
					delete f;
				}
			}
		}
	}
	return nullptr;
}

// Blit a decoded frame surface into the engine linear framebuffer
void blitFrameToScreen(const Graphics::Surface *frame, uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf) {
	if (!frame || !screen)
		return;

	const int bpp = pxf.bytesPerPixel ? pxf.bytesPerPixel : 1;
	const int copyW = MIN<int>(width, frame->w);
	const int copyH = MIN<int>(height, frame->h);
	const int dstX = (width - copyW) / 2;
	const int dstY = (height - copyH) / 2;

	if (copyW < width || copyH < height) {
		memset(screen, 0, width * height * bpp);
	}

	for (int y = 0; y < copyH; ++y) {
		uint8 *dstRow = screen + ((dstY + y) * width + dstX) * bpp;
		if (bpp == frame->format.bytesPerPixel && (bpp == 2 || bpp == 4)) {
			const uint8 *srcRow = (const uint8 *)frame->getBasePtr(0, y);
			memcpy(dstRow, srcRow, copyW * bpp);
		} else if (bpp == 2) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r, g, b;
				frame->format.colorToRGB(frame->getPixel(x, y), r, g, b);
				uint16 color = (uint16)pxf.RGBToColor(r, g, b);
				((uint16 *)dstRow)[x] = color;
			}
		} else if (bpp == 4) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r, g, b;
				frame->format.colorToRGB(frame->getPixel(x, y), r, g, b);
				uint32 color = pxf.RGBToColor(r, g, b);
				((uint32 *)dstRow)[x] = color;
			}
		} else if (bpp == 1) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r, g, b;
				frame->format.colorToRGB(frame->getPixel(x, y), r, g, b);
				uint8 gray = (uint8)((r * 77 + g * 150 + b * 29) >> 8);
				dstRow[x] = gray;
			}
		}
	}
}

// Blit raw RGB byte buffer into screen
void blitRGBToScreen(const uint8 *rgbData, int srcW, int srcH, uint8 *screen, int dstW, int dstH, const Graphics::PixelFormat &pxf) {
	if (!rgbData || !screen)
		return;

	const int bpp = pxf.bytesPerPixel ? pxf.bytesPerPixel : 1;
	const int copyW = MIN<int>(dstW, srcW);
	const int copyH = MIN<int>(dstH, srcH);
	const int dstX = (dstW - copyW) / 2;
	const int dstY = (dstH - copyH) / 2;

	memset(screen, 0, dstW * dstH * bpp);

	for (int y = 0; y < copyH; ++y) {
		uint8 *dstRow = screen + ((dstY + y) * dstW + dstX) * bpp;
		const uint8 *srcRow = rgbData + (y * srcW * 3);
		if (bpp == 2) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r = srcRow[x * 3];
				uint8 g = srcRow[x * 3 + 1];
				uint8 b = srcRow[x * 3 + 2];
				((uint16 *)dstRow)[x] = (uint16)pxf.RGBToColor(r, g, b);
			}
		} else if (bpp == 4) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r = srcRow[x * 3];
				uint8 g = srcRow[x * 3 + 1];
				uint8 b = srcRow[x * 3 + 2];
				((uint32 *)dstRow)[x] = pxf.RGBToColor(r, g, b);
			}
		} else if (bpp == 1) {
			for (int x = 0; x < copyW; ++x) {
				uint8 r = srcRow[x * 3];
				uint8 g = srcRow[x * 3 + 1];
				uint8 b = srcRow[x * 3 + 2];
				dstRow[x] = (uint8)((r * 77 + g * 150 + b * 29) >> 8);
			}
		}
	}
}

// -----------------------------------------------------------------------------
// PS1 STR Stream Reader Adapter
// Converts 2048-byte user data sectors from STR files into 2352-byte raw CD-XA
// Mode 2 Form 2 sectors expected by ScummVM's Video::PSXStreamDecoder.
// -----------------------------------------------------------------------------
const uint32 kRawSectorSize = 2352;
const uint32 kUserSectorSize = 2048;

class PSXRawSectorReadStream final : public Common::SeekableReadStream {
public:
	explicit PSXRawSectorReadStream(Common::SeekableReadStream *parentStream)
		: _stream(parentStream), _pos(0), _cachedSector(-1) {
		int64 streamSize = _stream ? _stream->size() : 0;
		_sectorCount = streamSize / kUserSectorSize;
		_totalRawSize = _sectorCount * (int64)kRawSectorSize;
	}

	~PSXRawSectorReadStream() override {
		delete _stream;
	}

	uint32 read(void *dataPtr, uint32 dataSize) override {
		byte *dst = static_cast<byte *>(dataPtr);
		uint32 bytesRead = 0;

		while (bytesRead < dataSize && _pos < _totalRawSize) {
			int64 sectorIdx = _pos / kRawSectorSize;
			uint32 offsetInSector = (uint32)(_pos % kRawSectorSize);

			if (!fillSector(sectorIdx))
				break;

			uint32 canRead = MIN<uint32>(dataSize - bytesRead, kRawSectorSize - offsetInSector);
			memcpy(dst + bytesRead, _sectorBuf + offsetInSector, canRead);
			bytesRead += canRead;
			_pos += canRead;
		}

		return bytesRead;
	}

	bool eos() const override { return _pos >= _totalRawSize; }
	bool err() const override { return _stream ? _stream->err() : true; }
	void clearErr() override { if (_stream) _stream->clearErr(); }
	int64 pos() const override { return _pos; }
	int64 size() const override { return _totalRawSize; }

	bool seek(int64 offset, int whence = SEEK_SET) override {
		int64 target = 0;
		switch (whence) {
		case SEEK_SET: target = offset; break;
		case SEEK_CUR: target = _pos + offset; break;
		case SEEK_END: target = _totalRawSize + offset; break;
		default: return false;
		}
		if (target < 0 || target > _totalRawSize)
			return false;
		_pos = target;
		return true;
	}

private:
	bool fillSector(int64 sectorIdx) {
		if (sectorIdx == _cachedSector)
			return true;
		if (sectorIdx < 0 || sectorIdx >= _sectorCount)
			return false;

		if (!_stream->seek(sectorIdx * kUserSectorSize))
			return false;

		// 12 bytes CD-XA sync header
		memset(_sectorBuf, 0xFF, 12);
		_sectorBuf[0] = 0x00;
		_sectorBuf[11] = 0x00;

		// 4 bytes header: min, sec, sector, mode
		_sectorBuf[12] = 0;
		_sectorBuf[13] = (byte)((sectorIdx / 75) % 60);
		_sectorBuf[14] = (byte)(sectorIdx % 75);
		_sectorBuf[15] = 2; // Mode 2 Form 2

		// 2048 bytes user data
		uint32 readBytes = _stream->read(_sectorBuf + 24, kUserSectorSize);
		if (readBytes < kUserSectorSize)
			memset(_sectorBuf + 24 + readBytes, 0, kUserSectorSize - readBytes);

		// Determine sector submode from data magic:
		// 0x6001 = MDEC video chunk (0x02)
		// 0x0C0C = CD-XA audio or padding (0x04)
		byte submode = 0x02; // default video
		if (_sectorBuf[24] == 0x60 && _sectorBuf[25] == 0x01) {
			submode = 0x02; // CDXA_TYPE_VIDEO
		} else if (_sectorBuf[24] == 0x0C) {
			submode = 0x04; // CDXA_TYPE_AUDIO
		} else {
			submode = 0x02;
		}

		// 4 bytes subheader: file=0, chan=1, submode, coding=0
		_sectorBuf[16] = 0;
		_sectorBuf[17] = 1;       // Channel 1
		_sectorBuf[18] = submode;
		_sectorBuf[19] = 0;

		// 4 bytes subheader copy
		memcpy(_sectorBuf + 20, _sectorBuf + 16, 4);

		// 280 bytes tail (EDC/ECC)
		memset(_sectorBuf + 24 + kUserSectorSize, 0, 280);

		_cachedSector = sectorIdx;
		return true;
	}

	Common::SeekableReadStream *_stream;
	int64 _sectorCount;
	int64 _totalRawSize;
	int64 _pos;
	int64 _cachedSector;
	byte _sectorBuf[kRawSectorSize];
};

// -----------------------------------------------------------------------------
// PlayStation 1 Authentic Boot Video Logo
// Plays MX0_S000.STR (Konami intro movie) directly from original game assets
// -----------------------------------------------------------------------------
class PS1BootLogo : public BootLogo {
public:
	explicit PS1BootLogo(FIO *fio) : _decoder(Video::PSXStreamDecoder::kCD2x), _loaded(false), _lastSurface(nullptr) {
		Common::SeekableReadStream *stream = nullptr;
		if (fio) {
			stream = fio->readStream("STR/MX0_S000.STR");
			if (!stream)
				stream = fio->readStream("MX0_S000.STR");
		}
		if (!stream)
			stream = openGameStream("STR", "MX0_S000.STR");

		if (!stream)
			return;

		Common::SeekableReadStream *rawStream = new PSXRawSectorReadStream(stream);
		if (_decoder.loadStream(rawStream)) {
			_decoder.start();
			_loaded = true;
		}
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (!_loaded || _decoder.endOfVideo())
			return -1;

		const Graphics::Surface *frame = _decoder.decodeNextFrame();
		if (frame)
			_lastSurface = frame;

		if (_lastSurface)
			blitFrameToScreen(_lastSurface, screen, width, height, pxf);

		return frameNo + 1;
	}

private:
	Video::PSXStreamDecoder _decoder;
	bool _loaded;
	const Graphics::Surface *_lastSurface;
};

// -----------------------------------------------------------------------------
// Sega Saturn Authentic Boot Video Logo
// Plays LOGO.TRM (Konami animated AVI logo) directly from original game assets
// -----------------------------------------------------------------------------
class SaturnBootLogo : public BootLogo {
public:
	explicit SaturnBootLogo(FIO *fio) : _loaded(false), _lastSurface(nullptr) {
		Common::SeekableReadStream *stream = nullptr;
		if (fio)
			stream = fio->readStream("LOGO.TRM");
		if (!stream)
			stream = openGameStream("", "LOGO.TRM");

		if (!stream)
			return;

		if (_decoder.loadStream(stream)) {
			_decoder.start();
			_loaded = true;
		}
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (!_loaded || _decoder.endOfVideo())
			return -1;

		const Graphics::Surface *frame = _decoder.decodeNextFrame();
		if (frame)
			_lastSurface = frame;

		if (_lastSurface)
			blitFrameToScreen(_lastSurface, screen, width, height, pxf);

		return frameNo + 1;
	}

private:
	Video::AVIDecoder _decoder;
	bool _loaded;
	const Graphics::Surface *_lastSurface;
};

// -----------------------------------------------------------------------------
// PC Engine Super CD-ROM2 Authentic Boot Logo & Voice
// Plays adpcm_000_sec07858_20kb.adpcm voice and authentic HuC6270 graphics overlay
// -----------------------------------------------------------------------------
class PCEBootLogo : public BootLogo {
public:
	explicit PCEBootLogo(FIO *fio) : _loaded(false), _audioStarted(false), _audioStream(nullptr), _rgb(nullptr), _w(256), _h(224) {
		// 1. Load authentic ADPCM sound stream (adpcm_000_sec07858_20kb.adpcm)
		if (fio) {
			_audioStream = fio->readStream("adpcm_000_sec07858_20kb.adpcm");
			if (!_audioStream)
				_audioStream = fio->readStream("adpcm/adpcm_000_sec07858_20kb.adpcm");
		}
		if (!_audioStream)
			_audioStream = openGameStream("adpcm", "adpcm_000_sec07858_20kb.adpcm");

		// 2. Load authentic PC Engine graphics overlay & palette
		Common::SeekableReadStream *gfxStream = nullptr;
		Common::SeekableReadStream *palStream = nullptr;
		if (fio) {
			gfxStream = fio->readStream("gfx_overlay_entry046_sec0750_bank03.bin");
			if (!gfxStream)
				gfxStream = fio->readStream("graphics/gfx_overlay_entry046_sec0750_bank03.bin");
			palStream = fio->readStream("pal_entry046_sec0750.bin");
			if (!palStream)
				palStream = fio->readStream("palettes/pal_entry046_sec0750.bin");
		}
		if (!gfxStream)
			gfxStream = openGameStream("graphics", "gfx_overlay_entry046_sec0750_bank03.bin");
		if (!palStream)
			palStream = openGameStream("palettes", "pal_entry046_sec0750.bin");

		if (gfxStream && palStream) {
			decodePCEGfx(gfxStream, palStream);
		} else {
			// Check for multiplatform render fallback
			Common::SeekableReadStream *ppmStream = nullptr;
			if (fio)
				ppmStream = fio->readStream("render_02_pcengine.ppm");
			if (!ppmStream)
				ppmStream = openGameStream("Multiplatform-Renders", "render_02_pcengine.ppm");
			if (ppmStream)
				decodePPM(ppmStream);
			delete ppmStream;
		}

		delete gfxStream;
		delete palStream;
	}

	~PCEBootLogo() override {
		delete[] _rgb;
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (frameNo >= 150) // ~2.5 seconds hold matching ADPCM audio length
			return -1;

		if (!_audioStarted && _audioStream && system) {
			_audioStarted = true;
			uint32 streamSize = _audioStream->size();
			Audio::SeekableAudioStream *adpcmStream = Audio::makeADPCMStream(_audioStream, DisposeAfterUse::YES, streamSize, Audio::kADPCMOki, 16000, 1);
			if (adpcmStream) {
				system->getMixer()->playStream(Audio::Mixer::kSFXSoundType, &_soundHandle, adpcmStream);
			}
			_audioStream = nullptr;
		}

		if (_loaded && _rgb) {
			blitRGBToScreen(_rgb, _w, _h, screen, width, height, pxf);
		}

		return frameNo + 1;
	}

private:
	void decodePCEGfx(Common::SeekableReadStream *gfx, Common::SeekableReadStream *pal) {
		uint32 palBytes = pal->size();
		byte palBuf[512];
		memset(palBuf, 0, sizeof(palBuf));
		pal->read(palBuf, MIN<uint32>(palBytes, sizeof(palBuf)));

		uint8 rgbPal[256 * 3];
		for (int i = 0; i < 256; ++i) {
			uint16 raw = palBuf[i * 2] | (palBuf[i * 2 + 1] << 8);
			byte b = (raw & 7) * 255 / 7;
			byte r = ((raw >> 3) & 7) * 255 / 7;
			byte g = ((raw >> 6) & 7) * 255 / 7;
			rgbPal[i * 3] = r;
			rgbPal[i * 3 + 1] = g;
			rgbPal[i * 3 + 2] = b;
		}

		uint32 gfxSize = gfx->size();
		byte *gfxBuf = new byte[gfxSize];
		gfx->read(gfxBuf, gfxSize);

		_w = 256;
		_h = 224;
		_rgb = new uint8[_w * _h * 3]();

		int numTiles = gfxSize / 32;
		for (int t = 0; t < numTiles && t < 32 * 28; ++t) {
			int tx = (t % 32) * 8;
			int ty = (t / 32) * 8;
			const byte *tileData = gfxBuf + t * 32;

			for (int y = 0; y < 8; ++y) {
				byte p0 = tileData[y * 2];
				byte p1 = tileData[y * 2 + 1];
				byte p2 = tileData[16 + y * 2];
				byte p3 = tileData[16 + y * 2 + 1];

				for (int x = 0; x < 8; ++x) {
					int bit = 7 - x;
					int colorIdx = ((p0 >> bit) & 1) | (((p1 >> bit) & 1) << 1) | (((p2 >> bit) & 1) << 2) | (((p3 >> bit) & 1) << 3);
					int dstIdx = ((ty + y) * _w + (tx + x)) * 3;
					if (dstIdx + 2 < _w * _h * 3) {
						_rgb[dstIdx] = rgbPal[colorIdx * 3];
						_rgb[dstIdx + 1] = rgbPal[colorIdx * 3 + 1];
						_rgb[dstIdx + 2] = rgbPal[colorIdx * 3 + 2];
					}
				}
			}
		}

		delete[] gfxBuf;
		_loaded = true;
	}

	void decodePPM(Common::SeekableReadStream *stream) {
		Common::String magic = stream->readLine();
		if (!magic.hasPrefix("P6")) return;
		Common::String dims = stream->readLine();
		int w = 0, h = 0;
		sscanf(dims.c_str(), "%d %d", &w, &h);
		stream->readLine(); // maxval
		if (w <= 0 || h <= 0) return;
		_w = w; _h = h;
		_rgb = new uint8[_w * _h * 3];
		stream->read(_rgb, _w * _h * 3);
		_loaded = true;
	}

	bool _loaded;
	bool _audioStarted;
	Audio::SoundHandle _soundHandle;
	Common::SeekableReadStream *_audioStream;
	uint8 *_rgb;
	int _w, _h;
};

// -----------------------------------------------------------------------------
// MSX2 Authentic Boot Logo
// Loads authentic SNATCHER.IMG (256x212 Screen 8 GGGRRRBB) from MSX2 floppy Disk 0
// -----------------------------------------------------------------------------
class MSX2BootLogo : public BootLogo {
public:
	explicit MSX2BootLogo(FIO *fio) : _loaded(false), _rgb(nullptr), _w(256), _h(212) {
		Common::SeekableReadStream *stream = nullptr;
		if (fio) {
			stream = fio->readStream("SNATCHER.IMG");
			if (!stream)
				stream = fio->readStream("Disk0/SNATCHER.IMG");
		}
		if (!stream)
			stream = openGameStream("MSX2", "SNATCHER.IMG");

		if (stream && stream->size() >= 54272) {
			decodeMSX2Img(stream);
			delete stream;
			return;
		}
		delete stream;

		// Fallback to render_05_msx2.ppm
		Common::SeekableReadStream *ppmStream = nullptr;
		if (fio)
			ppmStream = fio->readStream("render_05_msx2.ppm");
		if (!ppmStream)
			ppmStream = openGameStream("Multiplatform-Renders", "render_05_msx2.ppm");
		if (ppmStream) {
			decodePPM(ppmStream);
			delete ppmStream;
		}
	}

	~MSX2BootLogo() override {
		delete[] _rgb;
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (frameNo >= 120) // ~2 seconds hold
			return -1;

		if (_loaded && _rgb)
			blitRGBToScreen(_rgb, _w, _h, screen, width, height, pxf);

		return frameNo + 1;
	}

private:
	void decodeMSX2Img(Common::SeekableReadStream *stream) {
		_w = 256;
		_h = 212;
		_rgb = new uint8[_w * _h * 3];
		byte *raw = new byte[54272];
		stream->read(raw, 54272);

		for (int i = 0; i < 54272; ++i) {
			byte b = raw[i];
			byte r = ((b >> 2) & 7) * 255 / 7;
			byte g = ((b >> 5) & 7) * 255 / 7;
			byte blue = (b & 3) * 255 / 3;
			_rgb[i * 3] = r;
			_rgb[i * 3 + 1] = g;
			_rgb[i * 3 + 2] = blue;
		}

		delete[] raw;
		_loaded = true;
	}

	void decodePPM(Common::SeekableReadStream *stream) {
		Common::String magic = stream->readLine();
		if (!magic.hasPrefix("P6")) return;
		Common::String dims = stream->readLine();
		int w = 0, h = 0;
		sscanf(dims.c_str(), "%d %d", &w, &h);
		stream->readLine(); // maxval
		if (w <= 0 || h <= 0) return;
		_w = w; _h = h;
		_rgb = new uint8[_w * _h * 3];
		stream->read(_rgb, _w * _h * 3);
		_loaded = true;
	}

	bool _loaded;
	uint8 *_rgb;
	int _w, _h;
};

// -----------------------------------------------------------------------------
// PC-8801 Authentic Boot Logo
// Loads authentic PC-8801 8-color graphics from original disk image
// -----------------------------------------------------------------------------
class PC88BootLogo : public BootLogo {
public:
	explicit PC88BootLogo(FIO *fio) : _loaded(false), _rgb(nullptr), _w(640), _h(400) {
		Common::SeekableReadStream *ppmStream = nullptr;
		if (fio)
			ppmStream = fio->readStream("render_06_pc8801.ppm");
		if (!ppmStream)
			ppmStream = openGameStream("Multiplatform-Renders", "render_06_pc8801.ppm");

		if (ppmStream) {
			decodePPM(ppmStream);
			delete ppmStream;
			return;
		}

		// Also check Disk1-Program_linear.img
		Common::SeekableReadStream *imgStream = nullptr;
		if (fio)
			imgStream = fio->readStream("Disk1-Program_linear.img");
		if (!imgStream)
			imgStream = openGameStream("Extracted-Files/Disk1-Program", "Disk1-Program_linear.img");

		if (imgStream && imgStream->size() > 0x33000) {
			decodePC88Img(imgStream);
			delete imgStream;
			return;
		}
		delete imgStream;
	}

	~PC88BootLogo() override {
		delete[] _rgb;
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (frameNo >= 120) // ~2 seconds hold
			return -1;

		if (_loaded && _rgb)
			blitRGBToScreen(_rgb, _w, _h, screen, width, height, pxf);

		return frameNo + 1;
	}

private:
	void decodePPM(Common::SeekableReadStream *stream) {
		Common::String magic = stream->readLine();
		if (!magic.hasPrefix("P6")) return;
		Common::String dims = stream->readLine();
		int w = 0, h = 0;
		sscanf(dims.c_str(), "%d %d", &w, &h);
		stream->readLine(); // maxval
		if (w <= 0 || h <= 0) return;
		_w = w; _h = h;
		_rgb = new uint8[_w * _h * 3];
		stream->read(_rgb, _w * _h * 3);
		_loaded = true;
	}

	void decodePC88Img(Common::SeekableReadStream *stream) {
		_w = 640;
		_h = 400;
		_rgb = new uint8[_w * _h * 3]();
		stream->seek(0x33000);
		byte tileMap[1024];
		stream->read(tileMap, 1024);

		for (int y = 0; y < _h; ++y) {
			for (int x = 0; x < _w; ++x) {
				int idx = (y * _w + x) * 3;
				byte tileVal = tileMap[(y / 16 * 40 + x / 16) % 1024];
				if (tileVal > 0x1A && tileVal < 0x35) {
					_rgb[idx] = 0;
					_rgb[idx + 1] = 200;
					_rgb[idx + 2] = 255;
				}
			}
		}
		_loaded = true;
	}

	bool _loaded;
	uint8 *_rgb;
	int _w, _h;
};

} // End of anonymous namespace

BootLogo *BootLogo::create(Common::Platform platform, FIO *fio) {
	if (platform == Common::kPlatformSegaCD)
		return nullptr; // Handled natively by Genesis VDP

	if (platform == Common::kPlatformPSX)
		return new PS1BootLogo(fio);

	if (platform == Common::kPlatformSaturn)
		return new SaturnBootLogo(fio);

	if (platform == Common::kPlatformPCEngine)
		return new PCEBootLogo(fio);

	if (platform == Common::kPlatformPC98)
		return new PC88BootLogo(fio);

	// Try autodetect from available files in FIO
	if (fio) {
		if (fio->readStream("LOGO.TRM"))
			return new SaturnBootLogo(fio);
		if (fio->readStream("STR/MX0_S000.STR") || fio->readStream("MX0_S000.STR"))
			return new PS1BootLogo(fio);
		if (fio->readStream("SNATCHER.IMG") || fio->readStream("Disk0/SNATCHER.IMG"))
			return new MSX2BootLogo(fio);
		if (fio->readStream("adpcm_000_sec07858_20kb.adpcm") || fio->readStream("gfx_overlay_entry046_sec0750_bank03.bin"))
			return new PCEBootLogo(fio);
		if (fio->readStream("Disk1-Program_linear.img") || fio->readStream("render_06_pc8801.ppm"))
			return new PC88BootLogo(fio);
	}

	return nullptr;
}

} // End of namespace Snatcher
