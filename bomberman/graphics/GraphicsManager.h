//Author: Tobias
#ifndef GRAPHICS_GRAPHICSMANAGER_H_
#define GRAPHICS_GRAPHICSMANAGER_H_

#include "TileSet.h"

#include <SDL.h>

namespace graphics {

//Graphics Manager: The class that manages all the graphics
class GraphicsManager {
public:
	const int kWindowHeight = 360;
	const int kWindowWidth = 480;

	GraphicsManager(bool init_graphics);
	~GraphicsManager();

	//call at the start of every frame
	void BeginFrame();
	void DrawTile(Tile tile, Color color, int x, int y);
	//call at the end of every frame
	void EndFrame();

private:
	TileSet* game_tileset_;
	TileSet* text_tileset_;
	SDL_Window * window_;
	SDL_Renderer * renderer_;
};

} //namespace graphics

#endif
