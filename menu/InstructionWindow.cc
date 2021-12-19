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
        MenuItem start = MenuItem("Los geht's!", Start, 350, 400);
        MenuWindow::AddMenuItem(start);
    }

    void InstructionWindow::Draw(){
        MenuWindow::Draw();

        graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();
        // Instructions on how to play the game
        std::string instructionText[] = {"So geht's:",
                                         "Bei Bomberman muesst ihr eure Mitspieler mittels Bomben ausschalten und als letzter ueberleben.",
                                         "Um zu euren Mitspielern zu gelangen muesst ihr dafuer erst die perforierten Bloecke durch Explosionen zerstoeren.",
                                         "Unter diesen Bloecken koennen sich manchmal auch Upgrades befinden, die ihr einsammeln koennt."};
        int counter = 1;
        for (std::string tmp: instructionText) {
            graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 10, counter++*25);
        }

        // Key-Assignement for players
        std::string playerText[3][2] = {{"Bewegen", "Bombe legen"},
                                        {"WASD", "Linkes Shift"},
                                        {"IJKL", "Rechtes Shift"}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                graphics.WriteText(playerText[j][i], graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 100+i*110, 145+j*40);

                if (i==0){
                      switch (theme_) {
                         case Classic:
                             //Setze Player-Tiles auf Bomberman
                             break;
                         case Halloween:
                             //Setze Player-Tiles auf Ghostman
                             break;
                         case Chicken:
                             //Setze Player-Tiles auf Birdman
                             break;
                         case Corona:
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
        std::string upgradeText[] = {"Upgrade",
                                     "Hoehere Bombenzahl",
                                     "Groessere Explosionen",
                                     "Hoehere Schnelligkeit"};
        graphics::Tile upgradeTile[] = {graphics::kTileBombCountUpgrade,
                                      graphics::kTileExplosionRadiusUpgrade,
                                      graphics::kTileSpeedUpgrade};
        counter = 0;
        for (std::string tmp: upgradeText) {
            graphics.DrawTile(upgradeTile[counter], graphics::Color(255,255,255,255), 20, 305+(counter+1)*40);
            graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 100, 305+(counter++)*40);
        }
    }

    void InstructionWindow::OnMenuItemSelect(int selected_option){
        switch (selected_option) {
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
