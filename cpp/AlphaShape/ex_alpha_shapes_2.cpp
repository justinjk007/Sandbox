#include <CGAL/Alpha_shape_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/algorithm.h>

#include <fstream>
#include <iostream>
#include <list>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;

typedef K::FT FT;
typedef K::Point_2 Point;
typedef K::Segment_2 Segment;

typedef CGAL::Alpha_shape_vertex_base_2<K> Vb;
typedef CGAL::Alpha_shape_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K, Tds> Triangulation_2;

typedef CGAL::Alpha_shape_2<Triangulation_2> Alpha_shape_2;
typedef Alpha_shape_2::Alpha_shape_edges_iterator Alpha_shape_edges_iterator;

template <class OutputIterator>
void alpha_edges(const Alpha_shape_2& A, OutputIterator out)
{
    for (Alpha_shape_edges_iterator it = A.alpha_shape_edges_begin();
         it != A.alpha_shape_edges_end(); ++it) {
        *out++ = A.segment(*it);
    }
}

template <class OutputIterator>
bool file_input(OutputIterator out)
{
    std::ifstream is("fin2.dat", std::ios::in);

    if (is.fail()) {
        std::cerr << "unable to open file for input" << std::endl;
        return false;
    }

    int n;
    is >> n;
    std::cout << "Reading " << n << " points from file" << std::endl;
    CGAL::cpp11::copy_n(std::istream_iterator<Point>(is), n, out);

    return true;
}

void writeToFile(std::list<Segment> lines)
{
    /**
     * Write the points to file , for plotting and stuff
     */
    std::ofstream myfile;
    std::string file_name = "rawData.csv";
    myfile.open(file_name);
    myfile << "x,y\n";
    std::list<Segment>::iterator it = lines.begin();
    while (it != lines.end()) {
      myfile << it->source().x() << "," << it->source().y() << "\n";
      myfile << it->target().x() << "," << it->target().y() << "\n";
        ++it;
    }
    myfile.close();
}

// Reads a list of points and returns a list of segments
// corresponding to the Alpha shape.
int main()
{
    std::list<Point> points;
    if (!file_input(std::back_inserter(points))) {
        return -1;
    }

    Alpha_shape_2 A(points.begin(), points.end(), FT(20), Alpha_shape_2::GENERAL);
    std::list<Segment> segments;
    alpha_edges(A, std::back_inserter(segments));
    writeToFile(segments);
    std::cout << "Alpha Shape computed" << std::endl;
    std::cout << segments.size() << " alpha shape edges" << std::endl;
    std::cout << "Optimal alpha: " << *A.find_optimal_alpha(1) << std::endl;

    /**
     // Point_2 point(2.0, 1.0);
     * Points can be defined like the declaration above, include
     * respected headers and typedefs from * this file thou
     */

    return 0;
}
