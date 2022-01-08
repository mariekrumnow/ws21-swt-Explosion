// Autor Tobias

#ifndef BOMBERMAN_GAME_SPGAMEWINDOW_H
#define BOMBERMAN_GAME_SPGAMEWINDOW_H

#include "GameWindow.h"

#include <string>

namespace game {

/// The Interface for the SinglePlayerMode

class SinglePlayerGameWindow : public GameWindow {
public:

    /// Constructor of SinglePlayerGameWindow
    SinglePlayerGameWindow();

    /// Destructor of SinglePlayerGameWindow
    ~SinglePlayerGameWindow();

    /// Draws the Interface for the SinglePlayerGameMode
    void Draw();

    /// Allocates the attributes timer_ and high_score_
    ///
    /// \param timer The time that was needed in this run
    /// \param high_score The current lowest time that was needed
    void SetTimers(std::string timer, std::string high_score);

private:
    std::string timer_; ///< The time that was needed in this run
    std::string high_score_; ///< The current lowest time that was needed
};

} // namespace game

#endif // BOMBERMAN_GAME_SPGAMEWINDOW_H
