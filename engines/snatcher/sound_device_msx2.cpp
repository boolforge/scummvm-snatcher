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
#include "audio/softsynth/ym2149.h"
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"

namespace Snatcher {

/**
 * MSX2 Sound Device (Konami SCC / PSG AY-3-8910 Subsystem)
 * Handles 5-channel SCC custom wavetable synthesis and 3-channel SSG PSG music/sfx.
 */
class SoundDeviceMSX2 : public SoundDevice {
public:
	SoundDeviceMSX2(FIO *fio);
	~SoundDeviceMSX2() override;

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
	Audio::SoundHandle _sccHandle;
};

SoundDeviceMSX2::SoundDeviceMSX2(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr) {
}

SoundDeviceMSX2::~SoundDeviceMSX2() {
}

bool SoundDeviceMSX2::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDeviceMSX2::cdaPlay(int track, uint32 bcdTime) {
}

void SoundDeviceMSX2::cdaStop() {
}

bool SoundDeviceMSX2::cdaIsPlaying() const {
	return false;
}

int SoundDeviceMSX2::cdaGetCurTrack() const {
	return -1;
}

uint32 SoundDeviceMSX2::cdaGetTime() const {
	return 0;
}

void SoundDeviceMSX2::fmSendCommand(int cmd, int arg) {
	// Konami SCC sound driver registers
	debug(3, "SoundDeviceMSX2::fmSendCommand (SCC): cmd=0x%02X, arg=%d", cmd, arg);
}

uint8 SoundDeviceMSX2::fmGetStatus() const {
	return 0;
}

void SoundDeviceMSX2::pcmSendCommand(int cmd, int arg) {
	// PSG sound effects
	debug(3, "SoundDeviceMSX2::pcmSendCommand (PSG): cmd=0x%02X, arg=%d", cmd, arg);
}

void SoundDeviceMSX2::pcmInitSound(int sndId) {
	debug(3, "SoundDeviceMSX2::pcmInitSound: sndId=%d", sndId);
}

uint8 SoundDeviceMSX2::pcmGetStatus() const {
	return 0;
}

int16 SoundDeviceMSX2::pcmGetResourceId() const {
	return 0;
}

void SoundDeviceMSX2::pause(bool toggle) {
	if (_mixer)
		_mixer->pauseHandle(_sccHandle, toggle);
}

void SoundDeviceMSX2::update() {
}

void SoundDeviceMSX2::reduceVolume2(bool enable) {
}

void SoundDeviceMSX2::setMusicVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_sccHandle, vol);
}

void SoundDeviceMSX2::setSoundEffectVolume(int vol) {
}

SoundDevice *SoundDevice::createMSXSoundDevice(FIO *fio) {
	return new SoundDeviceMSX2(fio);
}

} // End of namespace Snatcher
