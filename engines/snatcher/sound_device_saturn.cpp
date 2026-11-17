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
#include "common/stream.h"
#include "common/system.h"
#include "common/textconsole.h"

namespace Snatcher {

/**
 * Sega Saturn Sound Device (SCSP / CD-DA Subsystem)
 * Handles Yamaha YMF292 (SCSP) 32-channel PCM audio and CD-DA Redbook tracks.
 */
class SoundDeviceSaturn : public SoundDevice {
public:
	SoundDeviceSaturn(FIO *fio);
	~SoundDeviceSaturn() override;

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
	Audio::SoundHandle _scspHandle;
};

SoundDeviceSaturn::SoundDeviceSaturn(FIO *fio) : SoundDevice(), _fio(fio), _mixer(nullptr),
	_curTrack(-1), _trackStartTime(0), _pauseStartTime(0) {
}

SoundDeviceSaturn::~SoundDeviceSaturn() {
	cdaStop();
}

bool SoundDeviceSaturn::init(Audio::Mixer *mixer) {
	_mixer = mixer;
	return true;
}

void SoundDeviceSaturn::cdaPlay(int track, uint32 bcdTime) {
	if (track <= 0)
		return;

	uint32 frm = 0;
	if (bcdTime != 0)
		frm = Util::decodeBCDTimeStamp(bcdTime, Util::kBCD_MMSSFR) / (1000 / 75);

	g_system->getAudioCDManager()->play(track - 1, 1, frm, 0);
	_curTrack = track;
	_trackStartTime = g_system->getMillis();
	_pauseStartTime = 0;
	debug(2, "SoundDeviceSaturn::cdaPlay: Playing Saturn CD track %d (frame %u)", track, frm);
}

void SoundDeviceSaturn::cdaStop() {
	g_system->getAudioCDManager()->stop();
	if (_mixer) {
		_mixer->stopHandle(_cdaHandle);
		_mixer->stopHandle(_scspHandle);
	}
	_curTrack = -1;
	_trackStartTime = 0;
	_pauseStartTime = 0;
}

bool SoundDeviceSaturn::cdaIsPlaying() const {
	if (g_system->getAudioCDManager()->isPlaying())
		return true;
	if (_mixer && _mixer->isSoundHandleActive(_cdaHandle))
		return true;
	return false;
}

int SoundDeviceSaturn::cdaGetCurTrack() const {
	return cdaIsPlaying() ? _curTrack : -1;
}

uint32 SoundDeviceSaturn::cdaGetTime() const {
	uint32 relTime = cdaIsPlaying() ? (g_system->getMillis() - _trackStartTime) : 0;
	if (_pauseStartTime)
		relTime -= (g_system->getMillis() - _pauseStartTime);
	return Util::makeBCDTimeStamp(relTime, Util::kBCD_MMSSFR);
}

void SoundDeviceSaturn::fmSendCommand(int cmd, int arg) {
	debug(3, "SoundDeviceSaturn::fmSendCommand: cmd=0x%02X, arg=%d", cmd, arg);
}

uint8 SoundDeviceSaturn::fmGetStatus() const {
	return 0;
}

void SoundDeviceSaturn::pcmSendCommand(int cmd, int arg) {
	debug(3, "SoundDeviceSaturn::pcmSendCommand: cmd=0x%02X, arg=%d", cmd, arg);
}

void SoundDeviceSaturn::pcmInitSound(int sndId) {
	debug(3, "SoundDeviceSaturn::pcmInitSound: sndId=%d", sndId);
}

uint8 SoundDeviceSaturn::pcmGetStatus() const {
	return 0;
}

int16 SoundDeviceSaturn::pcmGetResourceId() const {
	return 0;
}

void SoundDeviceSaturn::pause(bool toggle) {
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
		_mixer->pauseHandle(_scspHandle, toggle);
	}
}

void SoundDeviceSaturn::update() {
}

void SoundDeviceSaturn::reduceVolume2(bool enable) {
}

void SoundDeviceSaturn::setMusicVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_cdaHandle, vol);
}

void SoundDeviceSaturn::setSoundEffectVolume(int vol) {
	if (_mixer)
		_mixer->setChannelVolume(_scspHandle, vol);
}

SoundDevice *SoundDevice::createSaturnSoundDevice(FIO *fio) {
	return new SoundDeviceSaturn(fio);
}

} // End of namespace Snatcher
