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
    Point a1(9.3, 5.5);
    Point b1(9.3, 5.5);

    Point a2(9.3, 5.5);
    Point b2(9.3, 5.5);

    Segment one(a1, b1);
    Segment two(a2, b2);

    if (CGAL::do_intersect(one, two))
        std::cout << "These lines intersect" << std::endl;  // This is correct
    else
        std::cout << "These lines doesn't intersect" << std::endl;

    return 0;
}
