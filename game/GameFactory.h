// Autor Dennis, Peter

#ifndef BOMBERMAN_GAMEFACTORY_H
#define BOMBERMAN_GAMEFACTORY_H

#include "../graphics/Keys.h"
#include "win_condition/BaseWinCondition.h"

namespace game {

/// Managers setting up the structure and object spawns of a new game manager

class GameFactory {
public:
    /// Creates a new GameManager
    ///
    /// \param width width of the map
    /// \param height height of the map
    /// \param winCondition The condition for the game to end
    GameFactory(int width, int height, win_condition::BaseWinCondition* win_condition);

    /// Generates Map with Player(s)
    ///
    /// \param player_count The amount of Players
    /// \param indest_prop The chance that a DestructibleBlock is spawned on a tile
    void GenerateGame(int player_count, int indest_prop);

private:
    /// Place the indestructible and destructible blocks on the map
    /// IndestructibleBlocks : outer Wall and Blocks in the middle
    /// DestructibleBlocks: randomized except starting areas for Players
    ///
    /// \param indest_count The amount of IndestructibleBlocks
    void GenerateMap(int indest_count) const;

    /// Creates the given amount of Players in the corners of the map
    ///
    /// \param player_count The amount of Players
    /// \param player_keys The keys to control the Players
    void GeneratePlayers(int player_count, graphics::PlayerKeys* player_keys) const;

    int width_; ///< width of the map
    int height_; ///< height of the map
};

/// Initializes a new classic mode game
void StartClassicGame();

/// Initializes a single player game
void StartSinglePlayerGame();

} // namespace game

#endif //BOMBERMAN_GAMEFACTORY_H
