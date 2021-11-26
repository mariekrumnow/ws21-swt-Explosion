//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_INDESTRUCTABLE_H
#define BOMBERMAN_INDESTRUCTABLE_H

#include "Block.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

///
class IndestructableBlock : public Block{
public:
    /// Calls the constructor of Block
    IndestructableBlock(int x, int y);

    /// Sends signal that the explosion was ended by a block
    bool OnExplosion(GameObject& source);

    /// Returns the shape of the block
    graphics::Tile GetTile();

    /// Returns color of the block
    graphics::Color GetColor();
};

} // namespace game

#endif //BOMBERMAN_INDESTRUCTABLE_H
