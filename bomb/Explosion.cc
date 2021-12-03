//Autor: Marlene, Tobias, Marie

#include "Explosion.h"

#include "GameObject.h"
#include "GameManager.h"
#include "AppManager.h"
#include "Color.h"
#include "Tile.h"

namespace game {
namespace bomb {

    Explosion::Explosion() {
        timer_ = kExplosionDuration;
    }

    /// If a nullptr is returned, an error occured or the object couldn't be placed
    Explosion* Explosion::CreateExplosion(int x, int y){
          Explosion* temp = new Explosion();
          if (temp!=nullptr){
                if (!temp->SetPosition(x,y)) {
                      temp->Destroy();
                      return nullptr;
                }
                GameManager::GetCurrentGame().AddGameObject(*temp);
          }
          return temp;
    }

    Explosion::~Explosion() {}


    graphics::Tile Explosion::GetTile() {
        return graphics::kTileExplosion;
    }

    graphics::Color Explosion::GetColor() {
        return graphics::Color(255, 128, 0, 255);
    }

    void Explosion::Update(double delta_time) {
        GameManager& game = GameManager::GetCurrentGame();
        for(GameObject* go : game.GetObjectsAtPos(GetX(),GetY())) {
            go ->OnExplosion(*this);
        }

        timer_ -= delta_time;
        if (timer_ <= 0){
            delete this;
        }
    }

}   //namespace bomb
} //namespace game
