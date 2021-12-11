//
// Autor: Marlene, Marie, Patrick
//
#include <vector>

#include "MenuWindow.h"
#include "../core/AppManager.h"


namespace menu{
    void MenuWindow::Update(double delta_time){
          graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

          // Goes up or down in the selectable buttons
          /*
          if (graphics.IsKeyHeld(key_menu_up)) {
                selected_option_--;
          } else if (graphics.IsKeyHeld(key_menu_down)) {
                selected_option_++;
          }//*/
          //key_menu_up und key_menu_down müssen noch implementiert werden

          // Sends signal that the MenuItem wants to be activated
          if (graphics.IsKeyPressed(graphics::key_return)) {
                OnMenuItemSelect(selected_option_);
          }
    }


    void MenuWindow::OnMenuItemSelect(int selected_option){}

    int MenuWindow::GetSelectedOption(){
          return selected_option_;
    }

    std::vector<MenuItem>& MenuWindow::GetMenuItems(){
          return menu_items_;
    }

    void MenuWindow::AddMenuItem(MenuItem menu_item){
          menu_items_.push_back(menu_item);
    }

}   // namespace menu
