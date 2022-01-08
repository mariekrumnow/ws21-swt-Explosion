// Autor: Tobias

#ifndef BOMBERMAN_MENU_HIGHSCOREWINDOW_H
#define BOMBERMAN_MENU_HIGHSCOREWINDOW_H

#include <string>

#include "MenuWindow.h"


namespace menu{

/// Shown after a game has ended, shows the outcome and an exit Item

class HighScoreWindow : public MenuWindow {
public:

    /// Initialises the high score and the buttons for the next options
    ///
    /// \param win has the player won or lost
    /// \param player_time The time the Player needed this round
    /// \param high_score The current high score
    /// \param is_high_score new high score?
    HighScoreWindow(bool win, std::string player_time,
        std::string high_score, bool is_high_score);

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    ///
    /// \param selected_option The number of the selected option in the menu
    void OnMenuItemSelect(int selected_option);

private:
    bool win_; ///< has the player won or lost?
    std::string player_time_; ///< The time the Player needed this round
    std::string high_score_; ///< The current highs core
    bool is_high_score_; ///< new high score?
};

}   // namespace menu

#endif //BOMBERMAN_MENU_HIGHSCOREWINDOW_H
