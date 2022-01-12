//
// Autor: Tobias
//

#ifndef BOMBERMAN_MENU_SINGLEPLAYERINSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_SINGLEPLAYERINSTRUCTIONWINDOW_H

#include "../graphics/Keys.h"
#include "MenuWindow.h"


namespace menu{

/// Shows instruction text and MenuItem to start the game
class SinglePlayerInstructionWindow : public MenuWindow {
public:
    /// Initialises the instructions and the button to start the game
    SinglePlayerInstructionWindow();

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

private:
    int theme_;

};

}   // namespace menu


#endif //BOMBERMAN_MENU_SINGLEPLAYERINSTRUCTIONWINDOW_H
