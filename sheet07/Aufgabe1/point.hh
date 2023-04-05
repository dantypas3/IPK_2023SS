#ifndef POINT_HH
#define POINT_HH

#include<array>
#include<cmath>
// because Point is now a template the functions which use the template parameter must be declared in the .h file
// further reading: https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl


template<typename Coord, int dim>
class Point {
    // funktioniert nicht bzw. kein plan wie man es von auserhalb aufrufen kann...
    using Coordinate = Coord;      // export of the coordinate type

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
        //coordinates[i] = 5;     // compiler error, can't change value in const function
        return coordinates[i];
    }

    // const Coord& makes the datatype Coord constant - it can't be changed
    // operator[](...) const makes the function constant - it can't change values of the class - compiler errror
};

#endif
