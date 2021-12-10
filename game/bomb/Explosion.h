// Autor: Marlene, Marie, Carla, Nina

#ifndef BOMBERMAN_GAME_BOMB_EXPLOSION_H
#define BOMBERMAN_GAME_BOMB_EXPLOSION_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game {
namespace bomb {

class Explosion : public GameObject {
public:
    Explosion();
    static Explosion* CreateExplosion(int x, int y,int t);
    ~Explosion();

    graphics::Tile GetTile();

    graphics::Color GetColor();

    void Update(double delta_time);

    const double kExplosionDuration = 0.5;

    int GetOrientation();

private:
    double timer_;
    int orientation_;
};


}  // namespace bomb
}  // namespace game

#endif // BOMBERMAN_GAME_BOMB_EXPLOSION_H
