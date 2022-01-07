// Autor: Marlene, Marie, Carla, Nina

#ifndef BOMBERMAN_GAME_BOMB_EXPLOSION_H
#define BOMBERMAN_GAME_BOMB_EXPLOSION_H

#include "../../core/AppManager.h"
#include "../../graphics/Color.h"
#include "../../graphics/Tile.h"
#include "../GameObject.h"
#include "../GameManager.h"



namespace game {
namespace bomb {

/// The appearance of the Explosion

class Explosion : public GameObject {
public:
    /// Sets the timer for the Explosion duration
    Explosion();

    /// Creates a new Explosion and spawns it in the game
    ///
    /// \param x The X-coordinate of the new Explosion
    /// \param y The Y-coordinate of the new Explosion
    /// \param oriented The way the Explosion is steered
    /// \return A reference to the new Explosion
    static Explosion* CreateExplosion(int x, int y,int oriented);

    /// Deconstructor of Explosion
    ~Explosion();

    /// Returns Graphics of the Explosion
    ///
    /// \return Graphics of the Explosion
    graphics::Tile GetTile();

    /// Returns Color of the Explosion
    ///
    /// \return Color of the Explosion
    graphics::Color GetColor();

    /// Updates the time left until the Explosion is over
    ///
    /// \param delta_time Color of the Explosion
    void Update(double delta_time);

    ///
    ///
    /// \param source The origin of the Explosion
    /// \return true
    virtual bool OnCollision(GameObject& source);

    /// A Getter for the orientation variable
    ///
    /// \return The orientation of the Explosion
    int GetOrientation();

private:
    double timer_;  ///< The time left till teh Explosion is over
    int orientation_;   ///< The way the Explosion is steered
};

}  // namespace bomb
}  // namespace game

#endif // BOMBERMAN_GAME_BOMB_EXPLOSION_H
