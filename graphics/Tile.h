// Author: Tobias, Dennis, Peter

#ifndef BOMBERMAN_GRAPHICS_TILE_H_
#define BOMBERMAN_GRAPHICS_TILE_H_

namespace graphics {

/// Contains an offset into a tile atlas

class Tile {
public:

    /// Constructor of Tile
    ///
    /// \param x_offset Y-offset in the graphics .bmt file
    /// \param y_offset X-offset in the graphics .bmt file
    Tile(int x_offset, int y_offset) : x_offset_(x_offset), y_offset_(y_offset) {}

    /// A Getter for x_offset_
    ///
    /// \return The X-offset
    int getXOffset();

    /// A Getter for y_offset_
    ///
    /// \return The Y-offset
    int getYOffset();

    private:
        int x_offset_; ///< The X-offset into the tile atlas
        int y_offset_; ///< The Y-offset into the tile atlas

    };


// Grafiken


    struct PlayerTile {
        PlayerTile(Tile up, Tile down, Tile left, Tile right);

        Tile up; ///< The Tile for the Player control up
        Tile down; ///< The Tile for the Player control down
        Tile left; ///< The Tile for the Player control left
        Tile right; ///< The Tile for the Player control right
    };

    const Tile kTileEmpty = Tile(0,0); ///< The Tile for an empty field

    const PlayerTile kPlayer1Tiles(Tile(0,3),Tile(1,3),
                                   Tile(2,3), Tile(3,3)); ///< The Tile-set for Player1
    const PlayerTile kPlayer2Tiles(Tile(0,4),Tile(1,4),
                                   Tile(2,4), Tile(3,4)); ///< The Tile-set for Player2

    const Tile kTileSolidWall = Tile(2,0); ///< The Tile for a SolidWall
    const Tile kTileBrittleWall = Tile(1,0); ///< The Tile for a BrittleWall

    const Tile kTileExplosionMiddle = Tile(1,2); ///< The Tile for the center of the explosion part
    const Tile kTileExplosionHorizontal = Tile(2,2); ///< The Tile for the horizontal explosion part
    const Tile kTileExplosionVertical = Tile(3,2); ///< The Tile for the vertical explosion part
    const Tile kTileExplosionUp = Tile(3,1); ///< The Tile for the upper explosion end
    const Tile kTileExplosionRight = Tile(4,0); ///< The Tile for the right explosion end
    const Tile kTileExplosionLeft = Tile(3,0); ///< The Tile for the left explosion end
    const Tile kTileExplosionDown = Tile(4,2); ///< The Tile for the lower explosion end

    const Tile kTileBomb = Tile(0,2); ///< The Tile for the Bomb

    const Tile kTileSpeedUpgrade = Tile(0,1); ///< The Tile for SpeedUpgarde
    const Tile kTileExplosionRadiusUpgrade = Tile(1,1); ///< The Tile for ExplosionRadiusUpgrade
    const Tile kTileBombCountUpgrade = Tile(2,1); ///< The Tile for BombCountUpgrade

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILE_H_
