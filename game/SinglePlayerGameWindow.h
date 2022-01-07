// Autor Tobias

#ifndef BOMBERMAN_GAME_SPGAMEWINDOW_H
#define BOMBERMAN_GAME_SPGAMEWINDOW_H

#include "GameWindow.h"

#include <string>

namespace game {

class SinglePlayerGameWindow : public GameWindow {
public:
    SinglePlayerGameWindow();
    ~SinglePlayerGameWindow();
    void Draw();

    void SetTimers(std::string timer, std::string high_score);

private:
    std::string timer_;
    std::string high_score_;
};

} // namespace game

#endif // BOMBERMAN_GAME_SPGAMEWINDOW_H
