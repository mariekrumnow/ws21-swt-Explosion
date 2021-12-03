//Autor Nina, Tobias

#ifndef BOMBERMAN_GAMEWINDOW_H
#define BOMBERMAN_GAMEWINDOW_H

#include "../core/Window.h"
#include "GameManager.h"
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

} //namespace game


#endif //BOMBERMAN_GAMEWINDOW_H
