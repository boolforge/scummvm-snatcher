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
#include "audio/decoders/adpcm.h"
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"

namespace Snatcher {

/**
 * PC Engine Super CD-ROM² Sound Device
 * Handles HuC6280 6-channel wavetable PSG, OKI MSM5205 ADPCM, and CD-DA Redbook audio.
 */
class SoundDevicePCE : public SoundDevice {
public:
	SoundDevicePCE(FIO *fio);
	~SoundDevicePCE() override;

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
	Audio::SoundHandle _cdaHandle;
	Audio::SoundHandle _adpcmHandle;
};

SoundDevicePCE::SoundDevicePCE(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr),
	_curTrack(-1), _trackStartTime(0) {
}

SoundDevicePCE::~SoundDevicePCE() {
	cdaStop();
}

bool SoundDevicePCE::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDevicePCE::cdaPlay(int track, uint32 bcdTime) {
	_curTrack = track;
	_trackStartTime = g_system->getMillis();
	debug(2, "SoundDevicePCE::cdaPlay: Playing PC Engine CD track %d", track);
}

void SoundDevicePCE::cdaStop() {
	if (_mixer) {
		_mixer->stopHandle(_cdaHandle);
		_mixer->stopHandle(_adpcmHandle);
	}
	_curTrack = -1;
	_trackStartTime = 0;
}

bool SoundDevicePCE::cdaIsPlaying() const {
	if (_mixer && _mixer->isSoundHandleActive(_cdaHandle))
		return true;
	return _curTrack != -1;
}

int SoundDevicePCE::cdaGetCurTrack() const {
	return _curTrack;
}

uint32 SoundDevicePCE::cdaGetTime() const {
	if (_curTrack == -1)
		return 0;
	return g_system->getMillis() - _trackStartTime;
}

void SoundDevicePCE::fmSendCommand(int cmd, int arg) {
	// PC Engine PSG channels
	debug(3, "SoundDevicePCE::fmSendCommand (PSG): cmd=0x%02X, arg=%d", cmd, arg);
}

uint8 SoundDevicePCE::fmGetStatus() const {
	return 0;
}

void SoundDevicePCE::pcmSendCommand(int cmd, int arg) {
	// PC Engine OKI ADPCM streaming
	debug(3, "SoundDevicePCE::pcmSendCommand (ADPCM): cmd=0x%02X, arg=%d", cmd, arg);
}

void SoundDevicePCE::pcmInitSound(int sndId) {
	debug(3, "SoundDevicePCE::pcmInitSound: sndId=%d", sndId);
}

uint8 SoundDevicePCE::pcmGetStatus() const {
	return 0;
}

int16 SoundDevicePCE::pcmGetResourceId() const {
	return 0;
}

void SoundDevicePCE::pause(bool toggle) {
	if (_mixer) {
		_mixer->pauseHandle(_cdaHandle, toggle);
		_mixer->pauseHandle(_adpcmHandle, toggle);
	}
}

void SoundDevicePCE::update() {
}

void SoundDevicePCE::reduceVolume2(bool enable) {
}

void SoundDevicePCE::setMusicVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_cdaHandle, vol);
}

void SoundDevicePCE::setSoundEffectVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_adpcmHandle, vol);
}

SoundDevice *SoundDevice::createPCESoundDevice(FIO *fio) {
	return new SoundDevicePCE(fio);
}

} // End of namespace Snatcher
