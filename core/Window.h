// Author: Tobias

#ifndef BOMBERMAN_CORE_GAMEWINDOW_H_
#define BOMBERMAN_CORE_GAMEWINDOW_H_

namespace core {

/// Window: Abstract class to represent different program display modes,
/// like the main game, or menus.

class Window {
public:
    /// Pure virtual method called once a frame to update the games simulation
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time) = 0;

    /// Pure virtual method called once a frame to draw the games current state to the window
    virtual void Draw() = 0;
};

} // namespace core

#endif // BOMBERMAN_CORE_GAMEWINDOW_H_
