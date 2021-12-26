//
// Autor: Marlene, Marie, Patrick
//

#include "InstructionWindow.h"

#include "../core/AppManager.h"
#include "../game/GameManager.h"


namespace menu{

InstructionWindow::InstructionWindow(int theme)
: MenuWindow(kStart), theme_(theme)
{
    MenuItem start = MenuItem("Los geht's!", kStart, 350, 400);
    MenuWindow::AddMenuItem(start);
}

void InstructionWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
    // Instructions on how to play the game
    std::string instruction_text[] = {"So geht's:",
                                     "Bei Bomberman müsst ihr eure Mitspieler mittels Bomben ausschalten und als "
                                     "letzter überleben.",
                                     "Um zu euren Mitspielern zu gelangen müsst ihr dafür erst die bröckeligen Blöcke"
                                     "durch Explosionen zerstören.",
                                     "Unter diesen Blöcken können sich manchmal auch Upgrades befinden, die ihr"
                                     "einsammeln könnt."};
    int counter = 1;
    for (std::string tmp: instruction_text) {
        graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 10, counter*25);
        counter++;
    }

    // Key-Assignement for players
    std::string player_text[3][2] = {{"Bewegen", "Bombe legen"},
                                    {"WASD", "Linkes Shift"},
                                    {"IJKL", "Rechtes Shift"}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            graphics.WriteText(player_text[j][i], graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                                    false, 100+i*110, 145+j*40);

            if (i==0) {
                  switch (theme_) {
                     case kClassic:
                         //Setze Player-Tiles auf Bomberman
                         break;
                     case kHalloween:
                         //Setze Player-Tiles auf Ghostman
                         break;
                     case kChicken:
                         //Setze Player-Tiles auf Birdman
                         break;
                     case kCorona:
                         //Setze Player-Tiles auf Coronaman
                         break;
                     default:
                         break;
                 }
                 //graphics::kPlayer2Tiles.right
                 graphics.DrawTile(graphics::kTilePlayer, graphics::Color(255,255,255,0), 20, 145+j*40);
                 graphics.DrawTile(graphics::kTilePlayer, graphics::Color(255,255,255,0), 20, 145+j*40);
           }
        }
    }

    // Use of upgrades
    std::string upgrade_text[] = {"Upgrade",
                                 "Höhere Bombenzahl",
                                 "Größere Explosionen",
                                 "Höhere Schnelligkeit"};
    graphics::Tile upgrade_tile[] = {graphics::kTileBombCountUpgrade,
                                  graphics::kTileExplosionRadiusUpgrade,
                                  graphics::kTileSpeedUpgrade};
    counter = 0;
    for (std::string tmp: upgrade_text) {
        graphics.DrawTile(upgrade_tile[counter], graphics::Color(255,255,255,255), 20, 305+(counter+1)*40);
        graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                    false, 100, 305+counter*40);
        counter++;
    }
}

void InstructionWindow::OnMenuItemSelect(int selected_option){
    switch (selected_option) {
        case kStart:
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
