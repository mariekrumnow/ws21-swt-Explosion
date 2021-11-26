//Autor: Tobias, Carla, Dennis

#include <iostream>

#include "AppManager.h"
#include "GraphicsManager.h"

#include "GameWindow.h"
#include "GameManager.h"
#include "Player.h"

#include "Keys.h"

int main(int argc, char** argv)
{
    //initialize the app manager
    core::AppManager app = core::AppManager(true);

    graphics::GraphicsManager& graphics = app.GetGraphics();

    game::GameWindow game_window = game::GameWindow();
    app.SetActiveGameWindow(game_window);
    game::GameManager game_manager = game::GameManager(15,13);

    game::Player player1 = game::Player(graphics::key_player_1_up, graphics::key_player_1_down,
                                        graphics::key_player_1_left, graphics::key_player_1_right, graphics::key_player_1_bomb);
    game::Player player2 = game::Player(graphics::key_player_2_up, graphics::key_player_2_down,
                                         graphics::key_player_2_left, graphics::key_player_2_right, graphics::key_player_2_bomb);
    player1.IncreaseSpeed(9);
    player2.IncreaseSpeed(9);
    game_manager.AddGameObject(player1);
    game_manager.AddGameObject(player2);


    app.Run();

    return 0;
}
