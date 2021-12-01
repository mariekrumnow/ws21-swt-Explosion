//Autor: Tobias, Carla, Dennis

#include <iostream>

#include "AppManager.h"
#include "GraphicsManager.h"

#include "GameWindow.h"
#include "GameManager.h"
#include "Player.h"

#include "Keys.h"

#include "game/upgrade/SpeedUpgrade.h"

int main(int argc, char** argv)
{
    //initialize the app manager
    core::AppManager app = core::AppManager(true);

    graphics::GraphicsManager& graphics = app.GetGraphics();

    game::GameWindow game_window = game::GameWindow();
    app.SetActiveGameWindow(game_window);
    game::GameManager game_manager = game::GameManager(15,13);

    graphics::PlayerKeys player1keys{};
    player1keys.up = SDL_SCANCODE_W;
    player1keys.down = SDL_SCANCODE_S;
    player1keys.left = SDL_SCANCODE_A;
    player1keys.right = SDL_SCANCODE_D;
    player1keys.bomb = SDL_SCANCODE_LSHIFT;

    graphics::PlayerKeys player2keys{};
    player2keys.up = SDL_SCANCODE_I;
    player2keys.down = SDL_SCANCODE_K;
    player2keys.left = SDL_SCANCODE_J;
    player2keys.right = SDL_SCANCODE_L;
    player1keys.bomb = SDL_SCANCODE_RSHIFT;

    game::Player player1 = game::Player(player1keys);
    game::Player player2 = game::Player(player2keys);
    player1.IncreaseSpeed(9);
    player2.IncreaseSpeed(9);
    game_manager.AddGameObject(player1);
    game_manager.AddGameObject(player2);

    app.Run();

    return 0;
}
