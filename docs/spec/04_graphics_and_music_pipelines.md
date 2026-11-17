# 04: Graphics & Music Pipelines Specification

Deterministic technical reference for graphics packing, palette management, and audio synthesizing across all 6 ports.

---

## 1. Graphics Subsystem Architectures

| Platform | Color Depth | Resolution | Hardware Architecture | Native Cell/Tile Packing |
|---|---|---|---|---|
| **PC-8801** | 3-bit (8 fixed colors) | 640x200 | Digital RGB CRT | Planar 3-bit: B, R, G planes |
| **MSX2** | 4bpp (16 colors from 512) | 256x212 / 512x212 | Yamaha V9938 (Screen 5) | Linear 4bpp nibbles; hardware blitter (HMMM/LMMC) |
| **PC Engine** | 4bpp (16 palettes of 16 colors) | 256x224 | Hudson HuC6270 VDC | 8x8 character tiles (4-bit planar) |
| **Sega CD** | 4bpp (4 palettes of 16 colors) | 320x224 | Yamaha VDP Mode 4/5 | 8x8 cell tiles (4bpp packed nibbles) |
| **PlayStation** | 4/8/16bpp (Direct/CLUT) | 320x240 | Sony GPU / MDEC | TIM texture containers / MDEC macroblocks |
| **Sega Saturn** | 8/16bpp | 320x224 / 352x240 | Sega VDP1 & VDP2 | Framebuffer sprites / TrueMotion 1 frames |

---

## 2. Audio & Voice Synthesizing Pipelines

### 2.1. FM Synthesizer & Sound Chips
- **PC-8801:** YM2203 (OPN): 3 FM channels + 3 SSG (AY-3-8910) channels.
- **MSX2:** AY-3-8910 PSG + Konami SCC (051649) 5-channel wavetable synthesis.
- **PC Engine:** HuC6280 6-channel wavetable + OKI MSM5205 ADPCM voice driver.
- **Sega CD:** Yamaha YM2612 (6 FM channels) + Ricoh RF5C164 (8 PCM channels @ 32kHz).
- **PlayStation:** SPU 24-channel ADPCM with digital reverb and hardware pitch modulation.
- **Sega Saturn:** SCSP (Yamaha YMF292-F) 32-channel PCM/FM DSP processor.

### 2.2. Lip-Sync & Voice Triggering
Opcodes `o_chatWithPortraitAnim` and `o_pcmSound` synchronously drive portrait mouth/eye sprite cycles while checking voice channel playback status (`m_pcmWait`).

---

## 3. PlayStation 1 DES Container & VRAM Layout

Decompressed PS1 `DES/*.BIN` graphics buffers (via `Decompressor::decompressPS1LZSS`) adhere to a fixed binary header layout indexing sprite elements and standard Sony PlayStation TIM structures:

```c
struct PS1_DES_ChunkHeader {
    uint32_t offsetLayer1;     // Byte offset to background tile layer (e.g. 0x00006234)
    uint32_t offsetLayer2;     // Byte offset to overlay tile layer (e.g. 0x00004310)
    uint32_t offsetAnimTable;  // Byte offset to animation metadata (e.g. 0x00000210)
    uint32_t flags;            // Layer display mode & CLUT bit depth (e.g. 0x00000008)
};
```

Sub-elements within decompressed `DES` streams:
- `+0x0000`: 32-bit offset table referencing graphics sub-chunks.
- `+0x00C3`: Embedded Sony PlayStation TIM image file signatures (`0x10 0x00 0x00 0x00`).
  - Standard TIM header: `Tag (0x10)`, `Version/Flags (4bpp=0x08, 8bpp=0x09, 16bpp=0x02)`, `CLUT Header (X, Y, W, H, Colors)`, `Pixel Data Block (X, Y, W, H)`.

---

## 4. Sega Saturn DATA.BIN & LZ3 Stream Format

Sega Saturn `DATA.BIN` contains sequentially concatenated, sector-aligned LZ3-compressed graphic and scenario chunks.

```c
struct Saturn_LZ3_Header {
    uint32_t uncompressedSize; // Big-endian 32-bit unpacked payload size
    uint16_t numBitWords;      // Count of 32-bit control words (nw)
    uint16_t numTokens;        // Count of 16-bit match tokens (nh)
    // Followed immediately by:
    // uint32_t bitstream[numBitWords];
    // uint16_t tokens[numTokens];
    // uint8_t  literals[];
};
```

### Decompression State Machine
- Read bits sequentially from `bitstream` (MSB to LSB):
  - `0`: Emit literal byte from `literals`.
  - `1`: Match reference.
    - If next bit is `1`: Short match (`len = (bits(2) + 2)`, `dist = literal_byte + 1`).
    - If next bit is `0`: Read 16-bit word `w` from `tokens`.
      - If `w == 0`: End-of-stream terminator.
      - If `(w & 0x0F) != 0`: `len = (w & 0x0F) + 2`, `dist = (w >> 4) + 1`.
      - If `(w & 0x0F) == 0`: Long match (`len = next_literal_byte`, `dist = (w >> 4)`).