//
// Autor: Marlene, Marie, Patrick
//

#include "MenuWindow.h"

#include <list>

#include "../core/AppManager.h"
#include "../sound/SoundEffect.h"


namespace menu{

MenuWindow::MenuWindow(int selected_option)
: selected_option_(selected_option) {}


void MenuWindow::Update(double delta_time){
      graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

      // Goes up or down in the selectable MenuItems
      if (graphics.IsKeyPressed(graphics::key_menu_up[0]) || graphics.IsKeyPressed(graphics::key_menu_up[1])) {
          core::AppManager::GetAppManager().GetSound().PlaySoundEffectAlone(sound::effect_menu_click, 0);

            selected_option_ = (selected_option_==0) ? menu_items_.size()-1 : selected_option_-1;
      } else if (graphics.IsKeyPressed(graphics::key_menu_down[0])
                    || graphics.IsKeyPressed(graphics::key_menu_down[1])) {
            core::AppManager::GetAppManager().GetSound().PlaySoundEffectAlone(sound::effect_menu_click, 0);
            selected_option_ = (selected_option_+1) %menu_items_.size();
      }

      // Sends signal that the MenuItem wants to be activated
      if (graphics.IsKeyPressed(graphics::key_return)) {
          core::AppManager::GetAppManager().GetSound().PlaySoundEffectAlone(sound::effect_menu_click, 0);
            OnMenuItemSelect(selected_option_);
      }
}

void MenuWindow::Draw(){
    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    for (auto it = menu_items_.begin(); it!=menu_items_.end(); it++) {
            graphics::Color button_color = graphics::Color(255, 255, 255, 255);

            if (it->GetOptionNum() == selected_option_){
                  // Currently chosen button is highlighted by different color and a sign
                  button_color = graphics::Color(255, 140, 0, 255);
                  graphics.WriteText(">", button_color, graphics::FontSize::kLarge, true, it->GetX()-35, it->GetY());
            }

            graphics.WriteText(it->GetText(), button_color, graphics::FontSize::kLarge, true, it->GetX(), it->GetY());
	  }
}

void MenuWindow::AddMenuItem(MenuItem menu_item){
      menu_items_.push_back(menu_item);
}

void MenuWindow::OnMenuItemSelect(int selected_option){}

int MenuWindow::GetSelectedOption(){
    return selected_option_;
}

std::list<MenuItem>& MenuWindow::GetMenuItems(){
    return menu_items_;
}

}   // namespace menu
