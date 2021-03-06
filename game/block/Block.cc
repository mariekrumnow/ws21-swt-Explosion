// Autor: Nina, Marie


#include "Block.h"

#include "../GameObject.h"


namespace game {
namespace obstacles{

Block::Block() : GameObject() {}

void Block::Update(double delta_time) {}

bool Block::OnCollision(GameObject& source) {
    return true;
}

bool Block::OnPlayerCollision(Player& Player) {
    return true;
}

} // namespace obstacles
} // namespace game
