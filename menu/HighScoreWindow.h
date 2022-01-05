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
    HighScoreWindow(bool win);

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

private:
    bool win_; //has the player won or lost?
};

}   // namespace menu

#endif //BOMBERMAN_MENU_HIGHSCOREWINDOW_H
