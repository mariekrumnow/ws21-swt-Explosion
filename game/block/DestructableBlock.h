//
// Autor: Nina, Marie
//

#ifndef BOMBERMAN_DESTRUCTABLE_H
#define BOMBERMAN_DESTRUCTABLE_H

#include "Block.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {
class DestructableBlock : public Block{
public:
    DestructableBlock();
    ~DestructableBlock();
    bool OnExplosion();
    graphics::Tile GetTile();
    graphics::Color GetColor();
};
}// namespace game

#endif //BOMBERMAN_DESTRUCTABLE_H
