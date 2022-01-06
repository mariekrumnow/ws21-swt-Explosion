//
// Autor: Tobias
//

#include "SinglePlayerInstructionWindow.h"

#include "../core/AppManager.h"
#include "../game/GameFactory.h"
#include "MainWindow.h"


namespace menu{

enum SinglePlayerInstructionWindowButton {kStart=0, kBack=1};

SinglePlayerInstructionWindow::SinglePlayerInstructionWindow()
: MenuWindow(kStart)
{
    MenuItem start = MenuItem("Los geht's!", kStart, 400, 700);
    MenuWindow::AddMenuItem(start);

    MenuItem back = MenuItem("Zurück", kBack, 400, 800);
    MenuWindow::AddMenuItem(back);
}

void SinglePlayerInstructionWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    // Button instruction
    graphics.WriteText("F12: Musik im Spiel ändern", graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                                    false, 815, 10);

    // Instructions on how to play the game
    std::string instruction_text[] = {"So geht's:",
                                     "Bei Bomberman Singleplayer musst du alle zerstörbaren Blöcke",
                                     "zerstören. Unter diesen Blöcken können sich manchmal",
                                     "auch Upgrades befinden, die du einsammeln kannst. Deine Zeit wird gemessen,",
                                     "und deine kürzeste Zeit gespeichert.",
                                     "Versuche deinen eigenen Highscore zu schlagen!",};
    int counter = 1;
    for (std::string tmp: instruction_text) {
        graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                        false, 125, 50+counter*25);
        counter++;
    }

    // Key-Assignement for players
    std::string player_text[2][2] = {{"Bewegen", "Bombe legen"},
                                    {"WASD", "Linkes Shift"}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            graphics.WriteText(player_text[j][i], graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                                    false, 200+i*110, 350+j*70);
            if (i==0 && j!=0) {
                  graphics::Tile player_tile = graphics::kPlayer1Tiles.right;
                  graphics.DrawTile(player_tile, graphics::Color(255,255,255,0), 125, 330+j*70);
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
        graphics.DrawTile(upgrade_tile[counter], graphics::Color(255,255,255,255), 550, 330+(counter+1)*70);
        graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kMedium,
                                                                    false, 620, 350+counter*70);
        counter++;
    }
}

void SinglePlayerInstructionWindow::OnMenuItemSelect(int selected_option){
    bool go_back = false;
    switch (selected_option) {
        case kStart:
            game::StartSinglePlayerGame();
            break;
        case kBack:
            go_back = true;
            break;
        default:
            //Error, a button should always be selected
            break;
    }
    if (go_back) {
          MainWindow * mainW = new MainWindow();
          core::AppManager::GetAppManager().SetActiveWindow(*mainW);
    }
}

}   // namespace menu
