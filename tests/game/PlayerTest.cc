//Autor: Tobias
#include "../../core/AppManager.h"
#include "../../game/GameWindow.h"
#include "../../game/GameManager.h"
#include "../../game/Player.h"
#include "../../graphics/Keys.h"
#include "../../graphics/Tile.h"

#include <boost/test/unit_test.hpp>
#include <iostream>

namespace game {

BOOST_AUTO_TEST_SUITE(PlayerTests)

	BOOST_AUTO_TEST_CASE(PlayerTest) {
        std::cout << "Start PlayerTest" << std::endl;
		//Set up environment
		core::AppManager* app = new core::AppManager("",false);
		GameWindow* window = new GameWindow();
		GameManager* manager = new GameManager(10,10, nullptr);
		app->SetActiveWindow(*window);

		//Spawn player
		graphics::PlayerKeys player_keys;

	    player_keys.up = graphics::key_w;
	    player_keys.down = graphics::key_s;
	    player_keys.left = graphics::key_a;
	    player_keys.right = graphics::key_d;
	    player_keys.bomb = graphics::key_l_shift;
		
		Player* player = Player::CreatePlayer(5,5, player_keys,
			graphics::PlayerTile(graphics::kTileEmpty,graphics::kTileEmpty
				,graphics::kTileEmpty,graphics::kTileEmpty), 0);

		BOOST_CHECK(player);

		//Check stat upgrade
		player->IncreaseSpeed(1);
		player->IncreaseExplosionRadius(1);
		player->IncreaseMaxBombCount(1);

		BOOST_CHECK(player->GetSpeed() == 1);
		BOOST_CHECK(player->GetExplosionRadius() == 2);
		BOOST_CHECK(player->GetMaxBombCount() == 2);

		//check Bomb placement
		BOOST_CHECK(player->PlaceBomb(0,0));
		BOOST_CHECK(manager->GetObjectsAtPos(0,0).size() == 1);

		//blow up player
		player->OnExplosion(*player);
		BOOST_CHECK(player->GetDestroyed());

		delete manager;
		delete window;
		delete app;
	}

BOOST_AUTO_TEST_SUITE_END()

} //namespace game
