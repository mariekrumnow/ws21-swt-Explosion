//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <GameManager.h>

namespace game {
    BOOST_AUTO_TEST_SUITE(GameObjectTest)

        BOOST_AUTO_TEST_CASE(GameObjectTest) {
            std::cout << "Start GameObjectTest" << std::endl;

            auto* manager = new GameManager(10,10, nullptr);


            // GameObject is a pure virtual class


            delete manager;
        }

    BOOST_AUTO_TEST_SUITE_END()

} // namespace game