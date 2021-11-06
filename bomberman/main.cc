//Author: Tobias
#define SDL_MAIN_HANDLED
#include <boost_test.h>
//If you don't run the test, execute the main function
#if RUN_BOOST_TESTS==0

#include "engine/AppManager.h"
#include "graphics/Tile.h"
#include "graphics/Color.h"

#include <iostream>

#include <SDL.h>
//include the sdl header file

int main(int argc, char** argv)
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
