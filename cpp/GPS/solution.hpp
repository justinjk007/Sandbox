#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "point.hpp"
#include "signal.hpp"
#include <vector>
#include <math.h>

const double PI = 3.14159265;

double getSlope(const Point&, const Point&);
Point getLocation(const std::vector<Signal>&);
Point getCurrentSatellitePostion(const Signal&);
int whichQuadrant(const double&);

#endif /* SOLUTION_HPP */
