#include <iostream
#include <cmath>

double root_iterative(double q, int n, int steps)
{
	if (q <= 0 ) {
		std::cout << "q muss eine positive Zahl sein!" << std::endl;
		return 0;
	}

	if (n == 0) {
		std::cout << "N muss ungleich 0 sein." << std::endl;
	}

	if (n < 0) {
		return 1 / root_iterative(q, -n, steps);
	}
	
	doub+le a = 1;
	for (int i = 0; i < steps; i++) {
		double a_minus_1_pot = std::pow(a, n - 1);
		a = a + (q / a_minus_1_pot - a) / n;
	}

	return a;
}

int main()
{
	std::cout << root_iterative(4, 2, 1) << std::endl;
}