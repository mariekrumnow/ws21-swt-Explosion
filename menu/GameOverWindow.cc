//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"
#include "../core/AppManager.h"

namespace menu{
    GameOverWindow::GameOverWindow(game::Player *winner)
    : MenuWindow(0)
    {
        if (winner != nullptr) {
             outcome_text_ = "Spieler xy gewinnt!";
        }else{
             outcome_text_ = "Unentschieden";
        }

        MenuItem exit = MenuItem("Spiel schließen",0,10,10);
        MenuWindow::AddMenuItem(exit);
    }

    void GameOverWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
        graphics.WriteText(outcome_text_, graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 10, 40);
    }

    void GameOverWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case 0:
                //Exitbutton ist ausgewählt
                //Das Programm wird geschlossen (hier?)
                break;
            default:
                //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
                break;
        }
    }

}
