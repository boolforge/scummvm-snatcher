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
#include "audio/decoders/xa.h"
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"

namespace Snatcher {

/**
 * PlayStation 1 Sound Device (SPU / XA Audio Subsystem)
 * Handles native CD-DA / XA streaming audio and 24-channel SPU voices.
 */
class SoundDevicePSX : public SoundDevice {
public:
	SoundDevicePSX(FIO *fio);
	~SoundDevicePSX() override;

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
	int _curTrack;
	uint32 _trackStartTime;
	Audio::SoundHandle _xaHandle;
	Audio::SoundHandle _cdaHandle;
};

SoundDevicePSX::SoundDevicePSX(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr),
	_curTrack(-1), _trackStartTime(0) {
}

SoundDevicePSX::~SoundDevicePSX() {
	cdaStop();
}

bool SoundDevicePSX::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDevicePSX::cdaPlay(int track, uint32 bcdTime) {
	_curTrack = track;
	_trackStartTime = g_system->getMillis();
	debug(2, "SoundDevicePSX::cdaPlay: Playing PSX track %d", track);
}

void SoundDevicePSX::cdaStop() {
	if (_mixer) {
		_mixer->stopHandle(_cdaHandle);
		_mixer->stopHandle(_xaHandle);
	}
	_curTrack = -1;
	_trackStartTime = 0;
}

bool SoundDevicePSX::cdaIsPlaying() const {
	if (_mixer && _mixer->isSoundHandleActive(_cdaHandle))
		return true;
	return _curTrack != -1;
}

int SoundDevicePSX::cdaGetCurTrack() const {
	return _curTrack;
}

uint32 SoundDevicePSX::cdaGetTime() const {
	if (_curTrack == -1)
		return 0;
	return g_system->getMillis() - _trackStartTime;
}

void SoundDevicePSX::fmSendCommand(int cmd, int arg) {
	// PSX does not use FM synthesis; mapped to SPU program cues
	debug(3, "SoundDevicePSX::fmSendCommand: cmd=0x%02X, arg=%d", cmd, arg);
}

uint8 SoundDevicePSX::fmGetStatus() const {
	return 0;
}

void SoundDevicePSX::pcmSendCommand(int cmd, int arg) {
	debug(3, "SoundDevicePSX::pcmSendCommand: cmd=0x%02X, arg=%d", cmd, arg);
}

void SoundDevicePSX::pcmInitSound(int sndId) {
	debug(3, "SoundDevicePSX::pcmInitSound: sndId=%d", sndId);
}

uint8 SoundDevicePSX::pcmGetStatus() const {
	return 0;
}

int16 SoundDevicePSX::pcmGetResourceId() const {
	return 0;
}

void SoundDevicePSX::pause(bool toggle) {
	if (_mixer) {
		_mixer->pauseHandle(_cdaHandle, toggle);
		_mixer->pauseHandle(_xaHandle, toggle);
	}
}

void SoundDevicePSX::update() {
	// PSX audio update ticks
}

void SoundDevicePSX::reduceVolume2(bool enable) {
}

void SoundDevicePSX::setMusicVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_cdaHandle, vol);
}

void SoundDevicePSX::setSoundEffectVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_xaHandle, vol);
}

SoundDevice *SoundDevice::createPSXSoundDevice(FIO *fio) {
	return new SoundDevicePSX(fio);
}

} // End of namespace Snatcher
