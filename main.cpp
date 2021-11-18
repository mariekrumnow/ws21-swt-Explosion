#include "AppManager.h"

#include "Keys.h"

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