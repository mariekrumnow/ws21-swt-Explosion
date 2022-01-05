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
        static TileSet* CreateTileset(SDL_Renderer* renderer, std::string file,
                int tile_size_x, int tile_size_y);

        TileSet(SDL_Renderer* renderer, SDL_Texture* tile_atlas,
                int tile_size_x, int tile_size_y);

        ~TileSet();
        void DrawTile(SDL_Renderer* renderer, Tile tile, Color color, int x, int y);

    private:
        SDL_Texture* tile_atlas_;
        int tile_size_x_;
        int tile_size_y_;
    };

} // namespace graphics

#endif // BOMBERMAN_GRAPHICS_TILESET_H_
