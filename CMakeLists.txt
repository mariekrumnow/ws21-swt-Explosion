cmake_minimum_required(VERSION 3.20)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

add_executable(bomberman main.cpp)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARIES})

add_subdirectory(core)
target_include_directories(bomberman PRIVATE core)
target_link_directories(bomberman PRIVATE core)
target_link_libraries(bomberman core)

add_subdirectory(game)
target_link_directories(bomberman PRIVATE game)
target_link_directories(bomberman PRIVATE game)
target_link_libraries(bomberman game)

add_subdirectory(graphics)
target_link_directories(bomberman PRIVATE graphics)
target_link_directories(bomberman PRIVATE graphics)
target_link_libraries(bomberman graphics)

add_subdirectory(tests)
