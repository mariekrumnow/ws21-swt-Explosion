//Autor: Tobias

#include "Music.h"

#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#else
#include <filesystem>
#endif

#include <SDL_mixer.h>

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
	Music* music = Music::LoadMusicFile("assets/"+theme+"/music/"+filename);
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


	//load all battle music files via Windows API
#	ifdef _WIN32
	WIN32_FIND_DATA find_file_data;
	HANDLE file;

	//Get handle to first file
	file = FindFirstFile(("./assets/"+theme+"/music/battle/*").c_str(), &find_file_data);

	if (file != INVALID_HANDLE_VALUE) {
		//iterate through all other handles in the directory
		do {

			//if the handle is to a file, not a directory
			if (!(find_file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				//load it as a music file
				std::string path =
					"./assets/"+theme+"/music/battle/" + find_file_data.cFileName;
				Music* music = Music::LoadMusicFile(path);
				if (music) {
					battle_music.push_back(music);
				}
			}
		} while (FindNextFile(file, &find_file_data));
	}

	FindClose(file);

	//on Unix, use C++17 interface instead (only on Unix, Windows GCC doesn't support it)
#	else
	const std::filesystem::path music_path{"./assets/"+theme+"/music/battle"};
	for (auto entry : std::filesystem::directory_iterator(music_path)) {
		Music* music = Music::LoadMusicFile(entry.path().u8string());
		if (music) {
			battle_music.push_back(music);
		}
	}
#	endif


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
