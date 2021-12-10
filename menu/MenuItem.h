//
// Autor: Marlene, Marie, Patrick
//


#ifndef BOMBERMAN_MENU_MENUITEM_H
#define BOMBERMAN_MENU_MENUITEM_H

#include <string>

namespace menu{

class MenuItem {
public:
    ///
    MenuItem();
    ~MenuItem();
    ///
    std::string GetText();

    ///
    int GetXPosition();

    ///
    int GetYPosition();

private:
    ///
    std::string text_;
    ///
    int x_;
    ///
    int y_;

};


}   // namespace menu

#endif //BOMBERMAN_MENU_MENUITEM_H
