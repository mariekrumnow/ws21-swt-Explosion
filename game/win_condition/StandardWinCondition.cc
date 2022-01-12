// Autor: Dennis, Peter

#include "StandardWinCondition.h"


#include "../../menu/GameOverWindow.h"
#include "../GameManager.h"


namespace game {
namespace win_condition{

void StandardWinCondition::CheckWin() {

    if (GameManager::GetCurrentGame().GetPlayers().size() <= 1) {
        if (GameManager::GetCurrentGame().GetPlayers().size() == 1) {
            menu::GameOverWindow *over_w = new menu::GameOverWindow(
                GameManager::GetCurrentGame().GetPlayers().front());
            core::AppManager::GetAppManager().SetActiveWindow(*over_w);
        } else {
            menu::GameOverWindow *over_w = new menu::GameOverWindow(
                nullptr);
            core::AppManager::GetAppManager().SetActiveWindow(*over_w);
        }
    }
}

} // namespace win_condition
} // namespace game
