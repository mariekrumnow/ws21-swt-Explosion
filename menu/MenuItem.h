//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_MENUITEM_H
#define BOMBERMAN_MENU_MENUITEM_H

#include <string>

namespace menu{

class MenuItem {
public:
    /// Creates an Item and puts it in the window
    MenuItem(std::string text, int x, int y);

    std::string GetText();
    int GetXPosition();
    int GetYPosition();

private:
    /// What's written on the Item
    std::string text_;
    /// Position of the Item
    int x_;
    int y_;

};


}   // namespace menu

#endif //BOMBERMAN_MENU_MENUITEM_H
