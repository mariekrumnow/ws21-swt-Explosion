//Autor: Tobias, Carla, Dennis

#include <iostream>

#include "AppManager.h"
#include "GraphicsManager.h"

#include "GameWindow.h"
#include "GameManager.h"
#include "Player.h"

#include "Keys.h"

#include "game/upgrade/ExplosionRadiusUpgrade.h"
#include "game/upgrade/BombCountUpgrade.h"
#include "../game/block/DestructibleBlock.h"
#include "../game/block/IndestructibleBlock.h"

int main(int argc, char** argv)
{
    //initialize the app manager
    core::AppManager app = core::AppManager(true);

    graphics::GraphicsManager& graphics = app.GetGraphics();

    game::GameWindow game_window = game::GameWindow();
    app.SetActiveWindow(game_window);
    game::GameManager game_manager = game::GameManager(15,13);

    srand(time(0));

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
    player2keys.bomb = SDL_SCANCODE_RSHIFT;

    game::upgrade::ExplosionRadiusUpgrade * upgrade
      = game::upgrade::ExplosionRadiusUpgrade::CreateExplosionRadiusUpgrade(8,8);

    //auto upgrade2 = game::upgrade::BombCountUpgrade::CreateBombCountUpgrade(1, 0);

    game::obstacles::IndestructibleBlock * block2 = game::obstacles::IndestructibleBlock::CreateIndestructibleBlock(4,4);

    game::obstacles::DestructibleBlock * block3 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(4,8);
    game::obstacles::DestructibleBlock * block4 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(5,8);
    game::obstacles::DestructibleBlock * block5 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(6,8);
    game::obstacles::DestructibleBlock * block6 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(4,9);
    game::obstacles::DestructibleBlock * block7 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(4,10);
    game::obstacles::DestructibleBlock * block8 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(4,11);
    game::obstacles::DestructibleBlock * block9 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(6,6);
    game::obstacles::DestructibleBlock * block10 = game::obstacles::DestructibleBlock::CreateDestructibleBlock(5,5);

    game::Player * player1 = game::Player::CreatePlayer(0,0,player1keys);
    game::Player * player2 = game::Player::CreatePlayer(14,12,player2keys);
    player1->IncreaseSpeed(6);
    player1->IncreaseMaxBombCount(2);
    player2->IncreaseSpeed(6);

    app.Run();

    return 0;
}
