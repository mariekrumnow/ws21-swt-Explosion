//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_MENUITEM_H
#define BOMBERMAN_MENU_MENUITEM_H

#include <string>

namespace menu{

/// Clickable and non-clickable Text on Menus
class MenuItem {
public:
    /// Creates an Item and puts it in the window
    MenuItem(std::string text, int option_num, int x, int y);

    std::string GetText();
    int GetOptionNum();
    int GetX();
    int GetY();

private:
    /// What's written on the Item
    std::string text_;
    /// Button-number, -1 if Item is not a button, 0 if top button
    int option_num_;
    /// Position of the Item
    int x_;
    int y_;

};


}   // namespace menu

#endif //BOMBERMAN_MENU_MENUITEM_H
