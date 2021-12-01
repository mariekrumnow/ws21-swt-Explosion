// Autor: Tobias
#ifndef GRAPHICS_KEYS_H_
#define GRAPHICS_KEYS_H_

#include <SDL.h>

namespace graphics {
// declarations of re-assignable scancodes for each In-Game function

extern SDL_Scancode key_return;
extern SDL_Scancode key_escape;
extern SDL_Scancode key_fullscreen;

struct PlayerKeys {
    SDL_Scancode up;
    SDL_Scancode down;
    SDL_Scancode left;
    SDL_Scancode right;
    SDL_Scancode bomb;
};

}

#endif
