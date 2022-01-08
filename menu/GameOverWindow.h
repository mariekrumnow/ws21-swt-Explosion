//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_GAMEOVERWINDOW_H
#define BOMBERMAN_MENU_GAMEOVERWINDOW_H

#include <string>

#include "../game/Player.h"
#include "../graphics/Color.h"
#include "MenuWindow.h"

namespace menu{

/// Shown after a game has ended, shows the outcome and an exit Item

class GameOverWindow : public MenuWindow {
public:
    /// Initialises the game outcome text based on the winning player
    ///
    /// \param winner The winner of the round
    GameOverWindow(game::Player *winner);

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    ///
    /// \param selected_option The number of the selected option in the menu
    void OnMenuItemSelect(int selected_option);

private:
    game::Player *winner_; ///< The Player that won

};

}   // namespace menu

#endif //BOMBERMAN_MENU_GAMEOVERWINDOW_H
