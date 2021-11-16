//Author: Tobias
#define SDL_MAIN_HANDLED
#include <boost_test.h>

//If you don't run the test, execute the main function
#if RUN_BOOST_TESTS==0

#include "core/AppManager.h"
#include "graphics/Tile.h"
#include "graphics/Color.h"
#include "graphics/Keys.h"

#include <iostream>

#include <SDL.h>
//include the sdl header file

int main(int argc, char** argv)
{
  //initialize the app manager
  core::AppManager app = core::AppManager(true);

  //blink ten times between a red A and a green G
  while(true) {
    app.graphics_.BeginFrame();

    app.graphics_.DrawTile(graphics::kTileG, graphics::Color(0,255,255,255),
      100, 200);

    //If A is pressed, print an A
    if (app.graphics_.IsKeyPressed(key_player_1_left)) {
      app.graphics_.DrawTile(graphics::kTileA, graphics::Color(255,0,0,255),
        100, 100);
    }

    //If W is pressed, print a W
    if (app.graphics_.IsKeyHeld(key_player_1_up)) {
      app.graphics_.DrawTile(graphics::kTileW, graphics::Color(0,255,0,255),
        200, 100);
    }

    //If Esc is pressed, exit the window
    if (app.graphics_.IsKeyPressed(key_escape)) {
      app.graphics_.Quit();
    }

    app.graphics_.EndFrame();
    SDL_Delay(50);
  }
  return 0;
}

#else
//this workaround is necessary to make Boost and SDL2 work together
//run the boost test cases
#define BOOST_TEST_MODULE "Bomberman Test Cases"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

// entry point:
int main(int argc, char* argv[], char* envp[])
{
  return boost::unit_test::unit_test_main( &init_unit_test, argc, argv );
}
#endif
