//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_INDESTRUCTIBLE_H
#define BOMBERMAN_INDESTRUCTIBLE_H

#include "Block.h"
#include "../../graphics/Tile.h"
#include "../../graphics/Color.h"

namespace game {

namespace obstacles{

/// Block that can be shown on the map and NOT be destroyed by an explosion
class IndestructibleBlock : public Block{
public:
    /// asically calls the constructor of GameObject
    IndestructibleBlock();

    /// Creates an IndestructibleBlock on the map
    static IndestructibleBlock* CreateIndestructibleBlock(int x, int y);

    /// Sends signal that the explosion was ended by a block
    bool OnExplosion(GameObject& source);

    /// Returns the shape of the block
    graphics::Tile GetTile();

    /// Returns color of the block
    graphics::Color GetColor();
};

} // namespace obstacles

} // namespace game

#endif //BOMBERMAN_INDESTRUCTIBLE_H
