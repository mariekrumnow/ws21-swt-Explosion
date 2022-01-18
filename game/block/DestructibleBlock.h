// Autor: Nina, Marie


#ifndef BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H
#define BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H

#include "Block.h"

#include "../../graphics/Tile.h"
#include "../../graphics/Color.h"

namespace game {
namespace obstacles{

///  Block that can be shown on the map and be destroyed by an explosion
class DestructibleBlock : public Block{
public:

    ///  Basically calls the constructor of GameObject
    DestructibleBlock();

    ///  Creates a DestructibleBlock on the map
    ///
    /// \param x the x-coordinate of the new block
    /// \param y the y-coordinate of the new block
    /// \return A Pointer on the newly created block or nullptr if an error occurred
    static DestructibleBlock* CreateDestructibleBlock(int x, int y);

    ///  Removes block from the map, spawns an upgrade with a 35% chance and ends the explosion
    bool OnExplosion(GameObject& source);

    ///  Returns the shape of the block
    graphics::Tile GetTile();

    ///  Returns color of the block
    graphics::Color GetColor();

    void Destroy(); //so the GameManagers block count can be reduced
};

} // namespace obstacles
} // namespace game

#endif // BOMBERMAN_GAME_BLOCK_DESTRUCTIBLE_H
