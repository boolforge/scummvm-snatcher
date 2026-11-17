# 01: File Catalog & Container Formats Specification

Deterministic technical reference for all container formats, disk layouts, and asset files across all 6 Snatcher ports.

---

## 1. Platform Matrix Overview

| Platform | Target Hardware | Primary Media | Container Types | Audio Formats | Video/Cutscene Formats |
|---|---|---|---|---|---|
| **PC-8801** | Z80 @ 4MHz, 64KB RAM | 5x 5.25" D88 Disks | Raw sectors / Flat D88 | OPN (YM2203) FM+SSG | Planar 3-bit / 8 colors |
| **MSX2** | Z80 @ 3.58MHz, 64KB RAM | 3x 3.5" DSK (720KB) | FAT12 / Flat DSK | PSG + SCC (051649) | Screen 5 (V9938 4bpp) |
| **PC Engine** | HuC6280 @ 7.16MHz | CD-ROM2 (Super CD) | ISO 9660 Mode 1 + CUE | OKI MSM5205 ADPCM + CD-DA | 16-color VDC Tiles/Sprites |
| **Sega CD** | 68000 + Sub-CPU 12.5MHz | Sega CD (Disc) | ISO 9660 / Mode 1 | RF5C164 PCM + CD-DA | Genesis VDP 4bpp Cells |
| **PlayStation** | MIPS R3000A @ 33.8MHz | CD-ROM (XA) | ISO 9660 + Mode 2 Form 2 | SPU ADPCM (VAB) + CD-XA | MDEC STR (320x240 15fps) |
| **Sega Saturn** | 2x SH-2 @ 28.6MHz | CD-ROM | ISO 9660 (DATA.BIN) | SCSP PCM + AIFF | TrueMotion 1 AVI (.TRM) |

---

## 2. Container Formats & Sector Layouts

### 2.1. PlayStation MDEC `.STR` Stream (Mode 2 Form 2 Demuxed)
- **Sector Size:** 2048 bytes (User Data).
- **Framerate:** 15 fps (CD 2x speed: 150 sectors/sec; ~10 sectors per frame).
- **Header Layout (First 32 bytes of sector):**

```c
struct PSX_STR_SectorHeader {
    uint16 magic;        // 0x0160 (Little Endian)
    uint16 type;         // 0x8001 (MDEC Video chunk)
    uint16 chunk_index;  // 0-based chunk index for current frame
    uint16 chunk_count;  // Total chunks for current frame (e.g. 9 or 10)
    uint16 frame_index;  // 1-based video frame counter
    uint16 reserved;     // 0x0000
    uint32 frame_size;   // Demuxed frame size in bytes (e.g. 3276)
    uint16 width;        // Frame width (320)
    uint16 height;       // Frame height (240)
    uint8  padding[12];  // Zeroes
};
// Payload begins at byte offset 32 (2016 bytes per sector).
```

### 2.2. Sega Saturn `DATA.BIN` Container
- **Size:** 10,967,040 bytes.
- **Structure:** Sequential packed archive containing scene modules (`DATA_A0.BIN` .. `DATA_Q8.BIN`).
- **Magic / Header:** `00 00 cd a0 04 84 0f 6d`.

### 2.3. Sega CD `PCMLD_01.BIN` Voice / Audio Container
- **Size:** 84,748,288 bytes.
- **Structure:** Table of 8-bit sign-magnitude/offset RF5C164 PCM voice samples indexed by dialogue trigger IDs.
- **Magic / Header:** `00 00 5b 02 ff ff ff ff`.

---

## 3. Exhaustive Asset Inventory by Platform

### 3.1. PC88 Files (361 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `Disks/Snatcher (1988)(Konami)(Disk 1 of 5)(Program Disk).d88` | 426,240 | `00 00 00 00 00 00 00 00` | `........` | `e0a70bc3e5fa4485...` |
| `Disks/Snatcher (1988)(Konami)(Disk 1 of 5)(Program Disk)[a2].d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `4bee1471ca5f4b62...` |
| `Disks/Snatcher (1988)(Konami)(Disk 1 of 5)(Program Disk)[a].d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `d31d57b20b8a847b...` |
| `Disks/Snatcher (1988)(Konami)(Disk 2 of 5)(Data Disk 1).d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `c66ccb03bf066bc7...` |
| `Disks/Snatcher (1988)(Konami)(Disk 2 of 5)(Data Disk 1)[a].d88` | 436,640 | `00 00 00 00 00 00 00 00` | `........` | `95e666f4dbead586...` |
| `Disks/Snatcher (1988)(Konami)(Disk 3 of 5)(Data Disk 2).d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `0be4e3f448547540...` |
| `Disks/Snatcher (1988)(Konami)(Disk 3 of 5)(Data Disk 2)[a].d88` | 436,640 | `00 00 00 00 00 00 00 00` | `........` | `b051847a557b32b4...` |
| `Disks/Snatcher (1988)(Konami)(Disk 4 of 5)(Data Disk 3).d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `b0c49411bdcb0cf6...` |
| `Disks/Snatcher (1988)(Konami)(Disk 4 of 5)(Data Disk 3)[a].d88` | 436,640 | `00 00 00 00 00 00 00 00` | `........` | `a5e8fe3f77b1e0d4...` |
| `Disks/Snatcher (1988)(Konami)(Disk 5 of 5)(Data Disk 4).d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `33188a805d04091a...` |
| `Disks/Snatcher (1988)(Konami)(Disk 5 of 5)(Data Disk 4)[a2].d88` | 415,840 | `00 00 00 00 00 00 00 00` | `........` | `2e67a5551f51ba26...` |
| `Disks/Snatcher (1988)(Konami)(Disk 5 of 5)(Data Disk 4)[a].d88` | 436,640 | `00 00 00 00 00 00 00 00` | `........` | `e19f72e2c3a06e18...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_000_0x000000.bin` | 16,384 | `30 01 00 0c 00 00 00 01` | `0.......` | `59ea9f72eff4b99c...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_001_0x004000.bin` | 16,384 | `86 e1 c9 d5 dd 5e 0d dd` | `.....^..` | `e7bcce2aadaad2f6...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_002_0x008000.bin` | 16,384 | `1d 5b 05 20 51 71 10 5b` | `.[. Qq.[` | `f75cf85839c664cc...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_003_0x00C000.bin` | 16,384 | `e1 06 e1 06 e4 06 e1 06` | `........` | `8d4e809ced5626fc...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_004_0x010000.bin` | 16,384 | `ff ff ff ff ff ff ff ff` | `........` | `88dd2d3bf94a8fb3...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_005_0x014000.bin` | 16,384 | `b3 82 a2 82 76 81 2b ff` | `....v.+.` | `85e2d3aa056f8bc6...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_006_0x018000.bin` | 16,384 | `68 83 45 81 58 83 4a 83` | `h.E.X.J.` | `60122a5436e9409e...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_007_0x01C000.bin` | 16,384 | `62 83 68 83 78 81 cd 82` | `b.h.x...` | `1247801e2c6d72e9...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_008_0x020000.bin` | 16,384 | `00 43 f7 30 46 f4 f1 1e` | `.C.0F...` | `55f4c0600669eeb7...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_009_0x024000.bin` | 16,384 | `e8 01 f5 e8 01 f5 05 02` | `........` | `d043b8ad2152dd02...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_010_0x028000.bin` | 16,384 | `30 20 10 00 f0 0c e3 b0` | `0 ......` | `2c8e1f58b172eb4f...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_011_0x02C000.bin` | 16,384 | `a1 80 a1 60 a1 40 a1 20` | `...`.@. ` | `69c83bb1ef2b93f7...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_012_0x030000.bin` | 16,384 | `ff ff ff ff ff ff ff ff` | `........` | `822a70f272401543...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_013_0x034000.bin` | 16,384 | `ff ff a3 00 06 08 ff ff` | `........` | `d845199e0586cc34...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_014_0x038000.bin` | 16,384 | `09 81 49 06 09 82 89 09` | `..I.....` | `d67dbc1f12dc21b3...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_015_0x03C000.bin` | 16,384 | `fe 7f 7f f5 05 15 fe a8` | `........` | `d1427b4315aadf09...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_016_0x040000.bin` | 16,384 | `ff ff ff ff ff ff ff ff` | `........` | `d950b773d8fb6b52...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_017_0x044000.bin` | 16,384 | `ae 15 02 03 00 86 0e 00` | `........` | `adc75059e3d5a06b...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_018_0x048000.bin` | 16,384 | `00 84 40 00 00 80 13 00` | `..@.....` | `cd01cf94a84ba9b5...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_019_0x04C000.bin` | 16,384 | `03 ff 02 00 86 c0 f8 00` | `........` | `19218c71bafcc0e5...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_020_0x050000.bin` | 16,384 | `00 85 03 3f f8 01 3f 03` | `...?..?.` | `0a4ce30351bfdc90...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_021_0x054000.bin` | 16,384 | `84 db ff 85 fc 03 0c 85` | `........` | `fa8adee1dc6587e8...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_022_0x058000.bin` | 16,384 | `bc 80 1d 03 00 84 a1 a6` | `........` | `e1c7cc34d1768501...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_023_0x05C000.bin` | 16,384 | `00 03 ff 81 00 03 ff 81` | `........` | `066e73431307d4ab...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_024_0x060000.bin` | 16,384 | `81 00 00 ff ff 00 ff ff` | `........` | `5b95d8f01151ec95...` |
| `Extracted-Assets/Disk1-Program/chunks/chunk_025_0x064000.bin` | 9,216 | `ff 26 ff 07 3a 02 02 26` | `.&..:..&` | `32a6618c08e345f0...` |
| `Extracted-Assets/Disk1-Program/strings.json` | 345,764 | `5b 0a 20 20 7b 0a 20 20` | `[.  {.  ` | `924e90f3de69fa58...` |
| `Extracted-Assets/Disk2-Data1/chunks/chunk_000_0x000000.bin` | 16,384 | `18 12 91 01 04 0b 00 00` | `........` | `6df679e260503097...` |
| ... *(321 additional files indexed in tools/asset_catalog.json)* | | | | |

### 3.2. MSX2 Files (177 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `English-Translated/DISK0.dsk` | 737,280 | `eb fe 90 44 53 4b 54 4f` | `...DSKTO` | `2d328aad6dd566ed...` |
| `English-Translated/DISK1.dsk` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `f0723f1b6b933c19...` |
| `English-Translated/DISK2.dsk` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `c9e9ac8025a1db46...` |
| `English-Translated/DISK3.dsk` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `d0c1a40bfe5e6aa5...` |
| `English-Translated/Floppy-Files/AUTOEXEC.BAT` | 13 | `73 6e 61 74 63 68 65 72` | `snatcher` | `3d4127c98f56ec6c...` |
| `English-Translated/Floppy-Files/COMMAND.COM` | 6,656 | `c3 00 05 0c 00 12 00 02` | `........` | `7600d3ccfdac18a1...` |
| `English-Translated/Floppy-Files/DSK2SAV.COM` | 1,152 | `11 90 02 0e 09 cd 7d f3` | `......}.` | `8bb1ffd72f58295d...` |
| `English-Translated/Floppy-Files/FDSAVE.COM` | 851 | `c3 5e 02 0d 53 65 63 74` | `.^..Sect` | `dda2389bfae77ae4...` |
| `English-Translated/Floppy-Files/INSTALL.BAT` | 464 | `65 63 68 6f 20 6f 66 66` | `echo off` | `2d37659195648123...` |
| `English-Translated/Floppy-Files/LEIAME.TXT` | 11,341 | `20 20 20 20 20 20 20 20` | `        ` | `f456e065c4bd916f...` |
| `English-Translated/Floppy-Files/MSXDOS.SYS` | 2,496 | `c3 00 02 45 00 4c 00 50` | `...E.L.P` | `5599c7601a3937f1...` |
| `English-Translated/Floppy-Files/README.TXT` | 10,964 | `20 20 20 20 20 20 20 20` | `        ` | `e04e849bf2a391cc...` |
| `English-Translated/Floppy-Files/SAV2DSK.COM` | 1,280 | `11 9e 02 0e 09 cd 7d f3` | `......}.` | `60a532fd083d2024...` |
| `English-Translated/Floppy-Files/SNATCHER.000` | 0 | `` | `` | `e3b0c44298fc1c14...` |
| `English-Translated/Floppy-Files/SNATCHER.COM` | 3,584 | `11 bb 05 0e 09 cd 7d f3` | `......}.` | `a0a4ce4ef8ee656a...` |
| `English-Translated/Floppy-Files/SNATCHER.FNT` | 20,480 | `00 00 00 00 00 00 00 00` | `........` | `9ba5480eb7e6ed9b...` |
| `English-Translated/Floppy-Files/SNATCHER.IMG` | 54,272 | `11 19 11 11 11 11 11 11` | `........` | `649f8875e117240f...` |
| `English-Translated/Floppy-Files/SNATCHER.INS` | 566 | `25 31 0d 0a 63 6f 70 79` | `%1..copy` | `621d297694ef0065...` |
| `English-Translated/Floppy-Files/SNATCHER.SCR` | 16,384 | `40 02 0f 00 de ba 00 00` | `@.......` | `1307836e63fa37e8...` |
| `English-Translated/MSX2_SECTOR_LAYOUT.md` | 10,775 | `23 20 4d 53 58 32 20 53` | `# MSX2 S` | `6f021c7d177a68cd...` |
| `English-Translated/README.TXT` | 10,964 | `20 20 20 20 20 20 20 20` | `        ` | `e04e849bf2a391cc...` |
| `English-Translated/SNATCHER.DSK` | 8,192,000 | `eb fe 90 4e 4d 53 20 32` | `...NMS 2` | `e3ee5e09b58eb7bd...` |
| `English-Translated/SNATCHER_EN.DSK` | 8,192,000 | `eb fe 90 4e 4d 53 20 32` | `...NMS 2` | `e3ee5e09b58eb7bd...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.001` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `f0723f1b6b933c19...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.002` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `c9e9ac8025a1db46...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.003` | 737,280 | `eb 04 00 00 01 00 00 00` | `........` | `d0c1a40bfe5e6aa5...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.BAT` | 483 | `63 6c 73 0a 6d 6f 64 65` | `cls.mode` | `b54a2a7dc0176ffd...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.COM` | 3,584 | `11 bb 05 0e 09 cd 7d f3` | `......}.` | `a0a4ce4ef8ee656a...` |
| `English-Translated/SNATCHER_HDD/SNATCHER.SCR` | 16,384 | `40 02 0f 00 de ba 00 00` | `@.......` | `1307836e63fa37e8...` |
| `Extracted-Files/Disk0/AUTOEXEC.BAT` | 13 | `73 6e 61 74 63 68 65 72` | `snatcher` | `3d4127c98f56ec6c...` |
| `Extracted-Files/Disk0/COMMAND.COM` | 6,656 | `c3 00 05 0c 00 12 00 02` | `........` | `7600d3ccfdac18a1...` |
| `Extracted-Files/Disk0/DSK2SAV.COM` | 1,152 | `11 90 02 0e 09 cd 7d f3` | `......}.` | `8bb1ffd72f58295d...` |
| `Extracted-Files/Disk0/FDSAVE.COM` | 851 | `c3 5e 02 0d 53 65 63 74` | `.^..Sect` | `dda2389bfae77ae4...` |
| `Extracted-Files/Disk0/INSTALL.BAT` | 464 | `65 63 68 6f 20 6f 66 66` | `echo off` | `2d37659195648123...` |
| `Extracted-Files/Disk0/LEIAME.TXT` | 11,341 | `20 20 20 20 20 20 20 20` | `        ` | `f456e065c4bd916f...` |
| `Extracted-Files/Disk0/MSXDOS.SYS` | 2,496 | `c3 00 02 45 00 4c 00 50` | `...E.L.P` | `5599c7601a3937f1...` |
| `Extracted-Files/Disk0/README.TXT` | 10,964 | `20 20 20 20 20 20 20 20` | `        ` | `e04e849bf2a391cc...` |
| `Extracted-Files/Disk0/SAV2DSK.COM` | 1,280 | `11 9e 02 0e 09 cd 7d f3` | `......}.` | `60a532fd083d2024...` |
| `Extracted-Files/Disk0/SNATCHER.000` | 0 | `` | `` | `e3b0c44298fc1c14...` |
| `Extracted-Files/Disk0/SNATCHER.COM` | 3,584 | `11 bb 05 0e 09 cd 7d f3` | `......}.` | `a0a4ce4ef8ee656a...` |
| ... *(137 additional files indexed in tools/asset_catalog.json)* | | | | |

### 3.3. PC-Engine Files (529 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `English-CD-ROMantic/readme.txt` | 1,820 | `53 4e 41 54 43 48 45 52` | `SNATCHER` | `f3c069837168baed...` |
| `English-CD-ROMantic/snatcher-en.dat` | 269,778,395 | `53 4e 41 54 43 48 45 4e` | `SNATCHEN` | `658a28476f66660e...` |
| `English-CD-ROMantic/snatcher-patch` | 907,544 | `7f 45 4c 46 02 01 01 00` | `.ELF....` | `bc0974e3971ae973...` |
| `English-CD-ROMantic/snatcher-patch.exe` | 184,832 | `4d 5a 90 00 03 00 00 00` | `MZ......` | `82ae040637664d77...` |
| `English-Extracted/README.md` | 4,821 | `23 20 53 6e 61 74 63 68` | `# Snatch` | `ef47b9a73cd9b825...` |
| `English-Extracted/adpcm/adpcm_000_sec07858_20kb.adpcm` | 20,480 | `00 00 00 00 00 00 00 00` | `........` | `79d8597eab8f08f3...` |
| `English-Extracted/adpcm/adpcm_001_sec07868_18kb.adpcm` | 18,432 | `00 00 00 00 00 00 00 00` | `........` | `cd629ded159b2ffc...` |
| `English-Extracted/adpcm/adpcm_002_sec07877_58kb.adpcm` | 59,392 | `00 00 00 00 00 00 00 00` | `........` | `fe378f22e3e9f82b...` |
| `English-Extracted/adpcm/adpcm_003_sec07906_8kb.adpcm` | 8,192 | `00 00 00 00 00 00 00 00` | `........` | `c8c3862fcfcbcf19...` |
| `English-Extracted/adpcm/adpcm_004_sec07910_8kb.adpcm` | 8,192 | `00 00 00 00 00 00 00 00` | `........` | `d349d7fa540c8f45...` |
| `English-Extracted/adpcm/adpcm_005_sec07914_14kb.adpcm` | 14,336 | `00 00 00 00 00 00 00 00` | `........` | `a2bb2f9823f4035c...` |
| `English-Extracted/adpcm/adpcm_006_sec07921_12kb.adpcm` | 12,288 | `00 00 00 00 00 00 00 00` | `........` | `0ca766e48d368a30...` |
| `English-Extracted/adpcm/adpcm_007_sec07927_14kb.adpcm` | 14,336 | `00 00 00 00 00 00 00 00` | `........` | `d86d70f604f785bf...` |
| `English-Extracted/adpcm/adpcm_008_sec07934_34kb.adpcm` | 34,816 | `00 00 00 00 00 00 00 00` | `........` | `cb36ef163a81fa9d...` |
| `English-Extracted/adpcm/adpcm_009_sec07951_20kb.adpcm` | 20,480 | `00 00 00 00 00 00 00 00` | `........` | `39c097a49cf3b7bb...` |
| `English-Extracted/adpcm/adpcm_010_sec07961_20kb.adpcm` | 20,480 | `00 00 00 00 00 00 00 00` | `........` | `08b0a0f04cfc9bbe...` |
| `English-Extracted/adpcm/adpcm_011_sec07971_18kb.adpcm` | 18,432 | `00 00 00 00 00 00 00 00` | `........` | `b78b999b1f1dad4b...` |
| `English-Extracted/adpcm/adpcm_012_sec07980_24kb.adpcm` | 24,576 | `00 00 00 00 00 00 00 00` | `........` | `382a1d25cd125bcb...` |
| `English-Extracted/adpcm/adpcm_013_sec07992_24kb.adpcm` | 24,576 | `00 00 00 00 00 00 00 00` | `........` | `75c11a9d6c753dde...` |
| `English-Extracted/adpcm/adpcm_014_sec08004_22kb.adpcm` | 22,528 | `00 00 00 00 00 00 00 00` | `........` | `d8736ddb1364e084...` |
| `English-Extracted/adpcm/adpcm_015_sec08015_24kb.adpcm` | 24,576 | `00 00 00 00 00 00 00 00` | `........` | `b5ba37a500872219...` |
| `English-Extracted/adpcm/adpcm_016_sec08027_24kb.adpcm` | 24,576 | `00 00 00 00 00 00 00 00` | `........` | `273fafce85e5c04d...` |
| `English-Extracted/adpcm/adpcm_017_sec08039_12kb.adpcm` | 12,288 | `00 00 00 00 00 00 00 00` | `........` | `3d4e34fe58e39b27...` |
| `English-Extracted/adpcm/adpcm_018_sec08045_60kb.adpcm` | 61,440 | `00 00 00 00 00 00 00 00` | `........` | `51e380457129bd40...` |
| `English-Extracted/adpcm/adpcm_019_sec08075_60kb.adpcm` | 61,440 | `00 00 00 00 00 00 00 00` | `........` | `396880fede75b012...` |
| `English-Extracted/adpcm/adpcm_020_sec08105_60kb.adpcm` | 61,440 | `00 00 00 00 00 00 00 00` | `........` | `2bf8f2d5213a652f...` |
| `English-Extracted/adpcm/adpcm_021_sec08135_54kb.adpcm` | 55,296 | `00 00 00 00 00 00 00 00` | `........` | `87f3c298301390e1...` |
| `English-Extracted/adpcm/adpcm_022_sec08162_40kb.adpcm` | 40,960 | `00 00 00 00 00 00 00 00` | `........` | `b08eb3353d2c9a6e...` |
| `English-Extracted/adpcm/adpcm_023_sec08182_38kb.adpcm` | 38,912 | `00 00 00 00 00 00 00 00` | `........` | `0f4598541d0c7735...` |
| `English-Extracted/adpcm/adpcm_024_sec08201_40kb.adpcm` | 40,960 | `00 00 00 00 00 00 00 00` | `........` | `0c60a4b797d0783f...` |
| `English-Extracted/adpcm/adpcm_025_sec08221_28kb.adpcm` | 28,672 | `08 08 08 b8 30 b3 08 08` | `....0...` | `72a51a97105ac948...` |
| `English-Extracted/adpcm/adpcm_026_sec08797_28kb.adpcm` | 28,672 | `08 08 08 08 08 08 08 0c` | `........` | `0cb3ea47e462a2c5...` |
| `English-Extracted/adpcm/adpcm_027_sec08473_52kb.adpcm` | 53,248 | `08 08 08 08 08 08 08 08` | `........` | `c6b78dd661b5dd59...` |
| `English-Extracted/adpcm/adpcm_028_sec12736_8kb.adpcm` | 8,192 | `08 08 08 08 08 08 08 08` | `........` | `e3eb76e20a98cc16...` |
| `English-Extracted/adpcm/adpcm_029_sec08888_22kb.adpcm` | 22,528 | `08 08 08 08 08 08 08 08` | `........` | `06f9e64d172deb3b...` |
| `English-Extracted/adpcm/adpcm_030_sec08640_36kb.adpcm` | 36,864 | `08 08 08 08 08 08 08 08` | `........` | `b30b44105c20a110...` |
| `English-Extracted/adpcm/adpcm_031_sec08658_32kb.adpcm` | 32,768 | `0b 20 08 08 08 08 0b 20` | `. ..... ` | `9e5a91391c828688...` |
| `English-Extracted/adpcm/adpcm_032_sec09198_10kb.adpcm` | 10,240 | `08 c3 00 80 80 8b 84 80` | `........` | `38697046f087de53...` |
| `English-Extracted/adpcm/adpcm_033_sec08674_32kb.adpcm` | 32,768 | `08 08 08 08 08 08 08 08` | `........` | `20c841753c848df2...` |
| `English-Extracted/adpcm/adpcm_034_sec08690_32kb.adpcm` | 32,768 | `08 08 08 08 08 08 08 08` | `........` | `cf46658e016472ce...` |
| ... *(489 additional files indexed in tools/asset_catalog.json)* | | | | |

### 3.4. SegaCD Files (230 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `BOOT_SCD.BIN` | 32,768 | `00 ff ff ff ff ff ff ff` | `........` | `ac5dc9c74db80aaf...` |
| `Original-USA/DATA_A0.BIN` | 64,188 | `00 02 80 08 00 02 b0 58` | `.......X` | `549121fc221be6cd...` |
| `Original-USA/DATA_B0.BIN` | 24,176 | `00 02 80 08 00 02 83 4a` | `.......J` | `69ffd14a2a64f526...` |
| `Original-USA/DATA_D0.BIN` | 247,996 | `00 02 80 0c 00 02 80 18` | `........` | `2887e2690cc2e960...` |
| `Original-USA/DATA_D1.BIN` | 139,884 | `00 02 80 0c 00 02 8c 9a` | `........` | `f60026501fd34893...` |
| `Original-USA/DATA_D2.BIN` | 79,396 | `00 02 80 0c 00 02 82 78` | `.......x` | `f5d2fe6c70acb3d6...` |
| `Original-USA/DATA_F0.BIN` | 98,620 | `00 02 80 08 00 02 95 5c` | `.......\` | `af4ab46d2cbed37b...` |
| `Original-USA/DATA_F4.BIN` | 78,684 | `00 02 80 08 00 02 94 dc` | `........` | `6b29435c5345df64...` |
| `Original-USA/DATA_G0.BIN` | 121,076 | `00 02 80 08 00 02 9b 5a` | `.......Z` | `5fa75c7a468ce87e...` |
| `Original-USA/DATA_H00.BIN` | 26,332 | `00 02 80 08 00 02 84 ac` | `........` | `4b5e47f3127a84c8...` |
| `Original-USA/DATA_H01.BIN` | 11,834 | `00 02 80 08 00 02 82 4c` | `.......L` | `8ac46cfc15fb0564...` |
| `Original-USA/DATA_H02.BIN` | 31,798 | `00 02 80 08 00 02 95 b0` | `........` | `21a27bd49d2d9ef6...` |
| `Original-USA/DATA_H03.BIN` | 33,514 | `00 02 80 08 00 02 8e a0` | `........` | `9f4fc51249a765bf...` |
| `Original-USA/DATA_H04.BIN` | 40,018 | `00 02 80 08 00 02 8e a8` | `........` | `809a6c4f9dd007f5...` |
| `Original-USA/DATA_H05.BIN` | 13,868 | `00 02 80 08 00 02 83 38` | `.......8` | `e069492881f77160...` |
| `Original-USA/DATA_H06.BIN` | 20,562 | `00 02 80 08 00 02 84 20` | `....... ` | `6c48ff1821967c87...` |
| `Original-USA/DATA_H07.BIN` | 54,294 | `00 02 80 08 00 02 92 f4` | `........` | `62d8ed8ee10bfd5f...` |
| `Original-USA/DATA_H08.BIN` | 74,794 | `00 02 80 08 00 02 8a f2` | `........` | `f05326bff92b7901...` |
| `Original-USA/DATA_H09.BIN` | 143,208 | `00 02 80 08 00 02 ad 0c` | `........` | `032f914cb9c64834...` |
| `Original-USA/DATA_H11.BIN` | 34,232 | `00 02 80 08 00 02 8a 3a` | `.......:` | `e5b8b8b9e9b5cd5e...` |
| `Original-USA/DATA_H12.BIN` | 28,074 | `00 02 80 08 00 02 99 44` | `.......D` | `16d8cb1c557b3100...` |
| `Original-USA/DATA_H13.BIN` | 15,194 | `00 02 80 08 00 02 87 a6` | `........` | `2fa59d76a5861e16...` |
| `Original-USA/DATA_H14.BIN` | 50,904 | `00 02 80 08 00 02 93 b6` | `........` | `d406e5fce8fef8a1...` |
| `Original-USA/DATA_H15.BIN` | 29,596 | `00 02 80 08 00 02 84 e4` | `........` | `b6534be24b7fdc43...` |
| `Original-USA/DATA_I0.BIN` | 79,478 | `00 02 80 08 00 02 91 2a` | `.......*` | `10643f296c28bd84...` |
| `Original-USA/DATA_J0.BIN` | 43,004 | `00 02 80 08 00 02 8b 96` | `........` | `fe7de2bd64e72805...` |
| `Original-USA/DATA_K1.BIN` | 120,474 | `00 02 80 08 00 02 96 8c` | `........` | `15a1b170d5883853...` |
| `Original-USA/DATA_M0.BIN` | 48,164 | `00 02 80 08 00 02 8f 82` | `........` | `c5822dd63ab24d6d...` |
| `Original-USA/DATA_O0.BIN` | 75,602 | `00 02 80 08 00 02 9f 64` | `.......d` | `2050c7e15b96e43a...` |
| `Original-USA/DATA_P0.BIN` | 90,842 | `00 02 80 08 00 02 96 f6` | `........` | `07e6f213c84d4e47...` |
| `Original-USA/DATA_Q3.BIN` | 95,840 | `00 02 80 08 00 02 9c 0e` | `........` | `d1707aee99f84ac6...` |
| `Original-USA/DATA_Q5.BIN` | 75,390 | `00 02 80 08 00 02 98 7c` | `.......|` | `45f5b3e6547eaf79...` |
| `Original-USA/DATA_Q8.BIN` | 88,184 | `00 02 80 08 00 02 b5 34` | `.......4` | `e06536e4b5494980...` |
| `Original-USA/DATA_S0.BIN` | 36,924 | `00 02 80 08 00 02 88 d8` | `........` | `17c4f92a5b76aa76...` |
| `Original-USA/DATA_S1.BIN` | 24,780 | `00 02 80 08 00 02 89 3a` | `.......:` | `0d84ab4ed5b24f02...` |
| `Original-USA/DATA_S2.BIN` | 108,728 | `00 02 80 08 00 02 a0 3a` | `.......:` | `256bfbab29d7cc43...` |
| `Original-USA/DATA_T0.BIN` | 24,670 | `00 02 80 08 00 02 84 40` | `.......@` | `1d416210299487a2...` |
| `Original-USA/DATA_U0.BIN` | 39,622 | `00 02 80 08 00 02 88 6e` | `.......n` | `55f793882d60588f...` |
| `Original-USA/DATA_Y00.BIN` | 78,954 | `00 02 80 08 00 02 96 be` | `........` | `6ca7fce2ec8672a7...` |
| `Original-USA/DATA_Y01.BIN` | 100,498 | `00 02 80 08 00 02 99 be` | `........` | `b7e1d892b24c8a56...` |
| ... *(190 additional files indexed in tools/asset_catalog.json)* | | | | |

### 3.5. PlayStation Files (2943 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `English-Translated/Extracted-Files/DES/CC3/CC3_B000.BIN` | 16,066 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `608d755ad9f887e1...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B010.BIN` | 14,526 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `ba66168ab2af483e...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B011.BIN` | 10,153 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `1813f85b37585f55...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B020.BIN` | 42,657 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `81603d1176e8e39c...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B030.BIN` | 11,638 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `c37847c3fad05015...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B040.BIN` | 10,657 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `21d82bebf348c083...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B050.BIN` | 25,716 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `41381deb9576e221...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B060.BIN` | 23,601 | `01 00 00 00 c2 52 a0 10` | `.....R..` | `32e9bb3aada88af5...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B070.BIN` | 16,427 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `5b8085f8c765d32b...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B080.BIN` | 22,280 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `5440e4805b9a8bae...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B090.BIN` | 11,604 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `9eef0d52848ecc36...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0A0.BIN` | 20,042 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `2d9372fd77988b7b...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0B0.BIN` | 41,224 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `b070bff2637d05ab...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0C0.BIN` | 20,700 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `5fa1bb8b6606b0c8...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0D0.BIN` | 22,633 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `7c89cdaa91f4def1...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0E0.BIN` | 23,869 | `01 00 00 00 e2 5d a0 10` | `.....]..` | `ace396985624894f...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B0F0.BIN` | 20,057 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `e00ed25943603a14...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B100.BIN` | 14,379 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `cc549b4282984da9...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B110.BIN` | 18,272 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `b53f776b05473153...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B120.BIN` | 19,064 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `069d369f4c77d8c5...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B130.BIN` | 18,008 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `cc4a420c5741c8fe...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B140.BIN` | 23,355 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `030a051e01a31a3a...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B150.BIN` | 8,030 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `f9cba9fbdc19825e...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B160.BIN` | 10,701 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `9a1232449961eff6...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B170.BIN` | 21,548 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `4f76b64018fda829...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B180.BIN` | 19,872 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `fb1b335cae8c02b9...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B190.BIN` | 35,972 | `01 00 00 00 80 00 04 72` | `.......r` | `924796cc4185fe04...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1A0.BIN` | 32,602 | `01 00 00 00 a2 5a a0 10` | `.....Z..` | `67094040abb4bf24...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1B0.BIN` | 25,135 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `4522bec02c11b4ba...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1C0.BIN` | 17,679 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `68eccc92dcbd93af...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1D0.BIN` | 26,842 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `3273e33e3c31ec4c...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1E0.BIN` | 20,703 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `b74b0442fe262ada...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B1F0.BIN` | 20,055 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `0dc3c8fd7d233106...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B200.BIN` | 16,169 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `cffa5800f5e4b699...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B210.BIN` | 27,952 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `7ac1719362a54b4c...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B220.BIN` | 13,692 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `869a6f6d2ccf4442...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B230.BIN` | 6,658 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `d515cfe3559a356f...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B240.BIN` | 23,421 | `01 00 00 00 9a 58 a0 10` | `.....X..` | `650dd63226e8b7a9...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B250.BIN` | 21,880 | `01 00 00 00 9a 58 a0 00` | `.....X..` | `0f597170d9724b30...` |
| `English-Translated/Extracted-Files/DES/CC3/CC3_B260.BIN` | 29,667 | `01 00 00 00 ea 62 a0 10` | `.....b..` | `30baee9920e2cc0d...` |
| ... *(2903 additional files indexed in tools/asset_catalog.json)* | | | | |

### 3.6. Sega-Saturn Files (394 items)

| Relative Path | Size (Bytes) | Magic (Hex) | Magic (ASCII) | SHA256 (Prefix) |
|---|---|---|---|---|
| `English-Translated/DATA.BIN` | 11,008,000 | `00 00 cd a0 04 84 0f 6d` | `.......m` | `123d6cbb2604e97d...` |
| `English-Translated/MAIN_L.BIN` | 259,192 | `df 07 e0 f0 60 0c 40 0e` | `....`.@.` | `2b56203c6fa9918f...` |
| `English-Translated/SDDRVS6.TSK` | 21,172 | `00 00 a0 00 00 00 10 00` | `........` | `b934464739fd83ae...` |
| `English-Translated/SE_XX.BIN` | 106,598 | `00 5a 00 6c 00 76 00 80` | `.Z.l.v..` | `cacd8b70eef8d78c...` |
| `English-Translated/SE_XX.CNV` | 2,246 | `00 2b 00 00 00 ae 00 00` | `.+......` | `329326d82e408607...` |
| `English-Translated/ScummVM-Playable/DATA_A0.BIN` | 64,188 | `00 02 80 08 00 02 b0 58` | `.......X` | `549121fc221be6cd...` |
| `English-Translated/ScummVM-Playable/DATA_B0.BIN` | 24,176 | `00 02 80 08 00 02 83 4a` | `.......J` | `69ffd14a2a64f526...` |
| `English-Translated/ScummVM-Playable/DATA_D0.BIN` | 247,996 | `00 02 80 0c 00 02 80 18` | `........` | `2887e2690cc2e960...` |
| `English-Translated/ScummVM-Playable/DATA_D1.BIN` | 139,884 | `00 02 80 0c 00 02 8c 9a` | `........` | `f60026501fd34893...` |
| `English-Translated/ScummVM-Playable/DATA_D2.BIN` | 79,396 | `00 02 80 0c 00 02 82 78` | `.......x` | `f5d2fe6c70acb3d6...` |
| `English-Translated/ScummVM-Playable/DATA_F0.BIN` | 98,620 | `00 02 80 08 00 02 95 5c` | `.......\` | `af4ab46d2cbed37b...` |
| `English-Translated/ScummVM-Playable/DATA_F4.BIN` | 78,684 | `00 02 80 08 00 02 94 dc` | `........` | `6b29435c5345df64...` |
| `English-Translated/ScummVM-Playable/DATA_G0.BIN` | 121,076 | `00 02 80 08 00 02 9b 5a` | `.......Z` | `5fa75c7a468ce87e...` |
| `English-Translated/ScummVM-Playable/DATA_H00.BIN` | 26,332 | `00 02 80 08 00 02 84 ac` | `........` | `4b5e47f3127a84c8...` |
| `English-Translated/ScummVM-Playable/DATA_H01.BIN` | 11,834 | `00 02 80 08 00 02 82 4c` | `.......L` | `8ac46cfc15fb0564...` |
| `English-Translated/ScummVM-Playable/DATA_H02.BIN` | 31,798 | `00 02 80 08 00 02 95 b0` | `........` | `21a27bd49d2d9ef6...` |
| `English-Translated/ScummVM-Playable/DATA_H03.BIN` | 33,514 | `00 02 80 08 00 02 8e a0` | `........` | `9f4fc51249a765bf...` |
| `English-Translated/ScummVM-Playable/DATA_H04.BIN` | 40,018 | `00 02 80 08 00 02 8e a8` | `........` | `809a6c4f9dd007f5...` |
| `English-Translated/ScummVM-Playable/DATA_H05.BIN` | 13,868 | `00 02 80 08 00 02 83 38` | `.......8` | `e069492881f77160...` |
| `English-Translated/ScummVM-Playable/DATA_H06.BIN` | 20,562 | `00 02 80 08 00 02 84 20` | `....... ` | `6c48ff1821967c87...` |
| `English-Translated/ScummVM-Playable/DATA_H07.BIN` | 54,294 | `00 02 80 08 00 02 92 f4` | `........` | `62d8ed8ee10bfd5f...` |
| `English-Translated/ScummVM-Playable/DATA_H08.BIN` | 74,794 | `00 02 80 08 00 02 8a f2` | `........` | `f05326bff92b7901...` |
| `English-Translated/ScummVM-Playable/DATA_H09.BIN` | 143,208 | `00 02 80 08 00 02 ad 0c` | `........` | `032f914cb9c64834...` |
| `English-Translated/ScummVM-Playable/DATA_H11.BIN` | 34,232 | `00 02 80 08 00 02 8a 3a` | `.......:` | `e5b8b8b9e9b5cd5e...` |
| `English-Translated/ScummVM-Playable/DATA_H12.BIN` | 28,074 | `00 02 80 08 00 02 99 44` | `.......D` | `16d8cb1c557b3100...` |
| `English-Translated/ScummVM-Playable/DATA_H13.BIN` | 15,194 | `00 02 80 08 00 02 87 a6` | `........` | `2fa59d76a5861e16...` |
| `English-Translated/ScummVM-Playable/DATA_H14.BIN` | 50,904 | `00 02 80 08 00 02 93 b6` | `........` | `d406e5fce8fef8a1...` |
| `English-Translated/ScummVM-Playable/DATA_H15.BIN` | 29,596 | `00 02 80 08 00 02 84 e4` | `........` | `b6534be24b7fdc43...` |
| `English-Translated/ScummVM-Playable/DATA_I0.BIN` | 79,478 | `00 02 80 08 00 02 91 2a` | `.......*` | `10643f296c28bd84...` |
| `English-Translated/ScummVM-Playable/DATA_J0.BIN` | 43,004 | `00 02 80 08 00 02 8b 96` | `........` | `fe7de2bd64e72805...` |
| `English-Translated/ScummVM-Playable/DATA_K1.BIN` | 120,474 | `00 02 80 08 00 02 96 8c` | `........` | `15a1b170d5883853...` |
| `English-Translated/ScummVM-Playable/DATA_M0.BIN` | 48,164 | `00 02 80 08 00 02 8f 82` | `........` | `c5822dd63ab24d6d...` |
| `English-Translated/ScummVM-Playable/DATA_O0.BIN` | 75,602 | `00 02 80 08 00 02 9f 64` | `.......d` | `2050c7e15b96e43a...` |
| `English-Translated/ScummVM-Playable/DATA_P0.BIN` | 90,842 | `00 02 80 08 00 02 96 f6` | `........` | `07e6f213c84d4e47...` |
| `English-Translated/ScummVM-Playable/DATA_Q3.BIN` | 95,840 | `00 02 80 08 00 02 9c 0e` | `........` | `d1707aee99f84ac6...` |
| `English-Translated/ScummVM-Playable/DATA_Q5.BIN` | 75,390 | `00 02 80 08 00 02 98 7c` | `.......|` | `45f5b3e6547eaf79...` |
| `English-Translated/ScummVM-Playable/DATA_Q8.BIN` | 88,184 | `00 02 80 08 00 02 b5 34` | `.......4` | `e06536e4b5494980...` |
| `English-Translated/ScummVM-Playable/DATA_S0.BIN` | 36,924 | `00 02 80 08 00 02 88 d8` | `........` | `17c4f92a5b76aa76...` |
| `English-Translated/ScummVM-Playable/DATA_S1.BIN` | 24,780 | `00 02 80 08 00 02 89 3a` | `.......:` | `0d84ab4ed5b24f02...` |
| `English-Translated/ScummVM-Playable/DATA_S2.BIN` | 108,728 | `00 02 80 08 00 02 a0 3a` | `.......:` | `256bfbab29d7cc43...` |
| ... *(354 additional files indexed in tools/asset_catalog.json)* | | | | |
