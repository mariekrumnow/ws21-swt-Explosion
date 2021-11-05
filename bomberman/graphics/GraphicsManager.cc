//Author: Tobias
#include "GraphicsManager.h"

namespace graphics {

GraphicsManager::GraphicsManager(bool init_graphics) {
	if (init_graphics) {
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_CreateWindowAndRenderer(kWindowWidth, kWindowHeight, 0,
			&window_, &renderer_);

		game_tileset_ = new TileSet(renderer_, "assets/curses_square_16x16.bmp",
			16,16);
		text_tileset_ = new TileSet(renderer_, "assets/curses_640x300.bmp", 9, 12);

	} else {
		window_ = nullptr;
		renderer_ = nullptr;
		game_tileset_ = nullptr;
		text_tileset_ = nullptr;
	}
}

GraphicsManager::~GraphicsManager() {
	if (game_tileset_ != nullptr) delete game_tileset_;
	if (text_tileset_ != nullptr) delete text_tileset_;
	SDL_Quit();
}

void GraphicsManager::BeginFrame() {
	if (window_ == nullptr) return;
	//fill the screen black
	SDL_SetRenderDrawColor(renderer_, 0,0,0,255);
	SDL_RenderClear(renderer_);
	//pump events so the os doesn't think the program has crashed
	SDL_PumpEvents();
}

void GraphicsManager::DrawTile(Tile tile, Color color, int x, int y) {
	if (window_ == nullptr) return;
	game_tileset_->DrawTile(renderer_, tile, color, x, y);
}

void GraphicsManager::EndFrame() {
	if (window_ == nullptr) return;
	SDL_RenderPresent(renderer_);
}

} //namespace graphics
