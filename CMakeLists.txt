cmake_minimum_required(VERSION 3.20)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

add_executable(bomberman main.cc)

# Libraries
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
link_libraries(${SDL2_LIBRARIES})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})
link_libraries(${SDL2_TTF_LIBRARIES})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
link_libraries(${SDL2_IMAGE_LIBRARIES})

find_package(SDL2_mixer REQUIRED)
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
link_libraries(${SDL2_MIXER_LIBRARIES})

# Subdirectories
add_subdirectory(core)
target_include_directories(bomberman PRIVATE core)
target_link_directories(bomberman PRIVATE core)
target_link_libraries(bomberman core)

add_subdirectory(game)
target_include_directories(bomberman PRIVATE game)
target_link_directories(bomberman PRIVATE game)
target_link_libraries(bomberman game)

add_subdirectory(graphics)
target_include_directories(bomberman PRIVATE graphics)
target_link_directories(bomberman PRIVATE graphics)
target_link_libraries(bomberman graphics)

add_subdirectory(tests)
