//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <GameManager.h>
#include <GameFactory.h>

namespace game {
    BOOST_AUTO_TEST_SUITE(GameFactoryTest)

        BOOST_AUTO_TEST_CASE(GameFactoryTest) {
            std::cout << "Start GameFactoryTest" << std::endl;

            core::AppManager* app = new core::AppManager("",false);

            StartClassicGame();

            GameManager& manager = GameManager::GetCurrentGame();

            BOOST_CHECK(manager.GetPlayers().size() == 2);

            delete &manager;

            delete app;

        }

    BOOST_AUTO_TEST_SUITE_END()

} // namespace game
