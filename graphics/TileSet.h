// Author: Tobias

#ifndef BOMBERMAN_GRAPHICS_TILESET_H_
#define BOMBERMAN_GRAPHICS_TILESET_H_

#include <SDL.h>
#include <string>

#include "Color.h"
#include "Tile.h"

namespace graphics {

/// manages drawing of the tiles from a texture atlas

class TileSet {
public:
    /// Creates a tileset and puts the bmp-file on top of the tile_atlas_
    ///
    /// \param renderer The renderer of the window
    /// \param file The file where the Tileset is in
    /// \param tile_size_x The X-size of the file
    /// \param tile_size_y The Y-size of the file
    /// \return A pointer to the Tileset
    static TileSet* CreateTileset(SDL_Renderer* renderer, std::string file,
                                  int tile_size_x, int tile_size_y);

    /// Sets Variables tile_atlas_, tile_size_x_ and tile_size_y
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
    SDL_Texture* tile_atlas_; ///< The assets-grid
    int tile_size_x_; ///< The X-size of the Tiles
    int tile_size_y_; ///< The Y-size of the Tiles
};

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILESET_H_
