//Autor: Tobias

#include "SinglePlayerWinCondition.h"
#include "../GameManager.h"
#include "../../menu/HighScoreWindow.h"

namespace game {

namespace win_condition {

void SinglePlayerWinCondition::checkWin() {
	if (GameManager::GetCurrentGame().GetDestructibleBlockCount() <= 0) {
		menu::HighScoreWindow *over_w = new menu::HighScoreWindow(true);
        core::AppManager::GetAppManager().SetActiveWindow(*over_w);

	} else if (GameManager::GetCurrentGame().GetPlayers().size() <= 0) {
		menu::HighScoreWindow *over_w = new menu::HighScoreWindow(false);
        core::AppManager::GetAppManager().SetActiveWindow(*over_w);
	}
}

} // namespace win_condition
} // namespace game
