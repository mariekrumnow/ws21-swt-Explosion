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

/// abstract class of all Objects which are needed on the game map

class Player;

class GameObject {
public:

    /// Creates a GameObject
    GameObject();

    /// Destructor of GameObject
    ~GameObject();

    /// virtual method for the method OnExplosion
    ///
    /// \param source The source of the Explosion
    /// \return false
    virtual bool OnExplosion(GameObject& source);

    /// virtual method for the method OnPlayerCollision
    ///
    /// \param player The Player that collides with the GameObject
    /// \return false
    virtual bool OnPlayerCollision(Player& player);

    /// virtual method for the method OnCollision
    ///
    /// \param source The GameObject that is colliding with the GameObject
    /// \return false
    virtual bool OnCollision(GameObject& source);

    /// Pure virtual method for the method GetTile
    ///
    /// \return Graphics of the Explosion
    virtual graphics::Tile GetTile()=0;

    /// Pure virtual method for the method GetColor
    ///
    /// \return Color of the Explosion
    virtual graphics::Color GetColor()=0;

    /// Pure virtual method for the method Update
    ///
    /// \param delta_time The amount of time that has passed since last update
    virtual void Update(double delta_time)=0;

    /// A Getter for the X-coordinate of the GameObject
    ///
    /// \return The X-coordinate of the GameObject
    virtual int GetX();

    /// AW Getter for the Y-coordinate of the GameObject
    ///
    /// \return The Y-coordinate of the GameObject
    virtual int GetY();

    /// Changes the Position of the GameObject
    ///
    /// \param x The new X-coordinate of the GameObject
    /// \param y The new Y-coordinate of the GameObject
    /// \return true if no collision occurred
    virtual bool SetPosition(int x, int y);

    /// virtual method that calls the DestroyGameObject method of GameManager
    virtual void Destroy();

private:
    int x_ = 0; ///< Default X-coordinate of a new GameObject
    int y_ = 0; ///< Default Y-coordinate of a new GameObject
    bool destroyed_ = false; ///< Tells if the GameObject is destroyed or not
};

} // namespace game


#endif // BOMBERMAN_GAME_GAMEOBJECT_H
