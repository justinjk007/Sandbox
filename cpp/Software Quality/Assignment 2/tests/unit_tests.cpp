#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../dependencies/catch.hpp"
#include "../src/helper.hpp"

using namespace std;

TEST_CASE("Default case")
{
    // Default case returns 0
    char entries[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int result = checkIfWinning(&entries[0]);
    REQUIRE(result == 0);
}

TEST_CASE("Player 1 wins case")
{
    char entries[10] = {'0', 'X', 'O', '3', 'X', '5', '6', 'X', '8', 'O'};
    int result = checkIfWinning(&entries[0]);
    REQUIRE(result == 1);
}

TEST_CASE("Player 2 wins case")
{
    char entries[10] = {'0', 'X', 'X', 'O', 'X', 'O', '7', 'O', '8', 'X'};
    int result = checkIfWinning(&entries[0]);
    REQUIRE(result == 1);
}

TEST_CASE("Game is draw case")
{
    char entries[10] = {'0','X', 'O', 'X', 'O', 'X', 'X', 'O', 'X', 'O',};
    int result = checkIfWinning(&entries[0]);
    REQUIRE(result == -1);
}
