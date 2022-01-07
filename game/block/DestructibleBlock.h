// Autor: Nina, Marie


#ifndef BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H
#define BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Block.h"

namespace game {
namespace obstacles{

/// Block that can be shown on the map and be destroyed by an explosion
class DestructibleBlock : public Block{
public:

    /// Calls the constructor of GameObject
    DestructibleBlock();

    /// Creates a DestructibleBlock on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created block or nullptr if an error occurred
    static DestructibleBlock* CreateDestructibleBlock(int x, int y);

    /// Removes block from the map, spawns an upgrade with a 35% chance and ends the explosion
    ///
    /// \param source The origin of the Explosion
    /// \return true
    bool OnExplosion(GameObject& source);

    /// Returns the shape of the block
    ///
    /// \return Graphics of the DestructibleBlock
    graphics::Tile GetTile();

    /// Returns color of the block
    ///
    /// \return Color of the Entity
    graphics::Color GetColor();

    /// Removes the GameObject from the current Game
    void Destroy(); //so the GameManagers block count can be reduced
};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H
