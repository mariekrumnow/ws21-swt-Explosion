// Autor: Peter, Nina, Tobias, Dennis

#ifndef BOMBERMAN_GAME_GAMEMANAGER_H
#define BOMBERMAN_GAME_GAMEMANAGER_H

namespace game {
    class Player;
}

#include <list>
#include <vector>

#include "../core/AppManager.h"
#include "win_condition/BaseWinCondition.h"
#include "GameObject.h"

namespace game {

/// manages the Objects of the current Game

class GameManager {
public:
    /// Initializes the map vectors used for object storage
    /// Deletes previous GameManager
    ///
    /// \param width width of the map
    /// \param height height of the map
    /// \param winCondition The condition for the game to end
    GameManager(const int width, const int height, win_condition::BaseWinCondition* winCondition);

    /// Destructor of GameManager
    /// Deletes all remainig GameObjects
    ~GameManager();

    /// Updates all GameObjects and checks if the Win condition is fulfilled
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);

    /// A Getter for the current GameManager
    ///
    /// \return A reference to the current game manager
    static GameManager& GetCurrentGame();

    /// Removes an object from the map
    ///
    /// \param game_object The GameObject that should be removed from the game
    void RemoveGameObject(GameObject& game_object);

    /// Removes an object from the map and adds it to the destroyed objects
    ///
    /// \param game_object The Gameobject that should be removed and deleted
    void DestroyGameObject(GameObject& game_object);

    /// Adds a new GameObject to the map
    ///
    /// \param game_object The new GameObject that needs to be added
    void AddGameObject(GameObject& game_object);

    /// Repositions a GameObject
    ///
    /// \param game_object The GameObject that changes its position
    /// \param x The new X-coordinate
    /// \param y The new Y-coordinate
    /// \return Whether the repositioning was successful
    bool ChangeObjectPosition(GameObject& game_object, int x, int y);

    /// A Getter for all GameObjects at a specific position
    ///
    /// \param x The X-coordinate of the searched GameObject
    /// \param y The Y-coordinate of the searched GameObject
    /// \return A reference to a vector of GameObjects that is at the coordinates (x,y)
    std::vector<GameObject*>& GetObjectsAtPos(int x, int y);

    /// A Getter for all GameObjects
    ///
    /// \return A vector of all GameObjects on the map
    std::vector<GameObject*> GetAllObjects();

    /// A Getter for the width of the Game map
    ///
    /// \return The width of the map
    int GetWidth() const;

    /// A Getter for the height of the Game map
    ///
    /// \return The height of the map
    int GetHeight() const;

    /// Removes a player from the player list
    ///
    /// \param player The Player that needs to be removed
    void RemovePlayer(Player &player);

    /// Adds a player to the player list
    ///
    /// \param player The Player that needs to be added
    void AddPlayer(Player* player);

    /// Get the player list
    ///
    /// \return A vector of all Players on the map
    std::vector<Player*> GetPlayers();

    /// Adds a DestructibleBlock to the destructible block count
    void AddDestructibleBlock();

    /// Removes a DestructibleBlock to the destructible block count
    void RemoveDestructibleBlock();

    /// A Getter for the destructible block count
    ///
    /// \return The amount of DestructibleBlocks on the map
    int GetDestructibleBlockCount();


private:
    std::vector<GameObject*>** objects_by_pos_; ///< A 2D array of vectors with every GameObject sorted by position on the map
    std::vector<GameObject*> empty_object_vector_; ///< The default object vector for oob positions
    std::list<GameObject*> destroyed_game_objects_; ///< A list of all GameObject that have been destroyed
    static GameManager* current_game_;  ///< A pointer to the current game manager
    win_condition::BaseWinCondition* win_condition_;    ///< The win condition on which manages the end of the game 

    std::vector<Player*> players_;  ///< A vector with references to all Players on the map
    int destructible_block_count_ = 0;  ///< The amount of DestructibleBlocks on the map

    int width_;  ///< The width of the map
    int height_; ///< The hight of the map
};

} // namespace game

#endif // BOMBERMAN_GAME_GAMEMANAGER_H
