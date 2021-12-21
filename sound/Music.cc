//Autor: Tobias

#include "Music.h"

#include <iostream>
#include <filesystem>
#include <fstream>

#include <SDL_mixer.h>

namespace fs = std::filesystem;

namespace sound {

Music* Music::LoadMusicFile(std::string filename) {

	Mix_Music* mix_music = Mix_LoadMUS(filename.c_str());
	if (mix_music == NULL) {
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

Music* LoadMusicFile(std::string theme, std::string filename) {
	Music* music = Music::LoadMusicFile("assets\\"+theme+"\\music\\"+filename);
	if (!music) {
		if (theme == "default") {
			std::cout << "Couldn't load music "+filename+" - ";
			std::cout << Mix_GetError() << std::endl;
			return nullptr;
		} else {
			return LoadMusicFile("default", filename);
		}
	}

	return music;
}

//return false on failure, true on success (only call while playback is halted)
bool LoadMusic(std::string theme) {
	delete menu_music;
	delete victory_music;
	for (auto music_pointer : battle_music) {
		delete music_pointer;
	}
	battle_music.clear();

	for (auto entry : fs::directory_iterator("./assets/"+theme+"/music/battle")) {
		Music* music = Music::LoadMusicFile(entry.path().u8string());
		if (music) {
			battle_music.push_back(music);
		}
	}

	if (battle_music.size() == 0) {
		std::cout << "Couldn't load battle music for theme "+theme << std::endl;
	}

	menu_music = LoadMusicFile(theme, "Menu.wav");
	victory_music = LoadMusicFile(theme, "Victory.wav");

	if (battle_music.size() == 0 || !menu_music || !victory_music) {
		return false;
	}

	return true;
}

} //namespace sound
