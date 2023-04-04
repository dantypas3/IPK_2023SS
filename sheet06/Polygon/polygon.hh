#ifndef POLYGON_HH
#define POLYGON_HH

#include <vector>
#include "point.hh"

class Polygon {
private:
	std::vector<Point> m_corners;

public:
	Polygon(std::vector<Point> const& corners);
	Polygon(std::vector<double> const& x, std::vector<double> const& y);
	Polygon(unsigned int const& num_corners_regular);

	std::size_t corners() const;
	Point const& corner(std::size_t i) const;
	double volume() const;
};

#endif