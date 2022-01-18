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

            auto* app = new core::AppManager("",false);

            StartClassicGame();

            auto& manager = GameManager::GetCurrentGame();

            BOOST_CHECK(manager.GetPlayerCount() == 2);

            // workaround to delete current game manager
            auto* managerPtr = new GameManager(10,10, nullptr);
            delete managerPtr;

            delete app;

        }

    BOOST_AUTO_TEST_SUITE_END()

} // namespace game