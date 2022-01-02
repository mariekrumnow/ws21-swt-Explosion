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

bool DestructibleBlock::OnExplosion(GameObject& source) {
    this->Destroy();

    if (rand()%100 < 35) {
        int rand_num = rand()%23;
        if (rand_num < 11) {
            upgrade::ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(GetX(), GetY());
        } else if (rand_num < 18) {
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
