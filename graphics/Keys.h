// Autor: Tobias, Dennis, Peter

#ifndef BOMBERMAN_GRAPHICS_KEYS_H_
#define BOMBERMAN_GRAPHICS_KEYS_H_

#include <SDL.h>

namespace graphics {

// declarations of re-assignable scancodes for each In-Game function

extern SDL_Scancode key_return; ///< re-assignable scancode of the button: Return
extern SDL_Scancode key_escape; ///< re-assignable scancode of the button: Escape
extern SDL_Scancode key_fullscreen; ///< re-assignable scancode of the button: F11
extern SDL_Scancode key_menu_up[2]; ///< re-assignable scancode of the button: W and UP
extern SDL_Scancode key_menu_down[2]; ///< re-assignable scancode of the button: s and DOWN


extern SDL_Scancode key_w; ///< re-assignable scancode of the button: W
extern SDL_Scancode key_s; ///< re-assignable scancode of the button: S
extern SDL_Scancode key_a; ///< re-assignable scancode of the button: A
extern SDL_Scancode key_d; ///< re-assignable scancode of the button: D
extern SDL_Scancode key_l_shift; ///< re-assignable scancode of the button: lShift

extern SDL_Scancode key_i; ///< re-assignable scancode of the button: i
extern SDL_Scancode key_j; ///< re-assignable scancode of the button: j
extern SDL_Scancode key_k; ///< re-assignable scancode of the button: k
extern SDL_Scancode key_l; ///< re-assignable scancode of the button: l
extern SDL_Scancode key_r_shift; ///< re-assignable scancode of the button: rShift

extern SDL_Scancode key_switch_music; ///< re-assignable scancode of the button: F12
extern SDL_Scancode key_volume_louder; ///< re-assignable scancode of the button: F8
extern SDL_Scancode key_volume_quieter; ///< re-assignable scancode of the button: F7

/// Struct for storing a players control keys
struct PlayerKeys {
    SDL_Scancode up; ///< key for up
    SDL_Scancode down; ///< key for down
    SDL_Scancode left; ///< key for left
    SDL_Scancode right; ///< key for right
    SDL_Scancode bomb; ///< Key for placing bomb
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_KEYS_H_
