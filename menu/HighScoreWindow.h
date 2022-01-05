//
// Autor: Tobias
//

#ifndef BOMBERMAN_MENU_HIGHSCOREWINDOW_H
#define BOMBERMAN_MENU_HIGHSCOREWINDOW_H

#include <string>

#include "MenuWindow.h"


namespace menu{

/// Shown after a game has ended, shows the outcome and an exit Item
class HighScoreWindow : public MenuWindow {
public:
    HighScoreWindow(bool win, std::string player_time,
        std::string high_score, bool is_high_score);

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

private:
    bool win_; //has the player won or lost?
    std::string player_time_;
    std::string high_score_;
    bool is_high_score_;
};

}   // namespace menu

#endif //BOMBERMAN_MENU_HIGHSCOREWINDOW_H
