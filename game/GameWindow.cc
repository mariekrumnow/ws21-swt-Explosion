//Autor Nina, Tobias

#include "GameWindow.h"

#include <iostream>

#include "../graphics/Tile.h"
#include "../graphics/Color.h"
#include "GameManager.h"


namespace game {

GameWindow::GameWindow() {}

GameWindow::~GameWindow() {}

void GameWindow::Draw() {
	GameManager& game = GameManager::GetCurrentGame();
	graphics::GraphicsManager& graphics = core::AppManager::GetAppManager()
		.GetGraphics();

	int x_offset = 120;
	int y_offset = 76;

	for (int x = 0; x < game.GetWidth(); x++) {
		for (int y = 0; y < game.GetHeight(); y++) {

			std::vector<GameObject*>& objects = game.GetObjectsAtPos(x, y);

            graphics.DrawTile(graphics::kTileEmpty,graphics::Color(255,255,255,255),x_offset + x*60, y_offset + y*60);
            if (objects.size() != 0) {
                graphics.DrawTile(objects[0]->GetTile(), objects[0]->GetColor(),x_offset + x*60, y_offset + y*60);
            }
		}
	}
}

void GameWindow::Update(double delta_time) {
	GameManager& game = GameManager::GetCurrentGame();
	game.Update(delta_time);
}

} // namespace game
