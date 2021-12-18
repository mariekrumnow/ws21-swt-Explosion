//Autor: Tobias

#ifndef SOUND_SOUNDMANAGER_H
#define SOUND_SOUNDMANAGER_H

#include "SoundEffect.h"
#include "Music.h"

#include <list>
#include <string>

#include <SDL_mixer.h>


namespace sound {

class SoundManager {
public:
	SoundManager(bool init_sound);
	~SoundManager();

	void SetMasterVolume(double volume);
	void SetMusicVolume(double volume);
	void SetSoundEffectVolume(double volume);

	double GetMasterVolume();
	double GetMusicVolume();
	double GetSoundEffectVolume();

	void PlayMusic(Music* music);
	void PlayNextBattleMusic();
	void PlayRandomBattleMusic();

	void PlaySoundEffect(SoundEffect* effect, int loops); //loops=1 => 2 playbacks

	//will only allow the sound effect to be played again once it's stopped playing.
	void PlaySoundEffectAlone(SoundEffect* effect, int loops);

	void StopAllPlayback(); //call this before any music assets are deleted!

	//only used as a global callback, do not call manually
	void OnChannelFinished(int channel);
private:
	std::list<SoundEffect*> playing_alone_;
	int current_battle_music_;

	double master_volume_;
	double music_volume_;
	double effect_volume_;

	//set to true if the AppManager is in Test Mode, so no hardware is initialized.
	bool fake_;
};

} //namespace sound

#endif
