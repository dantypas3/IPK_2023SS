#include <iostream>
#include <cmath>

double root_iterative (double q, int n, int steps)
{
	if(q <= 0) {
		std::cout << "q muss positiv sein!" << std::endl;
		return 0;
	}

	if (n == 0)
	{
		std::cout << "n muss ungleich 0 sein" << std::endl;
		return 0;
	}

	if (n < 0)
	{
		return 1 / root_iterative(q, -n, steps);
	}

		double a = 1;
		for (int i = 0; i < steps; i++) {
			double a_hoch_n_min_1 = std::pow (a, n-1);
			a = a + (q / a_hoch_n_min_1 -a) / n;

		}
		return a;

}

void test_root (double q, int n, int steps)
{
	double root_2 = root_iterative(q, n, steps);
	double a_pow = std::pow(root_2, n);
	double x = q - a_pow;

	std::cout << " a = test_root(q = " << q << ", n = " << n << ", steps = " << steps <<
	")" << std::endl;

	std::cout << "q - a^n = " << x << std::endl;
}

int main()
{
	double test_q[] {1029593149, 1250489015, 5357950159, 1025990463,
					2359453065, 8172978014, 9872159753, 3429137590,
					9895936571, 9850124593, 1241985321};

	double steps[] {100, 200, 300, 400, 500, 600, 700, 800, 900, 999};

	std::cout << "Test mit zehstelligen Ganzzahlen: " << std::endl;

	for (int i = 0; i < 10; i++) {
		test_root(test_q[i], i, steps[i]);
		std::cout << std::endl;
	}

	std::cout << "Test q¹ = q: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		test_root(test_q[i], 1, steps[i]);
		std::cout << std::endl;
	}

	std::cout << "Test Quadratwurzel: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		test_root(test_q[i], 2, steps[i]);
		std::cout << std::endl;
	}



	return 0;
}