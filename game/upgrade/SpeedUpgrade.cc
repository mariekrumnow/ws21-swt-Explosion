//Autor Peter, Patrick

#include "SpeedUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game{
    namespace upgrade{
        SpeedUpgrade::SpeedUpgrade(int x, int y) : Upgrade {x, y} {

        }

        bool SpeedUpgrade::OnPlayerCollision(Player& player) {
            GameManager::GetCurrentGame().RemoveGameObject(*this);
            if(player.GetSpeed() < player.GetKMaxSpeed()){
                player.IncreaseSpeed(1);
            }

            return true;
        }

        bool SpeedUpgrade::OnExplosion(GameObject& source){
            GameManager::GetCurrentGame().RemoveGameObject(*this);
            return true;
        }

        graphics::Color SpeedUpgrade::GetColor(){
            return graphics::Color(255,255,0,255);
        }

        graphics::Tile SpeedUpgrade::GetTile(){
            return graphics::kTileSpeedUpgrade;
        }
    }
}