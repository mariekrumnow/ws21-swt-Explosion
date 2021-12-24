// Autor Dennis, Peter, Tobias

#include "GameFactory.h"

#include "../core/AppManager.h"
#include "../graphics/Keys.h"
#include "block/IndestructibleBlock.h"
#include "block/DestructibleBlock.h"
#include "win_condition/StandardWinCondition.h"
#include "Player.h"
#include "GameManager.h"
#include "GameWindow.h"

namespace game {

GameFactory::GameFactory(int width, int height): width_(width), height_(height) {
    win_condition::BaseWinCondition* winCondition = new win_condition::StandardWinCondition();
    new GameManager(15, 13, winCondition);
}

void GameFactory::GenerateGame(int player_count, int indest_prop) {
    graphics::PlayerKeys player_keys[4];
    player_keys[0].up = graphics::key_w;
    player_keys[0].down = graphics::key_s;
    player_keys[0].left = graphics::key_a;
    player_keys[0].right = graphics::key_d;
    player_keys[0].bomb = graphics::key_l_shift;

    player_keys[1].up = graphics::key_i;
    player_keys[1].down = graphics::key_k;
    player_keys[1].left = graphics::key_j;
    player_keys[1].right = graphics::key_l;
    player_keys[1].bomb = graphics::key_r_shift;

    this->GenerateMap(indest_prop);
    this->GeneratePlayers(player_count, player_keys);
}

void GameFactory::GenerateMap(int indest_prop) const {
    // Outer walls (minus 0,0: somehow won't be placed)
    for (int i = 0; i < width_; i++) {
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i, 0); // Upper wall
        obstacles::IndestructibleBlock::CreateIndestructibleBlock(i, (height_ - 1)); // Lower wall

        if (i == 0 || i == (width_ - 1)) { // Left or right wall
            for (int j = 1; j < (height_ - 1); j++) {
                obstacles::IndestructibleBlock::CreateIndestructibleBlock(i, j);
            }
        }
    }


    // Indestructible blocks in the middle
    for (int i = 2; i <= (width_ - 3); i += 2) {
        for (int j = 2; j <= (height_ - 3); j += 2) {
            obstacles::IndestructibleBlock::CreateIndestructibleBlock(i, j);
        }
    }

    // Randomly placed destructible blocks
    for (int i = 1; i < width_ - 1; i++) {
        for (int j = 1; j < height_ - 1; j++) {
            // Is a destructible block allowed?

            if ((i % 2 || j % 2) && !(
                    ((i == (1) && j == (1)) || (i == (1) && j == (2)) || (i == (2) && j == (1))) || // top left
                    ((i == (1) && j == (height_ - 2)) || (i == (1) && j == (height_ - 3)) ||
                     (i == (2) && j == (height_ - 2))) ||                          // bottom left
                    ((i == (width_ - 3) && j == (1)) || (i == (width_ - 2) && j == (1)) ||
                     (i == (width_ - 2) && j == (2))) ||                          // top right
                    ((i == (width_ - 3) && j == (height_ - 2)) || (i == (width_ - 2)) && (j == (height_ - 2)) ||
                     (i == (width_ - 2) && (j == (height_ - 3)))) // bottom right
            )) {
                if (rand() % 100 <= indest_prop) { // Places destructible block with a 85% chance
                    obstacles::DestructibleBlock::CreateDestructibleBlock(i, j);
                }
            }
        }
    }
}

void GameFactory::GeneratePlayers(int player_count, graphics::PlayerKeys* player_keys) const {
    // player
    Player* players[player_count];

    for (int i = 0; i < player_count; i++) {
        if (i == 0) {
            players[i] = Player::CreatePlayer(1, 1, player_keys[i], graphics::kPlayer1Tiles, 1);
        } else if (i == 1) {
            players[i] = Player::CreatePlayer((width_ - 2), (height_ - 2), player_keys[i], graphics::kPlayer2Tiles, 2);
        } else if (i == 2) {
            players[i] = Player::CreatePlayer(1, (height_ - 2), player_keys[i], graphics::kPlayer1Tiles, 3);
        } else if (i == 3) {
            players[i] = Player::CreatePlayer((width_ - 2), 1, player_keys[i], graphics::kPlayer2Tiles, 4);
        }
    }
}

void StartClassicGame() {
    GameFactory factory = GameFactory(15, 12);
    factory.GenerateGame(2, 85);

    core::AppManager& app = core::AppManager::GetAppManager();

    GameWindow * game_window = new GameWindow();
    app.SetActiveWindow(*game_window);

    app.GetSound().PlayRandomBattleMusic();
}

} // namespace game
