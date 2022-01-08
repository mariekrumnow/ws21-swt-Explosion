//Autor: Tobias

#ifndef SOUND_MUSIC_H
#define SOUND_MUSIC_H

#include <SDL_mixer.h>
#include <string>
#include <vector>

namespace sound {

/// the music of the game

class Music {
public:
    /// Loads the .wav-file with the matching filename from assets
    ///
    /// \param filename The filename that needs to be loaded
    /// \return A pointer to the loaded music
	static Music* LoadMusicFile(std::string filename);

    /// Sets the current music
    ///
    /// \param music The music that should play
	Music(Mix_Music* music);

    /// Halts the music
	~Music();

    /// A Getter for music_
    ///
    /// \return The current music
	Mix_Music* GetMusic();
private:
	Mix_Music* music_; ///< The current music
};

/// Plays the corresponding music of the theme/menu
///
/// \param theme The theme that is chosen
/// \return true, if no error occurred
extern bool LoadMusic(std::string theme);


extern std::vector<Music*> battle_music; ///< The battle music
extern Music* menu_music; ///< The menu music
extern Music* victory_music; ///< The victory music


} //namespace sound

#endif
