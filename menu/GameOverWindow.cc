//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"

#include "../core/AppManager.h"


namespace menu{

GameOverWindow::GameOverWindow(game::Player *winner)
: MenuWindow(kExit2) , winner_(winner)
{
    MenuItem exit = MenuItem("Spiel schließen", kExit2, 100, 300);
    MenuWindow::AddMenuItem(exit);
}

void GameOverWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string tmp;
    if (winner_ != nullptr) {
        graphics.DrawTile(winner_->GetTile(), winner_->GetColor(), 30, 100);
        tmp = "Du gewinnst!!!";
    } else {
        tmp = "-Unentschieden-";
    }
    graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 100, 100);

}

void GameOverWindow::OnMenuItemSelect(int selected_option){
    switch (selected_option) {
        case kExit2:
            //Exitbutton ist ausgewählt
            //Das Programm wird geschlossen (hier?)
            core::AppManager::GetAppManager().GetGraphics().Quit();
            //^Nur testweise, später quit-Funktion von Peter/Dennis nutzen
            break;
        default:
            //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
            break;
    }
}

}   // namespace menu
