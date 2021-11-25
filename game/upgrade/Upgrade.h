//Autor Peter, Patrick

#ifndef BOMBERMAN_UPGRADE_H
#define BOMBERMAN_UPGRADE_H

namespace game {
    namespace upgrade {
        class Upgrade;
    }
}

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game {
    namespace upgrade {
        class BombCountUpgrade;

        class ExplosionRadiusUpgrade;

        class SpeedUpgrade;

        class Upgrade : public GameObject {
        public:
            Upgrade();

            ~Upgrade();

            virtual bool OnCollision(GameObject& source);

            virtual bool OnExplosion(GameObject& source);

            virtual void Update(double delta_time);

            virtual graphics::Color GetColor() = 0;

            virtual graphics::Tile GetTile() = 0;
        };
    }
}

#endif //BOMBERMAN_UPGRADE_H
