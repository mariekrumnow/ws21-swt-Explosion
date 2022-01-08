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

/// Class of the Player

class Player : public GameObject {
public:

    /// Sets the PlayerKeys, the shape of the Player and its Id
    ///
    /// \param id The number of the Player
    Player(graphics::PlayerKeys, graphics::PlayerTile, int id);

    /// Creates a new Player
    ///
    /// \param x The X-coordinate where the Player needs to spawn
    /// \param y The Y-coordinate where the Player needs to spawn
    /// \param keys The controls of the Player
    /// \param tiles The graphics of the Player
    /// \param id  The number of the Player
    /// \return A pointer to the new Player
    static Player* CreatePlayer(int x, int y, graphics::PlayerKeys keys,
                                graphics::PlayerTile tiles, int id);

    /// Destructor of Player
    ~Player();

    /// Increases the Players speed_
    ///
    /// \param value How much the speed has to grow
    void IncreaseSpeed(int value);

    /// Increases the players explosion_radius_
    ///
    /// \param value How much the explosion radius has to grow
    void IncreaseExplosionRadius(int value);

    /// Increases the players max_bomb_count_
    ///
    /// \param value How much the max bomb count has to grow
    void IncreaseMaxBombCount(int value);

    /// Reduces the amount of owned_bombs_
    ///
    /// \param bomb The Bomb that has been destroyed
    void OnBombDestroyed(bomb::Bomb& bomb);

    /// Updates move_timer_ and checks if a key is pressed at the moment
    /// If a Key is pressed it moves the Player in the matching direction
    ///
    /// \param delta_time The X-coordinate where the Player needs to spawn
    void Update(double delta_time);

    /// Removes the Player from the Current Game
    ///
    /// \param source The source of the explosion
    /// \return false
    bool OnExplosion(GameObject& source);

    /// Returns, that an Object can pass the Player
    ///
    /// \param source The GameObject that collides with the Player
    /// \return false
    bool OnCollision(GameObject& source);

    /// A Getter for the current time, the player needs, to be able to move again
    ///
    /// \return The current move timer
    double GetCurrentMovementTimer();

    /// A Getter for the current speed of the Player
    ///
    /// \return The current speed of the Player
    int GetSpeed() const;

    /// A Getter for the current explosion radius of the Bombs placed by this Player
    ///
    /// \return The current explosion radius of the Player
    int GetExplosionRadius() const;

    /// A Getter for the amount of Bombs a Player can place at a time
    ///
    /// \return The current max bomb count of the Player
    int GetMaxBombCount() const;

    /// A Getter for the amount of existing Bombs placed by the Player
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

    /// A Getter for the number of the Player
    ///
    /// \return The number of the Player
    int GetId() const;

    /// A Getter for the matching Tile of the players orientation
    ///
    /// \return Graphics of the Player
    graphics::Tile GetTile();

    /// A Getter for the color of the Player
    ///
    /// \return Color of the Player
    graphics::Color GetColor();

    /// A Getter for the Graphic-set of the Player
    ///
    /// \return Graphic-set of the Player
    graphics::PlayerTile GetTileset();

private:
    /// The Player places a Bomb at its current position
    ///
    /// \param x The X-coordinate of the new bomb
    /// \param y The Y-coordinate of the new bomb
    /// \return true if no error occurred
    bool PlaceBomb(int x,int y);

    /// Changes the position of the Player
    /// Verifies via OnPlayerCollision if the Position is free
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
    int id_; ///< The number of the Player

    double move_timer_ = 0;  ///< timer till player can move again
    const double kMaxMoveTimer = 0.4; ///< The max. value of move timer
    const double kMinMoveTimer = 0.1; ///< The min. value of move timer

    graphics::PlayerKeys keys_; ///< controls of the Player
    graphics::PlayerTile tiles_; ///< graphics of the Player

};

} // namespace game

#endif // BOMBERMAN_GAME_PLAYER_H
