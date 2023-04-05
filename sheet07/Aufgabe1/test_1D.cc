#include <iostream>
#include <assert.h>
#include "point.hh"

#define DIMENSION 1     // define placeholer, compiler will replace it

int main() {
    //call default constructor
    Point<double, DIMENSION> p1;
    // check if point is = {0}
    for (int i = 0; i < DIMENSION; i++) {
        assert(0.0 == p1.x(i));
        assert(0.0 == p1[i]);
        const Point<double, DIMENSION>& p2 = p1;
        assert(0.0 == p2[i]);
    }

    assert(0.0 == p1.norm());

    // call constructor with array
    Point<double, DIMENSION> p3({3.3});
    assert(3.3 == p3[0]);

    assert(std::abs(3.3 - p3.norm()) <= 1e-7);
}
