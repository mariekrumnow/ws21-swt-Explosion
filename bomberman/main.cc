//Autor: Tobias


#define BOOST_TEST_MODULE test
#include <boost/test/unit_test.hpp>
#include <iostream>


//Enable to run boost tests in project
#define RUN_BOOST_TESTS 1


#if !RUN_BOOST_TESTS

int main()
{
    std::cout << "Hello World!\n";
}

#else

#define BOOST_TEST_MAIN

#endif

BOOST_AUTO_TEST_CASE(ExampleTest) {
    BOOST_CHECK(true);
}
