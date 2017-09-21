/**
 * Randomly generate polygons of size under 1000 sides or less
 */
#include <algorithm>
#include <chrono>
#include <iostream>
#include <list>

using namespace std;

class Point
{
   public:
    double x_val;
    double y_val;
    Point()
    {
        /**
         * This is the default constructor
         */
        this->x_val = 0;
        this->y_val = 0;
    }
    Point(double x_cord, double y_cord)
    {
        /**
         * This constructor creates objects with the values passed in
         */
        this->x_val = x_cord;
        this->y_val = y_cord;
    }
    double Point::x()
    {
        return this->x_val;
    }
    double Point::y()
    {
        return this->y_val;
    }
};

Point centroid;

Point getCentroid(std::list<Point> points)
{
    /**
     * Returns the centroid of the given list of points
     */
    double sum_x = 0.0, sum_y = 0.0;
    int count = 0;
    for (list<Point>::iterator it = points.begin(); it != points.end(); it++) {
        count++;
        sum_x += it->x();
        sum_y += it->y();
    }
    Point center(sum_x / count, sum_y / count);  // Getting the average of the points
    return center;
}

bool comparePoints(Point a, Point b)
{
    /**
     * Compare points based on there angle with centroid
     * https://stackoverflow.com/questions/6989100/sort-points-in-clockwise-order
     */

    if (a.x() - centroid.x() >= 0 && b.x() - centroid.x() < 0) return true;
    if (a.x() - centroid.x() < 0 && b.x() - centroid.x() >= 0) return false;
    if (a.x() - centroid.x() == 0 && b.x() - centroid.x() == 0) {
        if (a.y() - centroid.y() >= 0 || b.y() - centroid.y() >= 0) return (a.y() > b.y());
        return (b.y() > a.y());
    }

    int det, d1, d2;

    // Compute the cross product of vectors (centroid -> a) x (centroid -> b)
    det = (a.x() - centroid.x()) * (b.y() - centroid.y()) -
          (b.x() - centroid.x()) * (a.y() - centroid.y());
    if (det < 0) return true;
    if (det > 0) return false;

    // Points a and b are on the same line from the center
    // Check which point is closer to the center
    d1 = (a.x() - centroid.x()) * (a.x() - centroid.x()) +
         (a.y() - centroid.y()) * (a.y() - centroid.y());
    d2 = (b.x() - centroid.x()) * (b.x() - centroid.x()) +
         (b.y() - centroid.y()) * (b.y() - centroid.y());
    return d1 > d2;
}

std::list<Point> sortClockwise(std::list<Point> points)
{
    /**
     * Sort the given points in the list in a clockwise order.
     */
    centroid = getCentroid(points);
    points.sort(comparePoints);
    return points;
    // det = (a.x - centroid.x) * (b.y - centroid.y) - (b.x - centroid.x) * (a.y - centroid.y)
}

int main()
{
    auto start = chrono::high_resolution_clock::now();  // Start clock
    int size   = 200;

    list<int> data_x(size);
    list<int> data_y(size);
    list<Point> points(size);
    generate(data_x.begin(), data_x.end(), rand);  // Populate with random numbers
    generate(data_y.begin(), data_y.end(), rand);  // Populate with random numbers

    auto it1 = data_x.begin();
    auto it2 = data_y.begin();
    auto it3 = points.begin();
    for (; it3 != points.end(); ++it1, ++it2, ++it3) {
        // Genreate points
        *it3 = Point(*it1, *it2);
    }

    points = sortClockwise(points);

    it3 = points.begin();
    cout << "{";
    for (; it3 != points.end(); ++it3) {
        // Display points
        cout << "{" << it3->x() << "," << it3->y() << "},";
    }
    cout << "}";

    auto finish                      = chrono::high_resolution_clock::now();  // Stop clock
    chrono::duration<double> elapsed = finish - start;                        // Mesure time elapsed
    cout << "\n------ Elapsed time: " << elapsed.count() << " s ------\n";

    return 0;
}
