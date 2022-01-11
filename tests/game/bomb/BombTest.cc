//Autor: Tobias
#include "../../../core/AppManager.h"
#include "../../../game/GameWindow.h"
#include "../../../game/GameManager.h"
#include "../../../game/bomb/Bomb.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

namespace game {
namespace bomb {

BOOST_AUTO_TEST_SUITE(BombTest)
	BOOST_AUTO_TEST_CASE(BombTest) {
        std::cout << "Start BombTest" << std::endl;

		//Set up environment
		core::AppManager* app = new core::AppManager("",false);
		GameWindow* window = new GameWindow();
		GameManager* manager = new GameManager(10,10, nullptr);
		app->SetActiveWindow(*window);



		//Create Bomb with explosion power 2, 1 second explosion delay
		Bomb* bomb1 = Bomb::CreateBomb(5,5, nullptr, 2, 1);
		BOOST_CHECK(bomb1);

		//Run game for 1 second, so bomb explodes
		app->RunFrame(1);
		//bomb should spawn 9 explosions, 2 in each direction, 1 in center
		BOOST_CHECK(manager->GetAllObjects().size() == 9);

		//run for 3 seconds so explosions despawn
		app->RunFrame(3);

		//spawn two bombs next to each other
		//(one 2 seconds delay, other 1, so one explodes first)
		Bomb* bomb2 = Bomb::CreateBomb(5,5, nullptr, 1, 1);
		Bomb* bomb3 = Bomb::CreateBomb(4,5, nullptr, 1, 2);

		//trigger one, check that they triggered each other
		app->RunFrame(1);
		BOOST_CHECK(bomb2->GetDestroyed());
		BOOST_CHECK(bomb3->GetDestroyed());

		delete manager;
		delete window;
		delete app;
	}

BOOST_AUTO_TEST_SUITE_END()

} //namespace bomb
} //namespace game
