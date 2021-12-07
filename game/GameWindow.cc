//Autor Nina, Tobias

#include "GameWindow.h"

#include "../core/Window.h"
#include "GameManager.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

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

	//Graphik Test Beispiele
	/*graphics.WriteText("Hallo Carla!", graphics::Color(255,128,0,255), graphics::FontSize::kLarge, false, 10,10);
	graphics.WriteText("Hallo Carla!", graphics::Color(255,0,0,255), graphics::FontSize::kMedium, false, 10,100);
	graphics.WriteText("Hallo Carla!", graphics::Color(0,255,0,255), graphics::FontSize::kSmall, false, 10,200);
	graphics.WriteText("Hallo Carla!", graphics::Color(255,128,0,255), graphics::FontSize::kLarge, true, 200,10);
	graphics.WriteText("Hallo Carla!", graphics::Color(255,0,0,255), graphics::FontSize::kMedium, true, 200,100);
	graphics.WriteText("Hallo Carla!", graphics::Color(0,255,0,255), graphics::FontSize::kSmall, true, 200,200);*/
}

void GameWindow::Update(double delta_time) {
	GameManager& game = GameManager::GetCurrentGame();

	game.Update(delta_time);
}

}  //namespace game
