// Autor Dennis, Peter

#ifndef BOMBERMAN_BASEWINCONDITION_H
#define BOMBERMAN_BASEWINCONDITION_H

#include <vector>

namespace game {
namespace win_condition {

class BaseWinCondition {
public:
    virtual void checkWin() = 0;
};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_BASEWINCONDITION_H
