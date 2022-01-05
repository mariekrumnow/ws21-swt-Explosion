//Autor: Tobias
#include "../../../core/AppManager.h"
#include "../../../game/GameWindow.h"
#include "../../../game/GameManager.h"
#include "../../../game/upgrade/SpeedUpgrade.h"
#include "../../../game/Player.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

namespace game {
namespace upgrade {

BOOST_AUTO_TEST_SUITE(SpeedUpgradeTest)
	BOOST_AUTO_TEST_CASE(SpeedUpgradeTest) {
		//Set up environment
		core::AppManager* app = new core::AppManager("",false);
		GameWindow* window = new GameWindow();
		GameManager* manager = new GameManager(10,10, nullptr);
		app->SetActiveWindow(*window);

		//Spawn player at 5,5 to collect upgrade
		graphics::PlayerKeys player_keys;
	    player_keys.up = graphics::key_w;
	    player_keys.down = graphics::key_s;
	    player_keys.left = graphics::key_a;
	    player_keys.right = graphics::key_d;
	    player_keys.bomb = graphics::key_l_shift;
		Player* player = Player::CreatePlayer(5,5, player_keys,
			graphics::PlayerTile(graphics::kTileEmpty,graphics::kTileEmpty
				,graphics::kTileEmpty,graphics::kTileEmpty), 0);

		//spawn upgrade at 0,0
		SpeedUpgrade* upgrade1 = SpeedUpgrade::CreateSpeedUpgrade(0,0);
		BOOST_CHECK(upgrade1);

		//collect the upgrade
		player->SetPosition(0,0);
		BOOST_CHECK(upgrade1->GetDestroyed());
		BOOST_CHECK(player->GetSpeed() == 1);

		//spawn new upgrade
		SpeedUpgrade* upgrade2 = SpeedUpgrade::CreateSpeedUpgrade(1,1);

		//blow it up
		upgrade2->OnExplosion(*player);
		BOOST_CHECK(upgrade2->GetDestroyed());

		delete manager;
		delete window;
		delete app;
	}

BOOST_AUTO_TEST_SUITE_END()

} //namespace upgrade
} //namespace game
