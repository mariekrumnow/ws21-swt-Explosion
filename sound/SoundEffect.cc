//Autor: Tobias

#include "SoundEffect.h"

#include <iostream>
#include <string>

#include <SDL_mixer.h>

namespace sound {

SoundEffect::SoundEffect(Mix_Chunk* sample, double volume) {
	sample_ = sample;
	current_channel_ = -1;
	Mix_VolumeChunk(sample_, volume * MIX_MAX_VOLUME);
}

SoundEffect::~SoundEffect() {
	Mix_FreeChunk(sample_);
}

Mix_Chunk* SoundEffect::GetSample() {
	return sample_;
}

void SoundEffect::SetCurrentChannel(int current_channel) {
	current_channel_ = current_channel;
}

int SoundEffect::GetCurrentChannel() {
	return current_channel_;
}

SoundEffect* effect_bomb_explode;
SoundEffect* effect_bomb_tick;
SoundEffect* effect_menu_click;
SoundEffect* effect_upgrade_collect;
SoundEffect* effect_walk;

SoundEffect* LoadSoundEffect(std::string theme, std::string filename, double volume) {
	Mix_Chunk* sample = Mix_LoadWAV(("./assets/"+theme+"/sounds/"+filename).c_str());

	//if sound effect isn't available in the theme, try the default
	if (!sample) {
		if (theme == "default") {
			std::cout << "Couldn't load sound "+filename+" for theme "+theme+" - ";
			std::cout << Mix_GetError() << std::endl;
			return nullptr;
		} else {
			return LoadSoundEffect("default", filename, volume);
		}
	}

	return new SoundEffect(sample, volume);
}

bool LoadSoundEffects(std::string theme) {
	bool success = true;

	delete effect_bomb_explode;
	delete effect_bomb_tick;
	delete effect_menu_click;
	delete effect_upgrade_collect;
	delete effect_walk;

	success &= static_cast<bool>(effect_bomb_explode =
		LoadSoundEffect(theme, "bomb_explode.wav", 1.0));

	success &= static_cast<bool>(effect_bomb_tick =
		LoadSoundEffect(theme, "bomb_tick.wav", 1.0));

	success &= static_cast<bool>(effect_menu_click =
		LoadSoundEffect(theme, "menu_click.wav", 1.0));

	success &= static_cast<bool>(effect_upgrade_collect =
		LoadSoundEffect(theme, "upgrade_collect.wav", 1.0));

	success &= static_cast<bool>(effect_walk =
		LoadSoundEffect(theme, "walk.wav", 1.0));

	return success;
}

} //namespace sound
