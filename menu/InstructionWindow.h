//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_INSTRUCTIONWINDOW_H

#include "MenuWindow.h"

namespace menu{

class InstructionWindow : public MenuWindow {
public:
    ///
    InstructionWindow();

    /// Shows the current MenuWindow on screen
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
