// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_TILE_H_
#define BOMBERMAN_GRAPHICS_TILE_H_

namespace graphics {
/// Contains an offset into a tile atlas
    class Tile {
    public:
        Tile(int x_offset, int y_offset) : x_offset_(x_offset), y_offset_(y_offset) {}
        int getXOffset();
        int getYOffset();

    private:
        int x_offset_;
        int y_offset_;

    };

/// Text tile definitions
    const Tile kTileA = Tile(1,4);
    const Tile kTileB = Tile(2,4);
    const Tile kTileC = Tile(3,4);
    const Tile kTileD = Tile(4,4);
    const Tile kTileE = Tile(5,4);
    const Tile kTileF = Tile(6,4);
    const Tile kTileG = Tile(7,4);
    const Tile kTileH = Tile(8,4);
    const Tile kTileI = Tile(9,4);
    const Tile kTileJ = Tile(10,4);
    const Tile kTileK = Tile(11,4);
    const Tile kTileL = Tile(12,4);
    const Tile kTileM = Tile(13,4);
    const Tile kTileN = Tile(14,4);
    const Tile kTileO = Tile(15,4);
    const Tile kTileP = Tile(0,5);
    const Tile kTileQ = Tile(1,5);
    const Tile kTileR = Tile(2,5);
    const Tile kTileS = Tile(3,5);
    const Tile kTileT = Tile(4,5);
    const Tile kTileU = Tile(5,5);
    const Tile kTileV = Tile(6,5);
    const Tile kTileW = Tile(7,5);
    const Tile kTileX = Tile(8,5);
    const Tile kTileY = Tile(9,5);
    const Tile kTileZ = Tile(10,5);

/// Game tile definitions
/// curses 16x16
    /*const Tile kTileEmpty = Tile(0,0);
    const Tile kTileDot = Tile(10,15);
    const Tile kTilePlayer = Tile(1,0);
    const Tile kTileSolidWall = Tile(11,13);
    const Tile kTileBrittleWall = Tile(2,11);
    const Tile kTileExplosion = Tile(15,0);
    const Tile kTileBomb = Tile(2,10);
    const Tile kTileMenuCursor = Tile(0,1);
    const Tile kTileSpeedUpgrade = Tile(15,10);
    const Tile kTileExplosionRadiusUpgrade = Tile(13,1);
    const Tile kTileBombCountUpgrade = Tile(5,14);*/
/// Grafiken
    const Tile kTileEmpty = Tile(0,0);
    const Tile kTileDot = Tile(0,0);

    const Tile kTilePlayer1Up = Tile(0,3);
    const Tile kTilePlayer1Down = Tile(1,3);
    const Tile kTilePlayer1Right = Tile(3,3);
    const Tile kTilePlayer1Left = Tile(2,3);

    const Tile kTilePlayer2Up = Tile(0,4);
    const Tile kTilePlayer2Down = Tile(1,4);
    const Tile kTilePlayer2Right = Tile(3,4);
    const Tile kTilePlayer2Left = Tile(2,4);

    const Tile kTileSolidWall = Tile(2,0);
    const Tile kTileBrittleWall = Tile(1,0);

    const Tile kTileExplosionMiddle = Tile(1,2);
    const Tile kTileExplosionHorizontal = Tile(2,2);
    const Tile kTileExplosionVertical = Tile(3,2);
    const Tile kTileExplosionUp = Tile(3,1);
    const Tile kTileExplosionRight = Tile(4,0);
    const Tile kTileExplosionLeft = Tile(3,0);
    const Tile kTileExplosionDown = Tile(4,2);

    const Tile kTileBomb = Tile(0,2);

    const Tile kTileMenuCursor = Tile(0,1);

    const Tile kTileSpeedUpgrade = Tile(0,1);
    const Tile kTileExplosionRadiusUpgrade = Tile(1,1);
    const Tile kTileBombCountUpgrade = Tile(2,1);



} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILE_H_
