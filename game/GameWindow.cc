//
// Created by Dennis Neuhaus on 19.11.21.
//

#include "GameWindow.h"

#include "../core/Window.h"
#include "GameManager.h"
#include "Tile.h"
#include "Color.h"

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

			if (objects.size() == 0) {
				graphics.DrawTile(graphics::kTileDot, graphics::Color(200,200,200,255),
					x_offset + x*16, y_offset + y*16);
			} else {
				graphics.DrawTile(objects[0]->GetTile(), objects[0]->GetColor(),
					x_offset + x*16, y_offset + y*16);
			}
		}
	}
}

void GameWindow::Update(double delta_time) {
	GameManager& game = GameManager::GetCurrentGame();

	game.Update(delta_time);
}

}  //namespace game
