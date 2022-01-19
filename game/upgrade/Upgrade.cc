//Autor Peter, Patrick

#include "Upgrade.h"

#include "../GameObject.h"

namespace game {
namespace upgrade{

Upgrade::Upgrade() : GameObject() {}

bool Upgrade::OnCollision(GameObject& source){
    return false;
}

bool Upgrade::OnExplosion(GameObject& source) {
    return false;
}

void Upgrade::Update(double delta_time){}

} // namespace upgrade
} // namespace game
