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
	if (fake_) return;
	Mix_CloseAudio();
	Mix_Quit();
}

void SoundManager::PlayMusic(Music* music) {
	if (fake_) return;
	Mix_PlayMusic(music->GetMusic(), -1);
}

void SoundManager::PlayNextBattleMusic() {
	if (fake_) return;

	PlayMusic( battle_music[current_battle_music_] );

	current_battle_music_ += 1;

	current_battle_music_ %= battle_music.size();
}

void SoundManager::PlayRandomBattleMusic() {
	current_battle_music_ = rand() % battle_music.size();
	PlayNextBattleMusic();
}

void SoundManager::PlaySoundEffect(SoundEffect* effect, int loops) {
	if (fake_) return;
	Mix_PlayChannel(-1, effect->GetSample(), loops);
}

void SoundManager::PlaySoundEffectAlone(SoundEffect* effect, int loops) {
	if (fake_) return;
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
			break;
		}
	}
}

void SoundManager::StopAllPlayback() {
	if (fake_) return;
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	current_battle_music_ = 0;
}

} //namespace sound
