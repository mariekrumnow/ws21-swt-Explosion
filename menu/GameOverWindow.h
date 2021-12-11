//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_GAMEOVERWINDOW_H
#define BOMBERMAN_MENU_GAMEOVERWINDOW_H

#include <string>

#include "MenuWindow.h"
#include "../graphics/Color.h"
#include "../game/Player.h"

namespace menu{

class GameOverWindow : public MenuWindow {
public:
    /// Initialises the game outcome text based on the winning player
    GameOverWindow(game::Player *winner);

    /// Shows the current GameOverWindow on screen
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

private:
    std::string winner_name_;

};


}   // namespace menu

#endif //BOMBERMAN_MENU_GAMEOVERWINDOW_H
