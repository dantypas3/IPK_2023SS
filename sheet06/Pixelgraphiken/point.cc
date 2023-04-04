#include "point.hh"

//Default Constructor
Point::Point() :_x(0), _y(0) {}

//Gives value of x to _x
Point::Point(double x, double y) : _x(x), _y(y) {}

//Method for get _X
double Point::x() const {
    return _x;
}

//Method for get_y
double Point::y() const {
    return _y;
}