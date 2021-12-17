//Autor: Tobias

#ifndef SOUND_MUSIC_H
#define SOUND_MUSIC_H

#include <SDL_mixer.h>

namespace sound {

class Music {
public:
	static Music* LoadMusicFile(std::string filename);
	Music(Mix_Music* music);
	~Music();
	Mix_Music* GetMusic();
private:
	Mix_Music* music_;
}


extern std::vector<Music*> battle_music;
extern Music* menu_music;
extern Music* victory_music;

} //namespace sound

#endif
