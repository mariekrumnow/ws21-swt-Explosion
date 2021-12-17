// Autor: Peter, Nina, Tobias, Marie, Carla, Dennis

#ifndef BOMBERMAN_GAME_PLAYER_H
#define BOMBERMAN_GAME_PLAYER_H

#include <iostream>
#include <vector>

#include "GameManager.h"
#include "../graphics/Keys.h"
#include "../graphics/Color.h"
#include "../graphics/Tile.h"

namespace game {

namespace bomb { class Bomb;}

class Player : public GameObject {
public:
    static Player* CreatePlayer(int x, int y, graphics::PlayerKeys keys,
                                graphics::PlayerTile tiles);
    Player(graphics::PlayerKeys, graphics::PlayerTile);
    ~Player();

    void IncreaseSpeed(int value);
    void IncreaseExplosionRadius(int value);
    void IncreaseMaxBombCount(int value);
    void OnBombDestroyed(bomb::Bomb& bomb);
    void Update(double delta_time);
    bool OnExplosion(GameObject& source);
    bool OnCollision(GameObject& source);
    int GetSpeed() const;
    int GetExplosionRadius() const;
    int GetMaxBombCount() const;
    int GetOwnedBombs() const;
    int GetKMaxExplosionRadius() const;
    int GetKMaxBombCount() const;
    int GetKMaxSpeed() const;

    graphics::Tile GetTile();
    graphics::Color GetColor();

private:
    bool PlaceBomb(int x,int y);

    /// überprüft auch via OnPlayerCollision ob Position frei is
    bool SetPosition(int x, int y);

    int explosion_radius_ = 1;
    int max_bomb_count_ = 1;
    int speed_ = 7;
    int owned_bombs_ = 0;
    const int kMaxExplosionRadius = 10;
    const int kMaxMaxBombCount = 10;
    const int kMaxSpeed = 7;

    int orientation_ = 0;

    double move_timer_;  ///< timer till player can move again
    const double kMaxMoveTimer = 1.0;
    const double kMinMoveTimer = 0.1;

    graphics::PlayerKeys keys_; ///< controls
    graphics::PlayerTile tiles_;

};

} // namespace game

#endif // BOMBERMAN_GAME_PLAYER_H
