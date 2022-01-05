//
// Autor: Marlene, Marie, Patrick
//

#include "HighScoreWindow.h"

#include "../core/AppManager.h"
#include "../game/GameFactory.h"
#include "../graphics/Tile.h"
#include "../sound/Music.h"
#include "MainWindow.h"



namespace menu{

enum HighScoreWindowButton {kExit2=0, kNewRound=1, kToMain=2};

HighScoreWindow::HighScoreWindow(bool win) : MenuWindow(kExit2), win_(win)
{
    core::AppManager::GetAppManager().ChangeBackgroundColor(graphics::Color(50,130,255,0));

    MenuItem exit = MenuItem("Spiel schließen", kExit2, 350, 450);
    MenuWindow::AddMenuItem(exit);

    MenuItem new_round = MenuItem("Neue Runde", kNewRound, 350, 550);
    MenuWindow::AddMenuItem(new_round);

    MenuItem main = MenuItem("Zum Hauptmenü", kToMain, 350, 650);
    MenuWindow::AddMenuItem(main);

    core::AppManager::GetAppManager().GetSound().PlayMusic(sound::victory_music);
}

void HighScoreWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    graphics.DrawTile(graphics::kPlayer1Tiles.right, graphics::Color(255, 255, 255, 255), 320, 250);

    if (win_) {
        graphics.WriteText("Gewonnen!", graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 390, 265);
    } else {
        graphics.WriteText("Verloren!", graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 390, 265);
    }
}

void HighScoreWindow::OnMenuItemSelect(int selected_option){
    bool switch_to_main = false;
    switch (selected_option) {
        case kExit2:
            core::AppManager::GetAppManager().Quit();
            delete this;
            break;
        case kNewRound:
            game::StartClassicGame();
            break;
        case kToMain:
            switch_to_main = true;
            break;
        default:
            //Error, a button should always be selected
            break;
    }
    if (switch_to_main) {
        core::AppManager::GetAppManager().GetSound().PlayMusic(sound::menu_music);
          MainWindow * mainW = new MainWindow();
          core::AppManager::GetAppManager().SetActiveWindow(*mainW);
    }
}

}   // namespace menu
