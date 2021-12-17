//Autor: Tobias, Carla, Dennis

#include "core/AppManager.h"
#include "game/GameWindow.h"

#include "game/GameFactory.h"

int main(int argc, char** argv)
{
    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);

    // TODO: Klären ob das in den App Manager soll oder in die Factory
    game::GameWindow game_window = game::GameWindow();
    app.SetActiveWindow(game_window);

    game::CreateStandardGame(15, 13, 85, 2);

    app.Run();

    return 0;
}
