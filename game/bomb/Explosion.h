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
    /// \param oriented The Explosions tile (0-10)
    /// \return A reference to the new Explosion, or nullptr on error
    static Explosion* CreateExplosion(int x, int y,int oriented);

    /// Destructor of Explosion
    ~Explosion();

    /// Returns Tile of the Explosion
    ///
    /// \return Tile of the Explosion
    graphics::Tile GetTile() override;

    /// Returns Color of the Explosion
    ///
    /// \return Color of the Explosion
    graphics::Color GetColor() override;

    /// Called once per frame
    /// Updates the time left until the Explosion is over
    ///
    /// \param delta_time
    void Update(double delta_time) override;

    /// Called when an object collides with the explosion
    ///
    /// \param source The origin of the Explosion
    /// \return Whether the explosion stops the object (true)
    virtual bool OnCollision(GameObject& source);

    /// A Getter for the orientation variable
    ///
    /// \return The orientation of the Explosion
    int GetOrientation();

    const double kExplosionDuration = 0.5; ///< The duration of the Explosion

private:
    double timer_;  ///< The time left till the Explosion is over
    int orientation_;   ///< Which directional tile the explosion should be displayed with
};

}  // namespace bomb
}  // namespace game

#endif // BOMBERMAN_GAME_BOMB_EXPLOSION_H
