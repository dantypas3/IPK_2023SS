#ifndef POINT_HH
#define POINT_HH

#include<array>
#include<cmath>
// because Point is now a template the functions which use the template parameter must be declared in the .h file
// further reading: https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl


template<typename Coord, int dim>
class Point {

//using Coord Coordinate      // export of the coordinate type

private:
    std::array<Coord, dim> coordinates;

public:
    static const int dimension = dim;

    // default constructor, built origin
    Point(){
        for(Coord& x : coordinates) {
            x = 0;
        }
    }

    // initialise point with array
    Point(std::array<Coord, dim> coords) {
        coordinates = coords;
    }

    // get i-th coordinate
    Coord& x(int i) {
        return coordinates[i];
    }
    
    // calculate norm of point
    // doesn't change the point because the funciton is constant
    double norm() const {
        double sum = 0;
        for(Coord x : coordinates) {
            sum += std::pow(x, 2);
        }
        return std::sqrt(sum);
    }

    Coord& operator[] (int i) {
        return coordinates[i];
    }

    const Coord& operator[] (int i) const {
        return coordinates[i];
    }
};

#endif
