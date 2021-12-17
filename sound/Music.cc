//Autor: Tobias

#include "Music.h"

#include <iostream>
#include <filesystem>

#include <SDL_mixer.h>

namespace fs = std::filesystem;

namespace sound {

Music* Music::LoadMusicFile(std::string filename) {
	Mix_Music* mix_music = Mix_LoadMUS(filename.c_str());
	if (mix_music == nullptr) {
		std::cout << "Couldn't load "+filename << std::endl;
		return nullptr;
	}
	return new Music(mix_music);
}


Music::Music(Mix_Music * music) {
	music_ = music;
}

Music::~Music() {
	Mix_FreeMusic(music_);
}

Mix_Music* Music::GetMusic() {
	return music_;
}


std::vector<Music*> battle_music;
Music* menu_music = nullptr;
Music* victory_music = nullptr;

//return false on failure, true on success (only call while playback is halted)
bool LoadMusic(std::string theme) {
	for (auto music_pointer : battle_music) {
		delete music_pointer;
	}
	battle_music.clear();

	for (auto entry : fs::directory_iterator("./assets/"+theme+"/music/battle")) {
		battle_music.push_back(Music::LoadMusicFile(entry.path()));
	}

	delete menu_music;
	delete victory_music;
	menu_music = Music::LoadMusicFile("./assets/"+theme+"/music/Menu.wav");
	victory_music = Music::LoadMusicFile("./assets/"+theme+"/music/Victory.wav");

	if (!menu_music) {
		menu_music = Music::LoadMusicFile("./assets/default/music/Menu.wav");
	}
	if (!victory_music) {
		victory_music = Music::LoadMusicFile("./assets/default/music/Victory.wav");
	}

	if (battle_music.size() == 0) {
		std::cout << "Couldn't load battle music for theme "+theme << std::endl;
		return false;
	}
	if (!menu_music) {
		std::cout << "Couldn't load menu music for theme "+theme << std::endl;
		return false;
	}
	if (!victory_music) {
		std::cout << "Couldn't load victory music for theme "+theme << std::endl;
		return false;
	}
	return true;
}

} //namespace sound
