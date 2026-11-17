#!/usr/bin/env python3
import os
import sys
import hashlib
import json

BASE_DIR = "/storage/emulated/0/Download/Snatcher-Collection"

PLATFORMS = {
    "PC88": os.path.join(BASE_DIR, "PC88"),
    "MSX2": os.path.join(BASE_DIR, "MSX2"),
    "PC-Engine": os.path.join(BASE_DIR, "PC-Engine"),
    "SegaCD": os.path.join(BASE_DIR, "SegaCD"),
    "PlayStation": os.path.join(BASE_DIR, "PlayStation"),
    "Sega-Saturn": os.path.join(BASE_DIR, "Sega-Saturn"),
}

def get_file_info(filepath):
    stat = os.stat(filepath)
    size = stat.st_size
    magic = b""
    sha256 = ""
    with open(filepath, "rb") as f:
        magic = f.read(16)
        f.seek(0)
        h = hashlib.sha256()
        # Read in 64k chunks
        while chunk := f.read(65536):
            h.update(chunk)
        sha256 = h.hexdigest()
    magic_hex = " ".join(f"{b:02x}" for b in magic)
    magic_ascii = "".join(chr(b) if 32 <= b <= 126 else "." for b in magic)
    return {
        "size": size,
        "magic_hex": magic_hex,
        "magic_ascii": magic_ascii,
        "sha256": sha256
    }

def main():
    print("=== SNATCHER BATCH ASSET AUDIT ===")
    catalog = {}
    for platform, plat_path in PLATFORMS.items():
        print(f"\n--- Scanning {platform} at {plat_path} ---")
        plat_files = []
        if not os.path.exists(plat_path):
            print(f"Warning: path {plat_path} does not exist")
            continue
        for root, dirs, files in os.walk(plat_path):
            for fname in sorted(files):
                full_path = os.path.join(root, fname)
                rel_path = os.path.relpath(full_path, plat_path)
                try:
                    info = get_file_info(full_path)
                    info["name"] = fname
                    info["rel_path"] = rel_path
                    plat_files.append(info)
                except Exception as e:
                    print(f"Error reading {rel_path}: {e}")
        catalog[platform] = plat_files
        print(f"Cataloged {len(plat_files)} files in {platform}")

    out_json = "tools/asset_catalog.json"
    with open(out_json, "w") as f:
        json.dump(catalog, f, indent=2)
    print(f"\nWrote full asset catalog to {out_json}")

if __name__ == "__main__":
    main()
