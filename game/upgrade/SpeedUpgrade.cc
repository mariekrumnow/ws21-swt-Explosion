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
        SpeedUpgrade::SpeedUpgrade() {

        }

        SpeedUpgrade::~SpeedUpgrade() {
            GameManager::GetCurrentGame().RemoveGameObject(*this);
        }

        bool SpeedUpgrade::OnPlayerCollision(Player& player) {
            if(player.GetSpeed() < player.GetKMaxSpeed()){
                player.IncreaseSpeed(1);
            }

            //delete this;

            return false;
        }

        graphics::Color SpeedUpgrade::GetColor(){
            return graphics::Color(255,255,0,255);
        }

        graphics::Tile SpeedUpgrade::GetTile(){
            return graphics::kTileSpeedUpgrade;
        }
    }
}