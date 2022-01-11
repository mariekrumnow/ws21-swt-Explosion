//
// Created by Dennis Neuhaus on 11.01.22.
//

#include <boost/test/unit_test.hpp>
#include "../../core/AppManager.h"
#include "../../menu/MenuWindow.h"
#include "../../menu/InstructionWindow.h"

namespace menu {

    BOOST_AUTO_TEST_SUITE(InstructionWindowTest)

        BOOST_AUTO_TEST_CASE(InstructionWindowTest) {
            //Set up environment
            core::AppManager* app = new core::AppManager("",false);

            auto* window = new InstructionWindow();

            app->SetActiveWindow(*window);


            BOOST_CHECK(window);

            delete window;
            delete app;
        }

    BOOST_AUTO_TEST_SUITE_END()

} //namespace menu