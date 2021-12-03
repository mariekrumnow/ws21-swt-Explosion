//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_BLOCK_H
#define BOMBERMAN_BLOCK_H

#include "../game/GameObject.h"

namespace game {

namespace obstacles{

/// Abstract class to represent destructible and indestructible blocks
class Block : public GameObject{
public:
    /// Calls the constructor of GameObject
    Block();

    /// Overwrites virtual function of GameObject
    void Update(double delta_time);

    /// Sends signal that something collided with a block
    bool OnCollision(GameObject& source);

    /// Sends signal that the player that was passed over collided with a block
    bool OnPlayerCollision(Player& Player);

};

} // namespace obstacles

} // namespace game

#endif // BOMBERMAN_BLOCK_H
