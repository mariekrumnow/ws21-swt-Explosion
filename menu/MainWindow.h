//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MAINWINDOW_H
#define BOMBERMAN_MENU_MAINWINDOW_H

#include "MenuWindow.h"


namespace menu{

/// Shows the credits and buttons to start and close the game or change the theme

class MainWindow: public MenuWindow{
public:
    /// Initialises the buttons for starting and closing the game and for changing the theme
    MainWindow();

    /// Shows all MenuItems on screen and draws text
    void Draw();

    /// Activates the effect of the respective MenuItem
    ///
    /// \param selected_option The number of the selected option in the menu
    void OnMenuItemSelect(int selected_option);

private:
    int theme_;

};

}   // namespace menu


#endif //BOMBERMAN_MENU_MAINWINDOW_H
