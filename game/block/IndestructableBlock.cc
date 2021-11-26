//
// Autor: Nina, Marie
//

#include "Block.h"
#include "IndestructableBlock.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

    IndestructableBlock::IndestructableBlock(int x, int y) :
      Block {x,y}
    {}

    bool IndestructableBlock::OnExplosion(GameObject& source) {
          return true;
    }

    graphics::Tile IndestructableBlock::GetTile() {
          return graphics::kTileSolidWall;
    }

    graphics::Color IndestructableBlock::GetColor() {
          return graphics::Color(105, 105, 105, 255);
    }

}// namespace game
