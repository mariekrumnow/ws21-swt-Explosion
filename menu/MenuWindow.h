//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MENUWINDOW_H
#define BOMBERMAN_MENU_MENUWINDOW_H

#include <vector>

#include "MenuItem.h"
#include "../core/Window.h"
#include "../graphics/Keys.h"


namespace menu{

class MenuWindow : public core::Window {
public:
    /// Changes the selected MenuItem or sends a signal if keys are pressed
    void Update(double delta_time);

    virtual void OnMenuItemSelect(int selected_option);

    int GetSelectedOption();
    std::vector<MenuItem>& GetMenuItems();


private:
    /// The MenuItem the user is currently hovering over
    int selected_option_;
    /// All MenuItems on screen in order from top to bottom (or left to right)
    std::vector<MenuItem> menu_items_;

    /// Adds a MenuItem to the current MenuWindow and shows it
    void AddMenuItem(MenuItem menu_item);
};

}   // namespace menu

#endif //BOMBERMAN_MENU_MENUWINDOW_H
