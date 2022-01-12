// Autor Nina, Tobias

#ifndef BOMBERMAN_GAME_GAMEWINDOW_H
#define BOMBERMAN_GAME_GAMEWINDOW_H

#include "../core/Window.h"

namespace game {

/// The window that handles rendering the game

class GameWindow : public core::Window {
public:

    /// Constructor of the GameWindow
    GameWindow();

    /// Destructor of GameWindow
    ~GameWindow();

    /// Draws the objects of the GameManager on the screen
    void Draw();

    /// Updates the current game manager
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);
};

} // namespace game

#endif // BOMBERMAN_GAME_GAMEWINDOW_H
