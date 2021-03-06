//Autor: Peter, Nina, Tobias, Marie, Carla, Dennis

#include "Player.h"

#include <cmath>
#include <iostream>
#include <vector>

#include "../core/AppManager.h"
#include "../game/bomb/Bomb.h"
#include "../graphics/Color.h"
#include "../graphics/Keys.h"
#include "../graphics/Tile.h"
#include "../sound/SoundEffect.h"
#include "win_condition/BaseWinCondition.h"
#include "GameManager.h"
#include "GameObject.h"

namespace game {

Player::Player(graphics::PlayerKeys keys, graphics::PlayerTile tiles, int id)
                : id_(id), keys_(keys), tiles_(tiles) {}

// If a nullptr is returned, an error occured or the object couldn't be placed
Player* Player::CreatePlayer(int x, int y, graphics::PlayerKeys keys,
                             graphics::PlayerTile tiles, int id)                {
    Player* temp = new Player(keys, tiles, id);
      if (temp!=nullptr) {
          GameManager::GetCurrentGame().AddPlayer(temp);
            if (!temp->SetPosition(x,y)) {
                  temp->Destroy();
                  return nullptr;
            }
      }
      return temp;
}

Player::~Player(){}

void Player::IncreaseSpeed(int value) {
    speed_ += value;
}

void Player::IncreaseExplosionRadius(int value) {
    explosion_radius_ += value;

}

void Player::IncreaseMaxBombCount(int value){
    max_bomb_count_ += value;
}

void Player::OnBombDestroyed(bomb::Bomb& bomb) {
    owned_bombs_--;
}

void Player::Update(double delta_time) {
    core::AppManager& app = core::AppManager::GetAppManager();
    graphics::GraphicsManager& graphics = app.GetGraphics();

    if (move_timer_ > 0) {
        move_timer_ -= delta_time;
    }

    if (graphics.IsKeyHeld(keys_.bomb)) {
        PlaceBomb(GetX(), GetY());
    }

    if (move_timer_ <= 0) {
        bool player_moved = false;

        if (graphics.IsKeyHeld(keys_.up)) {
            player_moved = SetPosition(GetX(), GetY()-1);
            orientation_=0;
        } else if (graphics.IsKeyHeld(keys_.down)) {
            player_moved = SetPosition(GetX(), GetY()+1);
            orientation_=1;
        } else if (graphics.IsKeyHeld(keys_.left)) {
            player_moved = SetPosition(GetX()-1, GetY());
            orientation_=2;
        } else if (graphics.IsKeyHeld(keys_.right)) {
            player_moved = SetPosition(GetX()+1, GetY());
            orientation_=3;
        }

        if (player_moved) {
            app.GetSound().PlaySoundEffect(sound::effect_walk, 0);
            move_timer_ = GetCurrentMovementTimer();
        }
    }
}

bool Player::OnExplosion(GameObject &source) {
    GameManager::GetCurrentGame().RemovePlayer(*this);
    this->Destroy();
    return false;
}

bool Player::OnCollision(GameObject &source) {
    return false;
}

double Player::GetCurrentMovementTimer() {
    //exponential speed distribution for more uniform feeling of speed increase
    return (kMaxMoveTimer - 1) + pow(kMinMoveTimer - kMaxMoveTimer + 1, (static_cast<double>(speed_)) / kMaxSpeed);
}

int Player::GetSpeed() const {
    return speed_;
}

int Player::GetExplosionRadius() const {
    return explosion_radius_;
}

int Player::GetMaxBombCount() const {
    return max_bomb_count_;
}

int Player::GetOwnedBombs() const {
    return owned_bombs_;
}

int Player::GetKMaxExplosionRadius() const {
    return kMaxExplosionRadius;
}

int Player::GetKMaxBombCount() const {
    return kMaxMaxBombCount;
}

int Player::GetKMaxSpeed() const {
    return kMaxSpeed;
}

int Player::GetId() const {
    return id_;
}

graphics::Tile Player::GetTile() {
    switch(orientation_){
        case 0 :
            return tiles_.up;
        case 1 :
            return tiles_.down;
        case 2 :
            return tiles_.left;
        case 3 :
            return tiles_.right;
        default :
            return graphics::kTileEmpty;
    }
}

graphics::Color Player::GetColor() {
    return graphics::Color(255,255,255,0);
}

graphics::PlayerTile Player::GetTileset(){
    return tiles_;
}

bool Player::PlaceBomb(int x, int y) {
    GameManager& game = GameManager::GetCurrentGame();
    if (GetOwnedBombs() < GetMaxBombCount()) {
        bomb::Bomb* bomb = bomb::Bomb::CreateBomb(x, y, this,GetExplosionRadius(), 1.5);

        if (bomb != nullptr) {
            owned_bombs_++;
            return true;
        }
    }
    return false;
}

//??berpr??ft auch via OnPlayerCollision ob Position frei is
bool Player::SetPosition(int x, int y) {

  GameManager& game = GameManager::GetCurrentGame();

  bool collision = false;
  for (GameObject* object : game.GetObjectsAtPos(x,y)) {
    collision |= object->OnPlayerCollision(*this);
  }

  if (!collision) {
    return this->GameObject::SetPosition(x,y);
  }

  return false;
}

} // namespace game
