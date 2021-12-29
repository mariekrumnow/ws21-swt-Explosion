//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_INSTRUCTIONWINDOW_H

#include "../graphics/Keys.h"
#include "MenuWindow.h"


namespace menu{

enum InstructionButton {kStart=0};

/// Shows instruction text and MenuItem to start the game
class InstructionWindow : public MenuWindow {
public:
    /// Initialises the instructions and the button to start the game
    InstructionWindow();

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    void OnMenuItemSelect(int selected_option);

private:
    int theme_;

};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
