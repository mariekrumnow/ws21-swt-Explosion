//Autor: Tobias

#include "SoundManager.h"

#include <cstdlib>

#include <list>
#include <string>
#include <iostream>

#include <SDL_mixer.h>

#include "../core/AppManager.h"

namespace sound {

void ChannelFinishedCallback(int channel) {
	core::AppManager::GetAppManager().GetSound().OnChannelFinished(channel);
}

SoundManager::SoundManager(bool init_sound) {
	playing_alone_ = std::list<SoundEffect*>();
	current_battle_music_ = 0;
	master_volume_ = 1.0;
	music_volume_ = 1.0;
	effect_volume_ = 1.0;

	if (init_sound) {
		if (Mix_Init(0) == -1) {
			std::cout << "Mix_Init Error: " << Mix_GetError() << std::endl;
		}
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
				MIX_DEFAULT_FORMAT, MIX_CHANNELS, 1024) == -1) {
			std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
		};
		//make sure to get notified when a channel stops, for sound effect playback
		Mix_ChannelFinished(&ChannelFinishedCallback);
	}

	fake_ = !init_sound;
}

SoundManager::~SoundManager() {
	if (fake_)
		return;
	Mix_CloseAudio();
	Mix_Quit();
}

void SoundManager::SetMasterVolume(double volume)  {
	if (volume < 0)
		volume = 0;
	if (volume > 1)
		volume = 1;
	master_volume_ = volume;
	SetMusicVolume(music_volume_);
	SetSoundEffectVolume(effect_volume_);
}

void SoundManager::SetMusicVolume(double volume)  {
	if (volume < 0)
		volume = 0;
	if (volume > 1)
		volume = 1;
	music_volume_ = volume;
	Mix_VolumeMusic(MIX_MAX_VOLUME * master_volume_ * volume);
}

void SoundManager::SetSoundEffectVolume(double volume) {
	if (volume < 0)
		volume = 0;
	if (volume > 1)
		volume = 1;
	effect_volume_ = volume;
	Mix_Volume(-1, MIX_MAX_VOLUME * master_volume_  * volume);
}

double SoundManager::GetMasterVolume() {
	return master_volume_;
}

double SoundManager::GetMusicVolume() {
	return music_volume_;
}

double SoundManager::GetSoundEffectVolume() {
	return effect_volume_;
}

void SoundManager::PlayMusic(Music* music) {
	if (fake_)
		return;
	Mix_PlayMusic(music->GetMusic(), -1);
}

void SoundManager::PlayNextBattleMusic() {
	if (fake_)
		return;

	if (battle_music.size() == 0)
		return;

	PlayMusic( battle_music[current_battle_music_] );

	current_battle_music_ += 1;

	current_battle_music_ %= battle_music.size();
}

void SoundManager::PlayRandomBattleMusic() {
	current_battle_music_ = rand() % battle_music.size();
	PlayNextBattleMusic();
}

void SoundManager::PlaySoundEffect(SoundEffect* effect, int loops) {
	if (fake_)
		return;
	Mix_PlayChannel(-1, effect->GetSample(), loops);
}

void SoundManager::PlaySoundEffectAlone(SoundEffect* effect, int loops) {
	if (fake_)
		return;
	if (effect->GetCurrentChannel() != -1) {
		Mix_HaltChannel(effect->GetCurrentChannel());
	}

	int channel = Mix_PlayChannel(-1, effect->GetSample(), loops);
	effect->SetCurrentChannel(channel);

	playing_alone_.push_back(effect);
}

void SoundManager::OnChannelFinished(int channel) {
	//tell the sound effect that it has finished playing;
	for (auto it = playing_alone_.begin(); it!=playing_alone_.end(); it++) {
		if ((*it)->GetCurrentChannel() == channel) {
			(*it)->SetCurrentChannel(-1);
			playing_alone_.erase(it);
		}
	}
}

void SoundManager::StopPlayback() {
	if (fake_)
		return;
	Mix_HaltChannel(-1);
	playing_alone_.clear();
	current_battle_music_ = 0;
}

void SoundManager::StopMusicPlayback() {
	if (fake_)
		return;
	Mix_HaltMusic();
}

} //namespace sound
