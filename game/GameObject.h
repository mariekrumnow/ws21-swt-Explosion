//
// Created by Dennis Neuhaus on 15.11.21.
//

#ifndef BOMBERMAN_GAMEOBJECT_H
#define BOMBERMAN_GAMEOBJECT_H
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {
  class Player;
}

namespace game {

class GameObject {
public:
  GameObject();
  ~GameObject();

  virtual bool OnExplosion(GameObject& source);
  virtual bool OnPlayerCollision(Player& player);
  virtual bool OnCollision(GameObject& source);
  virtual graphics::Tile GetTile()=0;
  virtual graphics::Color GetColor()=0;
  virtual void Update(double delta_time)=0;
  virtual int GetX();
  virtual int GetY();
  virtual void SetPosition(int x, int y);


private:

  int x_;
  int y_;
};
} //namespace game


#endif //BOMBERMAN_GAMEOBJECT_H
