// Autor: Nina, Tobias, Marie

#ifndef BOMBERMAN_GAME_GAMEOBJECT_H
#define BOMBERMAN_GAME_GAMEOBJECT_H

namespace game {
  class GameObject;
}

#include "../graphics/Tile.h"
#include "../graphics/Color.h"
#include "GameManager.h"

namespace game {

class Player;

class GameObject {
public:
  GameObject();
  virtual ~GameObject();

  virtual bool OnExplosion(GameObject& source);
  virtual bool OnPlayerCollision(Player& player);
  virtual bool OnCollision(GameObject& source);
  virtual graphics::Tile GetTile()=0;
  virtual graphics::Color GetColor()=0;
  virtual void Update(double delta_time)=0;
  virtual int GetX();
  virtual int GetY();
  virtual bool SetPosition(int x, int y);
  virtual void Destroy();
  bool GetDestroyed();

private:
  int x_ = 0;
  int y_ = 0;
  bool destroyed_ = false;
};

} // namespace game


#endif // BOMBERMAN_GAME_GAMEOBJECT_H
