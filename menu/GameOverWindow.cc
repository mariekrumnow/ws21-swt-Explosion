//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"

#include "../core/AppManager.h"


namespace menu{

GameOverWindow::GameOverWindow(game::Player *winner)
: MenuWindow(kExit2) , winner_(winner)
{
    core::AppManager::GetAppManager().ChangeBackgroundColor(graphics::Color(50,130,255,0));

    MenuItem exit = MenuItem("Spiel schließen", kExit2, 350, 450);
    MenuWindow::AddMenuItem(exit);
}

void GameOverWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string tmp;
    if (winner_ != nullptr) {
        graphics.DrawTile(winner_->GetTile(), winner_->GetColor(), 320, 250);
        tmp = "Du gewinnst!!!";
    } else {
        tmp = "-Unentschieden-";
    }
    graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 390, 265);

}

void GameOverWindow::OnMenuItemSelect(int selected_option){
    switch (selected_option) {
        case kExit2:
            //Muss Fenster gelöscht werden? Wenn ja, wie?
            core::AppManager::GetAppManager().Quit();
            break;
        default:
            //Error, a button should always be selected
            break;
    }
}

}   // namespace menu
