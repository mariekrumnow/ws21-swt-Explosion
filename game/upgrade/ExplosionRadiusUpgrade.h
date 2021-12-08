//Autor Peter, Patrick, Marie

#ifndef BOMBERMAN_GAME_UPGRADE_EXPLOSIONRADIUSUPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_EXPLOSIONRADIUSUPGRADE_H

#include "../GameObject.h"
#include "../GameManager.h"
#include "../Player.h"
#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "Upgrade.h"

namespace game {
namespace upgrade {

/// Upgrade to increase the explosion radius of the player
class ExplosionRadiusUpgrade : public Upgrade {
public:
    /// Basically calls the constructor of GameObject
    ExplosionRadiusUpgrade();

    /// Creates a ExplosionRadiusUpgrade on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created upgrade or nullptr if an error occurred
    static ExplosionRadiusUpgrade* CreateExplosionRadiusUpgrade(int x, int y);

    /// Increases the explosion radius of the player, if possible, and removes the upgrade
    bool OnPlayerCollision(Player &player);

    /// Removes the upgrade from the map
    bool OnExplosion(GameObject& source);

    /// Returns the color of the upgrade
    virtual graphics::Color GetColor();

    /// Returns the shape of the upgrade
    virtual graphics::Tile GetTile();
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_EXPLOSIONRADIUSUPGRADE_H
