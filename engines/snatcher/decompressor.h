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

#ifndef SNATCHER_DECOMPRESSOR_H
#define SNATCHER_DECOMPRESSOR_H

#include "common/scummsys.h"
#include "common/types.h"

namespace Snatcher {

/**
 * Native in-engine decompressors for all platform-specific Snatcher asset formats:
 * - PlayStation 1 LZSS (4096-byte ring buffer, MSB-first bitstream, offset 4)
 * - Sega Saturn LZ3 (3-stream hybrid: LSB-first 32-bit bit words, 16-bit tokens, byte literals)
 * - PC Engine Super CD-ROM2 VDC planar tile RLE
 */
class Decompressor {
public:
	/**
	 * Decompress PlayStation 1 LZSS bitstream (used in DES/ * /C*.BIN files).
	 * Header: 01 00 00 00 (4 bytes), followed by MSB-first LZSS bitstream.
	 *
	 * @param src Pointer to compressed data (including 4-byte header or raw bitstream).
	 * @param srcSize Size of input compressed data.
	 * @param dst Output buffer.
	 * @param maxDstSize Capacity of output buffer.
	 * @param offset Byte offset in src where the bitstream begins (typically 4 if header is present).
	 * @return Number of decompressed bytes, or 0 on error.
	 */
	static uint32 decompressPS1LZSS(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize, uint32 offset = 4);

	/**
	 * Decompress Sega Saturn LZ3 chunk (used in DATA.BIN chunks, MAIN_L.BIN at 0x060CB548).
	 * Header: u32 outsize, u16 nwords, u16 nhalf (all big-endian).
	 *
	 * @param src Pointer to compressed chunk.
	 * @param srcSize Size of input chunk.
	 * @param dst Output buffer (must have capacity >= outsize).
	 * @param maxDstSize Capacity of output buffer.
	 * @return Number of decompressed bytes (matching declared outsize), or 0 on error.
	 */
	static uint32 decompressSaturnLZ3(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize);

	/**
	 * Decompress PC Engine Super CD-ROM2 VDC planar tile RLE stream ($7061 / $71B0).
	 *
	 * @param src Pointer to RLE stream.
	 * @param srcSize Size of input stream buffer.
	 * @param dst Output buffer for decoded planar tile data.
	 * @param maxDstSize Capacity of output buffer.
	 * @param bytesRead Optional pointer to receive the number of compressed bytes consumed.
	 * @return Number of decompressed bytes produced.
	 */
	static uint32 decompressPCERLE(const uint8 *src, uint32 srcSize, uint8 *dst, uint32 maxDstSize, uint32 *bytesRead = nullptr);

	/**
	 * Detect if a data buffer begins with the PS1 LZSS compression signature.
	 */
	static bool isPS1LZSS(const uint8 *data, uint32 size);

	/**
	 * Detect if a data buffer begins with a valid Saturn LZ3 chunk header.
	 */
	static bool isSaturnLZ3(const uint8 *data, uint32 size);
};

} // End of namespace Snatcher

#endif // SNATCHER_DECOMPRESSOR_H
