//Autor: Tobias

#ifndef SOUND_SOUNDEFFECT_H
#define SOUND_SOUNDEFFECT_H

#include <string>

#include <SDL_mixer.h>

namespace sound {

/// The sound-effects of the game

class SoundEffect {
public:
	/// Sets the sample, the channel and the volume
	///
	/// \param sample The music part that should play
	/// \param volume value between 0.0 and 1.0 inclusive
	SoundEffect(Mix_Chunk* sample, double volume);
	~SoundEffect();
	Mix_Chunk* GetSample();
	void SetCurrentChannel(int current_channel);
	int GetCurrentChannel();
private:
	Mix_Chunk* sample_;
	int current_channel_; //only set if the sound effects plays in "alone" mode
};

/// Loads the SoundEffects of the current Theme
///
/// \param theme The theme that is chosen
/// \return true if no error occurred
bool LoadSoundEffects(std::string theme);

} //namespace sound

#endif
