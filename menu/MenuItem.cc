//
// Autor: Marlene, Marie, Patrick
//
#include "MenuItem.h"

namespace menu{
    MenuItem::MenuItem(std::string text, int x, int y)
      : text_(text), x_(x), y_(y) {}

    std::string MenuItem::GetText(){
          return text_;
    }

    int MenuItem::GetXPosition(){
          return x_;
    }

    int MenuItem::GetYPosition(){
          return y_;
    }
}
