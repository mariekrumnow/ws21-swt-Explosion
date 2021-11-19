add_library(game
        GameManager.cc GameManager.h
        GameObject.cc GameObject.h
        Player.cc Player.h Bomb.cc Bomb.h)

target_link_libraries(game PUBLIC core)