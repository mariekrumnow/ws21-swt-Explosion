//
// Created by Dennis Neuhaus on 15.11.21.
//

#include "GameObject.h"

namespace game {

GameObject::GameObject(){}

GameObject::~GameObject(){}

void GameObject::SetPosition(int x, int y) {}

bool GameObject::OnExplosion(GameObject source) {}

bool GameObject::OnPlayerCollision(Player& player) {}

bool GameObject::OnCollision(GameObject source) {}

void GameObject::Update() {}

Color GameObject::GetColor() {}

Tile GameObject::GetTile() {}


} //namespace game