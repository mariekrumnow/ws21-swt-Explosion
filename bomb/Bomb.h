//Autor: Tobias, Marie

#ifndef BOMBERMAN_GAME_BOMB_BOMB_H
#define BOMBERMAN_GAME_BOMB_BOMB_H

#include <cmath>
#include <iostream>

#include "GameObject.h"
#include "GameManager.h"
#include "Player.h"
#include "Tile.h"
#include "Explosion.h"

namespace game {
namespace bomb {

class Bomb : public GameObject{

public:
	Bomb(Player* owner, int power, double explosion_delay);
	static Bomb* CreateBomb(int x, int y, Player* owner, int power, double explosion_delay);
	~Bomb();
	Player* GetOwner();
	virtual bool OnExplosion(GameObject& source);
	virtual bool OnCollision(GameObject& source);
	graphics::Tile GetTile();
	graphics::Color GetColor();
	void Update(double delta_time);

private:
	Player* owner_;
	int power_;
	double explosion_timer_;
	bool exploding_; //so the bomb can't explode multiple times
	void Explode();
	bool SpawnExplosion(int x, int y);
};

}
}
#endif
