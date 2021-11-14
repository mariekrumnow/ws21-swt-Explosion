//Author: Marie

#include "MenuItem.h"

namespace menu {

      string& menu::GetText() {
            return *text_;
      }

      int& menu::GetXposition() {
            return *x_;
      }

      int& menu::GetYposition() {
            return *y_;
      }

} //namespace menu
