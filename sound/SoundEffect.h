//Autor: Tobias

#ifndef SOUND_SOUNDEFFECT_H
#define SOUND_SOUNDEFFECT_H

#include <SDL_mixer.h>
#include <string>

namespace sound {

/// The sound-effects of the game

class SoundEffect {
public:
	/// Sets the sample, the channel and the volume
	///
	/// \param sample The music part that should play
	/// \param volume value between 0.0 and 1.0 inclusive
	SoundEffect(Mix_Chunk* sample, double volume);

    /// Halts the SoundEffect
	~SoundEffect();

    /// A Getter for sample_
    ///
    /// \return The current music part
	Mix_Chunk* GetSample();

    /// Changes the current Channel
    ///
    /// \param current_channel The current channel
	void SetCurrentChannel(int current_channel);

    /// A Getter for current_channel
    ///
    /// \return The current channel
	int GetCurrentChannel();
private:
	Mix_Chunk* sample_; ///< The music part
	int current_channel_; ///< only set if the sound effects plays in "alone" mode
};

/// Loads the SoundEffects of the current Theme
///
/// \param theme The theme that is chosen
/// \return true if no error occurred
bool LoadSoundEffects(std::string theme);


extern SoundEffect* effect_bomb_explode; ///< The exploding sound
extern SoundEffect* effect_bomb_tick; ///< The ticking sound
extern SoundEffect* effect_menu_click; ///< The menu clicking sound
extern SoundEffect* effect_upgrade_collect; ///< The collecting sound
extern SoundEffect* effect_walk; ///< The walking sound

} //namespace sound

#endif
