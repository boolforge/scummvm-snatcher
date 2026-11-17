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

#include "snatcher/decompressor.h"
#include "common/endian.h"
#include "common/textconsole.h"
#include "common/util.h"

namespace Snatcher {

bool Decompressor::isPS1LZSS(const uint8 *data, uint32 size) {
	if (!data || size < 8)
		return false;
	return (data[0] == 0x01 && data[1] == 0x00 && data[2] == 0x00 && data[3] == 0x00);
}

bool Decompressor::isSaturnLZ3(const uint8 *data, uint32 size) {
	if (!data || size < 8)
		return false;
	uint32 outsize = READ_BE_UINT32(data);
	uint16 nw = READ_BE_UINT16(data + 4);
	uint16 nh = READ_BE_UINT16(data + 6);
	if (outsize == 0 || nw == 0 || outsize > 0x1000000)
		return false;
	uint32 minSize = 8 + (nw * 4) + (nh * 2);
	return (minSize <= size);
}

uint32 Decompressor::decompressPS1LZSS(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize, uint32 offset) {
	if (!src || !dst || srcSize <= offset || maxDstSize == 0)
		return 0;

	uint32 srcPos = offset;
	uint32 dstPos = 0;
	uint8 ring[4096];
	memset(ring, 0, sizeof(ring));
	uint16 ringWritePos = 1;

	uint8 mask = 0x80;
	uint8 curByte = 0;

	auto getBit = [&]() -> uint32 {
		uint8 oldMask = mask;
		if (mask == 0x80) {
			if (srcPos >= srcSize)
				return 0;
			curByte = src[srcPos++];
		}
		mask >>= 1;
		if (mask == 0)
			mask = 0x80;
		return (curByte & oldMask) ? 1 : 0;
	};

	auto getNBits = [&](int n) -> uint32 {
		uint32 acc = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (getBit())
				acc |= (1 << i);
		}
		return acc;
	};

	while (srcPos <= srcSize && dstPos < maxDstSize) {
		if (srcPos == srcSize && mask == 0x80)
			break;

		if (getBit()) {
			// Literal byte
			uint8 val = (uint8)getNBits(8);
			if (dstPos < maxDstSize)
				dst[dstPos++] = val;
			ring[ringWritePos] = val;
			ringWritePos = (ringWritePos + 1) & 0x0FFF;
		} else {
			// Match reference
			uint16 pos = (uint16)getNBits(12);
			if (pos == 0) {
				// Terminator
				break;
			}
			uint32 len = getNBits(4) + 2;
			for (uint32 i = 0; i < len; ++i) {
				uint8 val = ring[(pos + i) & 0x0FFF];
				if (dstPos < maxDstSize)
					dst[dstPos++] = val;
				ring[ringWritePos] = val;
				ringWritePos = (ringWritePos + 1) & 0x0FFF;
			}
		}
	}

	return dstPos;
}

uint32 Decompressor::decompressSaturnLZ3(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize) {
	if (!src || !dst || srcSize < 8)
		return 0;

	uint32 outsize = READ_BE_UINT32(src);
	uint16 nw = READ_BE_UINT16(src + 4);
	uint16 nh = READ_BE_UINT16(src + 6);

	uint32 bitsOffset = 8;
	uint32 tokOffset = bitsOffset + ((uint32)nw * 4);
	uint32 litOffset = tokOffset + ((uint32)nh * 2);

	if (litOffset > srcSize || nw == 0)
		return 0;

	uint32 bp = bitsOffset;
	uint32 tp = tokOffset;
	uint32 lp = litOffset;

	uint32 word = READ_BE_UINT32(src + bp);
	bp += 4;
	int nb = 32;

	auto getBit = [&]() -> uint32 {
		--nb;
		uint32 t = word & 1;
		word >>= 1;
		if (nb == 0) {
			nb = 32;
			if (bp + 4 <= tokOffset) {
				word = READ_BE_UINT32(src + bp);
			} else {
				word = 0;
			}
			bp += 4;
		}
		return t;
	};

	uint32 dstPos = 0;

	while (dstPos < maxDstSize && dstPos < outsize) {
		if (getBit() == 0) {
			// Literal byte
			if (lp >= srcSize)
				break;
			dst[dstPos++] = src[lp++];
			continue;
		}

		uint32 dist = 0;
		uint32 len = 0;

		if (getBit() == 1) {
			// Short match
			if (lp >= srcSize)
				break;
			uint32 off = src[lp++];
			uint32 n = getBit();
			n = (n << 1) | getBit();
			len = n + 2;
			dist = off + 1;
		} else {
			// Token stream
			if (tp + 2 > litOffset)
				break;
			uint16 w = READ_BE_UINT16(src + tp);
			tp += 2;
			if (w == 0) {
				// End of stream
				break;
			}
			uint32 n = w & 15;
			uint32 off = w >> 4;
			if (n != 0) {
				len = n + 2;
				dist = off + 1;
			} else {
				if (lp >= srcSize)
					break;
				len = src[lp++];
				dist = off;
			}
		}

		if (dist == 0 || dist > dstPos) {
			warning("Decompressor::decompressSaturnLZ3: match before start (dist=%u, dstPos=%u)", dist, dstPos);
			break;
		}

		uint32 srcMatchPos = dstPos - dist;
		for (uint32 k = 0; k < len && dstPos < maxDstSize && dstPos < outsize; ++k) {
			dst[dstPos++] = dst[srcMatchPos + k];
		}
	}

	return dstPos;
}

uint32 Decompressor::decompressPCERLE(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize, uint32 *bytesRead) {
	if (!src || !dst || srcSize == 0 || maxDstSize == 0) {
		if (bytesRead)
			*bytesRead = 0;
		return 0;
	}

	uint32 pos = 0;
	uint32 outPos = 0;

	while (pos < srcSize && outPos < maxDstSize) {
		uint8 c = src[pos++];

		if (c & 0x80) {
			if (c == 0xFF) {
				// Clean stream termination
				break;
			}
			if (c == 0x80) {
				if (pos + 2 > srcSize)
					break;
				uint16 count = src[pos] | ((uint16)src[pos + 1] << 8);
				pos += 2;
				for (uint16 i = 0; i < count && pos < srcSize && outPos < maxDstSize; ++i) {
					dst[outPos++] = src[pos++];
				}
			} else if (c == 0xFE) {
				if (pos + 5 > srcSize)
					break;
				uint32 count = src[pos++];
				if (count == 0)
					count = 256;
				uint8 b1 = src[pos++];
				uint8 b2 = src[pos++];
				uint8 b3 = src[pos++];
				uint8 b4 = src[pos++];
				for (uint32 i = 0; i < count && outPos + 4 <= maxDstSize; ++i) {
					dst[outPos++] = b1;
					dst[outPos++] = b2;
					dst[outPos++] = b3;
					dst[outPos++] = b4;
				}
			} else {
				uint8 k = c & 0x7F;
				if (k >= 0x40) {
					uint32 count = k & 0x3F;
					if (count == 0)
						count = 256;
					for (uint32 i = 0; i < count && pos < srcSize && outPos + 2 <= maxDstSize; ++i) {
						dst[outPos++] = 0;
						dst[outPos++] = src[pos++];
					}
				} else {
					for (uint8 i = 0; i < k && pos < srcSize && outPos < maxDstSize; ++i) {
						dst[outPos++] = src[pos++];
					}
				}
			}
		} else {
			if (c == 0x00) {
				if (pos + 2 > srcSize)
					break;
				uint32 count = src[pos++];
				if (count == 0)
					count = 256;
				uint8 b = src[pos++];
				for (uint32 i = 0; i < count && pos < srcSize && outPos + 2 <= maxDstSize; ++i) {
					dst[outPos++] = b;
					dst[outPos++] = src[pos++];
				}
			} else if (c == 0x01) {
				if (pos + 3 > srcSize)
					break;
				uint16 count = src[pos] | ((uint16)src[pos + 1] << 8);
				pos += 2;
				uint8 b = src[pos++];
				for (uint16 i = 0; i < count && outPos < maxDstSize; ++i) {
					dst[outPos++] = b;
				}
			} else if (c == 0x02) {
				if (pos + 3 > srcSize)
					break;
				uint32 count = src[pos++];
				if (count == 0)
					count = 256;
				uint8 b1 = src[pos++];
				uint8 b2 = src[pos++];
				for (uint32 i = 0; i < count && outPos + 2 <= maxDstSize; ++i) {
					dst[outPos++] = b1;
					dst[outPos++] = b2;
				}
			} else if (c < 0x40) {
				if (pos >= srcSize)
					break;
				uint8 b = src[pos++];
				for (uint8 i = 0; i < c && outPos < maxDstSize; ++i) {
					dst[outPos++] = b;
				}
			} else {
				uint32 count = c & 0x3F;
				if (count == 0)
					count = 256;
				for (uint32 i = 0; i < count && outPos < maxDstSize; ++i) {
					dst[outPos++] = 0;
				}
			}
		}
	}

	if (bytesRead)
		*bytesRead = pos;

	return outPos;
}

} // End of namespace Snatcher
