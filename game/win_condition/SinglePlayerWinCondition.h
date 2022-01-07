// Autor Tobias


#ifndef BOMBERMAN_SINGLEPLAYERWINCONDITION_H
#define BOMBERMAN_SINGLEPLAYERWINCONDITION_H

#include "BaseWinCondition.h"
#include "../SinglePlayerGameWindow.h"

#include <chrono>

namespace game {

namespace win_condition {

/// Win condition for single player

class SinglePlayerWinCondition : public BaseWinCondition {
public:
    /// Starts timer for win condition
    ///
    /// \param window window for the single player mode
    SinglePlayerWinCondition(SinglePlayerGameWindow* window);

    /// checks if all destructibleBlocks are destroyed or the Player died and sets the highscore
    void checkWin() override;

private:
    SinglePlayerGameWindow* window_;    ///< window for the single player mode
    std::chrono::system_clock::time_point start_time_ ; ///< The starting time when the game started
    int high_score_;    ///< high score in seconds
};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_SINGLEPLAYERWINCONDITION_H
