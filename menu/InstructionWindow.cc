//
// Autor: Marlene, Marie, Patrick
//

#include "InstructionWindow.h"
#include "../core/AppManager.h"

namespace menu{
    InstructionWindow::InstructionWindow()
    : MenuWindow(0)
    {
        //x und y Positionen müssen so gewählt werden, dass die Spielanleitung über dem Button ist
        MenuItem start = MenuItem("Spiel starten",0,50,100);
        MenuWindow::AddMenuItem(start);

        MenuItem test = MenuItem("Button Test",1,50,150);
        MenuWindow::AddMenuItem(test);
    }

    void InstructionWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
        // Spielanleitung
        graphics.WriteText("Bei Bomberman muesst ihr eure Mitspieler mittels Bomben ausschalten und als letzter ueberleben.",
                        graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 20);
        graphics.WriteText("Um zu euren Mitspielern zu gelangen muesst ihr dafuer erst die perforierten Bloecke durch Explosionen zerstoeren.",
                        graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 40);
        graphics.WriteText("Unter diesen Bloecken koennen sich manchmal auch Upgrades befinden, die ihr einsammeln koennt.",
                        graphics::Color(0, 0, 255, 255), graphics::FontSize::kSmall, false, 10, 60);
    }

    void InstructionWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case 0:
                //Startbutton ist ausgewählt
                //Das Spiel wird gestartet
                //Das InstructionWindow wird geschlossen (hier?)
                core::AppManager::GetAppManager().GetGraphics().Quit(); //Nur testweise, gehört eig in GameOver, später quit-Funktion von Peter/Dennis nutzen
                break;
            default:
                //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
                break;
        }
    }

}   // namespace menu
