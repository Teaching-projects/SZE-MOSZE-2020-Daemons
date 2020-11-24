cmake_minimum_required(VERSION 2.6)
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
# Link runTests with what we want to test 
# and the GTest and pthread library
add_executable(coreunit_test all_unittests.cpp ../Hero.cpp ../Monster.cpp ../JSON.cpp ../Map.cpp )
target_link_libraries(coreunit_test ${GTEST_LIBRARIES} pthread)