//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <GameWindow.h>
#include <GameManager.h>
#include <win_condition/StandardWinCondition.h>
#include <iostream>

namespace game {
namespace win_condition {
BOOST_AUTO_TEST_SUITE(StandardWinConditionTest)

    BOOST_AUTO_TEST_CASE(StandardWinConditionTest) {
        std::cout << "Start AppManagerTest" << std::endl;
        //Set up environment
        core::AppManager* app = new core::AppManager("",false);
        GameWindow* window = new GameWindow();
        BaseWinCondition* win_condition = new StandardWinCondition();
        GameManager* manager = new GameManager(10,10, win_condition);
        app->SetActiveWindow(*window);

        BOOST_CHECK(win_condition);

        delete manager;
        delete window;
        delete app;
    }

BOOST_AUTO_TEST_SUITE_END()
} // namespace win_condition
} // namespace game