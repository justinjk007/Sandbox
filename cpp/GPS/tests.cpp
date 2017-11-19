#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <chrono>
#include <iostream>
#include "catch.hpp"
#include "point.hpp"
#include "solution.hpp"
#include "signal.hpp"

using namespace std;

TEST_CASE("Sample Test")  // Delete this
{
    int a = 1, b = 0;
    CHECK(b == 0);
    REQUIRE(a == Approx(1).epsilon(0.0001));  // Epsilon is tolerance
}

TEST_CASE("Testing satellite location")  // Delete this
{
    Signal one(Point(-100.0,350.0),90.0,1.75);
    Point loc = getCurrentSatellitePostion(one);
    CHECK(loc.x() == Approx(1).epsilon(0.1));
    CHECK(loc.y() == Approx(1).epsilon(0.1));
}
