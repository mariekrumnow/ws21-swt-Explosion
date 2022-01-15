//Autor Peter, Patrick, Marie

#ifndef BOMBERMAN_GAME_UPGRADE_BOMBCOUNTUPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_BOMBCOUNTUPGRADE_H

#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameObject.h"
#include "../Player.h"
#include "Upgrade.h"

namespace game {
namespace upgrade {

/// Upgrade to increase the bomb count of the player
class BombCountUpgrade : public Upgrade {
    public:
    /// Calls the constructor of GameObject
    BombCountUpgrade();

    /// Creates a BombCountUpgrade on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created upgrade or nullptr if an error occurred
    static BombCountUpgrade* CreateBombCountUpgrade(int x, int y);

    /// Called when a player collides with the upgrade
    /// Increases the max bomb count of the Player, if possible, and removes the upgrade
    ///
    /// \param player The Player that collides with the Upgrade
    /// \return Whether the upgrade blocks the movement (false)
    bool OnPlayerCollision(Player& player);

    /// Called when an explosion interacts with the upgrade
    /// Removes the Upgrade from the map
    ///
    /// \param source The origin of the Explosion
    /// \return Whether the explosion is stopped (false)
    bool OnExplosion(GameObject& source);

    /// Returns the color of the Upgrade
    ///
    /// \return Color of the Entity
    virtual graphics::Color GetColor();

    /// Returns the shape of the Upgrade
    ///
    /// \return Graphics of the Upgrade
    virtual graphics::Tile GetTile();
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_BOMBCOUNTUPGRADE_H
