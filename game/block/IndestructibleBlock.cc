//
// Autor: Nina, Marie
//

#include "Block.h"
#include "IndestructibleBlock.h"
#include "../../graphics/Tile.h"
#include "../../graphics/Color.h"

namespace game {
namespace obstacles{

    IndestructibleBlock::IndestructibleBlock() : Block() {}

    IndestructibleBlock* IndestructibleBlock::CreateIndestructibleBlock(int x, int y){
          IndestructibleBlock* temp = new IndestructibleBlock();
          if (temp!=nullptr){
                GameManager::GetCurrentGame().AddGameObject(*temp);
                if (!temp->SetPosition(x,y)) {
                      temp->Destroy();
                      return nullptr;
                }
          }
          return temp;
    }

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
