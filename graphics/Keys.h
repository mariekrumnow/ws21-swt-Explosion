// Autor: Tobias

#ifndef BOMBERMAN_GRAPHICS_KEYS_H_
#define BOMBERMAN_GRAPHICS_KEYS_H_

#include <SDL.h>

namespace graphics {

/// declarations of re-assignable scancodes for each In-Game function
extern SDL_Scancode key_return;
extern SDL_Scancode key_escape;
extern SDL_Scancode key_fullscreen;
extern SDL_Scancode key_menu_up[2];
extern SDL_Scancode key_menu_down[2];


struct PlayerKeys {
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
    SDL_Scancode bomb;
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_KEYS_H_
