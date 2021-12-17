//Autor Peter, Patrick, Marie

#include "BombCountUpgrade.h"

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../GameObject.h"
#include "../Player.h"


namespace game{
namespace upgrade{

BombCountUpgrade::BombCountUpgrade() : Upgrade() {}

BombCountUpgrade* BombCountUpgrade::CreateBombCountUpgrade(int x, int y) {
    BombCountUpgrade* temp = new BombCountUpgrade();
    if (temp!=nullptr) {
        GameManager::GetCurrentGame().AddGameObject(*temp);
        if (!temp->SetPosition(x,y)) {
            temp->Destroy();
            return nullptr;
        }
    }
    return temp;
}

bool BombCountUpgrade::OnPlayerCollision(Player& player) {
    this->Destroy();
    if (player.GetMaxBombCount() <= player.GetKMaxBombCount()) {
        player.IncreaseMaxBombCount(1);
    }
    return true;
}

bool BombCountUpgrade::OnExplosion(GameObject& source){
    this->Destroy();
    return false;
}

graphics::Color BombCountUpgrade::GetColor(){
    return graphics::Color(255,255,255,255);
}

graphics::Tile BombCountUpgrade::GetTile(){
    return graphics::kTileBombCountUpgrade;
}

} // namespace upgrade
} // namespace game
