//Author: Tobias

#include "TileSet.h"

#include <iostream>
#include <SDL.h>

namespace graphics {

    TileSet::TileSet(SDL_Renderer* renderer, SDL_Texture* tile_atlas,
                     int tile_size_x, int tile_size_y) {

        tile_atlas_ = tile_atlas;
        tile_size_x_ = tile_size_x;
        tile_size_y_ = tile_size_y;
    }

    TileSet::~TileSet() {
        SDL_DestroyTexture(tile_atlas_);
    }

    TileSet* TileSet::CreateTileset(SDL_Renderer* renderer, std::string file,
        int tile_size_x, int tile_size_y) {

        SDL_Surface* tile_atlas_surface = SDL_LoadBMP(file.c_str());
        SDL_Texture* tile_atlas = SDL_CreateTextureFromSurface(renderer, tile_atlas_surface);
        SDL_FreeSurface(tile_atlas_surface);

        if (!tile_atlas) {
            return nullptr;
        } else {
            return new TileSet(renderer, tile_atlas, tile_size_x, tile_size_y);
        }
    }

    void TileSet::DrawTile(SDL_Renderer* renderer, Tile tile, Color color, int x, int y){
        const SDL_Rect kSource =
                {tile.getXOffset()* tile_size_x_, tile.getYOffset() * tile_size_y_,
                 tile_size_x_, tile_size_y_};

        const SDL_Rect kDestination =
                {x, y, tile_size_x_, tile_size_y_};

        SDL_SetTextureColorMod(tile_atlas_, color.red_, color.green_, color.blue_);
        SDL_RenderCopy(renderer, tile_atlas_, &kSource, &kDestination);
    }

} // namespace graphics
