//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
#define BOMBERMAN_MENU_INSTRUCTIONWINDOW_H

#include "../graphics/Keys.h"
#include "MenuWindow.h"

namespace menu{

/// Shows instruction text and MenuItem to start the game

class InstructionWindow : public MenuWindow {
public:
    /// Initialises the instructions and the button to start the game
    InstructionWindow();

    /// Shows all MenuItems on screen and draws instruction text
    void Draw();

    /// Activates the effect of the respective MenuItem
    ///
    /// \param selected_option The number of the selected option in the menu
    void OnMenuItemSelect(int selected_option);

private:
    int theme_; ///< The theme that is chosen

};

}   // namespace menu


#endif //BOMBERMAN_MENU_INSTRUCTIONWINDOW_H
