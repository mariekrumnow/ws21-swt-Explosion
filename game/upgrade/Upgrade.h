//Autor Peter, Patrick

#ifndef BOMBERMAN_GAME_UPGRADE_UPGRADE_H
#define BOMBERMAN_GAME_UPGRADE_UPGRADE_H

#include "../GameObject.h"

namespace game {
namespace upgrade {

/// Abstract class to represent all the different upgrades
class Upgrade : public GameObject {
public:
    /// Calls the constructor of GameObject
    Upgrade();

    /// Called when an object collides with the upgrade
    ///
    /// \param source The object that is colliding with the Upgrade
    /// \return Whether the movement is blocked (false)
    virtual bool OnCollision(GameObject& source);

    /// Called when an object interacts with an explosion
    ///
    /// \param source The origin of the Explosion
    /// \return Whether the explosion is blocked (false)
    virtual bool OnExplosion(GameObject& source);

    /// Implementation of virtual function of GameObject
    /// Called once per frame, does nothing
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time);
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_UPGRADE_H
