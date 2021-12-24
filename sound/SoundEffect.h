//Autor: Tobias

#ifndef SOUND_SOUNDEFFECT_H
#define SOUND_SOUNDEFFECT_H

#include <string>

#include <SDL_mixer.h>

namespace sound {

class SoundEffect {
public:
	///volume takes a value between 0.0 and 1.0 inclusive
	SoundEffect(Mix_Chunk* sample, double volume);
	~SoundEffect();
	Mix_Chunk* GetSample();
	void SetCurrentChannel(int current_channel);
	int GetCurrentChannel();
private:
	Mix_Chunk* sample_;
	int current_channel_; //only set if the sound effects plays in "alone" mode
};


extern SoundEffect* effect_bomb_explode;
extern SoundEffect* effect_bomb_tick;
extern SoundEffect* effect_menu_click;
extern SoundEffect* effect_upgrade_collect;
extern SoundEffect* effect_walk;

bool LoadSoundEffects(std::string theme);

} //namespace sound

#endif
