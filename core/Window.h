// Author: Tobias

#ifndef BOMBERMAN_CORE_GAMEWINDOW_H_
#define BOMBERMAN_CORE_GAMEWINDOW_H_

namespace core {

/// Window: Abstract class to represent different program display modes,
/// like the main game, or menus.

class Window {
public:
    /// Pure virtual method for the method Update()
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time) = 0;

    /// Pure virtual method for the method Draw()
    virtual void Draw() = 0;
};

} // namespace core

#endif // BOMBERMAN_CORE_GAMEWINDOW_H_
