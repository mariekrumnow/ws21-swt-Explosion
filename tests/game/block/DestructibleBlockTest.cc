//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <block/DestructibleBlock.h>
#include <GameWindow.h>
#include <iostream>

namespace game {
namespace obstacles {

BOOST_AUTO_TEST_SUITE(DestructibleBlockTests)

    BOOST_AUTO_TEST_CASE(DestructibleBlockTests) {
        std::cout << "Start DestructibleBlockTest" << std::endl;

        //Set up environment
        auto* app = new core::AppManager("",false);
        auto* window = new GameWindow();
        auto* manager = new GameManager(10,10, nullptr);
        app->SetActiveWindow(*window);

        DestructibleBlock* block = DestructibleBlock::CreateDestructibleBlock(0,0);

        BOOST_CHECK(block);

        block->OnExplosion(*block);
        BOOST_CHECK(block->GetDestroyed());

        delete manager;
        delete window;
        delete app;
    }

BOOST_AUTO_TEST_SUITE_END()


} // namespace obstacles

} // namespace game