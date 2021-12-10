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
    ///
    GameOverWindow(game::Player *winner);

    ///
    void Draw();
    ///
    void OnMenuItemSelect(int selected_option);

private:
    ///
    std::string winner_name_;
    ///
    graphics::Color winner_color_;

};


}   // namespace menu

#endif //BOMBERMAN_MENU_GAMEOVERWINDOW_H
