//
// Autor: Marlene, Marie, Patrick
//
// Code hiermit in main testbar:
// menu::InstructionWindow instructions = menu::InstructionWindow();
// app.SetActiveWindow(instructions);

#include "InstructionWindow.h"
#include "../core/AppManager.h"

namespace menu{
    InstructionWindow::InstructionWindow()
    : MenuWindow(0,1)
    {
        MenuItem instructions = MenuItem(
             "Hier könnte ihre Anleitung stehen",
             -1,10,10);
        MenuWindow::AddMenuItem(instructions);
        //MenuItem erstellen für die Spielanleitung (eins oder mehr, siehe Benutzerhandbuch für Text)
        //AddMenuItem aufrufen (für alle)
        //MenuItem erstellen als Startbutton
        //AddMenuItem aufrufen
        //x und y Positionen müssen so gewählt werden, dass die Spielanleitung über dem Button ist
    }

    void InstructionWindow::OnMenuItemSelect(int selected_option){
        switch(selected_option){
            case 0:
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
