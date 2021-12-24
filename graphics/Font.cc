//Autor: Tobias

#include "Font.h"

#include "Color.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

namespace graphics {

Font* Font::CreateFont(std::string file, int size) {
	TTF_Font* font = TTF_OpenFont(file.c_str(), size);

	if (!font) {
		return nullptr;
	} else {
		return new Font(font);
	}
}

Font::Font(TTF_Font* font) : font_(font) {}

Font::~Font() {
	TTF_CloseFont(font_);
}

void Font::WriteText(SDL_Renderer* renderer, std::string text, Color color,
	bool bold, int x, int y) {

	TTF_SetFontStyle(font_, bold ? TTF_STYLE_BOLD : 0);

    SDL_Surface* text_surface =TTF_RenderUTF8_Shaded(font_, text.c_str(),
                                  {color.red_, color.green_, color.blue_, color.alpha_}, {0,0,0,0});

    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

    SDL_Rect text_size;
    SDL_GetClipRect(text_surface, &text_size);
    const SDL_Rect kDestination =
            {x, y, text_size.w, text_size.h};

    SDL_SetTextureColorMod(text_texture, 255, 255, 255);
    SDL_RenderCopy(renderer, text_texture, NULL, &kDestination);

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}


} //namespace graphics
