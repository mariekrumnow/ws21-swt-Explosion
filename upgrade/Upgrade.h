//Autor Peter, Patrick

#ifndef BOMBERMAN_GAME_UPGRADE_UPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_UPGRADE_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"

namespace game {
    namespace upgrade {

        /// Abstract class to represent all the different upgrades
        class Upgrade : public GameObject {
        public:
            /// Calls the constructor of GameObject
            Upgrade();

            /// ???
            virtual bool OnCollision(GameObject& source);

            virtual bool OnPlayerCollision(Player& player) = 0;

            virtual bool OnExplosion(GameObject& source) = 0;

            /// Overwrites virtual function of GameObject
            virtual void Update(double delta_time);

            virtual graphics::Color GetColor() = 0;

            virtual graphics::Tile GetTile() = 0;
        };
    }
}

#endif //BOMBERMAN_UPGRADE_H
