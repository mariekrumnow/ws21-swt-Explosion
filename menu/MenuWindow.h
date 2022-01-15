//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MENUWINDOW_H
#define BOMBERMAN_MENU_MENUWINDOW_H

#include <list>

#include "../core/Window.h"
#include "../graphics/Keys.h"
#include "MenuItem.h"


namespace menu{

/// A window for the menu, where the user can pick from a few options
class MenuWindow : public core::Window {
public:
    /// Simple constructor
    ///
    /// \param selected_option The MenuItem index that's selected at the start
    MenuWindow(int selected_option);

    /// Called once per frame
    /// Changes the selected MenuItem or sends a signal if keys are pressed
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);

    /// Shows all MenuItems on screen
    void Draw();

    /// Adds a MenuItem to the current MenuWindow
    ///
    /// \param menu_item The MenuItem to add
    void AddMenuItem(MenuItem menu_item);

    /// Called when a MenuItem is selected
    ///
    /// \param selected_option The MenuItem the user is currently hovering over
    virtual void OnMenuItemSelect(int selected_option);

    ///
    /// \return  selected_option_
    int GetSelectedOption();

    ///
    /// \return all MenuItems
    std::list<MenuItem>& GetMenuItems();

private:
    int selected_option_; ///< The MenuItem the user is currently hovering over, can be 0 to menu_items_.size()
    std::list<MenuItem> menu_items_; ///< All Buttons and texts on screen

};

}   // namespace menu

#endif //BOMBERMAN_MENU_MENUWINDOW_H
