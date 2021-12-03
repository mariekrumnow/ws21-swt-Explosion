//Autor Peter, Patrick, Marie

#include "ExplosionRadiusUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game{
    namespace upgrade{
        ExplosionRadiusUpgrade::ExplosionRadiusUpgrade() : Upgrade() {}

        /// If a nullptr is returned, an error occured or the object couldn't be placed
        ExplosionRadiusUpgrade* ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(int x, int y){
              ExplosionRadiusUpgrade* temp = new ExplosionRadiusUpgrade();
              if (temp!=nullptr){
                    GameManager::GetCurrentGame().AddGameObject(*temp);
                      if (!temp->SetPosition(x,y)) {
                            temp->Destroy();
                            return nullptr;
                      }
              }
              return temp;
        }

        bool ExplosionRadiusUpgrade::OnPlayerCollision(Player& player) {
            this->Destroy();
            if(player.GetExplosionRadius() <= player.GetKMaxExplosionRadius()){
                player.IncreaseExplosionRadius(1);
            }

            return true;
        }

        bool ExplosionRadiusUpgrade::OnExplosion(GameObject& source){
            this->Destroy();
            return false;
        }

        graphics::Color ExplosionRadiusUpgrade::GetColor(){
            return graphics::Color(255,255,0,255);
        }

        graphics::Tile ExplosionRadiusUpgrade::GetTile(){
            return graphics::kTileExplosionRadiusUpgrade;
        }
    }
}
