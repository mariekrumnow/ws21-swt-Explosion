// Autor Dennis, Peter

#ifndef BOMBERMAN_GAMEFACTORY_H
#define BOMBERMAN_GAMEFACTORY_H

#include "../graphics/Keys.h"
#include "win_condition/BaseWinCondition.h"

namespace game {

class GameFactory {
public:
    /// Creates a new GameManager
    ///
    /// \param width width of the map
    /// \param height height of the map
    /// \param winCondition How the game is supposed to check for the end
    GameFactory(int width, int height, win_condition::BaseWinCondition* winCondition);

    /// Assigns player keys and generates Map with Player(s)
    ///
    /// \param player_count The amount of Players
    /// \param indest_prop The chance that a DestructibleBlock is spawned on a tile
    void GenerateGame(int player_count, int indest_prop);

private:
    /// Generates Map and places Blocks
    /// IndestructibleBlocks : outer Wall and Blocks in the middle
    /// DestructibleBlocks: randomized except starting places of Player
    ///
    /// \param indest_count The amount of IndestructibleBlocks
    void GenerateMap(int indest_count) const;

    /// Creates the necessary amount of Players in their corners
    ///
    /// \param player_count The amount of Players
    /// \param player_keys The keys to control the Player
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
