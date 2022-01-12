// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_TILESET_H_
#define BOMBERMAN_GRAPHICS_TILESET_H_

#include <SDL.h>
#include <string>

#include "Color.h"
#include "Tile.h"

namespace graphics {

/// manages drawing of tiles from a tile atlas

class TileSet {
public:
    /// Creates a tileset
    ///
    /// \param renderer The renderer of the window
    /// \param file The bmp file to be used as tile atlas
    /// \param tile_size_x The horizontal size of a tile
    /// \param tile_size_y The vertical size of a tile
    /// \return A pointer to the Tileset, or nullptr on error
    static TileSet* CreateTileset(SDL_Renderer* renderer, std::string file,
                                  int tile_size_x, int tile_size_y);

    /// Initializes the tile set
    ///
    /// \param renderer The renderer of the window
    /// \param tile_atlas The assets-grid
    /// \param tile_size_x The X-size of the Tile
    /// \param tile_size_y The Y-size of the Tile
    TileSet(SDL_Renderer* renderer, SDL_Texture* tile_atlas,
            int tile_size_x, int tile_size_y);

    /// Destructor of TileSet
    ~TileSet();

    /// Draws a Tile at a specified position of the Window
    ///
    /// \param renderer The renderer of the window
    /// \param tile The Tile that needs to be drawn
    /// \param color The Color of the Tile
    /// \param x The X-coordinate of the Tile
    /// \param y The Y-coordinate of the Tile
    void DrawTile(SDL_Renderer* renderer, Tile tile, Color color, int x, int y);

private:
    SDL_Texture* tile_atlas_; ///< The tile atlas
    int tile_size_x_; ///< The horizontal size of a tile
    int tile_size_y_; ///< The vertical size of a Tiles
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILESET_H_
