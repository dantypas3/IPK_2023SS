#include <iostream>
#include <cmath>

#include "point.hh"
#include "canvas.hh"
#include "pgm.hh"

int main(int, char**) {

    Point mitte {0, 0};
    
    Canvas falk {mitte, 4, 3, 4000, 3000};

    for (int i = 0; i < 4000; i++) {
        for (int j = 0; j < 3000; j++) {
           Point p = falk.coord(i, j);
            falk.setBrightness(i, j, std::fmax(0, 100 * (std::sin(1/p.x()) * std::sin(1/p.y()) + 1)));
        }
    }

    write_pgm(falk._grauwerte2(), "img.pgm");

    return 0;
}
