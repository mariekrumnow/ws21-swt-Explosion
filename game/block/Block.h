// Autor: Nina, Marie


#ifndef BOMBERMAN_GAME_BLOCK_BLOCK_H
#define BOMBERMAN_GAME_BLOCK_BLOCK_H

#include "../GameObject.h"

namespace game {
namespace obstacles{

/// Abstract class to represent destructible and indestructible blocks
class Block : public GameObject{
public:

    /// Calls the constructor of GameObject
    Block();

    /// An empty Update function
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);

    /// Called when an object collides with the block, returns true
    ///
    /// \param source The object that collided with this block
    /// \return Whether this object hinders movement
    bool OnCollision(GameObject& source);

    /// Called when a player collides with the block, returns true
    ///
    /// \param Player The player that collided with this block
    /// \return Whether this object hinders movement
    bool OnPlayerCollision(Player& Player);

};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_BLOCK_H
