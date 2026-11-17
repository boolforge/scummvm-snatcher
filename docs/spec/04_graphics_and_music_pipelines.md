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

## 3. Graphics Decoding Pipeline (`GraphicsEngine`, `Animator`, `Palette`)

`GraphicsEngine` coordinates visual presentation through three subsystems:
1. **`GraphicsEngine::runScript(ResourcePointer res, int func)`**:
   - Dispatches scenario graphics scripts using a function pointer table.
   - Command opcodes:
     - `0x00`: `Palette::enqueueEvent` (loads palette changes).
     - `0x01`: `Animator::initData(sc, _dataMode)` (transfers tile/bitmap data into VRAM).
     - `0x02`: `Animator::initAnimations(sc, len, true)` (configures dynamic animation slots).
     - `0x03` / `0x04`: `Animator::linkAnimations` (links chained animation sequences).
     - `0x05`..`0x07`: Sets `_verbAreaType` (controls verb prompt window style).
     - `0x08`: `Animator::setPlaneMode(mode)` (sets display planes and priority).
     - `0x09`: `_dataMode = sc[1]` (handles multi-part 2048-byte DMA transfers).

2. **`Animator` Architecture**:
   - `Animator_SCD` handles Sega CD native VDP tile graphics (plane A, plane B, window plane, sprites).
   - `LinearAnimator` handles linear framebuffers for PlayStation (`320x240`), Saturn (`320x224`), and PC Engine (`256x224`).

3. **PlayStation 1 Native Asset Formats (`DES/` Streams)**:
   - PS1 graphic assets in `DES/` are compressed with Konami PS1 LZSS (detected by magic `01 00 00 00` at `+0x00` and decompressed via `Decompressor::decompressPS1LZSS`).
   - Binary streams are categorized into two core types:
     - **`CC3_B*.BIN` (Background and Palette Streams):**
       - `+0x00`: Table of 32-bit little-endian relative offsets pointing to image sub-blocks (`0x00006234`, `0x00004310`, `0x00000210`, etc.).
       - Sub-blocks contain 16-bit packed RGB555 CLUTs and linear 4bpp/8bpp pixel matrices blitted directly into PSX VRAM coordinates.
     - **`CXD_B*.BIN` (Cutscene and Dialogue Visual Data):**
       - Contains 16-bit little-endian command arrays (e.g. `[0, 0, 17248, 0, 17204, 0, 8, ...]`) encoding coordinate offsets, animation step counts, and palette index assignments.


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