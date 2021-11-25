//Autor Peter, Patrick

#ifndef BOMBERMAN_BOMBCOUNTUPGRADE_H
#define BOMBERMAN_BOMBCOUNTUPGRADE_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Upgrade.h"


namespace game {
    namespace upgrade {
        class BombCountUpgrade : public Upgrade {
        public:
            BombCountUpgrade();

            ~BombCountUpgrade();

            bool OnPlayerCollision(Player &player);

            virtual graphics::Color GetColor();

            virtual graphics::Tile GetTile();
        };
    }
}

#endif //BOMBERMAN_BOMBCOUNTUPGRADE_H
