//Autor: Tobias, Carla, Dennis

#include "game/GameWindow.h"
#include "core/AppManager.h"
#include "GameFactory.h"

int main(int argc, char** argv)
{
    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);

    game::GameFactory factory = game::GameFactory(15, 12);
    factory.GenerateGame(2, 85);

    game::GameWindow game_window = game::GameWindow();
    app.SetActiveWindow(game_window);

    app.Run();

    return 0;
}
