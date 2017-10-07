#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/algorithm.h>
#include <CGAL/bounding_box.h>
#include <iostream>

using namespace std;

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef K::FT FT;
typedef K::Point_2 Point;
typedef K::Segment_2 Segment;
typedef K::Iso_rectangle_2 Rect;
typedef CGAL::Polygon_2<K> Polygon_2;

bool doIntersect(Segment, list<Segment>);

int main()
{
    // Define points
}

bool doIntersect(Segment line, list<Segment> lines)
{
    /**
     * Check if the passed line segments intersects with any of the
     * lines inside the given list of lines without checking for the
     * line that is an exception.
     */
    for (auto& current : lines) {
        cout << "Segments just tested :" << current << " " << line << endl;
        if (CGAL::do_intersect(line, current)) return true;
    }
    return false;
}
