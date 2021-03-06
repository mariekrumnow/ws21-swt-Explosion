// Autor Dennis, Peter, Tobias

#include "GameFactory.h"

#include "../core/AppManager.h"
#include "../graphics/Keys.h"
#include "block/DestructibleBlock.h"
#include "block/IndestructibleBlock.h"
#include "win_condition/SinglePlayerWinCondition.h"
#include "win_condition/StandardWinCondition.h"
#include "Player.h"
#include "GameManager.h"
#include "GameWindow.h"
#include "SinglePlayerGameWindow.h"

namespace game {

GameFactory::GameFactory(int width, int height, win_condition::BaseWinCondition* win_condition): width_(width), height_(height) {
    new GameManager(15, 13, win_condition);
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

    switch (player_count) {
        case 4:
            players[3] = Player::CreatePlayer((width_ - 2), 1, player_keys[3], graphics::kPlayer2Tiles, 4);
        case 3:
            players[2] = Player::CreatePlayer(1, (height_ - 2), player_keys[2], graphics::kPlayer1Tiles, 3);
        case 2:
            players[1] = Player::CreatePlayer((width_ - 2), (height_ - 2), player_keys[1], graphics::kPlayer2Tiles, 2);
        case 1:
            players[0] = Player::CreatePlayer(1, 1, player_keys[0], graphics::kPlayer1Tiles, 1);
    }
}

void StartClassicGame() {
    GameFactory factory = GameFactory(15, 13, new win_condition::StandardWinCondition());
    factory.GenerateGame(2, 85);

    core::AppManager& app = core::AppManager::GetAppManager();

    app.ChangeBackgroundColor(graphics::Color(113,104,98,0));

    GameWindow * game_window = new GameWindow();
    app.SetActiveWindow(*game_window);

    app.GetSound().PlayRandomBattleMusic();
}

void StartSinglePlayerGame() {
    SinglePlayerGameWindow * game_window = new SinglePlayerGameWindow();

    GameFactory factory = GameFactory(15, 13, new win_condition::SinglePlayerWinCondition(game_window));
    factory.GenerateGame(1, 85);

    core::AppManager& app = core::AppManager::GetAppManager();

    app.ChangeBackgroundColor(graphics::Color(113,104,98,0));

    app.SetActiveWindow(*game_window);

    app.GetSound().PlayRandomBattleMusic();
}

} // namespace game
