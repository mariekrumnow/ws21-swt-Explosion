//Autor Peter, Patrick, Marie

#include "BombCountUpgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../../sound/SoundEffect.h"

namespace game{
namespace upgrade{

BombCountUpgrade::BombCountUpgrade() : Upgrade() {}

BombCountUpgrade* BombCountUpgrade::CreateBombCountUpgrade(int x, int y){
    BombCountUpgrade* temp = new BombCountUpgrade();
    if (temp!=nullptr){
        GameManager::GetCurrentGame().AddGameObject(*temp);
        if (!temp->SetPosition(x,y)) {
            temp->Destroy();
            return nullptr;
        }
    }
    return temp;
}

bool BombCountUpgrade::OnPlayerCollision(Player& player) {
    core::AppManager::GetAppManager().GetSound()
        .PlaySoundEffect(sound::effect_upgrade_collect, 0);
    this->Destroy();
    if(player.GetMaxBombCount() <= player.GetKMaxBombCount()){
        player.IncreaseMaxBombCount(1);
    }
    return true;
}

bool BombCountUpgrade::OnExplosion(GameObject& source){
    this->Destroy();
    return false;
}

graphics::Color BombCountUpgrade::GetColor(){
    return graphics::Color(255,255,0,255);
}

graphics::Tile BombCountUpgrade::GetTile(){
    return graphics::kTileBombCountUpgrade;
}

} // namespace upgrade
} // namespace game
