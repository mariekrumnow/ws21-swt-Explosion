//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_INSTRUCTIONWINDOW_H

#include "MenuWindow.h"
#include "../graphics/Keys.h"

namespace menu{

class InstructionWindow : public MenuWindow {
public:
    /// Initialises the instructions and the button to start the game
    InstructionWindow();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
