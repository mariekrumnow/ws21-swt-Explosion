//Author: Tobias

#include "GraphicsManager.h"

#include <SDL_ttf.h>
#include <iostream>

namespace graphics {

GraphicsManager::GraphicsManager(std::string title, bool init_graphics) {
    if (init_graphics) {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(kWindowWidth, kWindowHeight, 0,
                                    &window_, &renderer_);

        SDL_SetWindowTitle(window_, title.c_str());

        game_tileset_ = new TileSet(renderer_, "assets/Halloween.bmp",
                                    60,60);
        text_tileset_ = new TileSet(renderer_, "assets/curses_640x300.bmp", 9, 12);

        for (int i=0; i<SDL_NUM_SCANCODES; i++) {
            key_not_pressed_[i] = false;
            key_held_[i] = false;
        }

        if (TTF_Init() < 0) {
            std::cout << "TTF initialization error" << std::endl;
        }

        font_small_ = TTF_OpenFont("assets/font.ttf", 14);
        font_medium_ = TTF_OpenFont("assets/font.ttf", 20);
        font_large_ = TTF_OpenFont("assets/font.ttf", 30);
        if (!font_small_ || !font_medium_ || !font_large_) {
            std::cout << "Font initialization error" << std::endl;
        }

        } else {
            window_ = nullptr;
            renderer_ = nullptr;
            game_tileset_ = nullptr;
            text_tileset_ = nullptr;
    }
}

GraphicsManager::~GraphicsManager() {
    if (game_tileset_ != nullptr)
        delete game_tileset_;
    if (text_tileset_ != nullptr)
        delete text_tileset_;
    SDL_Quit();
    TTF_Quit();
}

void GraphicsManager::BeginFrame() {
    if (window_ == nullptr)
        return;
    ///fill the screen black
    SDL_SetRenderDrawColor(renderer_, 0,0,0,255);
    SDL_RenderClear(renderer_);

    ///All keys held on the previous frame are now not pressed anymore
    for (int i=0; i<SDL_NUM_SCANCODES; i++) {
        key_not_pressed_[i] = key_held_[i];
    }

    ///handle all new events
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            ///events sent by the window manager
            case SDL_WINDOWEVENT:
                switch (event.window.event) {
                    case SDL_WINDOWEVENT_CLOSE:
                        Quit();
                        break;
                }
                break;
            ///quit event
            case SDL_QUIT:
                Quit();
                break;
            ///events sent by the keyboard
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

void GraphicsManager::WriteText(std::string text,Color color,
                                FontSize size,bool bold,
                                int x,int y) {
    TTF_Font* font = NULL;

    switch (size) {
        case FontSize::kSmall:
            font = font_small_;
            break;
        case FontSize::kMedium:
            font = font_medium_;
            break;
            case FontSize::kLarge:
            font = font_large_;
    }

    if (!font) return;

    TTF_SetFontStyle(font, bold ? TTF_STYLE_BOLD : 0);

    SDL_Surface* text_surface =TTF_RenderUTF8_Shaded(font, text.c_str(),
                                  {color.red_, color.green_, color.blue_, color.alpha_}, {0,0,0,0});

    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer_, text_surface);

    SDL_Rect text_size;
    SDL_GetClipRect(text_surface, &text_size);
    const SDL_Rect kDestination =
            {x, y, text_size.w, text_size.h};

    SDL_SetTextureColorMod(text_texture, 255, 255, 255);
    SDL_RenderCopy(renderer_, text_texture, NULL, &kDestination);

    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

void GraphicsManager::EndFrame() {
    if (window_ == nullptr)
        return;
    SDL_RenderPresent(renderer_);
}

void GraphicsManager::SetFullscreen(bool fullscreen) {
    if (fullscreen) {
        SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
    } else {
        SDL_SetWindowFullscreen(window_, 0);
    }
}

bool GraphicsManager::IsKeyPressed(int scancode) {
    if (scancode < 0 || scancode >= SDL_NUM_SCANCODES)
        return false;
    return key_held_[scancode] && !key_not_pressed_[scancode];
}

bool GraphicsManager::IsKeyHeld(int scancode) {
    if (scancode < 0 || scancode >= SDL_NUM_SCANCODES)
        return false;
    return key_held_[scancode];
}

void GraphicsManager::Quit() {
    exit(0);
}

void GraphicsManager::Sleep(int millis) {
    SDL_Delay(millis);
}

} // namespace graphics
