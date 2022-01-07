//Autor: Tobias, Marie, Carla, Nina

#include "Bomb.h"

#include <cmath>
#include <iostream>

#include "../core/AppManager.h"
#include "../sound/SoundEffect.h"
#include "Explosion.h"


namespace game {
namespace bomb {

Bomb::Bomb(Player* owner, int power, double explosion_delay) {
	owner_ = owner;
	power_ = power;
	explosion_timer_ = explosion_delay;
	exploding_ = false;
}

// If a nullptr is returned, an error occured or the object couldn't be placed
Bomb* Bomb::CreateBomb(int x, int y, Player* owner, int power, double explosion_delay){
	Bomb* temp = new Bomb(owner,power,explosion_delay);
	if (temp!=nullptr) {
		    GameManager::GetCurrentGame().AddGameObject(*temp);
	            if (!temp->SetPosition(x,y)) {
	                  temp->Destroy();
	                  return nullptr;
	            }
	  }

	//if explosion_delay is below 0.5, the loop formuar would fail.
	if (explosion_delay >= 0.5) {
		 core::AppManager::GetAppManager().GetSound()
		 	.PlaySoundEffectAlone(sound::effect_bomb_tick, trunc(explosion_delay/0.5)-1);
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
	return !exploding_; //exploding bombs aren't solid
}

graphics::Tile Bomb::GetTile() {
	return graphics::kTileBomb;
}

graphics::Color Bomb::GetColor() {
       if (std::fmod(explosion_timer_, 0.4) < 0.2) {
           return graphics::Color(255,255,255,255);
       } else {
           return graphics::Color(230,200,200,255);
       }
}

void Bomb::Update(double delta_time) {
	explosion_timer_ -= delta_time;
	if (explosion_timer_ <= 0) {
		Explode();
	}
}

bool Bomb::SpawnExplosion(int x, int y, int oriented) {
	Explosion* explosion = Explosion::CreateExplosion(x,y,oriented);
	if (explosion == nullptr) {
		return false;
	}

	return true;
}

void Bomb::Explode() {
	GameManager& game = GameManager::GetCurrentGame();

	core::AppManager::GetAppManager().GetSound()
		.PlaySoundEffect(sound::effect_bomb_explode, 0);

	exploding_ = true; //so the bomb isn't solid anymore

	if (owner_) {
		owner_->OnBombDestroyed(*this);
	}

	//The four explosion directions
	int x_turn[4] = {0,1,0,-1};
	int y_turn[4] = {1,0,-1,0};

	int current_x = GetX();
	int current_y = GetY();

	//always spawn explosion where bomb is
	SpawnExplosion(current_x, current_y,10);

	//for each of the four directions
	for (int turn=0; turn<4; turn++) {
		//explode for the given distance
		for (int d=1; d<=power_; d++) {
			//get rotated position
			int x = current_x + x_turn[turn]*d;
			int y = current_y + y_turn[turn]*d;

			//check for obstacles
			bool stopped = false;
			for (GameObject* go : game.GetObjectsAtPos(x,y)) {
				stopped |= go->OnExplosion(*this);
			}
            int oriented=turn;
            //differetiation between middle- and end- explosions
            if (d==power_) {
                switch(turn){
                    case 0 :
                        oriented=4;
                        break;
                    case 1 :
                        oriented=5;
                        break;
                    case 2 :
                        oriented=6;
                        break;
                    case 3 :
                        oriented=7;
                        break;
                }
            }
			//if none there, spawn explosion
			if (stopped) {
				//if the tile that stopped you is now empty, place end piece
				if (game.GetObjectsAtPos(x,y).size() == 0) {
					if (oriented <=3) oriented += 4; //turn it into an end piece
					SpawnExplosion(x,y,oriented);
				}
				break;
			} else if (!SpawnExplosion(x,y,oriented)) {
                break;
			}
		}
	}
	this->Destroy();
}

} // namespace bomb
} // namespace game
