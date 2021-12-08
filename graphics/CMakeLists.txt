add_library(graphics
        Color.h
        GraphicsManager.cc GraphicsManager.h
        Keys.cc Keys.h
        Tile.cc Tile.h
        TileSet.cc TileSet.h
        )


target_include_directories (graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

