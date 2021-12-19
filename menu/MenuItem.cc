//
// Autor: Marlene, Marie, Patrick
//

#include <string>

#include "MenuItem.h"


namespace menu{

    MenuItem::MenuItem(std::string text, int option_num, int x, int y)
      : text_(text), option_num_(option_num), x_(x), y_(y) {}

    void MenuItem::SetText(std::string text){
        text_= text;
    }


    std::string MenuItem::GetText(){
          return text_;
    }

    int MenuItem::GetOptionNum(){
          return option_num_;
    }

    int MenuItem::GetX(){
          return x_;
    }

    int MenuItem::GetY(){
          return y_;
    }

}   // namespace menu
