#ifndef POINT_HPP
#define POINT_HPP

class Point
{
   private:
    double X;
    double Y;

   public:
    Point()
    {
        this->X = 0.0;
        this->Y = 0.0;
    }
    Point(double x_cord, double y_cord)
    {
        this->X = x_cord;
        this->Y = y_cord;
    }
    double x() const
    {
        return this->X;
    }
    double y() const
    {
        return this->Y;
    }
    int whichQuadrant() const
    {
        /**
         * Returns the quadrant in which the point lies
         */
        if (this->X >= 0 && this->Y >= 0)
            return 1;
        else if (this->X >= 0 && this->Y < 0)
            return 2;
        else if (this->X < 0 && this->Y < 0)
            return 3;
        else
            return 4;
    }
};

#endif /* POINT_HPP */
