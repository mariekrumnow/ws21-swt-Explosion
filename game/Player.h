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
    void IncreaseExplosion(int value);
    void IncreaseMaxBombCount(int value);
    //void OnBombDestroyed(Bomb& bomb);
    void Update(double delta_time);
    bool OnExplosion(GameObject& source);
    bool OnCollision(GameObject& source);

private:
    //void PlaceBomb(int x,int y);
    void SetPosition(int x, int y);

    int speed_;
    int explosion_radius_;
    int max_bomb_count_;
    //std::vector<Bomb&> owned_bombs_;
  };
} //namespace game

#endif //BOMBERMAN_PLAYER_H
