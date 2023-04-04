#include "canvas.hh"
#include "pgm.hh"



Canvas::Canvas(const Point& center, double width, double height, int horPixels, int vertPixels) :
                _center(center), _width(width), _height(height), _horPixels(horPixels), _vertPixels(vertPixels)
                {
                    _grauwerte.resize(horPixels, std::vector<int>(vertPixels));
                }

int Canvas::brightness(int i, int j) const {
    return _grauwerte[i][j];
}

void Canvas::setBrightness(int i, int j, int brightness) {
    _grauwerte[i][j] = brightness;
}

Point Canvas::coord(int i, int j) const {
    double x = _center.x()+(-0.5*_width)+i*_width/_horPixels;
    double y = _center.y()+(-0.5*_height)+j*_height/_vertPixels;

    return Point(x, y);
}

std::vector<std::vector<int> >Canvas::_grauwerte2() const {
    return _grauwerte;
}
