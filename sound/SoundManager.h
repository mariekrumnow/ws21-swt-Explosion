//Autor: Tobias

#ifndef SOUND_SOUNDMANAGER_H
#define SOUND_SOUNDMANAGER_H

#include <list>
#include <SDL_mixer.h>
#include <string>

#include "Music.h"
#include "SoundEffect.h"

namespace sound {

/// Manages the SoundEffects and the Music
class SoundManager {
public:
    /// Initializes the object
    ///
    /// \param init_sound If the sound hardware interfaces are started in normal-mode or Unit-Testmode
	SoundManager(bool init_sound);

    /// Ends the Sounds and Music
	~SoundManager();

    /// Sets the master volume
    ///
    /// \param volume The value the master volume should have
	void SetMasterVolume(double volume);

    /// Sets the Volume of Music
    ///
    /// \param volume The value the music volume should have
	void SetMusicVolume(double volume);

    /// Sets the Volume of SoundEffects
    ///
    /// \param volume The value the effect volume should have
	void SetSoundEffectVolume(double volume);

    /// A Getter for master volume
    ///
    /// \return The current master volume
	double GetMasterVolume();

    /// A Getter for music volume
    ///
    /// \return The current music volume
	double GetMusicVolume();

    /// A Getter for the sound effect volume
    ///
    /// \return The current effect volume
	double GetSoundEffectVolume();

    /// Plays the appropriate music
    ///
    /// \param music The music that should play
	void PlayMusic(Music* music);

    /// Plays the next battle-music
	void PlayNextBattleMusic();

    /// Plays a random battle-music
	void PlayRandomBattleMusic();

    /// Plays the appropriate SoundEffect
    ///
    /// \param effect The effect that should be played
    /// \param loops The amount of times the effect should repeat (0 = effect played once)
	void PlaySoundEffect(SoundEffect* effect, int loops); //loops=1 => 2 playbacks

	/// Play the SoundEffect only if it isn't already playing
	///
	/// \param effect The effect that should be played
	/// \param loops The amount of times the effect should repeat
	void PlaySoundEffectAlone(SoundEffect* effect, int loops);

    /// Halts the SoundEffects
	void StopPlayback(); //call this before any sound assets are deleted!

    /// Halts the music
	void StopMusicPlayback();

	///	Relays the callback that the sound effect has finished playing
	///
	/// \param channel The channel on which the music is playing
	void OnChannelFinished(int channel);
private:
	std::list<SoundEffect*> playing_alone_; ///< A list of sound effects for single player
	int current_battle_music_; ///< The battle music

	double master_volume_; ///< The master volume
	double music_volume_; ///< The volume of the music
	double effect_volume_; ///< The volume of effects
	bool fake_; ///< Set to true if the AppManager is in Test Mode, so no hardware is initialized
};

} //namespace sound

#endif
