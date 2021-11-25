//Autor Peter, Patrick

#ifndef BOMBERMAN_SPEEDUPGRADE_H
#define BOMBERMAN_SPEEDUPGRADE_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Upgrade.h"


namespace game {
    namespace upgrade {
        class SpeedUpgrade : public Upgrade {
        public:
            SpeedUpgrade();

            ~SpeedUpgrade();

            bool OnPlayerCollision(Player &player);

            virtual graphics::Color GetColor();

            virtual graphics::Tile GetTile();
        };
    }
}

#endif //BOMBERMAN_SPEEDUPGRADE_H
