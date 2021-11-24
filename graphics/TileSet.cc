//Author: Tobias
#include "TileSet.h"

namespace graphics {

    TileSet::TileSet(SDL_Renderer* renderer, std::string file,
                     int tile_size_x, int tile_size_y) {

        tile_size_x_ = tile_size_x;
        tile_size_y_ = tile_size_y;

        SDL_Surface* tile_atlas_surface = SDL_LoadBMP(file.c_str());
        tile_atlas_ = SDL_CreateTextureFromSurface(renderer, tile_atlas_surface);

    }

    void TileSet::DrawTile(SDL_Renderer* renderer, Tile tile, Color color, int x, int y){
        const SDL_Rect kSource =
                {tile.getXOffset() * tile_size_x_, tile.getYOffset() * tile_size_y_,
                 tile_size_x_, tile_size_y_};

        const SDL_Rect kDestination =
                {x, y, tile_size_x_, tile_size_y_};

        SDL_SetTextureColorMod(tile_atlas_, color.red_, color.green_, color.blue_);
        SDL_RenderCopy(renderer, tile_atlas_, &kSource, &kDestination);
    }

} //namespace graphics
