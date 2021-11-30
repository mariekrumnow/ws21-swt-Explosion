//Autor: Nina, Tobias

#include "GameObject.h"

#include "../graphics/Tile.h"
#include "../graphics/Color.h"
#include "GameManager.h"

namespace game {

GameObject::GameObject(){
  x_ = 0;
  y_ = 0;
}

GameObject::GameObject(int x, int y) {
    x_ = x;
    y_ = y;
}

GameObject::~GameObject(){
  GameManager::GetCurrentGame().RemoveGameObject(*this);
}

bool GameObject::SetPosition(int x, int y) {
  GameManager& game = GameManager::GetCurrentGame();

  bool collision = false;
  for (GameObject* object : game.GetObjectsAtPos(x,y)) {
    collision |= object->OnCollision(*this);
  }

  if (!collision && game.ChangeObjectPosition(*this, x, y)) {
    x_ = x;
    y_ = y;
    return true;
  }
  return false;
}

bool GameObject::OnExplosion(GameObject& source) {
	return false;
}

bool GameObject::OnPlayerCollision(Player& player) {
	return false;
}

bool GameObject::OnCollision(GameObject& source) {
	return false;
}

int GameObject::GetX() {
    return x_;
}

int GameObject::GetY() {
    return y_;
}


} //namespace game
