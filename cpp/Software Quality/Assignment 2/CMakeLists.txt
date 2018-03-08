cmake_minimum_required (VERSION 3.2)
project (tic-tac-toe)

add_executable(tic-tac-toe src/main.cpp src/helper.cpp)
add_executable(run_unit_tests tests/unit_tests.cpp src/helper.cpp)
