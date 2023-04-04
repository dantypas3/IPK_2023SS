#include <iostream>
#include <cmath>

#include "polygon.hh"
#include "point.hh"


double regular_n_gon_area(int const n) {
	double n_d = n;
	return n_d / 2 * std::sin(2 * M_PI / n_d);
}

int main (int argc, char** argv) {
	int max_n = 20;

	for (unsigned int n = 1; n <= max_n; n++) {
		Polygon p{n};
		double area_analytical = regular_n_gon_area(n);
		double area_numerical = p.volume();
		double difference = area_analytical - area_numerical;

		std::cout << "Regular polygon with " << n << " edges." << std::endl;
		std::cout << "\tVolume analytical: " << area_analytical << std::endl;
		std::cout << "\tVolume numerical: " << area_numerical << std::endl;
		std::cout << "\tDifference: " << difference << std::endl;
	}
}