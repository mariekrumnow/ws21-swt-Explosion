// Autor Dennis, Peter


#ifndef BOMBERMAN_STANDARDWINCONDITION_H
#define BOMBERMAN_STANDARDWINCONDITION_H

#include "BaseWinCondition.h"


namespace game {

namespace win_condition {

class StandardWinCondition : public BaseWinCondition {
public:
    bool checkWin() override;

};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_STANDARDWINCONDITION_H
