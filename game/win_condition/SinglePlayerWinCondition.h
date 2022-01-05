// Autor Tobias


#ifndef BOMBERMAN_SINGLEPLAYERWINCONDITION_H
#define BOMBERMAN_SINGLEPLAYERWINCONDITION_H

#include "BaseWinCondition.h"


namespace game {

namespace win_condition {

class SinglePlayerWinCondition : public BaseWinCondition {
public:
    void checkWin() override;

};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_SINGLEPLAYERWINCONDITION_H
