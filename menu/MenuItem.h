//
// Autor: Marlene, Marie, Patrick
//

#ifndef BOMBERMAN_MENU_MENUITEM_H
#define BOMBERMAN_MENU_MENUITEM_H

#include <string>


namespace menu{

/// Clickable Text on Menus
class MenuItem {
public:
    /// Creates an Item
    MenuItem(std::string text, int option_num, int x, int y);
    void SetText(std::string text);

    std::string GetText();
    int GetOptionNum();
    int GetX();
    int GetY();

private:
    /// What's written on the Item
    std::string text_;
    /// The position in the item list the item has, 0 = top
    int option_num_;
    /// Position of the Item
    int x_;
    int y_;

};

}   // namespace menu

#endif //BOMBERMAN_MENU_MENUITEM_H
