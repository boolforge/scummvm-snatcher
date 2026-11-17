#!/usr/bin/env python3
"""
tools/ci_apk_pipeline.py
========================
Automated CI/CD APK Verification Pipeline & On-Device Shizuku Runner
Monitors GitHub Actions for boolforge/scummvm-snatcher, downloads the built
debug APK, installs it via Shizuku (`rish`), configures `scummvm.ini`, and
executes on-device regression playtests with framebuffer screencaps and logcat audit.
"""

import urllib.request
import json
import time
import zipfile
import io
import os
import subprocess
import sys

def get_github_token():
    token = os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")
    if token:
        return token
    try:
        remote_url = subprocess.check_output(["git", "remote", "get-url", "origin"], text=True).strip()
        if "@github.com" in remote_url and "//" in remote_url:
            user_token = remote_url.split("//")[1].split("@")[0]
            if ":" in user_token:
                return user_token.split(":")[1]
            return user_token
    except Exception:
        pass
    # Fallback from git credential helper
    try:
        p = subprocess.run(["git", "credential", "fill"], input="protocol=https\nhost=github.com\n\n", capture_output=True, text=True)
        for line in p.stdout.splitlines():
            if line.startswith("password="):
                return line.split("password=")[1]
    except Exception:
        pass
    return None

TOKEN = get_github_token()
REPO = "boolforge/scummvm-snatcher"
BRANCH = "snatcher"
PACKAGE_NAME = "org.scummvm.scummvm.debug"
INI_PATH = f"/data/data/{PACKAGE_NAME}/files/scummvm.ini"
DOWNLOAD_DIR = "/storage/emulated/0/Download"

def sh(cmd, check=False):
    res = subprocess.run(["rish", "-c", cmd], capture_output=True, text=True)
    if check and res.returncode != 0:
        raise RuntimeError(f"Command failed (code {res.returncode}): {cmd}\nStderr: {res.stderr}")
    return res.stdout.strip()

def get_latest_run():
    url = f"https://api.github.com/repos/{REPO}/actions/runs?branch={BRANCH}&per_page=5"
    req = urllib.request.Request(url, headers={"Authorization": f"Bearer {TOKEN}", "User-Agent": "Mozilla/5.0"})
    with urllib.request.urlopen(req) as resp:
        data = json.loads(resp.read().decode())
        for r in data.get("workflow_runs", []):
            if r["head_branch"] == BRANCH:
                return r["id"], r["status"], r.get("conclusion"), r["head_sha"]
    return None, None, None, None

def monitor_run(run_id, max_wait_sec=900):
    print(f"\n[CI-MONITOR] Tracking GitHub Actions Run ID {run_id}...")
    start_time = time.time()
    while time.time() - start_time < max_wait_sec:
        url = f"https://api.github.com/repos/{REPO}/actions/runs/{run_id}/jobs"
        req = urllib.request.Request(url, headers={"Authorization": f"Bearer {TOKEN}", "User-Agent": "Mozilla/5.0"})
        try:
            with urllib.request.urlopen(req) as resp:
                data = json.loads(resp.read().decode())
                for j in data.get("jobs", []):
                    if j["name"] == "Build Android APK":
                        status = j["status"]
                        conclusion = j.get("conclusion")
                        print(f"  [CI Status] Build Android APK: {status} (conclusion: {conclusion})")
                        if status == "completed":
                            return conclusion == "success"
        except Exception as e:
            print("  [Warning] Polling error:", e)
        time.sleep(15)
    return False

def download_and_install_apk(run_id):
    print("\n[DOWNLOAD] Fetching APK artifact from GitHub Actions...")
    art_url = f"https://api.github.com/repos/{REPO}/actions/runs/{run_id}/artifacts"
    req = urllib.request.Request(art_url, headers={"Authorization": f"Bearer {TOKEN}", "User-Agent": "Mozilla/5.0"})
    with urllib.request.urlopen(req) as resp:
        data = json.loads(resp.read().decode())
        artifact = None
        for a in data.get("artifacts", []):
            if a["name"] == "scummvm-snatcher-android-debug-apk":
                artifact = a
                break

    if not artifact:
        raise RuntimeError("Artifact 'scummvm-snatcher-android-debug-apk' not found in run!")

    dl_url = artifact["archive_download_url"]
    print(f"  Downloading artifact: {artifact['name']} ({artifact['size_in_bytes']} bytes)...")

    class NoAuthRedirectHandler(urllib.request.HTTPRedirectHandler):
        def redirect_request(self, req, fp, code, msg, headers, newurl):
            return urllib.request.Request(newurl, headers={"User-Agent": "Mozilla/5.0"}, method=req.get_method())

    opener = urllib.request.build_opener(NoAuthRedirectHandler)
    req2 = urllib.request.Request(dl_url, headers={"Authorization": f"Bearer {TOKEN}", "User-Agent": "Mozilla/5.0"})
    with opener.open(req2) as dl_resp:
        archive_bytes = dl_resp.read()

    z = zipfile.ZipFile(io.BytesIO(archive_bytes))
    apk_filename = None
    for fname in z.namelist():
        if fname.endswith(".apk"):
            apk_filename = fname
            break

    if not apk_filename:
        raise RuntimeError("No .apk found inside artifact zip!")

    apk_path = os.path.join(DOWNLOAD_DIR, "scummvm-snatcher-debug.apk")
    with open(apk_path, "wb") as f:
        f.write(z.read(apk_filename))

    print(f"  Saved APK to {apk_path} ({os.path.getsize(apk_path)} bytes)")
    print("\n[INSTALL] Installing APK on device via Shizuku (`rish pm install`)...")
    install_res = sh(f"pm install -r '{apk_path}'")
    print(f"  pm install output: {install_res}")
    if "Success" not in install_res:
        raise RuntimeError(f"APK installation failed: {install_res}")
    print(">>> APK successfully installed on device! <<<")

def configure_scummvm_ini():
    print("\n[CONFIG] Synchronizing multiplatform targets in scummvm.ini...")
    ini_content = """[scummvm]
filtering=false
android_saf_dialog_shown=true
remap_timeout_delay_ms=8000
FM_medium_quality=true
FM_high_quality=false
fullscreen=true
browser_lastpath=/
aspect_ratio=true
versioninfo=2026.4.1git
autosave_period=0

[snatcher-segacd]
description=Snatcher (Sega CD - USA)
path=/storage/emulated/0/Download/Snatcher-Collection/SegaCD/Original-USA
engineid=snatcher
gameid=snatcher
language=en
platform=segacd

[snatcher-ps1]
description=Snatcher (PlayStation - English)
path=/storage/emulated/0/Download/Snatcher-Collection/PlayStation/English-Translated
engineid=snatcher
gameid=snatcher
language=en
platform=psx

[snatcher-saturn]
description=Snatcher (Sega Saturn - Japan)
path=/storage/emulated/0/Download/Snatcher-Collection/Sega-Saturn/Original-Japan
engineid=snatcher
gameid=snatcher
language=ja
platform=saturn

[snatcher-pce]
description=Snatcher (PC-Engine - Unpacked)
path=/storage/emulated/0/Download/Snatcher-Collection/PC-Engine/English-Extracted
engineid=snatcher
gameid=snatcher
language=en
platform=pce

[snatcher-msx]
description=Snatcher (MSX2 - Playable)
path=/storage/emulated/0/Download/Snatcher-Collection/MSX2/ScummVM-Playable
engineid=snatcher
gameid=snatcher
language=en
platform=segacd

[snatcher-pc88]
description=Snatcher (PC-8801 - Playable)
path=/storage/emulated/0/Download/Snatcher-Collection/PC88/ScummVM-Playable
engineid=snatcher
gameid=snatcher
language=en
platform=segacd
"""
    tmp_ini = os.path.join(DOWNLOAD_DIR, "scummvm_test.ini")
    with open(tmp_ini, "w") as f:
        f.write(ini_content)

    sh(f"cp '{tmp_ini}' '{INI_PATH}' && chmod 660 '{INI_PATH}'")
    print(f"  Updated {INI_PATH} with 6 verified platform targets.")

def run_port_tests():
    print("\n==================================================================")
    print("EXECUTING ON-DEVICE RETRO RE MULTIPLATFORM PLAYTESTS VIA SHIZUKU")
    print("==================================================================")
    ports = [
        ("snatcher-segacd", "Sega CD (Original USA)"),
        ("snatcher-ps1",    "PlayStation 1 (English Translated)"),
        ("snatcher-saturn", "Sega Saturn (Original Japan)"),
        ("snatcher-pce",    "PC Engine Super CD-ROM (Unpacked)"),
        ("snatcher-msx",    "MSX2 (Playable)"),
        ("snatcher-pc88",   "PC-8801 (Playable)")
    ]

    results = []

    for port_id, port_name in ports:
        print(f"\n--- [PLAYTEST] Launching {port_name} (`{port_id}`) ---")
        sh(f"/system/bin/am force-stop {PACKAGE_NAME}")
        time.sleep(0.5)
        sh("logcat -c")

        start_cmd = f"/system/bin/am start -n {PACKAGE_NAME}/org.scummvm.scummvm.SplashActivity -a android.intent.action.MAIN -d 'scummvm:{port_id}'"
        sh(start_cmd)

        time.sleep(4.0)
        # Dismiss initial IME / system gesture overlay
        sh("input keyevent 4")
        time.sleep(1.0)

        # Screencap
        img_out = os.path.join(DOWNLOAD_DIR, f"screencap_{port_id}.png")
        sh(f"screencap -p '{img_out}'")

        # Capture logcat
        logs = sh("logcat -d | grep -i -E 'scummvm|snatcher' | tail -n 25")

        sh(f"/system/bin/am force-stop {PACKAGE_NAME}")

        has_crash = "fatal" in logs.lower() or "sigsegv" in logs.lower() or "exception" in logs.lower()
        success = not has_crash and os.path.exists(img_out) and os.path.getsize(img_out) > 1000

        print(f"  Frame capture: {img_out} ({os.path.getsize(img_out) if os.path.exists(img_out) else 0} bytes)")
        print("  Logcat tail:")
        for line in logs.splitlines()[-8:]:
            print(f"    {line}")

        status_str = "PASSED" if success else "FAILED"
        print(f"  Result: [{status_str}]")
        results.append((port_id, port_name, success))

    print("\n==================================================================")
    print("MULTI-TARGET ON-DEVICE REGRESSION AUDIT SUMMARY")
    print("==================================================================")
    all_passed = True
    for port_id, port_name, success in results:
        status_str = "PASSED" if success else "FAILED"
        if not success:
            all_passed = False
        print(f"  {port_name:36}: [{status_str}]")

    if all_passed:
        print("\n>>> ALL 6 PORTS PASSED ON-DEVICE HARDWARE REGRESSION TESTS <<<")
    else:
        print("\n>>> ONE OR MORE PORTS FAILED TEST SUITE <<<")

def main():
    run_id, status, conclusion, sha = get_latest_run()
    if not run_id:
        print("Failed to locate workflow run.")
        sys.exit(1)

    print(f"Latest run ID: {run_id} (SHA: {sha[:8]}, status: {status}, conclusion: {conclusion})")

    if status != "completed":
        success = monitor_run(run_id)
        if not success:
            print("CI build failed or timed out!")
            sys.exit(1)

    download_and_install_apk(run_id)
    configure_scummvm_ini()
    run_port_tests()

if __name__ == "__main__":
    main()
