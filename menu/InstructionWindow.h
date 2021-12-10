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
    ~InstructionWindow();

    ///
    void Draw();

    ///
    void OnMenuItemSelect(int selected_option);



};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
