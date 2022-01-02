//Autor Peter, Patrick, Marie

#include "ExplosionRadiusUpgrade.h"

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../GameObject.h"
#include "../Player.h"
#include "../../sound/SoundEffect.h"

namespace game{
namespace upgrade{

ExplosionRadiusUpgrade::ExplosionRadiusUpgrade() : Upgrade() {}

ExplosionRadiusUpgrade* ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(int x, int y) {
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
    core::AppManager::GetAppManager().GetSound()
         .PlaySoundEffect(sound::effect_upgrade_collect, 0);
    this->Destroy();
    if (player.GetExplosionRadius() <= player.GetKMaxExplosionRadius()) {
        player.IncreaseExplosionRadius(1);
    }

    return true;
}

bool ExplosionRadiusUpgrade::OnExplosion(GameObject& source) {
    this->Destroy();
    return false;
}

graphics::Color ExplosionRadiusUpgrade::GetColor(){
    return graphics::Color(255,255,255,255);
}

graphics::Tile ExplosionRadiusUpgrade::GetTile(){
    return graphics::kTileExplosionRadiusUpgrade;
}

} // namespace upgrade
} // namespace game
