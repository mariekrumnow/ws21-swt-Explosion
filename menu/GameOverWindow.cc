//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"

#include "../core/AppManager.h"
#include "../game/GameFactory.h"
#include "../sound/Music.h"
#include "MainWindow.h"



namespace menu{

enum GameOverButton {kExit2=0, kNewRound=1, kToMain=2};

GameOverWindow::GameOverWindow(game::Player *winner)
: MenuWindow(kExit2) , winner_(winner)
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

void GameOverWindow::Draw(){
    MenuWindow::Draw();

    graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

    std::string tmp;
    if (winner_ != nullptr) {
        graphics.DrawTile(winner_->GetTile(), winner_->GetColor(), 320, 250);
        tmp = "Du gewinnst!!!";
    } else {
        tmp = "-Unentschieden-";
    }
    graphics.WriteText(tmp, graphics::Color(0, 0, 255, 255), graphics::FontSize::kLarge, false, 390, 265);

}

void GameOverWindow::OnMenuItemSelect(int selected_option){
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
