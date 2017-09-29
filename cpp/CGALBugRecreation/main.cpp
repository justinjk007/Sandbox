#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/algorithm.h>
#include <CGAL/bounding_box.h>
#include <iostream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef K::FT FT;
typedef K::Point_2 Point;
typedef K::Segment_2 Segment;
typedef K::Iso_rectangle_2 Rect;
typedef CGAL::Polygon_2<K> Polygon_2;

int main()
{
    Point a1(2.49462, 7.6909);
    Point b1(6.54268, 4.75606);

    Point a2(4.51865, 6.22348);
    Point b2(21.1579, 6.22348);

    Segment one(a1, b1);
    Segment two(a2, b2);

    if (CGAL::do_intersect(one, two))
        std::cout << "These lines intersect" << std::endl;  // This is correct
    else
        std::cout << "These lines doesn't intersect" << std::endl;

    return 0;
}
