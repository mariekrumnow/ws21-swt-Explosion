//Autor: Tobias

#ifndef SOUND_MUSIC_H
#define SOUND_MUSIC_H

#include <SDL_mixer.h>
#include <string>
#include <vector>

namespace sound {

/// A object managing a music track

class Music {
public:
    /// Loads the .wav-file with the matching filename from assets
    ///
    /// \param filename The filename that needs to be loaded
    /// \return A pointer to the loaded music, or nullptr on error
	static Music* LoadMusicFile(std::string filename);

    /// Initialize the object
    ///
    /// \param music The music object
	Music(Mix_Music* music);

    /// Deletes the music
	~Music();

    /// A Getter for the internal music object
    ///
    /// \return The music object
	Mix_Music* GetMusic();
private:
	Mix_Music* music_; ///< The music object
};

/// Load the music files of a theme
///
/// \param theme The theme that is chosen
/// \return true, if no error occurred
extern bool LoadMusic(std::string theme);


extern std::vector<Music*> battle_music; ///< The battle music
extern Music* menu_music; ///< The menu music
extern Music* victory_music; ///< The victory music


} //namespace sound

#endif
