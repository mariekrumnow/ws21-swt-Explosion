//Autor: Dennis, Peter

#include "GameFactory.h"
#include "GameWindow.h"
#include "GameManager.h"
#include "Player.h"
#include "win_condition/StandardWinCondition.h"
#include "block/IndestructibleBlock.h"
#include "block/DestructibleBlock.h"




namespace game {

// TODO: Klasse oder Funktion?
void CreateStandardGame(int width, int height, int indest_prop, int playerCount) {
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

    game::win_condition::BaseWinCondition *winCondition = new game::win_condition::StandardWinCondition();
    game::GameManager game_manager = GameManager(15, 13, playerCount, winCondition);



    // Outer walls
    for (int i=0; i<width; i++) {
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,0); // Upper wall
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,(height-1)); // Lower wall

        if (i==0 || i==(width-1)) { // Left or right wall
            for (int j=1; j <(height-1); j++) {
                obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
            }
        }
    }


    // Indestructible blocks in the middle
    for (int i=2; i<=(width-3); i+=2) {
        for(int j=2; j<=(height-3); j+=2){
            obstacles::IndestructibleBlock::CreateIndestructibleBlock(i,j);
        }
    }



    // Randomly placed destructible blocks
    for (int i=1; i<width-1; i++) {
        for (int j=1; j<height-1; j++) {
            // Is a destructible block allowed?

            if ((i%2 || j%2) && !(
                    ( (i == (1) && j == (1)) || (i == (1) && j == (2)) || (i == (2) && j == (1)) ) ||                                               // top left
                    ( (i == (1) && j==(height-2)) || (i == (1) && j ==(height-3)) || (i == (2) && j == (height-2)) ) ||                          // bottom left
                    ( (i == (width-3) && j == (1)) || (i == (width-2) && j == (1)) || (i == (width-2) && j == (2)) ) ||                          // top right
                    ( (i == (width-3) && j == (height-2)) || ( i == (width-2)) && (j == (height-2)) || (i == (width-2) && (j == (height-3)))) // bottom right
            )) {
                if (rand()%100 <= indest_prop) { // Places destructible block with a chance = indest_prop
                    obstacles::DestructibleBlock::CreateDestructibleBlock(i,j);
                }
            }

        }
    }


    // Generate players

    Player* players[playerCount];

    for (int i = 0; i < playerCount; i++) {
        if (i == 0) {
            players[i] = Player::CreatePlayer(1,1, player_keys[i], graphics::player1Tiles);
        }
        else if (i == 1) {
            players[i] = Player::CreatePlayer((width-2),(height-2), player_keys[i], graphics::player2Tiles);
        }
        else if (i == 2) {
            players[i] = Player::CreatePlayer(1,(height-2), player_keys[i], graphics::player1Tiles);
        }
        else if (i == 3) {
            players[i] = Player::CreatePlayer((width-2), 1, player_keys[i], graphics::player2Tiles);
        }
    }
}

}; // namespace game