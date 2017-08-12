#include <algorithm>  // For the sort function
#include <cstdlib>    // For the rand() function
#include <ctime>      // For the time function
#include <iostream>
#include <list>

using namespace std;

struct Point {
  double x;
  double y;
  double slope;
  Point() {
    this->x = 0.0;
    this->y = 0.0;
    this->slope = 0.0;
  }
};

bool comparePoint(Point, Point);

int main()
{
    list<Point> points;
    srand((unsigned int)time(NULL));  // use current time as seed for random generator
    for (int i = 0; i < 10; ++i) {
        int random_var = rand();
        Point a;
        a.slope = i * 1.0 * random_var;
        points.push_back(a);
    }
    points.sort(comparePoint);
    for (list<Point>::iterator it = points.begin(); it != points.end(); ++it) {
        cout << "-- " << it->slope << " --\n";
    }
}

bool comparePoint(Point a,Point b)
{
    /**
     * Compare a return the point with the biggest slope, in boolean
     * values
     */
    return (a.slope > b.slope);
}
