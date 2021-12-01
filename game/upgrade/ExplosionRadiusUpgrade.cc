//Autor Peter, Patrick

#include "ExplosionRadiusUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game{
    namespace upgrade{
        ExplosionRadiusUpgrade::ExplosionRadiusUpgrade(int x, int y) : Upgrade {x, y} {

        }

        bool ExplosionRadiusUpgrade::OnPlayerCollision(Player& player) {
            GameManager::GetCurrentGame().RemoveGameObject(*this);
            if(player.GetExplosionRadius() <= player.GetKMaxExplosionRadius()){
                player.IncreaseExplosionRadius(1);
            }

            return true;
        }

        bool ExplosionRadiusUpgrade::OnExplosion(GameObject& source){
            GameManager::GetCurrentGame().RemoveGameObject(*this);
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