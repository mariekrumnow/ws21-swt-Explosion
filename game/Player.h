//Autor: Peter, Nina, Tobias

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <vector>
#include <iostream>

#include "GameObject.h"
#include "GameManager.h"
#include "../core/AppManager.h"
#include "../graphics/Keys.h"
#include "../graphics/Color.h"
#include "../graphics/Tile.h"

namespace game {

namespace bomb { class Bomb;}

class Player : public GameObject {
public:
    Player();
    ~Player();

    void IncreaseSpeed(int value);
    void IncreaseExplosionRadius(int value);
    void IncreaseMaxBombCount(int value);
    void OnBombDestroyed(bomb::Bomb& bomb);
    void Update(double delta_time);
    bool OnExplosion(GameObject& source);
    bool OnCollision(GameObject& source);
    int GetSpeed();
    int GetExplosionRadius();
    int GetMaxBombCount();
    int GetOwnedBombs();
    int GetKMaxExplosionRadius();
    int GetKMaxBombCount();
    int GetKMaxSpeed();

    graphics::Tile GetTile();
    graphics::Color GetColor();

private:
    bool PlaceBomb(int x,int y);
    bool SetPosition(int x, int y);      //überprüft auch via OnPlayerCollision ob Position frei is

    int explosion_radius_;
    int max_bomb_count_;
    int speed_;
    const int kMaxExplosionRadius = 10;
    const int kMaxMaxBombCount = 10;
    const int kMaxSpeed = 7;

    int owned_bombs_;

    //timer till player can move again
    double move_timer_;
    const double kMaxMoveTimer = 1.0;
    const double kMinMoveTimer = 0.1;
  };
} //namespace game

#endif //BOMBERMAN_PLAYER_H
