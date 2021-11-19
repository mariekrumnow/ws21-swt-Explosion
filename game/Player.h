//
// Created by Dennis Neuhaus on 18.11.21.
//

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <vector>

#include "GameObject.h"

namespace game {

class Player : public GameObject {
public:
    Player();
    ~Player();

    void IncreaseSpeed(int value);
    void IncreaseExplosionRadius(int value);
    void IncreaseMaxBombCount(int value);
    //boolvect OnBombDestroyed(Bomb& bomb);
    void Update(double delta_time);
    bool OnExplosion(GameObject& source);
    bool OnCollision(GameObject& source);
    int GetSpeed();
    void SetSpeed(int s);
    int GetExplosionRadius();
    void SetExplosionRadius(int r);
    int GetMaxBombCount();
    void SetMaxBombCount(int m);
    int GetOwnedBombs();
    void SetOwnedBombs(int o);

private:
    //void PlaceBomb(int x,int y);
    void SetPosition(int x, int y);      //überprüft auch via OnPlayerCollision ob Position frei is

    int speed_;
    int explosion_radius_;
    int max_bomb_count_;
    int owned_bombs_;
  };
} //namespace game

#endif //BOMBERMAN_PLAYER_H
