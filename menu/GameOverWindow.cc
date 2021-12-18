//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"
#include "../core/AppManager.h"

namespace menu{
    GameOverWindow::GameOverWindow(game::Player *winner)
    : MenuWindow(Exit2) , winner_(winner)
    {
        MenuItem exit = MenuItem("Spiel schließen",Exit2,10,10);
        MenuWindow::AddMenuItem(exit);
    }

    void GameOverWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

        if (winner_ != nullptr){
            graphics.DrawTile(winner_->GetTile(), winner_->GetColor(),30, 50);
            graphics.WriteText("Du gewinnst!!!", graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 80, 50);
        }else{
            graphics.WriteText("-Unentschieden-", graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 80, 50);
        }

    }

    void GameOverWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case Exit2:
                //Exitbutton ist ausgewählt
                //Das Programm wird geschlossen (hier?)
                break;
            default:
                //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
                break;
        }
    }

}
