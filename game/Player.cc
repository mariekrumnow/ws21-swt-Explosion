//Autor: Peter, Nina, Tobias

#include "Player.h"

#include <vector>

#include "GameObject.h"
#include "GameManager.h"
#include "Keys.h"
#include "Color.h"
#include "Tile.h"

namespace game {

Player::Player(graphics::PlayerKeys keys) : keys(keys)
{
  speed_ = 1;
  explosion_radius_ = 1;
  max_bomb_count_ = 1;
  owned_bombs_ = 0;

  move_timer_ = 0;
}

Player::~Player(){}

//überprüft auch via OnPlayerCollision ob Position frei is
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

void Player::IncreaseExplosionRadius(int value) {
    explosion_radius_ += value;

}

void Player::IncreaseMaxBombCount(int value){
    max_bomb_count_ += value;
}

void Player::IncreaseSpeed(int value) {
    speed_ += value;
}

//void Player::PlaceBomb(int x, int y) {}

void Player::Update(double delta_time) {
  graphics::GraphicsManager& graphics = core::AppManager::GetAppManager().GetGraphics();

  if (move_timer_ > 0) {
    move_timer_ -= delta_time;
  }

  if (move_timer_ <= 0) {
    bool player_moved = false;

    if (graphics.IsKeyHeld(keys.up)) {
      player_moved = SetPosition(GetX(), GetY()-1);

    } if (graphics.IsKeyHeld(keys.down)) {
      player_moved = SetPosition(GetX(), GetY()+1);

    } if (graphics.IsKeyHeld(keys.left)) {
      player_moved = SetPosition(GetX()-1, GetY());

    } if (graphics.IsKeyHeld(keys.right)) {
      player_moved = SetPosition(GetX()+1, GetY());
    }
    if (graphics.IsKeyHeld(keys.bomb)) {
        PlaceBomb(GetX(), GetY());
    }

    if (player_moved) {
      move_timer_ = kMinMoveTimer +
        (kMaxMoveTimer - kMinMoveTimer) * (1 - ((double)speed_) / kMaxSpeed);
    }
  }
}

graphics::Tile Player::GetTile() {
  return graphics::kTilePlayer;
}

graphics::Color Player::GetColor() {
  return graphics::Color(255, 0, 0, 255);
}

//void Player::OnBombDestroyed(Bomb bomb) {}

bool Player::OnCollision(GameObject &source) {
    return false;
}

bool Player::OnExplosion(GameObject &source) {
    return true;
}

int Player::GetSpeed() {
    return speed_;
}

int Player::GetExplosionRadius() {
    return explosion_radius_;
}
int Player::GetMaxBombCount() {
    return max_bomb_count_;
}

int Player::GetOwnedBombs() {
    return owned_bombs_;
}

} //namespace game
