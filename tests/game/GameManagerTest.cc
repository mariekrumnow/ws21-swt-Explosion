//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <GameManager.h>
#include <block/IndestructibleBlock.h>
#include "../../game/Player.h"

namespace game {
    BOOST_AUTO_TEST_SUITE(GameManagerTest)

        BOOST_AUTO_TEST_CASE(GameManagerTest) {
            std::cout << "Start GameManagerTest" << std::endl;

            auto* manager = new GameManager(10,10, nullptr);

            BOOST_CHECK(manager);

            BOOST_CHECK(manager == &GameManager::GetCurrentGame());

            auto* block = new obstacles::IndestructibleBlock();

            manager->AddGameObject(*block);

            BOOST_CHECK(manager->GetAllObjects().size() == 1);

            // TODO: Problem with manager deletion when destroying the game object
            manager->DestroyGameObject(*block);
            BOOST_CHECK(manager->GetAllObjects().empty());

            BOOST_CHECK(manager->GetPlayers().size() == 0);

            //Spawn player
            graphics::PlayerKeys player_keys{};

            player_keys.up = graphics::key_w;
            player_keys.down = graphics::key_s;
            player_keys.left = graphics::key_a;
            player_keys.right = graphics::key_d;
            player_keys.bomb = graphics::key_l_shift;

            Player* player = Player::CreatePlayer(5,5, player_keys,
                                                  graphics::PlayerTile(graphics::kTileEmpty, graphics::kTileEmpty,
                                                                       graphics::kTileEmpty,graphics::kTileEmpty), 0);

            BOOST_CHECK(manager->GetPlayers().size() == 1);

            delete manager;

        }

    BOOST_AUTO_TEST_SUITE_END()

} // namespace game
