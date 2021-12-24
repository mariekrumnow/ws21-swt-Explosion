// Autor: Nina, Marie

#include "IndestructibleBlock.h"

#include "../../graphics/Tile.h"
#include "../../graphics/Color.h"
#include "../GameManager.h"
#include "../GameObject.h"

namespace game {
namespace obstacles{

IndestructibleBlock::IndestructibleBlock() : Block() {}

IndestructibleBlock* IndestructibleBlock::CreateIndestructibleBlock(int x, int y) {
    IndestructibleBlock* temp = new IndestructibleBlock();
    if (temp!=nullptr) {
        GameManager::GetCurrentGame().AddGameObject(*temp);
        if (!temp->SetPosition(x,y)) {
            temp->Destroy();
            return nullptr;
        }
    }
    return temp;
}

bool IndestructibleBlock::OnExplosion(GameObject& source) {
    return true;
}

graphics::Tile IndestructibleBlock::GetTile() {
    return graphics::kTileSolidWall;
}

graphics::Color IndestructibleBlock::GetColor() {
    return graphics::Color(255,255,255,255);
}

} // namespace obstacles
} // namespace game
