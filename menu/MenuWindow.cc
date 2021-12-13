//
// Autor: Marlene, Marie, Patrick
//
#include <list>

#include "MenuWindow.h"
#include "../core/AppManager.h"


namespace menu{
    MenuWindow::MenuWindow(int selected_option, int num_options)
    : selected_option_(selected_option), num_options_(num_options)
    {}


    void MenuWindow::Update(double delta_time){
          graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

          // Goes up or down in the selectable MenuItems, num_options_-1 is the lowest button on screen
          // if (graphics.IsKeyHeld(graphics::key_menu_up)) {
                selected_option_ = (selected_option_==0) ? num_options_-1 : selected_option_-1;
          // } else if (graphics.IsKeyHeld(graphics::key_menu_down)) {
                selected_option_ = (selected_option_+1) %num_options_;
          // }

          // TODO: Damit obiger Code funktioniert Folgendes noch in keys.h/.cc einfügen:
          // extern SDL_Scancode key_menu_up;
          // extern SDL_Scancode key_menu_down;
          // SDL_Scancode key_menu_up = SDL_SCANCODE_W;
          // SDL_Scancode key_menu_down = SDL_SCANCODE_A;

          // Sends signal that the MenuItem wants to be activated
          if (graphics.IsKeyPressed(graphics::key_return)) {
                OnMenuItemSelect(selected_option_);
          }
    }

    void MenuWindow::Draw(){
        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        for (auto it = menu_items_.begin(); it!=menu_items_.end(); it++) {
            // FontSize kann noch auf kMedium/kSmall gesetzt werden, Bold=true
   		if (it->GetOptionNum() == selected_option_) {
                  // Currently chosen button is highlighted by different colour
                  graphics.WriteText(it->GetText(), graphics::Color(0, 255, 255, 255), graphics::FontSize::kMedium, false, it->GetX(), it->GetY());
   		} else {
                  graphics.WriteText(it->GetText(), graphics::Color(255, 255, 255, 255), graphics::FontSize::kMedium, false, it->GetX(), it->GetY());
            }
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
