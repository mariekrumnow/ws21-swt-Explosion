//Autor: Tobias

#include "SinglePlayerWinCondition.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "../../menu/HighScoreWindow.h"
#include "../GameManager.h"


namespace chr = std::chrono;

namespace game {
namespace win_condition {

const std::string kHighScoreFile = "highscore.txt";

SinglePlayerWinCondition::SinglePlayerWinCondition(SinglePlayerGameWindow* window)
 	: window_(window){
	start_time_ = chr::system_clock::now();
    high_score_ = -1;

    std::ifstream high_score_file;
    high_score_file.open(kHighScoreFile);
    if (high_score_file.good()) {
        high_score_file >> high_score_;
    }
    high_score_file.close();
}

void SinglePlayerWinCondition::CheckWin() {

    bool game_over = false;
    bool win = false;
    //check if the game is over, either by winning or loosing
	if (GameManager::GetCurrentGame().GetDestructibleBlockCount() <= 0) {
		game_over = true;
        win = true;
	} else if (GameManager::GetCurrentGame().GetPlayers().size() <= 0) {
        game_over = true;
        win = false;
	}

    //and set the window timers properly
    auto elapsed = chr::system_clock::now() - start_time_;
    int milliseconds = chr::duration_cast<chr::milliseconds>(elapsed).count();

    std::stringstream timer;
    timer << std::setfill('0');
    timer << std::setw(2) << milliseconds/60000 << std::setw(0) << ":";
    timer << std::setw(2) <<  (milliseconds%60000)/1000 << std::setw(0) << ".";
    timer << std::setw(3) <<  (milliseconds%1000);

    std::stringstream high_score;
    if (high_score_ != -1) {
        high_score << std::setfill('0');
        high_score << std::setw(2) << high_score_/60000 << std::setw(0) << ":";
        high_score << std::setw(2) <<  (high_score_%60000)/1000 << std::setw(0) << ".";
        high_score << std::setw(3) <<  (high_score_%1000);
    } else {
        high_score << "--:--.---";
    }

    window_->SetTimers(timer.str(), "Highscore: "+high_score.str());

    //if the game is over, switch to the high score screen
    if (game_over) {
        //if the player won, he can set a highscore
        if (win) {

            //has the player set a new highscore?
            if (high_score_ == -1 || (milliseconds) <= high_score_) {
                //save new highscore
                std::ofstream high_score_file;
                high_score_file.open(kHighScoreFile);
                high_score_file << milliseconds;
                high_score_file.close();

                menu::HighScoreWindow *over_w = new menu::HighScoreWindow
                    (true, timer.str(), timer.str(), true);
                core::AppManager::GetAppManager().SetActiveWindow(*over_w);
            } else {
                menu::HighScoreWindow *over_w = new menu::HighScoreWindow
                    (true, timer.str(), high_score.str(), false);
                core::AppManager::GetAppManager().SetActiveWindow(*over_w);
            }

        //if the player lost, he can't set a highscore
        } else {
            menu::HighScoreWindow *over_w = new menu::HighScoreWindow
                (false, timer.str(), high_score.str(), false);
            core::AppManager::GetAppManager().SetActiveWindow(*over_w);
        }
    }
}

} // namespace win_condition
} // namespace game
