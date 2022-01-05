set(Boost_USE_STATIC_LIBS OFF)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)
if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
endif()
include_directories(${Boost_INCLUDE_DIRS})

add_executable(tests AppManagerTest.cc)

target_link_libraries(tests ${Boost_LIBRARIES})
target_link_libraries(tests core)
target_link_libraries(tests graphics)
target_link_libraries(tests game)