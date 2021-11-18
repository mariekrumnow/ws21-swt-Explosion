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

            for (int i=0; i<SDL_NUM_SCANCODES; i++) {
                key_not_pressed_[i] = false;
                key_held_[i] = false;
            }

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

        //All keys held on the previous frame are now not pressed anymore
        for (int i=0; i<SDL_NUM_SCANCODES; i++) {
            key_not_pressed_[i] = key_held_[i];
        }

        //handle all new events
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                //events sent by the window manager
                case SDL_WINDOWEVENT:

                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_CLOSE:
                            Quit();
                            break;
                    }
                    break;

                    //quit event
                case SDL_QUIT:
                    Quit();
                    break;

                    //events sent by the keyboard
                case SDL_KEYDOWN:
                    key_held_[event.key.keysym.scancode] = true;
                    break;

                case SDL_KEYUP:
                    key_not_pressed_[event.key.keysym.scancode] = false;
                    key_held_[event.key.keysym.scancode] = false;
                    break;

            }
        }
    }

    void GraphicsManager::DrawTile(Tile tile, Color color, int x, int y) {
        if (window_ == nullptr) return;
        game_tileset_->DrawTile(renderer_, tile, color, x, y);
    }

    void GraphicsManager::EndFrame() {
        if (window_ == nullptr) return;
        SDL_RenderPresent(renderer_);
    }

    bool GraphicsManager::IsKeyPressed(int scancode) {
        if (scancode < 0 || scancode >= SDL_NUM_SCANCODES) return false;
        return key_held_[scancode] && !key_not_pressed_[scancode];
    }

    bool GraphicsManager::IsKeyHeld(int scancode) {
        if (scancode < 0 || scancode >= SDL_NUM_SCANCODES) return false;
        return key_held_[scancode];
    }

    void GraphicsManager::Quit() {
        exit(0);
    }

} //namespace graphics
