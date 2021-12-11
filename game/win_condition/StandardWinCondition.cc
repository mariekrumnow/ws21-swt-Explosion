// Autor Dennis, Peter


#include "StandardWinCondition.h"
#include <iostream>
#include "../GameManager.h"

namespace game {
namespace win_condition{

bool StandardWinCondition::checkWin() {

    if (GameManager::GetCurrentGame().GetPlayerCount() <= 1) {
        return true;
    }
    else {
        return false;
    }

}



} // namespace win_condition
} // namespace game