//
// Created by Dennis Neuhaus on 18.11.21.
//

#include "Player.h"
namespace game {

Player::Player(){}

Player::~Player(){}

void Player::SetPosition(int x, int y) {}

void Player::IncreaseExplosion(int value) {}

void Player::IncreaseMaxBombCount(int value){}

void Player::IncreaseSpeed(int value) {}

void Player::PlaceBomb(int x, int y) {}

void Player::Update(double delta_time) {}

bool Player::OnBombDestroyed(Bomb bomb) {}

} //namespace game