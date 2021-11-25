//Autor: Tobias

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

    game::upgrade::SpeedUpgrade speedUpgrade = game::upgrade::SpeedUpgrade();
    game_manager.AddGameObject(speedUpgrade);
    game_manager.ChangeObjectPosition(speedUpgrade, 3, 3);

    game::Player player = game::Player();
    //player.IncreaseSpeed(9);
    game_manager.AddGameObject(player);

    app.Run();

    return 0;
}
