//Autor: Marlene, Tobias, Marie, Carla, Nina

#include "Explosion.h"

#include <iostream>

#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../GameObject.h"

namespace game {
namespace bomb {

Explosion::Explosion() {
    timer_ = kExplosionDuration;
}

int Explosion::GetOrientation(){
    return orientation_;
}

/// \brief If a nullptr is returned, an error occured or the object couldn't be placed
Explosion* Explosion::CreateExplosion(int x, int y, int oriented) {
    Explosion* temp = new Explosion();
    if (temp!=nullptr) {
        GameManager::GetCurrentGame().AddGameObject(*temp);
        temp->orientation_=oriented;

        if (!temp->SetPosition(x,y)) {
            temp->Destroy();
            return nullptr;
        }
    }
    return temp;
}

Explosion::~Explosion() {}

/// defines witch Tile of an Explosion is correct to be drawn
graphics::Tile Explosion::GetTile() {
    switch(orientation_) {
        case 0 :
            return graphics::kTileExplosionVertical;
            break;
        case 1 :
            return graphics::kTileExplosionHorizontal;
            break;
        case 2 :
            return graphics::kTileExplosionVertical;
            break;
        case 3 :
            return graphics::kTileExplosionHorizontal;
            break;
        case 4 :
            return graphics::kTileExplosionDown;
            break;
        case 5 :
            return graphics::kTileExplosionRight;
            break;
        case 6 :
            return graphics::kTileExplosionUp;
            break;
        case 7 :
            return graphics::kTileExplosionLeft;
            break;
        case 10 :
            return graphics::kTileExplosionMiddle;
            break;
        default :
            return graphics::kTileEmpty;
    }
}

graphics::Color Explosion::GetColor() {
    return graphics::Color(255,255,255,255);
}

void Explosion::Update(double delta_time) {
    GameManager& game = GameManager::GetCurrentGame();
    for(GameObject* go : game.GetObjectsAtPos(GetX(),GetY())) {
        go->OnExplosion(*this);
    }

    timer_ -= delta_time;
    if (timer_ <= 0) {
        Destroy();
    }
}

} // namespace bomb
} // namespace game
