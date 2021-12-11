//
// Autor: Marlene, Marie, Patrick
//
#include "InstructionWindow.h"
#include "../core/AppManager.h"

namespace menu{
    InstructionWindow::InstructionWindow() //: selected_option_(1)
    {
        //menu_items_ muss leer initialisiert werden
        //MenuItem instructions = new MenuItem()
        //MenuItem erstellen für die Spielanleitung (eins oder mehr, siehe Benutzerhandbuch für Text)
        //AddMenuItem aufrufen (für alle)
        //MenuItem erstellen als Startbutton
        //AddMenuItem aufrufen
        //x und y Positionen müssen so gewählt werden, dass die Spielanleitung über dem Button ist
    }

    void InstructionWindow::Draw(){
        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
        //Anzeige der MenuItems per Textrendering an der jeweiligen Position
        //Die Farbe ist einheitlich außer bei dem zur Zeit ausgewählten MenuItem
    }

    void InstructionWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case 1:
                //Startbutton ist ausgewählt
                //Das Spiel wird gestartet
                //Das InstructionWindow wird geschlossen (hier?)
                break;
            default:
                //Fehler, es sollte eigentlich immer ein gültiger Button ausgewählt sein
                break;
        }
    }

}   // namespace menu
