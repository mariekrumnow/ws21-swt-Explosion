//Autor: Tobias, Carla, Dennis

#include <iostream>

#include "core/AppManager.h"


#include "graphics/GraphicsManager.h"
#include "graphics/Keys.h"
#include "game/GameWindow.h"
#include "game/GameManager.h"
#include "game/Player.h"
#include "game/upgrade/ExplosionRadiusUpgrade.h"
#include "game/upgrade/BombCountUpgrade.h"
#include "../game/block/DestructibleBlock.h"
#include "../game/block/IndestructibleBlock.h"

#include "../menu/MainWindow.h"

int main(int argc, char** argv)
{
    /// Initialize the app manager
    core::AppManager app = core::AppManager("Bomberman Explosion", true);


    graphics::GraphicsManager& graphics = app.GetGraphics();

    menu::MainWindow mainW = menu::MainWindow();
    app.SetActiveWindow(mainW);

    // game::GameWindow game_window = game::GameWindow();
    // app.SetActiveWindow(game_window);
    // game::GameManager game_manager = game::GameManager(15,13);
    //
    // srand(time(0));
    //
    // graphics::PlayerKeys player1keys{};
    // player1keys.up = SDL_SCANCODE_W;
    // player1keys.down = SDL_SCANCODE_S;
    // player1keys.left = SDL_SCANCODE_A;
    // player1keys.right = SDL_SCANCODE_D;
    // player1keys.bomb = SDL_SCANCODE_LSHIFT;
    //
    // graphics::PlayerKeys player2keys{};
    // player2keys.up = SDL_SCANCODE_I;
    // player2keys.down = SDL_SCANCODE_K;
    // player2keys.left = SDL_SCANCODE_J;
    // player2keys.right = SDL_SCANCODE_L;
    // player2keys.bomb = SDL_SCANCODE_RSHIFT;
    //
    // //auto upgrade2 = game::upgrade::BombCountUpgrade::CreateBombCountUpgrade(1, 0);
    //
    // // Outer walls (minus 0,0: somehow won't be placed)
    // for (int i=0; i<15; i++) {
    //       game::obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,0); // Upper wall
    //       game::obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,12); // Lower wall
    //
    //       if (i==0 || i==14) { // Left or right wall
    //             for (int j=1; j <12; j++) {
    //                   game::obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
    //             }
    //       }
    // }
    //
    // // Indestructible blocks in the middle
    // for (int i=2; i<=12; i+=2) {
    //       for(int j=2; j<=10; j+=2){
    //             game::obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
    //       }
    // }
    //
    // // Randomly placed destructible blocks
    // //game::obstacles::DestructibleBlock * blocks[14][12];
    // for (int i=1; i<14; i++) {
    //       for (int j=1; j<12; j++) {
    //             // Is a destructible block allowed?
    //             if ( (i%2 || j%2)
    //                     && !(
    //                     (i==1 && j==1) || (i==1 && j==2) || (i==2 && j==1) // Top left corner
    //                     || (i==1 && j==10) || (i==1 && j==11) || (i==2 && j==11) // Bottom left corner
    //                     || (i==12 && j==11) || (i==13 && j==11) || (i==13 && j==10) // Bottom right corner
    //                     || (i==12 && j==1) || (i==13 && j==1) || (i==13 && j==2) /* Top right corner */      ) )
    //             {
    //                   if (rand()%100 <=85) { // Places destructible block with a 85% chance
    //                        /*blocks[i][j] =*/ game::obstacles::DestructibleBlock::CreateDestructibleBlock(i,j);
    //                   }
    //             }
    //
    //       }
    // }
    //
    //
    // game::Player * player1 = game::Player::CreatePlayer(1,1,player1keys);
    // game::Player * player2 = game::Player::CreatePlayer(13,11,player2keys);
    // player1->IncreaseSpeed(6);
    // player1->IncreaseMaxBombCount(2);
    // player2->IncreaseSpeed(6);

    app.Run();

    return 0;
}
