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

    /// Virtual method for the method OnCollision()
    ///
    /// \param source The entity that is colliding with the Upgrade
    /// \return false
    virtual bool OnCollision(GameObject& source);

    /// Virtual method for the method OnExplosion()
    ///
    /// \param source The origin of the Explosion
    /// \return false
    virtual bool OnExplosion(GameObject& source);

    /// Overwrites virtual function of GameObject
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time);
};

} // namespace upgrade
} // namespace game

#endif //BOMBERMAN_UPGRADE_H
