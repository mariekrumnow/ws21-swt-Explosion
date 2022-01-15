// Autor: Nina, Tobias, Marie

#ifndef BOMBERMAN_GAME_GAMEOBJECT_H
#define BOMBERMAN_GAME_GAMEOBJECT_H

namespace game {
    class GameObject;
}

#include "../graphics/Color.h"
#include "../graphics/Tile.h"
#include "GameManager.h"

namespace game {

/// Abstract class of objects on the game map

class Player;

class GameObject {
public:

    /// Creates a GameObject
    GameObject();

    /// Destructor of GameObject
    ~GameObject();

    /// Called when the object interacts with an explosion
    ///
    /// \param source The source of the Explosion
    /// \return Whether this object blocks the explosion
    virtual bool OnExplosion(GameObject& source);

    /// Called when a player collides with this object
    ///
    /// \param player The Player that collides with this GameObject
    /// \return Whether this object blocks the movement
    virtual bool OnPlayerCollision(Player& player);

    /// Called when an object collides with this object
    ///
    /// \param source The GameObject that is colliding with this GameObject
    /// \return Whether this object blocks the movement
    virtual bool OnCollision(GameObject& source);

    /// Returns the objects graphic tile
    ///
    /// \return Graphics of the Explosion
    virtual graphics::Tile GetTile()=0;

    /// Returns the objects color
    ///
    /// \return Color of the Explosion
    virtual graphics::Color GetColor()=0;

    /// Called once a frame
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time)=0;

    /// A Getter for the X-coordinate of the GameObject
    ///
    /// \return The X-coordinate of the GameObject
    virtual int GetX();

    /// A Getter for the Y-coordinate of the GameObject
    ///
    /// \return The Y-coordinate of the GameObject
    virtual int GetY();

    /// Changes the Position of the GameObject
    ///
    /// \param x The new X-coordinate of the GameObject
    /// \param y The new Y-coordinate of the GameObject
    /// \return true if no collision occurred
    virtual bool SetPosition(int x, int y);

    /// Calls the DestroyGameObject method of GameManager
    virtual void Destroy();

private:
    int x_ = 0; ///< X-coordinate of the GameObject
    int y_ = 0; ///< Y-coordinate of the GameObject
    bool destroyed_ = false; ///< Tells if the GameObject is destroyed or not
};

} // namespace game


#endif // BOMBERMAN_GAME_GAMEOBJECT_H
