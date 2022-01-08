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
        int x_offset_; ///< The X-offset int the graphics .bmt file
        int y_offset_; ///< The Y-offset int the graphics .bmt file

    };

// Text tile definitions
    const Tile kTileA = Tile(1,4); ///< The Tile for the letter A
    const Tile kTileB = Tile(2,4); ///< The Tile for the letter B
    const Tile kTileC = Tile(3,4); ///< The Tile for the letter C
    const Tile kTileD = Tile(4,4); ///< The Tile for the letter D
    const Tile kTileE = Tile(5,4); ///< The Tile for the letter E
    const Tile kTileF = Tile(6,4); ///< The Tile for the letter F
    const Tile kTileG = Tile(7,4); ///< The Tile for the letter G
    const Tile kTileH = Tile(8,4); ///< The Tile for the letter H
    const Tile kTileI = Tile(9,4); ///< The Tile for the letter I
    const Tile kTileJ = Tile(10,4); ///< The Tile for the letter J
    const Tile kTileK = Tile(11,4); ///< The Tile for the letter K
    const Tile kTileL = Tile(12,4); ///< The Tile for the letter L
    const Tile kTileM = Tile(13,4); ///< The Tile for the letter M
    const Tile kTileN = Tile(14,4); ///< The Tile for the letter N
    const Tile kTileO = Tile(15,4); ///< The Tile for the letter O
    const Tile kTileP = Tile(0,5); ///< The Tile for the letter P
    const Tile kTileQ = Tile(1,5); ///< The Tile for the letter Q
    const Tile kTileR = Tile(2,5); ///< The Tile for the letter R
    const Tile kTileS = Tile(3,5); ///< The Tile for the letter S
    const Tile kTileT = Tile(4,5); ///< The Tile for the letter T
    const Tile kTileU = Tile(5,5); ///< The Tile for the letter U
    const Tile kTileV = Tile(6,5); ///< The Tile for the letter V
    const Tile kTileW = Tile(7,5); ///< The Tile for the letter W
    const Tile kTileX = Tile(8,5); ///< The Tile for the letter X
    const Tile kTileY = Tile(9,5); ///< The Tile for the letter Y
    const Tile kTileZ = Tile(10,5); ///< The Tile for the letter Z

// Game tile definitions
// curses 16x16
    /*
    const Tile kTileEmpty = Tile(0,0); ///< The Tile for an empty field
    const Tile kTileDot = Tile(10,15); ///< The Tile for a dot
    const Tile kTilePlayer = Tile(1,0); ///< The Tile for a Player
    const Tile kTileSolidWall = Tile(11,13); ///< The Tile for a SolidWall
    const Tile kTileBrittleWall = Tile(2,11); ///< The Tile for a BrittleWall
    const Tile kTileExplosion = Tile(15,0); ///< The Tile for the Explosion
    const Tile kTileBomb = Tile(2,10); ///< The Tile for a Bomb
    const Tile kTileMenuCursor = Tile(0,1); ///< The Tile for the MenuCursor
    const Tile kTileSpeedUpgrade = Tile(15,10); ///< The Tile for the SpeedUpgrade
    const Tile kTileExplosionRadiusUpgrade = Tile(13,1); ///< The Tile for ExplosionRadiusUpgrade
    const Tile kTileBombCountUpgrade = Tile(5,14); ///< The Tile for BombCountUpgrade
     */
// Grafiken


    struct PlayerTile {
        PlayerTile(Tile up, Tile down, Tile left, Tile right);

        Tile up; ///< The Tile for the Player control up
        Tile down; ///< The Tile for the Player control down
        Tile left; ///< The Tile for the Player control left
        Tile right; ///< The Tile for the Player control right
    };

    const Tile kTileEmpty = Tile(0,0); ///< The Tile for an empty field
    const Tile kTileDot = Tile(0,0); ///< The Tile for a dot

    const PlayerTile kPlayer1Tiles(Tile(0,3),Tile(1,3),
                                   Tile(2,3), Tile(3,3)); ///< The Tile-set for Player1
    const PlayerTile kPlayer2Tiles(Tile(0,4),Tile(1,4),
                                   Tile(2,4), Tile(3,4)); ///< The Tile-set for Player2

    const Tile kTileSolidWall = Tile(2,0); ///< The Tile for a SolidWall
    const Tile kTileBrittleWall = Tile(1,0); ///< The Tile for a BrittleWall

    const Tile kTileExplosionMiddle = Tile(1,2); ///< The Tile for the ExplosionMiddle
    const Tile kTileExplosionHorizontal = Tile(2,2); ///< The Tile for an ExplosionHorizontal
    const Tile kTileExplosionVertical = Tile(3,2); ///< The Tile for an ExplosionVertical
    const Tile kTileExplosionUp = Tile(3,1); ///< The Tile for an ExplosionUp
    const Tile kTileExplosionRight = Tile(4,0); ///< The Tile for an ExplosionRight
    const Tile kTileExplosionLeft = Tile(3,0); ///< The Tile for an ExplosionLeft
    const Tile kTileExplosionDown = Tile(4,2); ///< The Tile for an ExplosionDown

    const Tile kTileBomb = Tile(0,2); ///< The Tile for the Bomb

    const Tile kTileMenuCursor = Tile(0,1); ///< The Tile for the MenuCursor

    const Tile kTileSpeedUpgrade = Tile(0,1); ///< The Tile for SpeedUpgarde
    const Tile kTileExplosionRadiusUpgrade = Tile(1,1); ///< The Tile for ExplosionRadius
    const Tile kTileBombCountUpgrade = Tile(2,1); ///< The Tile for BombCountUpgrade

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILE_H_
