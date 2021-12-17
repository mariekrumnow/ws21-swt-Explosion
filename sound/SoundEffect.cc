//Autor: Tobias

#include "SoundEffect.h"

#include <SDL_mixer.h>


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
