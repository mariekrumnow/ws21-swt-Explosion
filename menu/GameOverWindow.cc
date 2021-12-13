//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"
#include "../core/AppManager.h"

namespace menu{
    GameOverWindow::GameOverWindow(game::Player *winner)
    : MenuWindow(0,1)
    {
        if (winner != nullptr) {
            //Je nach Sieger wird die entsprechende Nummer als winner_name_ gewählt
            //MenuItem erstellen mit Text für Sieg des jeweiligen Spielers
            //AddMenuItem aufrufen
        }else{
            //Unentschieden
            //MenuItem erstellen mit Text für Unentschieden
            //AddMenuItem aufrufen
        }
        //MenuItem erstellen als Exitbutton
        //AddMenuItem aufrufen
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
