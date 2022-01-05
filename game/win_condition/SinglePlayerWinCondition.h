// Autor Tobias


#ifndef BOMBERMAN_SINGLEPLAYERWINCONDITION_H
#define BOMBERMAN_SINGLEPLAYERWINCONDITION_H

#include "BaseWinCondition.h"
#include "../SinglePlayerGameWindow.h"

#include <chrono>

namespace game {

namespace win_condition {

class SinglePlayerWinCondition : public BaseWinCondition {
public:
    SinglePlayerWinCondition(SinglePlayerGameWindow* window);
    void checkWin() override;

private:
    SinglePlayerGameWindow* window_;

    std::chrono::system_clock::time_point start_time_ ;
    int high_score_; //highscore in seconds
};

} // namespace win_condition
} // namespace game


#endif //BOMBERMAN_SINGLEPLAYERWINCONDITION_H
