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

//void Player::PlaceBomb(int x, int y) {}

void Player::Update(double delta_time) {}

//void Player::OnBombDestroyed(Bomb bomb) {}

bool Player::OnCollision(int &source) {}

bool Player::OnExplosion(int &source) {}

} //namespace game