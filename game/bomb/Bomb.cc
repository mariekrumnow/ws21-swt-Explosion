//Autor: Tobias, Marie

#include "Bomb.h"
#include "Explosion.h"

#include <iostream>

namespace game {
namespace bomb {

Bomb::Bomb(Player* owner, int power, double explosion_delay) {
	owner_ = owner;
	power_ = power;
	explosion_timer_ = explosion_delay;
	exploding_ = false;
}

/// If a nullptr is returned, an error occured or the object couldn't be placed
Bomb* Bomb::CreateBomb(int x, int y, Player* owner, int power, double explosion_delay){
	Bomb* temp = new Bomb(owner,power,explosion_delay);
	if (temp!=nullptr){
		    GameManager::GetCurrentGame().AddGameObject(*temp);
                if (!temp->SetPosition(x,y)) {
                      temp->Destroy();
                      return nullptr;
                }
      }
	return temp;
}

Bomb::~Bomb() {}

Player* Bomb::GetOwner() {
	return owner_;
}

bool Bomb::OnExplosion(GameObject& source) {
	if (!exploding_) {
		Explode();
		return true;
	} else {
		return true;
	}
}

bool Bomb::OnCollision(GameObject& source) {
	return !exploding_; ///exploding bombs aren't solid
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

bool Bomb::SpawnExplosion(int x, int y) {
	Explosion* explosion = Explosion::CreateExplosion(x,y);
	if (explosion = nullptr) {
		return false;
	}

	return true;
}

void Bomb::Explode() {
	GameManager& game = GameManager::GetCurrentGame();

	exploding_ = true; ///so the bomb isn't solid anymore

	if (owner_) {
		owner_->OnBombDestroyed(*this);
	}

	//The four explosion directions
	int x_turn[4] = {0,1,0,-1};
	int y_turn[4] = {1,0,-1,0};

	int current_x = GetX();
	int current_y = GetY();

	///always spawn explosion where bomb is
	SpawnExplosion(current_x, current_y);

	///for each of the four directions
	for (int turn=0; turn<4; turn++) {
		///explode for the given distance
		for (int d=1; d<=power_; d++) {
			///get rotated position
			int x = current_x + x_turn[turn]*d;
			int y = current_y + y_turn[turn]*d;

			///check for obstacles
			bool stopped = false;
			for (GameObject* go : game.GetObjectsAtPos(x,y)) {
				stopped |= go->OnExplosion(*this);
			}

			///if none there, spawn explosion
			if (stopped) {
				break;
			} else {
				if (!SpawnExplosion(x,y)) {
					break;
				}
			}
		}
	}
	this->Destroy();
}

} // namespace bomb
} // namespace game
