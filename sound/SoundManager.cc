//Autor: Tobias

#include "SoundManager.h"

#include <list>

#include <SDL_mixer.h>

namespace sound {

SoundManager::SoundManager() {
	Mix_Init(0);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 16, 1024);

	playing_alone_ = std::list<SoundEffect*>();

	//make sure to get notified when a channel stops, for sound effect playback
	Mix_ChannelFinished([this](int channel) {this->OnChannelFinished(channel)});
}

SoundManager::~SoundManager() {
	Mix_CloseAudio();
	Mix_Quit();
}

void SoundManager::PlayMusic(Music* music) {
	Mix_PlayMusic(music->GetMusic(), -1);
}

void SoundManager::PlayNextBattleMusic() {
	PlayMusic( battle_music[current_battle_music_] );
	current_battle_music_ += 1;
	current_battle_music_ %= battle_music.size();
}

void SoundManager::PlaySoundEffect(SoundEffect* effect, int loops) {
	Mix_PlayChannel(-1, effect->GetSample(), loops);
}

void SoundManager::PlaySoundEffectAlone(SoundEffect* effect, int loops) {
	if (effect->GetCurrentChannel() != -1) return;

	int channel = Mix_PlayChannel(-1, effect->GetSample(), loops);
	effect->SetCurrentChannel(channel);

	playing_alone_.push_back(effect);
}

void SoundManager::OnChannelFinished(int channel) {
	//tell the sound effect that it has finished playing;
	for (auto it = playing_alone_.begin(); it!=playing_alone_.end(); it++) {
		if (it->GetCurrentChannel() == channel) {
			it->SetCurrentChannel(-1);
			playing_alone_.erase(it);
			break;
		}
	}
}

void SoundManager::StopAllPlayback() {
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	current_battle_music_ = 0;
}

} //namespace sound
