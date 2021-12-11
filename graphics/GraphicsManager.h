// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
#define BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_

#include "TileSet.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>

namespace graphics {

    enum class FontSize {
      kSmall,
      kMedium,
      kLarge
    };

/// Manages all the graphics
    class GraphicsManager {
    public:
        const int kWindowHeight = 900;
        const int kWindowWidth = 1100;

        GraphicsManager(std::string title, bool init_graphics);
        ~GraphicsManager();

        /// call at the start of every frame
        void BeginFrame();
        void DrawTile(Tile tile, Color color, int x, int y);
        /// sizes 14, 20, and 30 are supported
        void WriteText(std::string text, Color color, FontSize size, bool bold, int x, int y);
        /// call at the end of every frame
        void EndFrame();

        void SetFullscreen(bool fullscreen);

        /// only returns true on the first frame the key is pressed
        bool IsKeyPressed(int scancode);
        /// returns true as long as the key is pressed
        bool IsKeyHeld(int scancode);

        void Quit();

        void Sleep(int millis);

    private:
        TileSet* game_tileset_;
        TileSet* text_tileset_;
        SDL_Window * window_;
        SDL_Renderer * renderer_;

        TTF_Font * font_small_;
        TTF_Font * font_medium_;
        TTF_Font * font_large_;
      
        /// stores all keys that were already held on the last frame
        bool key_not_pressed_[SDL_NUM_SCANCODES];
        /// stores all keys that are held on this frame
        bool key_held_[SDL_NUM_SCANCODES];
        /// a key gets set to just held on the first frame,
        /// and then to "not pressed" and held on the second
    };

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
