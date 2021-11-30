//Autor Peter, Patrick

#include "BombCountUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game{
    namespace upgrade{
        BombCountUpgrade::BombCountUpgrade(int x, int y) : Upgrade {x, y} {

        }

        bool BombCountUpgrade::OnPlayerCollision(Player& player) {
            GameManager::GetCurrentGame().RemoveGameObject(*this);
            if(player.GetMaxBombCount() <= player.GetKMaxBombCount()){
                player.IncreaseMaxBombCount(1);
            }

            return true;
        }

        bool BombCountUpgrade::OnExplosion(GameObject& source){
            GameManager::GetCurrentGame().RemoveGameObject(*this);
            return true;
        }

        graphics::Color BombCountUpgrade::GetColor(){
            return graphics::Color(255,255,0,255);
        }

        graphics::Tile BombCountUpgrade::GetTile(){
            return graphics::kTileBombCountUpgrade;
        }
    }
}