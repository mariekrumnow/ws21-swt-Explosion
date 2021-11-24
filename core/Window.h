// Author: Tobias
#ifndef ENGINE_GAMEWINDOW_H_
#define ENGINE_GAMEWINDOW_H_

namespace core {

// Window: Abstract class to represent different program display modes,
// like the main game, or menus.
    class Window {
    public:
        virtual void Update(double delta_time) = 0;
        virtual void Draw() = 0;
    };

}

#endif
