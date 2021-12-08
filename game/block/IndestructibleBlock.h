//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H
#define BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H

#include "Block.h"
#include "../../graphics/Tile.h"
#include "../../graphics/Color.h"

namespace game {
namespace obstacles{


///  Block that can be shown on the map and NOT be destroyed by an explosion
class IndestructibleBlock : public Block{
public:

    ///  Basically calls the constructor of GameObject
    IndestructibleBlock();

    ///  Creates a IndestructibleBlock on the map
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created block or nullptr if an error occurred
    static IndestructibleBlock* CreateIndestructibleBlock(int x, int y);

    ///  Sends signal that the explosion was ended by a block
    bool OnExplosion(GameObject& source);

    ///  Returns the shape of the block
    graphics::Tile GetTile();

    ///  Returns color of the block
    graphics::Color GetColor();
};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_INDESTRUCTIBLE_H
