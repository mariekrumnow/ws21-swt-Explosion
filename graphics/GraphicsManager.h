// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
#define BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_

#include "TileSet.h"

#include <SDL.h>
#include <cstdlib>

namespace graphics {

/// Manages all the graphics
    class GraphicsManager {
    public:
        const int kWindowHeight = 360;
        const int kWindowWidth = 480;

        GraphicsManager(bool init_graphics);
        ~GraphicsManager();

        /// call at the start of every frame
        void BeginFrame();
        void DrawTile(Tile tile, Color color, int x, int y);
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

        /// stores all keys that were already held on the last frame
        bool key_not_pressed_[SDL_NUM_SCANCODES];
        /// stores all keys that are held on this frame
        bool key_held_[SDL_NUM_SCANCODES];
        /// a key gets set to just held on the first frame,
        /// and then to "not pressed" and held on the second
    };

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_GRAPHICSMANAGER_H_
