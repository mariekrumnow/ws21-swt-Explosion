//Author: Tobias
#include "AppManager.h"

#include <boost/test/unit_test.hpp>

namespace core {

	BOOST_AUTO_TEST_SUITE(AppManagerTests)

	BOOST_AUTO_TEST_CASE(SingletonTest) {
			//test if the app managers singleton mechanic is working
			AppManager test_1 = AppManager(false);
	    BOOST_CHECK(&AppManager::GetAppManager() == &test_1);

			AppManager test_2 = AppManager(false);
			BOOST_CHECK(&AppManager::GetAppManager() == &test_2);
	}

	BOOST_AUTO_TEST_SUITE_END()
}
