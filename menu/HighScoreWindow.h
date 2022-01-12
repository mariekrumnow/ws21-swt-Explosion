// Autor: Tobias

#ifndef BOMBERMAN_MENU_HIGHSCOREWINDOW_H
#define BOMBERMAN_MENU_HIGHSCOREWINDOW_H

#include <string>

#include "MenuWindow.h"


namespace menu{

/// Shown after a game has ended, shows the outcome and options to restart or exit

class HighScoreWindow : public MenuWindow {
public:

    /// Initialises the high score and the buttons for the different options
    ///
    /// \param win has the player won or lost
    /// \param player_time The time the Player took this round
    /// \param high_score The current high score
    /// \param is_high_score has the player set a new high score?
    HighScoreWindow(bool win, std::string player_time,
        std::string high_score, bool is_high_score);

    /// Shows all MenuItems on screen and draws text
    void Draw();

    /// Activates the effect of the selected MenuItem
    ///
    /// \param selected_option The number of the selected option in the menu
    void OnMenuItemSelect(int selected_option);

private:
    bool win_; ///< has the player won or lost?
    std::string player_time_; ///< The time the Player took this round
    std::string high_score_; ///< The current high score
    bool is_high_score_; ///< has the player set a new high score?
};

}   // namespace menu

#endif //BOMBERMAN_MENU_HIGHSCOREWINDOW_H
