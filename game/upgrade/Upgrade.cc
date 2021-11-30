//Autor Peter, Patrick

#include "Upgrade.h"

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game {
    namespace upgrade{
        Upgrade::Upgrade(int x, int y) : GameObject {x, y}{

        }

        void Upgrade::Update(double delta_time){

        }

        bool Upgrade::OnCollision(GameObject& source){
            return true;
        }

    }
}