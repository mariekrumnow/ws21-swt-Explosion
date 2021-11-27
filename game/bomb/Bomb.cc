//Autor: Tobias

#include "Bomb.h"

namespace game {
namespace bomb {

Bomb::Bomb(Player* owner, int power, double explosion_delay) {
	owner_ = owner;
	power_ = power;
	explosion_timer_ = explosion_delay;
}

Bomb::~Bomb() {
	if (owner_) {
		owner_->OnBombDestroyed(*this);
	}
}

Player* Bomb::GetOwner() {
	return owner_;
}

bool Bomb::OnExplosion(GameObject& source) {
	Explode();
	return true;
}

bool Bomb::OnCollision(GameObject& source) {
	return true;
}

graphics::Tile Bomb::GetTile() {
	return graphics::kTileBomb;
}

graphics::Color Bomb::GetColor() {
	if (std::fmod(explosion_timer_, 0.5) < 0.25) {
		return graphics::Color(255,0,0,255);
	} else {
		return graphics::Color(255,255,0,255);
	}
}

void Bomb::Update(double delta_time) {
	explosion_timer_ -= delta_time;
	if (explosion_timer_ <= 0) {
		Explode();
	}
}

void Bomb::SpawnExplosion(int x, int y) {

}

void Bomb::Explode() {
	GameManager& game = GameManager::GetCurrentGame();

	//The four explosion directions
	int xTurn[4] = {0,1,0,-1};
	int yTurn[4] = {1,0,-1,0};

	//alwys spawn explosion where bomb is
	SpawnExplosion(GetX(), GetY());

	//for each of the four directions
	for (int turn=0; turn<4; turn++) {
		//explode for the given distance
		for (int d=1; d<=power_; d++) {
			//get rotated position
			int x = GetX() + xTurn[turn]*d;
			int y = GetY() + yTurn[turn]*d;

			//check for obstacles
			bool stopped = false;
			for (GameObject* go : game.GetObjectsAtPos(x,y)) {
				stopped |= go->OnExplosion(*this);
			}

			//if none there, spawn explosion
			if (stopped) {
				break;
			} else {
				SpawnExplosion(x,y);
			}
		}
	}

	delete this;
}

} //namespace bomb
} //namespace game
