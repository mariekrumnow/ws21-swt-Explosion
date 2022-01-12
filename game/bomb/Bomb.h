// Autor: Tobias, Marie, Carla, Nina

#ifndef BOMBERMAN_GAME_BOMB_BOMB_H
#define BOMBERMAN_GAME_BOMB_BOMB_H

#include <cmath>
#include <iostream>

#include "../../graphics/Tile.h"
#include "../GameManager.h"
#include "../GameObject.h"
#include "../Player.h"
#include "Explosion.h"

namespace game {
namespace bomb {


/// A Bomb that can be placed by a Player and explodes after a determined time
class Bomb : public GameObject{

public:
    /// Assigns the parameters to Variables
    ///
    /// \param owner The Player that placed the bomb
    /// \param power The explosion radius of the owner
    /// \param explosion_delay Time that has to pass till it explodes
	Bomb(Player* owner, int power, double explosion_delay);

    /// Creates a Bomb and plays the matching Sound
    ///
    /// \param x The X-coordinate of the Bomb
    /// \param y The Y-coordinate of the Bomb
    /// \param owner The Player that placed the bomb (can be nullptr)
    /// \param power The explosion radius of the bomb
    /// \param explosion_delay Time that has to pass till it explodes
    /// \return A reference to the new Bomb, or nullptr if the placement failed
	static Bomb* CreateBomb(int x, int y, Player* owner, int power, double explosion_delay);

    /// Destructor of Bomb
	~Bomb();

    /// Detects the owner of the Bomb
    ///
    /// \return A reference of the Player that placed the Bomb
	Player* GetOwner();

    /// Called when an Explosion interacts with the bomb
    /// Calls the method Explode() if the bomb isn't exploding
    ///
    /// \param source The source of the Explosion
    /// \return Whether the bomb stops the propagation of the explosion
	virtual bool OnExplosion(GameObject& source);

    /// Called when an object collides with the bomb
	/// Returns true if the bomb isn't exploding
    ///
    /// \param source The other Entity that is Colliding with this one
    /// \return Whether the bomb stops the object
	virtual bool OnCollision(GameObject& source);

    /// Returns color of the Bomb
    ///
    /// \return Graphics of the Bomb
	graphics::Tile GetTile();

    /// Returns color of the Bomb
    ///
    /// \return Color of the Entity
	graphics::Color GetColor();

    /// Reduce explosion_timer_ and if its <=0 then calls the function Explode()
    ///
    /// \param delta_time The amount of time that has passed since last update
	void Update(double delta_time);

private:
    /// Spawns an Explosion on the tile of the bomb and the tiles next to it
    void Explode();

    /// Calls CreateExplosion and checks if it failed
    ///
    /// \param x The X-coordinate of the new Explosion-Tile
    /// \param y The Y-coordinate of the new Explosion-Tile
    /// \param oriented The way the Explosion is steered
    /// \return true if no error has occured
    bool SpawnExplosion(int x, int y, int oriented);

	Player* owner_; ///< The Player that placed the Bomb
	int power_; ///< The explosion radius of the Player that placed the Bomb
	double explosion_timer_; ///< The time left till exploding
	bool exploding_; ///< so the bomb can't explode multiple times
};

}
}
#endif // BOMBERMAN_GAME_BOMB_BOMB_H
