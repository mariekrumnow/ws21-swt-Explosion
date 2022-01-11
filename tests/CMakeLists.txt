set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
endif()
include_directories(${Boost_INCLUDE_DIRS})

add_executable(tests test_main.cc
        game/bomb/BombTest.cc
        game/bomb/ExplosionTest.cc
        game/upgrade/BombCountUpgradeTest.cc
        game/upgrade/ExplosionRadiusUpgradeTest.cc
        game/upgrade/SpeedUpgradeTest.cc
        menu/MenuWindowTest.cc
        game/GameManagerTest.cc
        game/GameFactoryTest.cc
        game/GameObjectTest.cc
        core/AppManagerTest.cc
        game/GameWindowTest.cc
        menu/GameOverWindowTest.cc
        menu/InstructionWindowTest.cc
        menu/MenuWindowTest.cc
        #game/win_condition/StandardWinConditionTest.cc
        #game/block/DestructibleBlockTest.cc
        #game/block/IndestructibleBlockTest.cc
        game/block/BlockTest.cc
        )

target_link_libraries(tests ${Boost_LIBRARIES})
target_link_libraries(tests core)
target_link_libraries(tests graphics)
target_link_libraries(tests game)
target_link_libraries(tests sound)