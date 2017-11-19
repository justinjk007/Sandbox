#include "solution.hpp"
#include <iostream>

using namespace std;

double getSlope(const Point& a, const Point& b)
{
    /**
     * Get slope of the line made by the given points
     */
    double diff_y = a.y() - b.y();
    double diff_x = a.x() - b.x();
    double m      = diff_y / diff_x;
    return m;
}

int whichQuadrant(const double& angle)
{
    /**
     * Returns the quadrant in which the direction angle will lie on
     */
    if (angle >= 0 && angle <= 90)
        return 1;
    else if (angle > 90 && angle <= 180)
        return 2;
    else if (angle > 180 && angle <= 270)
        return 3;
    else
        return 4;
}

Point getCurrentSatellitePostion(const Signal& signal)
{
    /**
     * Returns the position of the satlite after movement
     */
    double inc_angle;
    double slope;
    double x, y;
    if (signal.direction <= 90.0)
        inc_angle = 90.0 - signal.direction;  // Inclination angle
    else
        inc_angle = 360.0 - signal.direction;
    double sat_travel = signal.sat_speed * signal.time_send;  // Distace travelled by satellite
                                                              // after reference before sending the
                                                              // signal back;
    if ((inc_angle - 90.0) < 0.001)
        slope = NULL;  // Slope is undefined, line is parallel to y-axis
                       // http://www.thefreemathtutor.com/JPG/posnegzeroundexamples.jpg
    else
        slope = tan(inc_angle * PI / 180.0);

    if (slope != NULL) {
        x = signal.location.x() + sqrt(pow(sat_travel, 2.0) / (1.0 + pow(slope, 2.0)));
        y = sqrt(pow(sat_travel, 2.0) - pow(x - signal.location.x(), 2.0)) + signal.location.y();
    } else {
        x = signal.location.x();  // x doesn't change when slope is undefined
        y = sqrt(pow(sat_travel, 2.0) - pow(x - signal.location.x(), 2.0)) + signal.location.y();
    }

    Point loc_untested(x, y);  // Location point is generated

    if (loc_untested.whichQuadrant() == whichQuadrant(signal.direction))
        return loc_untested;  // We have the correct points
    else                      // Make points great again!!
    {
        if (slope != NULL) {
            x = signal.location.x() - sqrt(pow(sat_travel, 2.0) / (1.0 + pow(slope, 2.0)));
            y = sqrt(pow(sat_travel, 2.0) - pow(x - signal.location.x(), 2.0)) +
                signal.location.y();
        } else {
            x = signal.location.x();  // x doesn't change when slope is undefined
            y = sqrt(pow(sat_travel, 2.0) + pow(x - signal.location.x(), 2.0)) -
                signal.location.y();
        }
    }

    Point loc(x, y);
    return loc_untested;
}
