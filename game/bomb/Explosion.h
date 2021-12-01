// Autor: Marlene

#ifndef BOMBERMAN_GAME_BOMB_EXPLOSION_H
#define BOMBERMAN_GAME_BOMB_EXPLOSION_H

#include "GameObject.h"
#include "GameManager.h"
#include "AppManager.h"
#include "Color.h"
#include "Tile.h"

namespace game {
namespace bomb {

class Explosion : public GameObject {
public:
    Explosion();

    ~Explosion();

    graphics::Tile GetTile();

    graphics::Color GetColor();

    void Update(double delta_time);

    const double kExplosionDuration = 0.5;

private:
    double timer_;
};


}  // namespace bomb
}   //namespace game

#endif //BOMBERMAN_GAME_BOMB_EXPLOSION_H
