// Autor Tobias


#ifndef BOMBERMAN_SINGLEPLAYERWINCONDITION_H
#define BOMBERMAN_SINGLEPLAYERWINCONDITION_H

#include <chrono>

#include "../SinglePlayerGameWindow.h"
#include "BaseWinCondition.h"

namespace game {

namespace win_condition {

/// Win condition for single player games

class SinglePlayerWinCondition : public BaseWinCondition {
public:
    /// Initializes the timer
    ///
    /// \param window window for the single player mode
    SinglePlayerWinCondition(SinglePlayerGameWindow* window);

    /// checks if all destructible blocks are destroyed or the Player died
    /// If so, displays the High Score screen and saves the high score appropriately
    void CheckWin() override;

private:
    SinglePlayerGameWindow* window_;    ///< The active game window of single player mode
    std::chrono::system_clock::time_point start_time_ ; ///< The time the game started
    int high_score_;    ///< high score in milliseconds
};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_SINGLEPLAYERWINCONDITION_H
