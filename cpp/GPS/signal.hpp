#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include "point.hpp"

class Signal
{
   public:
    Point location;    // Location when signal received from gps
    double direction;  // Angle at which the satelite was moving
    double time_send;  // Time the signal was send at location second Point
    double speed;      // Speed of the signal, always constant
    double sat_speed;  // Speed of the satelite, always considered a constant here
    Signal(Point loc, double dir, double time)
    {
        this->location  = loc;
        this->direction = dir;
        this->time_send = time;
        this->speed     = 350.0;  // Speed in m/s
	this->sat_speed = 100.0;  // Speed in m/s
    }
};

#endif /* SIGNAL_HPP */
