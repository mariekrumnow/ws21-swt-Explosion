//Autor: Peter, Nina, Tobias

#ifndef BOMBERMAN_PLAYER_H
#define BOMBERMAN_PLAYER_H

#include <vector>

#include "GameObject.h"
#include "GameManager.h"
#include "Keys.h"
#include "Color.h"
#include "Tile.h"

namespace game {

class Player : public GameObject {
public:
    Player(SDL_Scancode up, SDL_Scancode down, SDL_Scancode left, SDL_Scancode right, SDL_Scancode bomb);
    ~Player();

    void IncreaseSpeed(int value);
    void IncreaseExplosionRadius(int value);
    void IncreaseMaxBombCount(int value);
    //boolvect OnBombDestroyed(Bomb& bomb);
    void Update(double delta_time);
    bool OnExplosion(GameObject& source);
    bool OnCollision(GameObject& source);
    int GetSpeed();
    int GetExplosionRadius();
    int GetMaxBombCount();
    int GetOwnedBombs();

    graphics::Tile GetTile();
    graphics::Color GetColor();

private:
    //void PlaceBomb(int x,int y);
    bool SetPosition(int x, int y);      //überprüft auch via OnPlayerCollision ob Position frei is

    int explosion_radius_;
    int max_bomb_count_;
    int speed_;
    const int kMaxExplosionRadius = 10;
    const int kMaxMaxBombCount = 10;
    const int kMaxSpeed = 10;

    int owned_bombs_;

    //timer till player can move again
    double move_timer_;
    const double kMaxMoveTimer = 1.0;
    const double kMinMoveTimer = 0.1;


    // controls
    SDL_Scancode up, down, left, right, bomb;

  };
} //namespace game

#endif //BOMBERMAN_PLAYER_H
