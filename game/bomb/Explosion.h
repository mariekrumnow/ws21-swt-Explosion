// Autor: Marlene, Marie, Carla, Nina

#ifndef BOMBERMAN_GAME_BOMB_EXPLOSION_H
#define BOMBERMAN_GAME_BOMB_EXPLOSION_H

#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameObject.h"
#include "../GameManager.h"

namespace game {
namespace bomb {

class Explosion : public GameObject {
public:
    Explosion();
    static Explosion* CreateExplosion(int x, int y,int oriented);
    ~Explosion();

    graphics::Tile GetTile() override;

    graphics::Color GetColor() override;

    void Update(double delta_time) override;

    const double kExplosionDuration = 0.5;

    int GetOrientation();

private:
    double timer_;
    int orientation_;
};

}  // namespace bomb
}  // namespace game

#endif // BOMBERMAN_GAME_BOMB_EXPLOSION_H
