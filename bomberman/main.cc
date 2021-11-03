//Author: Tobias

#define SDL_MAIN_HANDLED

//define the name of the test module in this file
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>
//include the boost test library


#include <iostream>

#include <SDL.h>
//include the sdl header file



//Enable to run boost tests in project
#define RUN_BOOST_TESTS 0


//If you don't run the test, execute the main function
#if !RUN_BOOST_TESTS

int main()
{
    //Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL couldn't be initialized! SDL_Error: " << SDL_GetError();
        return -1;
    }

    int screen_width = 640;
    int screen_height = 480;
    
    //Create the window
    SDL_Window* window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    
    //Make sure it actually exists
    if (window == NULL) {
        std::cout << "Window couldn't be created! SDL_Error: " << SDL_GetError();
        return -1;
    }

    //Get the renderer (The 2D GPU rendering component)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //Set the drawing color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //Draw a rectangle filling the entire screen
    SDL_RenderFillRect(renderer, NULL);

    //Set the drawing color to cyan
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    //Draw a rectangle filling the left half of the screen
    const SDL_Rect kRectangle = { 0, 0, screen_width / 2, screen_height };
    SDL_RenderFillRect(renderer, &kRectangle);

    //execute all the queued rendering commands
    SDL_RenderPresent(renderer);

    //wait 2 seconds
    SDL_Delay(2000);

    //clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

#else

//otherwise, run the boost test main function
#define BOOST_TEST_MAIN

#endif

//test if tests work (very meta!)
BOOST_AUTO_TEST_CASE(ExampleTest) {
    BOOST_CHECK(true);
}
