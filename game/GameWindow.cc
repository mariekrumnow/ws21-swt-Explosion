//Autor Nina, Tobias

#include "GameWindow.h"

#include <iostream>

#include "../graphics/Color.h"
#include "../graphics/Tile.h"
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
            for (int i = objects.size()-1; i>=0; --i) {
                graphics.DrawTile(objects[i]->GetTile(), objects[i]->GetColor(),x_offset + x*60, y_offset + y*60);
            }
		}
	}
}

void GameWindow::Update(double delta_time) {
	GameManager& game = GameManager::GetCurrentGame();
	game.Update(delta_time);

	//This needs to be in the Game Window, otherwise you can cycle through
	//battle music in the main menu
	if (core::AppManager::GetAppManager().GetGraphics().IsKeyPressed(graphics::key_switch_music)) {
		core::AppManager::GetAppManager().GetSound().PlayNextBattleMusic();
	}
}

} // namespace game
