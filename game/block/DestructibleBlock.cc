// Autor: Nina, Marie

#include "DestructibleBlock.h"

#include <iostream>
#include <time.h>

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
        GameManager::GetCurrentGame().AddDestructibleBlock();
    }
    return temp;
}

bool DestructibleBlock::OnExplosion(GameObject& source) {
    this->Destroy();

    if (rand()%100 < 35) {
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

void DestructibleBlock::Destroy() {
    GameManager::GetCurrentGame().RemoveDestructibleBlock();
    this->GameObject::Destroy();
}

} // namespace obstacles
} // namespace game
