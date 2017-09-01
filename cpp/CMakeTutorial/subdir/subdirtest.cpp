#include "subdirtest.hpp"
#include <iostream>

using namespace std;

void testFunction(int testing)
/**
 * This is just a test function that is void
 */
{
    cout << "The parameter passed is" << testing;
    cout << "The test value is" << returnTest(2.0);
}
double returnTest(double testVal)
/**
 * This is just a test function that returns a value
 */
{
    return 2.0 * testVal;
}
