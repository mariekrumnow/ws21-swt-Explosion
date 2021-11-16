//Author: Tobias
#include "AppManager.h"

#include <boost/test/unit_test.hpp>

namespace core {


AppManager* AppManager::manager_;

AppManager& AppManager::GetAppManager() {
	return *AppManager::manager_;
}

AppManager::AppManager(bool init_graphics) :
	graphics_(graphics::GraphicsManager(init_graphics)) {
	//ensure the reference to the AppManager stays active, and there is only one.
	if(AppManager::manager_ != nullptr) {
		delete AppManager::manager_;
	}

	AppManager::manager_ = this;
	active_game_window_ = nullptr;
}

AppManager::~AppManager() {
	AppManager::manager_ = nullptr;
}

void AppManager::SetActiveGameWindow(GameWindow &window) {
	active_game_window_ = &window;
}

GameWindow& AppManager::GetActiveWindow() {
	return *active_game_window_;
}

void AppManager::RunFrame(double delta_time) {
	if (active_game_window_ != nullptr) {
		active_game_window_->Update(delta_time);
		active_game_window_->Draw();
	}
}

void AppManager::Run() {
	double delta_time = 0.05;

	while (true) {
		auto start_time = std::chrono::high_resolution_clock::now();
		RunFrame(delta_time);

		//If Esc is pressed, exit the window
    if (graphics_.IsKeyPressed(key_escape)) {
      graphics_.Quit();
    }

		auto elapsed = std::chrono::high_resolution_clock::now() - start_time;

		delta_time = std::chrono::duration_cast<std::chrono::microseconds>(elapsed)
			.count()/1000000.0;
	}
}


} //namespace core
