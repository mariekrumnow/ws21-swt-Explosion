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

    /// Calls the constructor of Block
    DestructibleBlock();

    /// Creates a DestructibleBlock on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer to the newly created block or nullptr if an error occurred
    static DestructibleBlock* CreateDestructibleBlock(int x, int y);

    /// Called when an Explosion interacts with the Block
    /// Destroys the block and potentially spawns an item
    ///
    /// \param source The origin of the Explosion
    /// \return Whether the block stops the explosion (true)
    bool OnExplosion(GameObject& source);

    /// Returns the Tile of the block
    ///
    /// \return Graphics of the DestructibleBlock
    graphics::Tile GetTile();

    /// Returns the Color of the block
    ///
    /// \return Color of the DestructibleBlock
    graphics::Color GetColor();

    /// Removes the GameObject from the current Game and notifies the GameManager
    void Destroy(); //so the GameManagers block count can be reduced
};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H
