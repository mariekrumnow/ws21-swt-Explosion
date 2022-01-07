// Autor: Nina, Marie


#ifndef BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H
#define BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H


#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Block.h"
#include "GameObject.h"

namespace game {
namespace obstacles{


/// Block that can be shown on the map and NOT be destroyed by an explosion
class IndestructibleBlock : public Block{
public:

    /// Calls the constructor of GameObject
    IndestructibleBlock();

    /// Creates a IndestructibleBlock on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created block or nullptr if an error occurred
    static IndestructibleBlock* CreateIndestructibleBlock(int x, int y);

    /// Sends signal that the explosion was ended by a block
    ///
    /// \param source Color of the Entity
    /// \return true
    bool OnExplosion(GameObject& source);

    /// Returns the shape of the block
    ///
    /// \return Graphics of the IndestructibleBlock
    graphics::Tile GetTile();

    /// Returns color of the block
    ///
    /// \return Color of the Entity
    graphics::Color GetColor();
};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H
