//
// Autor: Marlene, Marie, Patrick
//

#include <list>

#include "MenuWindow.h"
#include "../core/AppManager.h"


namespace menu{

    MenuWindow::MenuWindow(int selected_option)
    : selected_option_(selected_option) {}


    void MenuWindow::Update(double delta_time){
          graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

          // Goes up or down in the selectable MenuItems
          if (graphics.IsKeyPressed(graphics::key_menu_up[0]) || graphics.IsKeyPressed(graphics::key_menu_up[1])) {
                selected_option_ = (selected_option_==0) ? menu_items_.size()-1 : selected_option_-1;
          } else if (graphics.IsKeyPressed(graphics::key_menu_down[0]) || graphics.IsKeyPressed(graphics::key_menu_down[1])) {
                selected_option_ = (selected_option_+1) %menu_items_.size();
          }

          // Sends signal that the MenuItem wants to be activated
          if (graphics.IsKeyPressed(graphics::key_return)) {
                OnMenuItemSelect(selected_option_);
          }
    }

    void MenuWindow::Draw(){
        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        for (auto it = menu_items_.begin(); it!=menu_items_.end(); it++) {
                // Currently chosen button is highlighted by different colour
                graphics::Color buttonColor = (it->GetOptionNum() == selected_option_) ? graphics::Color(255, 140, 0, 255) : graphics::Color(255, 255, 255, 255);
                graphics.WriteText(it->GetText(), buttonColor, graphics::FontSize::kLarge, true, it->GetX(), it->GetY());
   	  }
    }


    void MenuWindow::OnMenuItemSelect(int selected_option){}

    int MenuWindow::GetSelectedOption(){
          return selected_option_;
    }

    std::list<MenuItem>& MenuWindow::GetMenuItems(){
          return menu_items_;
    }

    void MenuWindow::AddMenuItem(MenuItem menu_item){
          menu_items_.push_back(menu_item);
    }

}   // namespace menu
