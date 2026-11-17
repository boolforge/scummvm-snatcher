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

#include "snatcher/sound_device.h"
#include "snatcher/resource.h"
#include "audio/mixer.h"
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"

namespace Snatcher {

/**
 * NEC PC-8801 Sound Device (Yamaha YM2203 OPN Subsystem)
 * Handles 3-channel FM synthesis + 3-channel SSG / AY-3-8910 synthesis.
 */
class SoundDevicePC88 : public SoundDevice {
public:
	SoundDevicePC88(FIO *fio);
	~SoundDevicePC88() override;

	bool init(Audio::Mixer *mixer) override;

	void cdaPlay(int track, uint32 bcdTime = 0) override;
	void cdaStop() override;
	bool cdaIsPlaying() const override;
	int cdaGetCurTrack() const override;
	uint32 cdaGetTime() const override;

	void fmSendCommand(int cmd, int arg) override;
	uint8 fmGetStatus() const override;

	void pcmSendCommand(int cmd, int arg) override;
	void pcmInitSound(int sndId) override;
	uint8 pcmGetStatus() const override;
	int16 pcmGetResourceId() const override;

	void pause(bool toggle) override;
	void update() override;

	void reduceVolume2(bool enable) override;

	void setMusicVolume(int vol) override;
	void setSoundEffectVolume(int vol) override;

private:
	FIO *_fio;
	Audio::Mixer *_mixer;
	Audio::SoundHandle _opnHandle;
};

SoundDevicePC88::SoundDevicePC88(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr) {
}

SoundDevicePC88::~SoundDevicePC88() {
}

bool SoundDevicePC88::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDevicePC88::cdaPlay(int track, uint32 bcdTime) {
}

void SoundDevicePC88::cdaStop() {
}

bool SoundDevicePC88::cdaIsPlaying() const {
	return false;
}

int SoundDevicePC88::cdaGetCurTrack() const {
	return -1;
}

uint32 SoundDevicePC88::cdaGetTime() const {
	return 0;
}

void SoundDevicePC88::fmSendCommand(int cmd, int arg) {
	// Yamaha YM2203 (OPN) FM commands
	debug(3, "SoundDevicePC88::fmSendCommand (YM2203): cmd=0x%02X, arg=%d", cmd, arg);
}

uint8 SoundDevicePC88::fmGetStatus() const {
	return 0;
}

void SoundDevicePC88::pcmSendCommand(int cmd, int arg) {
	// PC-88 SSG / Beep
	debug(3, "SoundDevicePC88::pcmSendCommand (SSG): cmd=0x%02X, arg=%d", cmd, arg);
}

void SoundDevicePC88::pcmInitSound(int sndId) {
	debug(3, "SoundDevicePC88::pcmInitSound: sndId=%d", sndId);
}

uint8 SoundDevicePC88::pcmGetStatus() const {
	return 0;
}

int16 SoundDevicePC88::pcmGetResourceId() const {
	return 0;
}

void SoundDevicePC88::pause(bool toggle) {
	if (_mixer)
		_mixer->pauseHandle(_opnHandle, toggle);
}

void SoundDevicePC88::update() {
}

void SoundDevicePC88::reduceVolume2(bool enable) {
}

void SoundDevicePC88::setMusicVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_opnHandle, vol);
}

void SoundDevicePC88::setSoundEffectVolume(int vol) {
}

SoundDevice *SoundDevice::createPC88SoundDevice(FIO *fio) {
	return new SoundDevicePC88(fio);
}

} // End of namespace Snatcher
