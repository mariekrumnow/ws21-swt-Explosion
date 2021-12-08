//Autor Peter, Patrick, Marie

#include "SpeedUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game{
namespace upgrade{
SpeedUpgrade::SpeedUpgrade() : Upgrade() {}

SpeedUpgrade* SpeedUpgrade::CreateSpeedUpgrade(int x, int y){
             SpeedUpgrade* temp = new SpeedUpgrade();
             if (temp!=nullptr){
                 GameManager::GetCurrentGame().AddGameObject(*temp);
                 if (!temp->SetPosition(x,y)) {
                     temp->Destroy();
                     return nullptr;
                 }
             }
             return temp;
}

bool SpeedUpgrade::OnPlayerCollision(Player& player) {
    this->Destroy();
    if(player.GetSpeed() < player.GetKMaxSpeed()){
        player.IncreaseSpeed(1);
    }
    return true;
}

bool SpeedUpgrade::OnExplosion(GameObject& source){
    this->Destroy();
    return false;
}

graphics::Color SpeedUpgrade::GetColor(){
    return graphics::Color(255,255,255,255);
}

graphics::Tile SpeedUpgrade::GetTile(){
    return graphics::kTileSpeedUpgrade;
}

} // namespace upgrade
} // namespace game
