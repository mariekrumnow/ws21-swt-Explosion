//Autor Peter, Patrick, Marie

#ifndef BOMBERMAN_GAME_UPGRADE_SPEEDUPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_SPEEDUPGRADE_H

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameObject.h"
#include "../Player.h"
#include "Upgrade.h"

namespace game {
namespace upgrade {

/// Upgrade to increase the speed of the player
class SpeedUpgrade : public Upgrade {
public:
    /// Calls the constructor of GameObject
    SpeedUpgrade();

    /// Creates a SpeedUpgrade on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created upgrade or nullptr if an error occurred
    static SpeedUpgrade* CreateSpeedUpgrade(int x, int y);

    /// Called when a Player collides with the upgrade
    /// Increases the speed of the Player, if possible, and removes the upgrade
    ///
    /// \param player The Player that collides with the Upgrade
    /// \return Whether the movement is blocked (false)
    bool OnPlayerCollision(Player& player);

    /// Called when an Explosion interacts with the upgrade
    /// Removes the Upgrade from the map
    ///
    /// \param source The origin of the Explosion
    /// \return Whether the explosion is stopped (false)
    bool OnExplosion(GameObject& source);

    /// Returns the color of the Upgrade
    ///
    /// \return Graphics of the Upgrade
    virtual graphics::Color GetColor();

    /// Returns the tile of the Upgrade
    ///
    /// \return Color of the Entity
    virtual graphics::Tile GetTile();
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_SPEEDUPGRADE_H
