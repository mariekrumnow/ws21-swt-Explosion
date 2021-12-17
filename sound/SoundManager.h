//Autor: Tobias

#ifndef SOUND_SOUNDMANAGER_H
#define SOUND_SOUNDMANAGER_H

#include "SoundEffect.h"
#include "Music.h"

#include <list>

#include <SDL_mixer.h>


namespace sound {

class SoundManager {
public:
	SoundManager();
	~SoundManager();

	void PlayMusic(Music* music);
	void PlayNextBattleMusic();

	void PlaySoundEffect(SoundEffect* effect, int loops); //loops=1 => 2 playbacks

	//will only allow the sound effect to be played again once it's stopped playing.
	void PlaySoundEffectAlone(SoundEffect* effect, int loops);

	void StopAllPlayback(); //call this before any music assets are deleted!
private:
	void OnChannelFinished(int channel);
	std::list<SoundEffect*> playing_alone_;
	int current_battle_music_;

}

}

#endif
