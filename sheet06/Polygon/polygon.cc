#include <stdexcept>
#include <cmath>

#include "polygon.hh"

Polygon::Polygon(std::vector<Point> const& corners) :
	m_corners(corners) {}

Polygon::Polygon(
	std::vector<double> const& x,
	std::vector<double> const& y) {
	for (std::size_t i = 0; i < x.size(); i++) {
		m_corners.push_back(Point(x[i], y[i]));
	}
}

Polygon::Polygon(unsigned int const& num_corners_regular) {
	double const pi = M_PI;

	for (unsigned int c = 1; c <= num_corners_regular; c++) {
		double c_over_n = ((double) c) / num_corners_regular;
		double x = std::cos(2 * pi * c_over_n);
		double y = std::sin(2 * pi * c_over_n);
		m_corners.push_back(Point(x, y));
	}
}

std::size_t Polygon::corners() const {
	return m_corners.size();
}

Point const& Polygon::corner(std::size_t i) const {
	if (i >= corners()) {
		throw std::invalid_argument("Index out of bounds.");
	}
	return m_corners[i];
}

double Polygon::volume() const {
	if (corners() <= 2) {
		return 0;
	}

	double acc = 0;

	for (std::size_t i = 0; i < corners() - 1; i++) {
		auto const& point_a = corner(i);
		auto const& point_b = corner(i + 1);
		acc += (point_a.x() * point_b.y() - point_b.x() * point_a.y());
	}

	return acc / 2.0;
}