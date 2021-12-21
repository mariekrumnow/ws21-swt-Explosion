add_library(game
        GameManager.cc GameManager.h
        GameObject.cc GameObject.h
        Player.cc Player.h
        GameWindow.cc GameWindow.h

        block/Block.h block/Block.cc
        block/DestructibleBlock.h block/DestructibleBlock.cc
        block/IndestructibleBlock.h block/IndestructibleBlock.cc

        bomb/Bomb.h bomb/Bomb.cc
        bomb/Explosion.h bomb/Explosion.cc

        upgrade/Upgrade.h upgrade/Upgrade.cc
        upgrade/SpeedUpgrade.h upgrade/SpeedUpgrade.cc
        upgrade/ExplosionRadiusUpgrade.h upgrade/ExplosionRadiusUpgrade.cc
        upgrade/BombCountUpgrade.h upgrade/BombCountUpgrade.cc

        win_condition/BaseWinCondition.h
        win_condition/StandardWinCondition.cc win_condition/StandardWinCondition.h GameFactory.cc GameFactory.h)

target_include_directories (game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(game PUBLIC core)
target_link_libraries(game PUBLIC graphics)