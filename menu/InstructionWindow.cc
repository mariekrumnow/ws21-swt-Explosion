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
            }

            switch (theme_) {
                case Classic:
                    //Male Tile vom Spieler der nach rechts läuft für das Tileset Bomberman
                    //graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255,255,255,0), 10, 50);
                    //graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255,255,255,0), 10, 50);
                    break;
                case Halloween:
                    //Male Tile vom Spieler der nach rechts läuft für das Tileset Ghostman
                    break;
                case Chicken:
                    //Male Tile vom Spieler der nach rechts läuft für das Tileset Birdman
                    break;
                case Corona:
                    //Male Tile vom Spieler der nach rechts läuft für das Tileset Coronaman
                    break;
                default:
                    break;
            }
        }

        // Use of upgrades
        std::string upgradeText[] = {"Upgrade",
                                     "Hoehere Bombenzahl",
                                     "Groessere Explosionen",
                                     "Hoehere Schnelligkeit"};
        counter = 0;
        for (std::string tmp: upgradeText) {
            //Tiles der Upgrades malen
            graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium, false, 100, 305+counter++*40);
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
