#include "AppManager.h"
#include "GraphicsManager.h"

#include "Keys.h"

int main(int argc, char** argv)
{
    //initialize the app manager
    core::AppManager app = core::AppManager(true);

    graphics::GraphicsManager& graphics = app.GetGraphics();

    //blink ten times between a red A and a green G
    while(true) {
        graphics.BeginFrame();

        graphics.DrawTile(graphics::kTileG, graphics::Color(0,255,255,255),
                               100, 200);

        //If A is pressed, print an A
        if (graphics.IsKeyPressed(key_player_1_left)) {
            graphics.DrawTile(graphics::kTileA, graphics::Color(255,0,0,255),
                                   100, 100);
        }

        //If W is pressed, print a W
        if (graphics.IsKeyHeld(key_player_1_up)) {
            graphics.DrawTile(graphics::kTileW, graphics::Color(0,255,0,255),
                                   200, 100);
        }

        //If Esc is pressed, exit the window
        if (graphics.IsKeyPressed(key_escape)) {
            graphics.Quit();
        }

        graphics.EndFrame();
        SDL_Delay(50);
    }
    return 0;
}
