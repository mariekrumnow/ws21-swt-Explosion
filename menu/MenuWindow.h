//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MENUWINDOW_H
#define BOMBERMAN_MENU_MENUWINDOW_H

#include <list>

#include "MenuItem.h"
#include "../core/Window.h"
#include "../graphics/Keys.h"


namespace menu{

class MenuWindow : public core::Window {
public:
    /// Simple constructor
    MenuWindow(int selected_option, int num_options);

    /// Changes the selected MenuItem or sends a signal if keys are pressed
    void Update(double delta_time);
    /// Shows the all MenuItems on screen
    void Draw();

    /// Adds a MenuItem to the current MenuWindow and shows it
    void AddMenuItem(MenuItem menu_item);

    virtual void OnMenuItemSelect(int selected_option);

    int GetSelectedOption();
    std::list<MenuItem>& GetMenuItems();


private:
    /// The MenuItem the user is currently hovering over, can be 0 to num_options_-1
    int selected_option_;
    /// Needs to be known so the user will loop back to the first option
    int num_options_;
    /// All Buttons and texts on screen
    std::list<MenuItem> menu_items_;
};

}   // namespace menu

#endif //BOMBERMAN_MENU_MENUWINDOW_H
