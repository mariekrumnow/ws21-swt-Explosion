//Autor: Tobias
#include "../../../core/AppManager.h"
#include "../../../game/GameWindow.h"
#include "../../../game/GameManager.h"
#include "../../../game/bomb/Explosion.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

namespace game {
namespace bomb {

BOOST_AUTO_TEST_SUITE(ExplosionTest)
	BOOST_AUTO_TEST_CASE(ExplosionTest) {
        std::cout << "Start ExplosionTest" << std::endl;
		//Set up environment
		core::AppManager* app = new core::AppManager("",false);
		GameWindow* window = new GameWindow();
		GameManager* manager = new GameManager(10,10, nullptr);
		app->SetActiveWindow(*window);

		//spawn explosion
		Explosion* explosion = Explosion::CreateExplosion(0,0,0);
		BOOST_CHECK(explosion);

		//check it disappears after the correct amount of time
		app->RunFrame(explosion->kExplosionDuration);
		BOOST_CHECK(explosion->GetDestroyed());

		delete manager;
		delete window;
		delete app;

	}

BOOST_AUTO_TEST_SUITE_END()

} //namespace bomb
} //namespace game
