//Autor Peter, Patrick, Marie

#ifndef BOMBERMAN_GAME_UPGRADE_SPEEDUPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_SPEEDUPGRADE_H

#include "Upgrade.h"

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameObject.h"
#include "../Player.h"

namespace game {
namespace upgrade {

/// Upgrade to increase the speed of the player
class SpeedUpgrade : public Upgrade {
public:
    /// Basically calls the constructor of GameObject
    SpeedUpgrade();

    /// Creates a SpeedUpgrade on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created upgrade or nullptr if an error occurred
    static SpeedUpgrade* CreateSpeedUpgrade(int x, int y);

    /// Increases the speed of the player, if possible, and removes the upgrade
    bool OnPlayerCollision(Player& player);

    /// Removes the upgrade from the map
    bool OnExplosion(GameObject& source);

    /// Returns the color of the upgrade
    virtual graphics::Color GetColor();

    /// Returns the shape of the upgrade
    virtual graphics::Tile GetTile();
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_SPEEDUPGRADE_H
