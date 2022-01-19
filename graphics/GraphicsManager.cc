//Author: Tobias

#include "GraphicsManager.h"

#include <iostream>
#include <SDL_ttf.h>

#include "Font.h"

namespace graphics {

GraphicsManager::GraphicsManager(std::string title, bool init_graphics)
      : background_color_{graphics::Color(50,130,255,0)} {

    window_ = nullptr;
    renderer_ = nullptr;
    game_tileset_ = nullptr;
    font_small_ = nullptr;
    font_medium_ = nullptr;
    font_large_ = nullptr;

    if (init_graphics) {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(kWindowWidth, kWindowHeight, 0,
                                    &window_, &renderer_);

        SDL_SetWindowTitle(window_, title.c_str());

        for (int i=0; i<SDL_NUM_SCANCODES; i++) {
            key_not_pressed_[i] = false;
            key_held_[i] = false;
        }

        if (TTF_Init() < 0) {
            std::cout << "TTF initialization error" << std::endl;
        }

    }
}

GraphicsManager::~GraphicsManager() {
    delete game_tileset_;
    delete font_small_;
    delete font_medium_;
    delete font_large_;
    SDL_Quit();
    TTF_Quit();
}

void GraphicsManager::BeginFrame() {
    if (window_ == nullptr)
        return;
    //fill the screen black
    SDL_SetRenderDrawColor(renderer_, background_color_.red_, background_color_.green_, background_color_.blue_, 255);
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
    game_tileset_->DrawTile(renderer_, tile, color,
                            x + x_draw_offset_, y + y_draw_offset_);
}

void GraphicsManager::WriteText(std::string text,Color color,
                                FontSize size,bool bold,
                                int x,int y) {
    Font* font = NULL;

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

    font->WriteText(renderer_, text, color, background_color_, bold,
        x + x_draw_offset_, y + y_draw_offset_);
}

void GraphicsManager::EndFrame() {
    if (window_ == nullptr)
        return;
    SDL_RenderPresent(renderer_);
}

void GraphicsManager::SetFullscreen(bool fullscreen) {
    int screen_width, screen_height;

    if (fullscreen) {
        //switch to unscaled fullscreen mode and change renderer scale,
        //so the renderer graphics fill the screen.
        SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN_DESKTOP);
        SDL_GetWindowSize(window_, &screen_width, &screen_height);

        float scale_factor;
        if (screen_width / kWindowWidth < screen_height / kWindowHeight) {
            scale_factor = static_cast<float>(screen_width) / kWindowWidth;
        } else {
            scale_factor = static_cast<float>(screen_height) / kWindowHeight;
        }

        x_draw_offset_ = ((screen_width/2)/scale_factor - kWindowWidth/2);
        y_draw_offset_ = ((screen_height/2)/scale_factor - kWindowHeight/2);

        SDL_RenderSetScale(renderer_, scale_factor, scale_factor);

    } else {
        //switch to windowed and reset renderer scale
        SDL_SetWindowFullscreen(window_, 0);
        SDL_RenderSetScale(renderer_, 1, 1);
        x_draw_offset_ = 0;
        y_draw_offset_ = 0;
    }
}

void GraphicsManager::SetBackgroundColor(Color background_color){
      background_color_ = background_color;
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

bool GraphicsManager::LoadTileset(std::string theme) {
    delete game_tileset_;
    game_tileset_ = TileSet::CreateTileset(renderer_, "assets/"+theme+"/tileset.bmp",
                                           60,60);
    if (!game_tileset_) { //load default, if that doesn't work, print error
        if (theme == "default") {
            std::cout << "Couldn't load tileset: " << SDL_GetError() << std::endl;
            return false;
        } else {
            return LoadTileset("default");
        }
    }

    return true;
}

bool GraphicsManager::LoadFonts(std::string theme) {
    delete font_small_;
    delete font_medium_;
    delete font_large_;
    font_small_ = Font::CreateFont("assets/"+theme+"/font.ttf", 14);
    font_medium_ = Font::CreateFont("assets/"+theme+"/font.ttf", 20);
    font_large_ = Font::CreateFont("assets/"+theme+"/font.ttf", 30);

    if (!font_small_ || !font_medium_ || !font_large_) {
        //load default, if that doesn't work, print error
        if (theme == "default") {
            std::cout << "Couldn't load fonts: " << TTF_GetError() << std::endl;
            return false;
        } else {
            return LoadFonts("default");
        }
    }

    return true;
}

} // namespace graphics
