//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include <GameWindow.h>
#include <GameManager.h>
#include <win_condition/StandardWinCondition.h>

namespace game {
namespace win_condition {
BOOST_AUTO_TEST_SUITE(WinConditionTest)

    BOOST_AUTO_TEST_CASE(WinConditionTest) {
        //Set up environment
        core::AppManager* app = new core::AppManager("",false);
        GameWindow* window = new GameWindow();
        BaseWinCondition* win_condition = new StandardWinCondition();
        GameManager* manager = new GameManager(10,10, win_condition);
        app->SetActiveWindow(*window);

        BOOST_CHECK(win_condition->checkWin() == true);

        // Add players here

        BOOST_CHECK(win_condition->checkWin() == false);
    }

BOOST_AUTO_TEST_SUITE_END()
} // namespace win_condition
} // namespace game