// Autor: Peter, Nina, Tobias, Dennis

#ifndef BOMBERMAN_GAME_GAMEMANAGER_H
#define BOMBERMAN_GAME_GAMEMANAGER_H

#include <list>
#include <vector>

namespace game {
    class Player;
}

#include "GameObject.h"
#include "../core/AppManager.h"
#include "win_condition/BaseWinCondition.h"

namespace game {

/// manages the Objects of the current Game

class GameManager {
public:
    GameManager(const int width, const int height, win_condition::BaseWinCondition* winCondition);
    ~GameManager();

    /// Updates all GameObjects and checks if the Win condition is fulfilled
    ///
    /// \param delta_time The amount of time that has passed since last update
    void Update(double delta_time);
    static GameManager& GetCurrentGame();

    /// removes an object from the map
    ///
    /// \param game_object The GameObject that should be removed from the game
    void RemoveGameObject(GameObject& game_object);

    /// removes an object from the map and adds it to the destroyed objects
    ///
    /// \param game_object The Gameobject that should be removed and deleted
    void DestroyGameObject(GameObject& game_object);

    ///
    /// \param game_object The new GameObject that needs to be added
    void AddGameObject(GameObject& game_object);

    /// returns false if position isn't valid
    ///
    /// \param game_object The GameObject that changes his position
    /// \param x The new X-coordinate
    /// \param y The new Y-coordinate
    /// \return true if no error occured
    bool ChangeObjectPosition(GameObject& game_object, int x, int y);

    /// A Getter for all GameObjects at a specific position
    ///
    /// \param x The X-coordinate of the searched GameObject
    /// \param y The Y-coordinate of the searched GameObject
    /// \return A reference to the GameObject that is at the coordinates (x,y)
    std::vector<GameObject*>& GetObjectsAtPos(int x, int y);

    /// A Getter for all GameObjects
    ///
    /// \return A vector of all GameObjects on the map
    std::vector<GameObject*> GetAllObjects();

    /// A Getter for the width of the Game map
    ///
    /// \return The width of the map
    int GetWidth() const;
    int GetHeight() const;

    void RemovePlayer(Player &player);
    void AddPlayer(Player* player);
    std::vector<Player*> GetPlayers();

    void AddDestructibleBlock();
    void RemoveDestructibleBlock();
    int GetDestructibleBlockCount();


private:
    std::vector<GameObject*>** objects_by_pos_; ///< A vector with every GameObject sorted by position on the map
    std::vector<GameObject*> empty_object_vector_; ///< As a default for oob positions
    std::list<GameObject*> destroyed_game_objects_; ///< A list of all GameObject that have been destroyed
    static GameManager* current_game_;  ///< A pointer to the current game
    win_condition::BaseWinCondition* win_condition_;    ///< The condition on which the game ends

    std::vector<Player*> players_;  ///< A vector with references to all Players on the map
    int destructible_block_count_ = 0;  ///< The amount of DestructibleBlocks on the map

    int width_;
    int height_;
};

} // namespace game

#endif // BOMBERMAN_GAME_GAMEMANAGER_H
