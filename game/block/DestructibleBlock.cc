// Autor: Nina, Marie


#include <time.h>
#include <iostream>

#include "DestructibleBlock.h"

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../upgrade/BombCountUpgrade.h"
#include "../upgrade/ExplosionRadiusUpgrade.h"
#include "../upgrade/SpeedUpgrade.h"

namespace game {
namespace obstacles{

DestructibleBlock::DestructibleBlock() : Block() {}

DestructibleBlock* DestructibleBlock::CreateDestructibleBlock(int x, int y) {
    DestructibleBlock* temp = new DestructibleBlock();
    if (temp!=nullptr) {
        GameManager::GetCurrentGame().AddGameObject(*temp);
        if (!temp->SetPosition(x,y)) {
            temp->Destroy();
            return nullptr;
        }
    }
    return temp;
}


/* Block Drop Chancen:
* There are on average ~86 blocks in each round -> 0.85 * ((13*6 + 7*5) - 12)
* We want each player to gain max speed, and good enough bomb count and radius.
* So let's say 7 in each = 7*6 = 42 upgrade total, equally shared
* 86/42 ~= 0.49 = necessary drop chance.
*/

bool DestructibleBlock::OnExplosion(GameObject& source) {
    this->Destroy();

    if (rand()%100 < 49) {
        int rand_num = rand()%3;
        if (rand_num < 1) {
            upgrade::ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(GetX(), GetY());
        } else if (rand_num < 2) {
            upgrade::BombCountUpgrade::CreateBombCountUpgrade(GetX(), GetY());
        } else {
            upgrade::SpeedUpgrade::CreateSpeedUpgrade(GetX(), GetY());
        }
    }
    return true;
}

graphics::Tile DestructibleBlock::GetTile() {
    return graphics::kTileBrittleWall;
}

graphics::Color DestructibleBlock::GetColor() {
    return graphics::Color(255,255,255,255);
}

} // namespace obstacles
} // namespace game
