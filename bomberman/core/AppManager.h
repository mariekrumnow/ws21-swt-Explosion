//Author: Tobias

#ifndef CORE_APPMANAGER_H_
#define CORE_APPMANAGER_H_

#include "GameWindow.h"

#include <chrono>

#include <graphics/GraphicsManager.h>
#include <graphics/Keys.h>

namespace core {

//AppManager: The main class of the program, containing a static reference to
//itself and the main loop of the game
class AppManager {

public:
	static AppManager& GetAppManager();

	graphics::GraphicsManager graphics_;

	//init_graphics can be set to false to disable graphical function for testing
	AppManager(bool init_graphics);
	~AppManager();

	//sets the active game window. DOESN'T delete the current window.
	void SetActiveGameWindow(GameWindow& window);
	GameWindow& GetActiveWindow();
	void RunFrame(double deltaTime);
	//Run game for ever
	void Run();

private:
	GameWindow* active_game_window_;

	//The static reference to the current AppManager
	static AppManager* manager_;
};

} //namespace core

#endif
