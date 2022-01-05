// Autor: Dennis, Peter

#include "StandardWinCondition.h"

#include "../GameManager.h"
#include "../../menu/GameOverWindow.h"

namespace game {
namespace win_condition{

void StandardWinCondition::checkWin() {

    if (GameManager::GetCurrentGame().GetPlayers().size() <= 1) {
        menu::GameOverWindow *over_w = new menu::GameOverWindow(
            GameManager::GetCurrentGame().GetPlayers().front());
        core::AppManager::GetAppManager().SetActiveWindow(*over_w);
    }
}

} // namespace win_condition
} // namespace game
