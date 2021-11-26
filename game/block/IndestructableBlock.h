//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_INDESTRUCTABLE_H
#define BOMBERMAN_INDESTRUCTABLE_H

#include "Block.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {
class IndestructableBlock : public Block{
public:
    IndestructableBlock();
    ~IndestructableBlock();
    bool OnExplosion();
    graphics::Tile GetTile();
    graphics::Color GetColor();
};
}// namespace game

#endif //BOMBERMAN_INDESTRUCTABLE_H
