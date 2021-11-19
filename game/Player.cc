//
// Created by Dennis Neuhaus on 18.11.21.
//

#include "Player.h"
namespace game {

Player::Player(){}

Player::~Player(){}

void Player::SetPosition(int x, int y) {}                     //überprüft auch via OnPlayerCollision ob Position frei is

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

void Player::Update(double delta_time) {}

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

void Player::SetSpeed(int s) {
    speed_ = s;
}

int Player::GetExplosionRadius() {
    return explosion_radius_;
}

void Player::SetExplosionRadius(int r) {
    explosion_radius_ = r;
}

int Player::GetMaxBombCount() {
    return max_bomb_count_;
}

void Player::SetMaxBombCount(int m) {
    max_bomb_count_ = m;
}

int Player::GetOwnedBombs() {
    return owned_bombs_;
}

void Player::SetOwnedBombs(int o){
    owned_bombs_ = o;
}

} //namespace game
