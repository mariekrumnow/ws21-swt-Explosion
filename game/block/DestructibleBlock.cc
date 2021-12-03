//
// Autor: Nina, Marie
//

#include <time.h>

#include "Block.h"
#include "GameManager.h"
#include "DestructibleBlock.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

namespace obstacles{

    DestructibleBlock::DestructibleBlock(int x, int y) :
      Block {x,y}
    {}

    bool DestructibleBlock::OnExplosion(GameObject& source) {
          GameManager::GetCurrentGame().RemoveGameObject(*this);

          if (rand()%100 < 35) {
                int rand_num = rand()%23;
                if (rand_num < 11) {
                      //ExplosionRadiusUpgrade(x_,y_);
                } else if (rand_num < 18) {
                      //BombCountUpgrade(x_,y_);
                } else {
                      //SpeedUpgrade(x_,y_);
                }
          }

          return true;
    }

    graphics::Tile DestructibleBlock::GetTile() {
          return graphics::kTileBrittleWall;
    }

    graphics::Color DestructibleBlock::GetColor() {
          return graphics::Color(169, 169, 169, 255);
    }

} // namespace obstacles

} // namespace game