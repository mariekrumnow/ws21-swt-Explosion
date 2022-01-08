// Autor Nina, Tobias

#ifndef BOMBERMAN_GAME_GAMEWINDOW_H
#define BOMBERMAN_GAME_GAMEWINDOW_H

#include "../core/Window.h"

namespace game {

/// The Window where the Game is played

class GameWindow : public core::Window {
public:

    /// Creates a GameWindow
    GameWindow();

    /// Destructor of GameWindow
    ~GameWindow();

    /// Draws a Window with 120x76 pixel
    void Draw();

    /// Updates the current game
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);
};

} // namespace game

#endif // BOMBERMAN_GAME_GAMEWINDOW_H
