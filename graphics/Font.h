//Autor: Tobias
#ifndef GRAPHICS_FONT_H
#define GRAPHICS_FONT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "Color.h"

namespace graphics {

/// Handles text drawing for a specific font and text size

class Font {
public:

    /// Creates a Font
    ///
    /// \param file The font file name
    /// \param size The size of the text
    /// \return A pointer to the font, or nullptr on error
	static Font* CreateFont(std::string file, int size);

    /// Constructor of Font
    ///
    /// \param font The text-font
	Font(TTF_Font* font);

    /// Destructor of Font
	~Font();

    /// Writes Text in the window
    ///
    /// \param renderer The renderer of the window in which the text needs to be written
    /// \param text The text that needs to be written
    /// \param color The color of the text
    /// \param background_color The background color of the text
    /// \param bold If the text should be bold or not
    /// \param x The X-position of the text
    /// \param y The Y-position of the text
	void WriteText(SDL_Renderer* renderer, std::string text, Color color, Color background_color,
		bool bold, int x, int y);

private:
	TTF_Font* font_; ///< The font that is being used
};

} //namespace graphics

#endif // GRAPHICS_FONT_H
