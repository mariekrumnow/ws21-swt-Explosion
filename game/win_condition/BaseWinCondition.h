// Autor Dennis, Peter

#ifndef BOMBERMAN_BASEWINCONDITION_H
#define BOMBERMAN_BASEWINCONDITION_H

namespace game {
namespace win_condition {

class BaseWinCondition {
public:
    virtual bool checkWin() = 0;

};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_BASEWINCONDITION_H
