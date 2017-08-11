#include <algorithm>  // For the sort function
#include <cstdlib>    // For the rand() function
#include <ctime>      // For the time function
#include <iostream>
#include <list>
#include "Point.hpp"

using namespace std;

Point comparePoint(Point, Point);

int main()
{
    list<Point> points;
    for (int i = 0; i < 100; ++i) {
        srand((unsigned int)time(NULL));  // use current time as seed for random generator
        int random_var = rand();
        Point a;
        a.slope = i * 1.0 * random_var;
        points.push_back(a);
    }
    sort(points.begin(), points.end(), comparePoint);
}

Point comparePoint(const Point& a, const Point& b)
{
    /**
     * Compare a return the point with the biggest slope
     */
    if (a.slope > b.slope) return a;
    return b;
}
