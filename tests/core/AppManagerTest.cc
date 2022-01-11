//
// Created by Dennis Neuhaus on 11.01.22.
//
#include <boost/test/unit_test.hpp>
#include "../../core/AppManager.h"
#include <iostream>

namespace core {
    BOOST_AUTO_TEST_SUITE(AppManagerTest)

        BOOST_AUTO_TEST_CASE(AppManagerTest) {
            std::cout << "Start AppManagerTest" << std::endl;
            auto* app = new core::AppManager("",false);

            BOOST_CHECK(app);

            BOOST_CHECK(app->LoadTheme("default"));

            BOOST_CHECK(app->LoadTheme("halloween"));

            BOOST_CHECK(app->LoadTheme("farm"));

            BOOST_CHECK(app->LoadTheme("corona"));

            delete app;
        }

    BOOST_AUTO_TEST_SUITE_END()
} // namespace core