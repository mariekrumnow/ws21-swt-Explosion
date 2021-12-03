//Autor: Nina, Tobias, Marie

#ifndef BOMBERMAN_GAMEOBJECT_H
#define BOMBERMAN_GAMEOBJECT_H

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
  ~GameObject();

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
	bool IsDestroyed();

private:

  int x_;
  int y_;
	bool destroyed_;
};
} //namespace game


#endif //BOMBERMAN_GAMEOBJECT_H
