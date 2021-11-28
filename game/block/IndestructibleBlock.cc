//
// Autor: Nina, Marie
//

#include "Block.h"
#include "IndestructibleBlock.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

namespace obstacles{

    IndestructibleBlock::IndestructibleBlock(int x, int y) :
      Block {x,y}
    {}

    bool IndestructibleBlock::OnExplosion(GameObject& source) {
          return true;
    }

    graphics::Tile IndestructibleBlock::GetTile() {
          return graphics::kTileSolidWall;
    }

    graphics::Color IndestructibleBlock::GetColor() {
          return graphics::Color(105, 105, 105, 255);
    }

} // namespace obstacles

} // namespace game
