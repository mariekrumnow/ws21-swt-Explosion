//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MENUWINDOW_H
#define BOMBERMAN_MENU_MENUWINDOW_H

#include <vector>

#include "../core/Window.h"
#include "MenuItem.h"


namespace menu{

class MenuWindow : public Window {
public:
    ///
    MenuWindow();
    ///
    ~MenuWindow();

    ///
    void Update(double delta_time);
    ///
    void Draw();

    ///
    void OnMenuItemSelect(int selected_option);
    ///
    int GetSelectedOption();
    ///
    std::vector<MenuItem>& GetMenuItems();


private:
    ///
    int selected_option_;
    ///
    std::vector<MenuItem> menu_items_;

    ///
    void AddMenuItem(MenuItem menu_item);
};

}   // namespace menu

#endif //BOMBERMAN_MENU_MENUWINDOW_H
