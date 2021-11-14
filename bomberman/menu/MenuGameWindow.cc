//Author: Marie

#include "GameWindow.h"
#include "MenuItem.h"

#include "MenuGameWindow.h"

namespace menu {

      void menu::Update(double delta_time) {

      }

      void menu::Draw() {

      }

      void menu::OnMenuItemSelect(int selected_option) {

      }


      int& menu::GetSelectedOption() {
            return *selected_option_;
      }

      std::vector<MenuItem>& menu::GetMenuItems() {
            return *menu_items_;
      }


      void menu::AddMenuItem(MenuItem menu_item) {

      }
};

} //namespace menu
