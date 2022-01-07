// Autor Dennis, Peter

#ifndef BOMBERMAN_BASEWINCONDITION_H
#define BOMBERMAN_BASEWINCONDITION_H

#include <vector>

namespace game {
namespace win_condition {

/// Abstract Class for the win conditions

class BaseWinCondition {
public:
    /// Pure virtual method for the method checkWin()
    virtual void checkWin() = 0;
};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_BASEWINCONDITION_H
