//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_INSTRUCTIONWINDOW_H

#include "MenuWindow.h"
#include "../graphics/Keys.h"

namespace menu{

/// Shows instruction text and MenuItem to start the game
class InstructionWindow : public MenuWindow {
public:
    /// Initialises the instructions and the button to start the game
    InstructionWindow();

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
