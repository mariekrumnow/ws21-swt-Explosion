//Autor Peter, Patrick, Marie

#include "SpeedUpgrade.h"

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../GameObject.h"
#include "../Player.h"
// #include "../../sound/SoundEffect.h"

namespace game{
namespace upgrade{

SpeedUpgrade::SpeedUpgrade() : Upgrade() {}

SpeedUpgrade* SpeedUpgrade::CreateSpeedUpgrade(int x, int y) {
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
    // core::AppManager::GetAppManager().GetSound()
    //     .PlaySoundEffect(sound::effect_upgrade_collect, 0);
    this->Destroy();
    if (player.GetSpeed() < player.GetKMaxSpeed()) {
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
