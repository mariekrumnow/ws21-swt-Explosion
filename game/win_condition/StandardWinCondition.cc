// Autor Dennis, Peter

#include "StandardWinCondition.h"

#include <iostream>

#include "../GameManager.h"

namespace game {
namespace win_condition{

bool StandardWinCondition::checkWin() {

    std::cout << GameManager::GetCurrentGame().GetPlayerCount() << std::endl;

    if (GameManager::GetCurrentGame().GetPlayerCount() <= 1) {
        return true;
    }
    else {
        return false;
    }

}

} // namespace win_condition
} // namespace game