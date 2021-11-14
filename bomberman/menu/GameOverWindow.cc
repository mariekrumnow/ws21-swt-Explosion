//Author: Marie

#include "GameOverWindow.h"

namespace menu {

      menu::GameOverWindow(Player* winner) :
            MenuGameWindow(0, nullptr) {
            winner_name_ = "";
            winner_color_ = ; //TODO: SDL-Color?
      }


      void menu::Draw() {

      }

      void menu::OnMenuItemSelect(int selected_option) {

      }


      string& menu::GetWinner() {
            return *winner_name_;
      }

      Color& menu::GetWinnerColor() {
            return *winner_color_;
      }

} //namespace menu
