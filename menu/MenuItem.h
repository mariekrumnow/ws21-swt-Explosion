//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_MENUITEM_H
#define BOMBERMAN_MENU_MENUITEM_H

#include <string>

namespace menu{
// Has to be pre-declared for the constructor
class MenuWindow;

class MenuItem {
public:
    /// Creates an Item and puts it in the window
    MenuItem(std::string text, int x, int y, MenuWindow& window);

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
