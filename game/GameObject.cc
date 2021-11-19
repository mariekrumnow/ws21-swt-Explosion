//
// Created by Dennis Neuhaus on 15.11.21.
//

#include "GameObject.h"

namespace game {

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::SetPosition(int x, int y) {
    x_ = x;
    y_ = y;
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
