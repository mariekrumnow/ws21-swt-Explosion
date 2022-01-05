//Autor Tobias

#include "SinglePlayerGameWindow.h"

#include <iostream>

#include "../core/AppManager.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"
#include "../graphics/GraphicsManager.h"


namespace game {

SinglePlayerGameWindow::SinglePlayerGameWindow() {}

SinglePlayerGameWindow::~SinglePlayerGameWindow() {}

void SinglePlayerGameWindow::Draw() {
	this->GameWindow::Draw();

	graphics::GraphicsManager& graphics = core::AppManager::GetAppManager()
		.GetGraphics();

	graphics.WriteText(high_score_, graphics::Color(0, 255, 0, 255), graphics::FontSize::kLarge, false, 10, 10);
	graphics.WriteText(timer_, graphics::Color(255, 0, 0, 255), graphics::FontSize::kLarge, false, 850, 10);
}

void SinglePlayerGameWindow::SetTimers(std::string timer, std::string high_score) {
	timer_ = timer;
	high_score_ = high_score;
}

} // namespace game
