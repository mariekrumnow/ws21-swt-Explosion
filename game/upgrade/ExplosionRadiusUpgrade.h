//Autor Peter, Patrick

#ifndef BOMBERMAN_EXPLOSIONRADIUSUPGRADE_H
#define BOMBERMAN_EXPLOSIONRADIUSUPGRADE_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Upgrade.h"

namespace game {
    namespace upgrade {
        class ExplosionRadiusUpgrade : public Upgrade {
        public:
            ExplosionRadiusUpgrade();

            ~ExplosionRadiusUpgrade();

            bool OnPlayerCollision(Player &player);

            virtual graphics::Color GetColor();

            virtual graphics::Tile GetTile();
        };
    }
}

#endif //BOMBERMAN_EXPLOSIONRADIUSUPGRADE_H
