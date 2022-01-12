// Autor: Peter, Nina, Tobias, Marie, Carla, Dennis

#ifndef BOMBERMAN_GAME_PLAYER_H
#define BOMBERMAN_GAME_PLAYER_H

#include <iostream>
#include <vector>

#include "../graphics/Color.h"
#include "../graphics/Keys.h"
#include "../graphics/Tile.h"
#include "GameManager.h"
#include "GameObject.h"

namespace game {

namespace bomb { class Bomb;}

/// The Player object

class Player : public GameObject {
public:

    /// Sets the PlayerKeys, the shape of the Player and its id
    ///
    /// \param id The number of the Player
    Player(graphics::PlayerKeys, graphics::PlayerTile, int id);

    /// Creates a new Player
    ///
    /// \param x The X-coordinate where the Player should spawn
    /// \param y The Y-coordinate where the Player should spawn
    /// \param keys The controls of the Player
    /// \param tiles The graphics of the Player
    /// \param id  The id of the Player
    /// \return A pointer to the new Player, or nullptr on error
    static Player* CreatePlayer(int x, int y, graphics::PlayerKeys keys,
                                graphics::PlayerTile tiles, int id);

    /// Destructor of Player
    ~Player();

    /// Increases the Players speed
    ///
    /// \param value How much the speed should increase
    void IncreaseSpeed(int value);

    /// Increases the players explosion radius
    ///
    /// \param value How much the explosion radius should increase
    void IncreaseExplosionRadius(int value);

    /// Increases the players max bomb count
    ///
    /// \param value How much the max bomb count should increase
    void IncreaseMaxBombCount(int value);

    /// Reduces the amount of owned bombs
    ///
    /// \param bomb The Bomb that has been destroyed
    void OnBombDestroyed(bomb::Bomb& bomb);

    /// Called once per frame
    /// Handles player movement
    ///
    /// \param delta_time The time since the last frame
    void Update(double delta_time);

    /// Called when the player interacts with an explosion
    /// Destroys the player
    ///
    /// \param source The source of the explosion
    /// \return Whether the explosion has been blocked
    bool OnExplosion(GameObject& source);

    /// Returns, that an Object can pass the Player
    ///
    /// \param source The GameObject that collides with the Player
    /// \return false
    bool OnCollision(GameObject& source);

    /// A Getter for the current time the player waits after moving till moving again
    ///
    /// \return The current move timer
    double GetCurrentMovementTimer();

    /// A Getter for the current speed of the Player
    ///
    /// \return The current speed of the Player
    int GetSpeed() const;

    /// A Getter for the current explosion radius for the Bombs placed by this Player
    ///
    /// \return The current explosion radius of the Player
    int GetExplosionRadius() const;

    /// A Getter for the amount of Bombs a Player can place at a time
    ///
    /// \return The current max bomb count of the Player
    int GetMaxBombCount() const;

    /// A Getter for the amount of existing Bombs by the Player
    ///
    /// \return The current amount of placed bombs from the Player
    int GetOwnedBombs() const;

    /// A Getter for the maximum value for the attribute explosion_radius_
    ///
    /// \return The max explosion radius
    int GetKMaxExplosionRadius() const;

    /// A Getter for the maximum value for the attribute max_bomb_count_
    ///
    /// \return The max bomb count
    int GetKMaxBombCount() const;

    /// A Getter for the maximum value for the attribute speed_
    ///
    /// \return The max speed
    int GetKMaxSpeed() const;

    /// A Getter for the id of the Player
    ///
    /// \return The id of the Player
    int GetId() const;

    /// A Getter for the matching Tile of the players orientation
    ///
    /// \return Tile of the Player
    graphics::Tile GetTile();

    /// A Getter for the color of the Player
    ///
    /// \return Color of the Player
    graphics::Color GetColor();

    /// A Getter for all Tiles of the Player
    ///
    /// \return Tileset of the Player
    graphics::PlayerTile GetTileset();

private:
    /// Places a Bomb
    ///
    /// \param x The X-coordinate of the new bomb
    /// \param y The Y-coordinate of the new bomb
    /// \return Whether an error occurred
    bool PlaceBomb(int x,int y);

    /// Changes the position of the Player
    /// Verifies via OnPlayerCollision if any object blocks the movement
    ///
    /// \param x The new X-coordinate of the GameObject
    /// \param y The new Y-coordinate of the GameObject
    /// \return true if no collision occurred
    bool SetPosition(int x, int y);

    int explosion_radius_ = 1; ///< The current explosion radius of placed Bombs
    int max_bomb_count_ = 1; ///< The amount of Bombs a Player can place, at a time
    int speed_ = 0; ///< The speed of the Player
    int owned_bombs_ = 0; ///< The amount of existing Bombs from the Player
    const int kMaxExplosionRadius = 10; ///< The max. value of the explosion radius
    const int kMaxMaxBombCount = 10; ///< The max. value of max bomb count
    const int kMaxSpeed = 7; ///< The max. value of speed

    int orientation_ = 1; ///< The way the Player faces
    int id_; ///< The id of the Player

    double move_timer_ = 0;  ///< timer till player can move again
    const double kMaxMoveTimer = 0.4; ///< The max. value of move timer
    const double kMinMoveTimer = 0.1; ///< The min. value of move timer

    graphics::PlayerKeys keys_; ///< keys used to control the Player
    graphics::PlayerTile tiles_; ///< tiles of the Player

};

} // namespace game

#endif // BOMBERMAN_GAME_PLAYER_H
