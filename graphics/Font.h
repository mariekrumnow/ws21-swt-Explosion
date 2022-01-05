//Autor: Tobias
#ifndef GRAPHICS_FONT_H
#define GRAPHICS_FONT_H

#include "Color.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace graphics {

class Font {
public:
	static Font* CreateFont(std::string file, int size);
	Font(TTF_Font* font);
	~Font();

	void WriteText(SDL_Renderer* renderer, std::string text, Color color, Color background_color,
		bool bold, int x, int y);

private:
	TTF_Font* font_;
};


} //namespace graphics
#endif
