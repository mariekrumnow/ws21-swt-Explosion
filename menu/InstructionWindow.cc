//
// Autor: Marlene, Marie, Patrick
//

#include "InstructionWindow.h"
#include "../core/AppManager.h"
#include "../game/GameManager.h"

namespace menu{
    InstructionWindow::InstructionWindow(int theme)
    : MenuWindow(Start), theme_(theme)
    {
        MenuItem start = MenuItem("Los geht's!",Start,350,400);
        MenuWindow::AddMenuItem(start);

    }

    void InstructionWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
        // Spielanleitung
        std::string instructionText[] = {"So geht's:",
                                         "Bei Bomberman muesst ihr eure Mitspieler mittels Bomben ausschalten und als letzter ueberleben.",
                                         "Um zu euren Mitspielern zu gelangen muesst ihr dafuer erst die perforierten Bloecke durch Explosionen zerstoeren.",
                                         "Unter diesen Bloecken koennen sich manchmal auch Upgrades befinden, die ihr einsammeln koennt."};
        int counter = 1;
        for(std::string tmp: instructionText){
            graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 10, counter++ * 25);
        }

        std::string playerText[3][2] = {{"Bewegen", "Bombe legen"},
                                        {"WASD", "Linkes Shift"},
                                        {"IJKL", "Rechtes Shift"}};
        for(int i = 0; i < 2; i++){
            //Tiles der Spieler malen
            for(int j = 0; j < 3; j++) {
                graphics.WriteText(playerText[j][i], graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false,
                                   100 + i * 110, 145 + j * 40);
            }
        }

        std::string upgradeText[] = {"Upgrade",
                                     "Hoehere Bombenzahl",
                                     "Groessere Explosionen",
                                     "Hoehere Schnelligkeit"};
        counter = 0;
        for(std::string tmp: upgradeText){
            //Tiles der Upgrades malen
            graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 100, 305 + counter++ * 40);
        }
    }

    void InstructionWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case Start:
                //Startbutton ist ausgewählt
                //Das Spiel wird gestartet mit entsprechendem Theme
                //Das InstructionWindow wird geschlossen (hier?)
                //CreateGameManager(15, 13, 70, 2, player_keys, winCondition);
                break;
            default:
                //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
                break;
        }
    }

}   // namespace menu
