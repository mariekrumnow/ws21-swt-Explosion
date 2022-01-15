// Autor Tobias

#ifndef BOMBERMAN_GAME_SPGAMEWINDOW_H
#define BOMBERMAN_GAME_SPGAMEWINDOW_H

#include "GameWindow.h"

#include <string>

namespace game {

/// The Rendering class for the single player game mode

class SinglePlayerGameWindow : public GameWindow {
public:

    /// Constructor of SinglePlayerGameWindow
    SinglePlayerGameWindow();

    /// Destructor of SinglePlayerGameWindow
    ~SinglePlayerGameWindow();

    /// Draws the Interface for the Single Player game mode,
    /// and calls GameWindow::Draw
    void Draw();

    /// Sets the timer and high score attributes to be rendered in the HUD
    ///
    /// \param timer The time since the start of the run
    /// \param high_score The current high score time
    void SetTimers(std::string timer, std::string high_score);

private:
    std::string timer_; ///< The time since the start of the run
    std::string high_score_; ///< The current high score time
};

} // namespace game

#endif // BOMBERMAN_GAME_SPGAMEWINDOW_H
