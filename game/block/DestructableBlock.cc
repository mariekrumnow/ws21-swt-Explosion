//
// Autor: Nina, Marie
//

#include <time.h>

#include "Block.h"
#include "GameManager.h"
#include "DestructableBlock.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"

namespace game {

    DestructableBlock::DestructableBlock(int x, int y) :
      Block {x,y}
    {}

    bool DestructableBlock::OnExplosion(GameObject& source) {
          //GameManager::RemoveGameObject(*this);

          srand(time(0));
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

    graphics::Tile DestructableBlock::GetTile() {
          return graphics::kTileBrittleWall;
    }

    graphics::Color DestructableBlock::GetColor() {
          return graphics::Color(169, 169, 169, 255);
    }

}// namespace game
