//
// Autor: Marlene, Marie, Patrick
//
#include "MenuItem.h"

namespace menu{
    MenuItem::MenuItem(std::string text, int x, int y, MenuWindow& window)
      : text_(text), x_(x), y_(y)
    {
          window.AddMenuItem(*this);
    }

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
