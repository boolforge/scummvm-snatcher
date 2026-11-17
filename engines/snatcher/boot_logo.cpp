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
#include "video/psx_decoder.h"
#include "video/avi_decoder.h"
#include "common/archive.h"
#include "common/config-manager.h"
#include "common/file.h"
#include "common/stream.h"
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

		// 4 bytes subheader: file=0, chan=1, submode=CDXA_TYPE_VIDEO (0x02), coding=0
		_sectorBuf[16] = 0;
		_sectorBuf[17] = 1;    // Channel 1
		_sectorBuf[18] = 0x02; // CDXA_TYPE_VIDEO
		_sectorBuf[19] = 0;

		// 4 bytes subheader copy
		memcpy(_sectorBuf + 20, _sectorBuf + 16, 4);

		// 2048 bytes user data (MDEC sector chunks)
		uint32 readBytes = _stream->read(_sectorBuf + 24, kUserSectorSize);
		if (readBytes < kUserSectorSize)
			memset(_sectorBuf + 24 + readBytes, 0, kUserSectorSize - readBytes);

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
// PS1 Authentic Boot Video Logo
// Plays MX0_S000.STR (Konami intro movie) directly from original game assets
// -----------------------------------------------------------------------------
class PS1BootLogo : public BootLogo {
public:
	PS1BootLogo() : _decoder(Video::PSXStreamDecoder::kCD2x), _loaded(false), _lastSurface(nullptr) {
		Common::SeekableReadStream *stream = openGameStream("STR", "MX0_S000.STR");
		if (!stream)
			return;

		Common::SeekableReadStream *rawStream = new PSXRawSectorReadStream(stream);
		if (_decoder.loadStream(rawStream)) {
			_decoder.start();
			_loaded = true;
		}
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (!_loaded)
			return -1;

		if (_decoder.endOfVideo())
			return -1;

		const Graphics::Surface *frame = _decoder.decodeNextFrame();
		if (frame) {
			_lastSurface = frame;
		}

		if (_lastSurface) {
			blitFrameToScreen(_lastSurface, screen, width, height, pxf);
		}

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
	SaturnBootLogo() : _loaded(false), _lastSurface(nullptr) {
		Common::SeekableReadStream *stream = openGameStream("", "LOGO.TRM");
		if (!stream)
			return;

		if (_decoder.loadStream(stream)) {
			_decoder.start();
			_loaded = true;
		}
	}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		if (!_loaded)
			return -1;

		if (_decoder.endOfVideo())
			return -1;

		const Graphics::Surface *frame = _decoder.decodeNextFrame();
		if (frame) {
			_lastSurface = frame;
		}

		if (_lastSurface) {
			blitFrameToScreen(_lastSurface, screen, width, height, pxf);
		}

		return frameNo + 1;
	}

private:
	Video::AVIDecoder _decoder;
	bool _loaded;
	const Graphics::Surface *_lastSurface;
};

// -----------------------------------------------------------------------------
// PC-8801 / MSX2 / PC Engine Fallback Banners
// -----------------------------------------------------------------------------
struct Glyph {
	char c;
	uint8 rows[7];
};

const Glyph kFont[] = {
	{'A', {0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}}, {'B', {0x1E, 0x11, 0x11, 0x1E, 0x11, 0x11, 0x1E}},
	{'C', {0x0E, 0x11, 0x10, 0x10, 0x10, 0x11, 0x0E}}, {'D', {0x1E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1E}},
	{'E', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x1F}}, {'F', {0x1F, 0x10, 0x10, 0x1E, 0x10, 0x10, 0x10}},
	{'G', {0x0E, 0x11, 0x10, 0x17, 0x11, 0x11, 0x0F}}, {'H', {0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11}},
	{'I', {0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E}}, {'J', {0x07, 0x02, 0x02, 0x02, 0x02, 0x12, 0x0C}},
	{'K', {0x11, 0x12, 0x14, 0x18, 0x14, 0x12, 0x11}}, {'L', {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F}},
	{'M', {0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11}}, {'N', {0x11, 0x11, 0x19, 0x15, 0x13, 0x11, 0x11}},
	{'O', {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}}, {'P', {0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, 0x10}},
	{'Q', {0x0E, 0x11, 0x11, 0x11, 0x15, 0x12, 0x0D}}, {'R', {0x1E, 0x11, 0x11, 0x1E, 0x14, 0x12, 0x11}},
	{'S', {0x0F, 0x10, 0x10, 0x0E, 0x01, 0x01, 0x1E}}, {'T', {0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04}},
	{'U', {0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E}}, {'V', {0x11, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x04}},
	{'W', {0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11}}, {'X', {0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11}},
	{'Y', {0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04}}, {'Z', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x10, 0x1F}},
	{'0', {0x0E, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0E}}, {'1', {0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E}},
	{'2', {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F}}, {'3', {0x1F, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0E}},
	{'4', {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02}}, {'5', {0x1F, 0x10, 0x1E, 0x01, 0x01, 0x11, 0x0E}},
	{'6', {0x06, 0x08, 0x10, 0x1E, 0x11, 0x11, 0x0E}}, {'7', {0x1F, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08}},
	{'8', {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E}}, {'9', {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x02, 0x0C}},
	{'(', {0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02}}, {')', {0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08}},
	{'.', {0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C}}, {',', {0x00, 0x00, 0x00, 0x00, 0x0C, 0x04, 0x08}},
	{'-', {0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00}}
};

struct PlatformBanner {
	Common::Platform platform;
	const char *system;
	const char *copyright;
};

const PlatformBanner kBanners[] = {
	{Common::kPlatformPC98,      "PC-8801 VERSION",       "(C) 1988 KONAMI"},
	{Common::kPlatformUnknown,   "MSX2 / PC-88 VERSION",  "(C) 1988 KONAMI"},
	{Common::kPlatformPCEngine,  "SUPER CD-ROM2 VERSION", "(C) 1992 KONAMI"}
};

const int kFadeFrames = 30;
const int kHoldFrames = 150;

class BannerBootLogo : public BootLogo {
public:
	BannerBootLogo(const PlatformBanner &b) : _b(b), _paletteSet(false) {}

	int drawFrame(uint8 *screen, int width, int height, const Graphics::PixelFormat &pxf, OSystem *system, int frameNo) override {
		const int total = kFadeFrames * 2 + kHoldFrames;
		if (frameNo >= total)
			return -1;

		int level = 255;
		if (frameNo < kFadeFrames)
			level = frameNo * 255 / kFadeFrames;
		else if (frameNo >= kFadeFrames + kHoldFrames)
			level = (total - frameNo) * 255 / kFadeFrames;

		const int bpp = pxf.bytesPerPixel ? pxf.bytesPerPixel : 1;
		if (bpp == 1 && !_paletteSet) {
			byte pal[256 * 3];
			for (int i = 0; i < 256; ++i)
				pal[i * 3] = pal[i * 3 + 1] = pal[i * 3 + 2] = i;
			system->getPaletteManager()->setPalette(pal, 0, 256);
			_paletteSet = true;
		}

		const uint32 color = (bpp == 1) ? (uint32)level : pxf.RGBToColor(level, level, level);
		const uint32 konamiOrange = (bpp == 1) ? (uint32)(level * 210 / 255) : pxf.RGBToColor(level * 228 / 255, level * 94 / 255, 0);
		const uint32 konamiRed = (bpp == 1) ? (uint32)(level * 180 / 255) : pxf.RGBToColor(level * 196 / 255, 0, level * 26 / 255);
		memset(screen, 0, width * height * bpp);

		const int cx = width / 2;
		const int cy = height / 3 - 8;
		const int rScale = MAX(1, width / 200);

		for (int dy = -16 * rScale; dy <= -4 * rScale; ++dy) {
			int y = cy + dy;
			int row = dy / rScale + 16;
			int xStart = cx - 28 * rScale + (row * 3 * rScale) / 2;
			int xEnd = xStart + 24 * rScale;
			for (int x = xStart; x < xEnd; ++x) {
				putPixel(screen, width, height, bpp, konamiOrange, x, y);
			}
		}

		for (int dy = -2 * rScale; dy <= 10 * rScale; ++dy) {
			int y = cy + dy;
			int row = dy / rScale + 2;
			int xStart = cx - 22 * rScale + (row * 3 * rScale) / 2;
			int xEnd = xStart + 24 * rScale;
			for (int x = xStart; x < xEnd; ++x) {
				putPixel(screen, width, height, bpp, konamiRed, x, y);
			}
		}

		const int scale = MAX(1, width / 256);
		drawCentered(screen, width, height, bpp, color, "KONAMI", cy + 18 * rScale, scale * 3);
		drawCentered(screen, width, height, bpp, color, _b.system, height * 2 / 3, scale);
		drawCentered(screen, width, height, bpp, color, _b.copyright, height * 2 / 3 + 12 * scale, scale);
		return frameNo + 1;
	}

private:
	static const Glyph *findGlyph(char c) {
		for (uint i = 0; i < ARRAYSIZE(kFont); ++i)
			if (kFont[i].c == c)
				return &kFont[i];
		return nullptr;
	}

	static void putPixel(uint8 *screen, int width, int height, int bpp, uint32 color, int x, int y) {
		if (x < 0 || y < 0 || x >= width || y >= height)
			return;
		uint8 *p = screen + (y * width + x) * bpp;
		for (int i = 0; i < bpp; ++i)
			p[i] = (color >> (8 * i)) & 0xFF;
	}

	static void drawCentered(uint8 *screen, int width, int height, int bpp, uint32 color, const char *text, int y, int s) {
		const int len = strlen(text);
		const int x0 = (width - len * 6 * s) / 2;
		for (int n = 0; n < len; ++n) {
			const Glyph *g = findGlyph(text[n]);
			if (!g)
				continue;
			for (int row = 0; row < 7; ++row)
				for (int col = 0; col < 5; ++col)
					if (g->rows[row] & (0x10 >> col))
						for (int dy = 0; dy < s; ++dy)
							for (int dx = 0; dx < s; ++dx)
								putPixel(screen, width, height, bpp, color, x0 + (n * 6 + col) * s + dx, y + row * s + dy);
		}
	}

	PlatformBanner _b;
	bool _paletteSet;
};

} // End of anonymous namespace

BootLogo *BootLogo::create(Common::Platform platform) {
	if (platform == Common::kPlatformSegaCD)
		return nullptr; // Handled natively by Animator_SCD

	if (platform == Common::kPlatformPSX)
		return new PS1BootLogo();

	if (platform == Common::kPlatformSaturn)
		return new SaturnBootLogo();

	for (uint i = 0; i < ARRAYSIZE(kBanners); ++i)
		if (kBanners[i].platform == platform)
			return new BannerBootLogo(kBanners[i]);

	return nullptr;
}

} // End of namespace Snatcher
