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