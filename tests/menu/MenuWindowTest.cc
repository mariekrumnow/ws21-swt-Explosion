//Autor: Tobias

//Autor: Tobias
#include "../../core/AppManager.h"
#include "../../menu/MenuWindow.h"
#include "../../menu/MenuItem.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

namespace menu {

BOOST_AUTO_TEST_SUITE(MenuWindowTest)

	BOOST_AUTO_TEST_CASE(MenuWindowTest) {
		//Set up environment
		core::AppManager* app = new core::AppManager("",false);

		//set up menu window
		MenuWindow* menu = new MenuWindow(1);
		menu->AddMenuItem(MenuItem("Test1",0,0,0));
		menu->AddMenuItem(MenuItem("Test2",1,1,1));
		app->SetActiveWindow(*menu);

		//check if setup worked properly
		app->RunFrame(1);
		BOOST_CHECK(menu->GetMenuItems().size() == 2);

		delete menu;
		delete app;
	}

BOOST_AUTO_TEST_SUITE_END()

} //namespace menu
