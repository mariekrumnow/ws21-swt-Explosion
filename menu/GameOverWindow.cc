//
// Autor: Marlene, Marie, Patrick
//

#include "GameOverWindow.h"

namespace menu{
    GameOverWindow::GameOverWindow(game::Player *winner) : winner_color_(graphics::Color(0,0,0,255)) {
        if (winner != nullptr) {
            winner_name_ = "Spieler1";
        }
    }
    GameOverWindow::~GameOverWindow(){}


    void GameOverWindow::Draw(){}

    void GameOverWindow::OnMenuItemSelect(int selected_option){}

    std::string& GameOverWindow::GetWinner(){}

    graphics::Color& GameOverWindow::GetWinnerColor(){}

}
