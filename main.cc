//Autor: Tobias, Carla, Dennis
#include "core/AppManager.h"

#include "graphics/Keys.h"
#include "game/GameWindow.h"
#include "game/GameManager.h"
#include "game/Player.h"


int main(int argc, char** argv)
{
    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);

    graphics::PlayerKeys player_keys[4];
    player_keys[0].up = graphics::key_w;
    player_keys[0].down = graphics::key_s;
    player_keys[0].left = graphics::key_a;
    player_keys[0].right = graphics::key_d;
    player_keys[0].bomb = graphics::key_l_shift;

    graphics::PlayerKeys player2keys{};
    player_keys[1].up = graphics::key_i;
    player_keys[1].down = graphics::key_k;
    player_keys[1].left = graphics::key_j;
    player_keys[1].right = graphics::key_l;
    player_keys[1].bomb = graphics::key_r_shift;


    game::GameWindow game_window = game::GameWindow();
    app.SetActiveWindow(game_window);
    game::GameManager game_manager = game::GameManager(15,13, 2, player_keys);


    // bleibt hier
    app.Run();

    return 0;
}
