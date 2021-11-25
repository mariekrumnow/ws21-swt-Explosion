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
        BombCountUpgrade::BombCountUpgrade() {

        }

        BombCountUpgrade::~BombCountUpgrade() {
            GameManager::GetCurrentGame().RemoveGameObject(*this);
        }

        bool BombCountUpgrade::OnPlayerCollision(Player& player) {
            if(player.GetMaxBombCount() <= player.GetKMaxBombCount()){
                player.IncreaseMaxBombCount(1);
            }

            //delete this;

            return false;
        }

        graphics::Color BombCountUpgrade::GetColor(){
            return graphics::Color(255,255,0,255);
        }

        graphics::Tile BombCountUpgrade::GetTile(){
            return graphics::kTileBombCountUpgrade;
        }
    }
}