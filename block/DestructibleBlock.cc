//
// Autor: Nina, Marie
//

#include <time.h>

#include "Block.h"
#include "GameManager.h"
#include "DestructibleBlock.h"
#include "../graphics/Tile.h"
#include "../graphics/Color.h"
#include "../game/upgrade/ExplosionRadiusUpgrade.h"
#include "../game/upgrade/BombCountUpgrade.h"
#include "../game/upgrade/SpeedUpgrade.h"

namespace game {

namespace obstacles{

    DestructibleBlock::DestructibleBlock() : Block() {}

    /// If a nullptr is returned, an error occured or the object couldn't be placed
    DestructibleBlock* DestructibleBlock::CreateDestructibleBlock(int x, int y){
          DestructibleBlock* temp = new DestructibleBlock();
          if (temp!=nullptr){
                if (!temp->SetPosition(x,y)) {
                      temp->Destroy();
                      return nullptr;
                }
                GameManager::GetCurrentGame().AddGameObject(*temp);
          }
          return temp;
    }

    bool DestructibleBlock::OnExplosion(GameObject& source) {
          this->Destroy();

          if (rand()%100 < 35) {
                int rand_num = rand()%23;
                if (rand_num < 11) {
                      upgrade::ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(GetX(), GetY());
                } else if (rand_num < 18) {
                      upgrade::BombCountUpgrade::CreateBombCountUpgrade(GetX(), GetY());
                } else {
                      upgrade::SpeedUpgrade::CreateSpeedUpgrade(GetX(), GetY());
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
