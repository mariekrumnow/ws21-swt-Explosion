//Author: Tobias

#include "Tile.h"

namespace graphics {

    int Tile::getXOffset() {
        return x_offset_;
    }

    int Tile::getYOffset() {
        return y_offset_;
    }

    PlayerTile::PlayerTile(Tile up, Tile down, Tile left, Tile right): up(up), down(down), left(left), right(right) {

    }
} // namespace graphics
