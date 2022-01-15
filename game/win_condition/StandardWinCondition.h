// Autor Dennis, Peter


#ifndef BOMBERMAN_STANDARDWINCONDITION_H
#define BOMBERMAN_STANDARDWINCONDITION_H

#include "BaseWinCondition.h"


namespace game {

namespace win_condition {

/// Win condition for multiplayer games

class StandardWinCondition : public BaseWinCondition {
public:

    /// Checks if the player count is <=1 and displays the GameOverWindow
    void CheckWin() override;

};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_STANDARDWINCONDITION_H
