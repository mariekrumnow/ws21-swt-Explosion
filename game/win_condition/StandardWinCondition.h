// Autor Dennis, Peter


#ifndef BOMBERMAN_STANDARDWINCONDITION_H
#define BOMBERMAN_STANDARDWINCONDITION_H

#include "BaseWinCondition.h"


namespace game {

namespace win_condition {

/// StandardWinCondition to check for the normal winning method in multiplayer games

class StandardWinCondition : public BaseWinCondition {
public:

    /// Checks if the playercount is <=1 and then calls the needed GameOverWindow
    void checkWin() override;

};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_STANDARDWINCONDITION_H
