// Autor Nina, Tobias

#ifndef BOMBERMAN_GAME_GAMEWINDOW_H
#define BOMBERMAN_GAME_GAMEWINDOW_H

#include "GameManager.h"
#include "../core/Window.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

class GameWindow : public core::Window {
public:
    GameWindow();
    ~GameWindow();
    void Draw();
    void Update(double delta_time);
};

} // namespace game


#endif // BOMBERMAN_GAME_GAMEWINDOW_H
