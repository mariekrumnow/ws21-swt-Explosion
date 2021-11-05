//Author: Tobias

#define SDL_MAIN_HANDLED

//define the name of the test module in this file
#define BOOST_TEST_MODULE main test
#include <boost/test/unit_test.hpp>
//include the boost test library

#include "engine/AppManager.h"
#include "graphics/Tile.h"
#include "graphics/Color.h"

#include <iostream>

#include <SDL.h>
//include the sdl header file


//Enable to run boost tests in project
#define RUN_BOOST_TESTS 0


//If you don't run the test, execute the main function
#if !RUN_BOOST_TESTS

int main()
{
  engine::AppManager app = engine::AppManager(true);

  for (int i=0; i<10; i++) {
    app.graphics_.BeginFrame();

    if (i%2 == 0) {
      app.graphics_.DrawTile(graphics::kTileA, graphics::Color(255,0,0,255),
        100, 100);
    } else {
      app.graphics_.DrawTile(graphics::kTileG, graphics::Color(0,255,0,255),
        100, 100);
    }

    app.graphics_.EndFrame();
    SDL_Delay(500);
  }
  return 0;
}

#else

//otherwise, run the boost test main function
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#endif

//test if tests work (very meta!)
BOOST_AUTO_TEST_CASE(ExampleTest) {
    BOOST_CHECK(true);
}
