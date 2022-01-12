// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
#define BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_

#include <cstdlib>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Font.h"
#include "TileSet.h"

namespace graphics {

/// enum
/// for Font-Sizes
enum class FontSize {
    kSmall,     ///< Enum value 0
    kMedium,    ///< Enum value 1
    kLarge      ///< Enum value 2
};

/// The object handling rendering and keyboard inputs
class GraphicsManager {
public:

    /// Initializes everything related to SDL-Graphics
    ///
    /// \param title The title of the window
    /// \param init_graphics If the graphic interface is started in normal-mode or Unit-Testmode
    GraphicsManager(std::string title, bool init_graphics);

    /// Deletes and ends everything related to SDL-Graphics
    ~GraphicsManager();

    /// Called at the start of every frame
    /// Clears the screen and processes incoming keyboard and window events
    void BeginFrame();

    /// Draws a given tile at a specific Position
    ///
    /// \param tile The tile that needs to be drawn
    /// \param color The color of the tile
    /// \param x The X-coordinate of the new tile
    /// \param y The Y-coordinate of the new tile
    void DrawTile(Tile tile, Color color, int x, int y);

    /// Writes Text in the matching Font-style
    ///
    /// \param text The text that needs to be written
    /// \param color The color of the text
    /// \param size The size of the text
    /// \param bold If the text is bold or not
    /// \param x The X-coordinate of the text
    /// \param y The Y-coordinate of the text
    void WriteText(std::string text, Color color, FontSize size, bool bold, int x, int y);

    /// Called at the end of every frame
    /// Updates the screen contents
    void EndFrame();

    /// Switches fromrm window-mode to fullscreen and vice versa
    ///
    /// \param fullscreen True: Switch to fullscreen, False: Switch to windowed
    void SetFullscreen(bool fullscreen);

    /// Change the background-color of the window
    ///
    /// \param background_color The background-color of the window
    void SetBackgroundColor(Color background_color);

    /// Checks if the Key is pressed
    /// Only returns true on the first frame the key is pressed
    ///
    /// \param scancode The key that is being pressed
    /// \return true on the first frame the key is pressed
    bool IsKeyPressed(int scancode);

    /// Checks if the Key is held
    /// returns true as long as the key is pressed
    ///
    /// \param scancode The key that is being pressed
    /// \return true as long as the key is being pressed
    bool IsKeyHeld(int scancode);

    /// closes the Game
    [[noreturn]] void Quit();

    /// Delays the game
    ///
    /// \param millis The time, in milliseconds, to wait
    void Sleep(int millis);

    /// Loads the graphics assets of a theme
    ///
    /// \param theme The theme that is chosen
    /// \return true if no error occurred
    bool LoadTileset(std::string theme);

    /// Creates the font of the theme
    ///
    /// \param theme The theme that is chosen
    /// \return true if no error occurred
    bool LoadFonts(std::string theme);

    const int kWindowHeight = 900; ///< The height of the window
    const int kWindowWidth = 1100; ///< The width of the window

private:
    bool key_not_pressed_[SDL_NUM_SCANCODES]; ///< stores all keys that were already held on the last frame
    bool key_held_[SDL_NUM_SCANCODES]; ///< stores all keys that are held on this frame
    TileSet* game_tileset_; ///< The current tileset for the game
    SDL_Window* window_; ///< The window of the game
    SDL_Renderer* renderer_; ///< The renderer of the window
    Color background_color_; ///< The background color of the window

    int x_draw_offset_=0; ///< X-offset for drawing
    int y_draw_offset_=0; ///< Y-offset for drawing

    Font* font_small_; ///< The small font
    Font* font_medium_; ///< The medium font
    Font* font_large_; ///< The large font
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
