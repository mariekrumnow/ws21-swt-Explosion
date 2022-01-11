//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <block/IndestructibleBlock.h>
#include <GameWindow.h>
#include <iostream>

namespace game {
    namespace obstacles {

        BOOST_AUTO_TEST_SUITE(IndestructibleBlockTest)

            BOOST_AUTO_TEST_CASE(IndestructibleBlockTest) {
                std::cout << "Start IndestructibleBlockTest" << std::endl;

                //Set up environment
                auto* app = new core::AppManager("",false);
                auto* window = new GameWindow();
                auto* manager = new GameManager(10,10, nullptr);
                app->SetActiveWindow(*window);

                IndestructibleBlock* block = IndestructibleBlock::CreateIndestructibleBlock(0,0);

                BOOST_CHECK(block);

                block->OnExplosion(*block);
                BOOST_CHECK(block);

                delete manager;
                delete window;
                delete app;
            }

        BOOST_AUTO_TEST_SUITE_END()


    } // namespace obstacles

} // namespace game