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
#include "snatcher/util.h"
#include "backends/audiocd/audiocd.h"
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
	uint32 _pauseStartTime;
	Audio::SoundHandle _cdaHandle;
	Audio::SoundHandle _adpcmHandle;
};

SoundDevicePCE::SoundDevicePCE(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr),
	_curTrack(-1), _trackStartTime(0), _pauseStartTime(0) {
}

SoundDevicePCE::~SoundDevicePCE() {
	cdaStop();
}

bool SoundDevicePCE::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDevicePCE::cdaPlay(int track, uint32 bcdTime) {
	if (track <= 0)
		return;

	uint32 frm = 0;
	if (bcdTime != 0)
		frm = Util::decodeBCDTimeStamp(bcdTime, Util::kBCD_MMSSFR) / (1000 / 75);

	g_system->getAudioCDManager()->play(track - 1, 1, frm, 0);
	_curTrack = track;
	_trackStartTime = g_system->getMillis();
	_pauseStartTime = 0;
	debug(2, "SoundDevicePCE::cdaPlay: Playing PC Engine CD track %d (frame %u)", track, frm);
}

void SoundDevicePCE::cdaStop() {
	g_system->getAudioCDManager()->stop();
	if (_mixer) {
		_mixer->stopHandle(_cdaHandle);
		_mixer->stopHandle(_adpcmHandle);
	}
	_curTrack = -1;
	_trackStartTime = 0;
	_pauseStartTime = 0;
}

bool SoundDevicePCE::cdaIsPlaying() const {
	if (g_system->getAudioCDManager()->isPlaying())
		return true;
	if (_mixer && _mixer->isSoundHandleActive(_cdaHandle))
		return true;
	return false;
}

int SoundDevicePCE::cdaGetCurTrack() const {
	return cdaIsPlaying() ? _curTrack : -1;
}

uint32 SoundDevicePCE::cdaGetTime() const {
	uint32 relTime = cdaIsPlaying() ? (g_system->getMillis() - _trackStartTime) : 0;
	if (_pauseStartTime)
		relTime -= (g_system->getMillis() - _pauseStartTime);
	return Util::makeBCDTimeStamp(relTime, Util::kBCD_MMSSFR);
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
	if (toggle) {
		if (_pauseStartTime == 0) {
			if (cdaIsPlaying()) {
				_pauseStartTime = g_system->getMillis();
				g_system->getAudioCDManager()->stop();
			} else {
				_curTrack = -1;
				_pauseStartTime = 0;
			}
		}
	} else {
		if (_pauseStartTime != 0) {
			if (_curTrack != -1)
				g_system->getAudioCDManager()->play(_curTrack - 1, 1, (_pauseStartTime - _trackStartTime) / (1000 / 75), 0);
			_trackStartTime += (g_system->getMillis() - _pauseStartTime);
			_pauseStartTime = 0;
		}
	}

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
