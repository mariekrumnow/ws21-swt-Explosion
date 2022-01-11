//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include "../../core/AppManager.h"
#include "../../menu/MenuWindow.h"
#include "../../menu/GameOverWindow.h"
#include <iostream>

namespace menu {

BOOST_AUTO_TEST_SUITE(GameOverWindowTest)

    BOOST_AUTO_TEST_CASE(GameOverWindowTest) {
        std::cout << "Start GameOverWindowTest" << std::endl;
        //Set up environment
        auto* app = new core::AppManager("",false);
        auto* manager = new game::GameManager(10,10, nullptr);


        graphics::PlayerKeys player_keys{};

        player_keys.up = graphics::key_w;
        player_keys.down = graphics::key_s;
        player_keys.left = graphics::key_a;
        player_keys.right = graphics::key_d;
        player_keys.bomb = graphics::key_l_shift;

        game::Player* player = game::Player::CreatePlayer(5,5, player_keys,
                                          graphics::PlayerTile(graphics::kTileEmpty,graphics::kTileEmpty
                                                  ,graphics::kTileEmpty,graphics::kTileEmpty), 0);


        auto* window = new GameOverWindow(player);

        app->SetActiveWindow(*window);


        BOOST_CHECK(window);

        delete window;
        delete manager;
        delete app;
    }

BOOST_AUTO_TEST_SUITE_END()

} //namespace menu