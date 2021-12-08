//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_GAME_BLOCK_BLOCK_H
#define BOMBERMAN_GAME_BLOCK_BLOCK_H

#include "../GameObject.h"

namespace game {
namespace obstacles{

///  Abstract class to represent destructible and indestructible blocks
class Block : public GameObject{
public:

    ///  Calls the constructor of GameObject
    Block();

    ///   Overwrites virtual function of GameObject
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);

    ///  Sends signal that something collided with a block
    ///
    /// \param source The object that collided with this block
    bool OnCollision(GameObject& source);

    /// Sends signal that the player that was passed over collided with a block
    ///
    /// \param Player The player_object that collided with this block
    bool OnPlayerCollision(Player& Player);

};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_BLOCK_H
