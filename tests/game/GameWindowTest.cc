//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <GameWindow.h>
#include "../../core/AppManager.h"

namespace game {
BOOST_AUTO_TEST_SUITE(GameWindowTest)

    BOOST_AUTO_TEST_CASE(GameWindowTest) {
        //Set up environment
        core::AppManager* app = new core::AppManager("",false);

        GameWindow* window = new GameWindow();

        BOOST_CHECK(window);

        delete window;
        delete app;

    }

BOOST_AUTO_TEST_SUITE_END()
}