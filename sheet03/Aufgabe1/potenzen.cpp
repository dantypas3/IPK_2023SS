#include <iostream>

namespace power {
	int iterative_naiv (int q, int n) {
		int res = 1;
		if (n == 0) {
			return res;
		} else if (n == 1) {
			return q;
		} else {
			for (int i = 0; i < n; i++) {
				res *= q;
			}
			return res;
		}
	}

	int recursive_naiv (int q, int n) {
		if (n == 0) {
			return 1;
		} else if (n == 1) {
			return q;
		} else {
			return recursive_naiv(q, n - 1) * q;
		}
	}
}

int iterative_cool (int q, int n)
{
	int res = 1;
	if (n == 0)
	{
		return res;
	}
	else if (n == 1)
	{
		return q;
	}
	else
	{
		if (n % 2 == 0) {
			for (int i = 0; i < n/2; i++) {
				res *= q;
			}
			return res*res;
		}
		else {
			for (int i = 0; i < (n-1)/2; i++) {
				res *= q;
			}
			res *= res;
			return res * q;
		}
	}
}

int recursive_cool (int q, int n)
{
	if (n == 0) {
		return 1;
	}
	else if (n == 1)
	{
		return q;
	}
	else {
		if (n % 2 == 0) {
			return (recursive_cool(q, n / 2 - 1) * q) * ( recursive_cool(q, n / 2 - 1) * q);
		}
		else {
			return recursive_cool(q, n - 1) * q;
		}
	}
}

int main()
{
	int q ,n;
	std::cout << "q = " << std::flush;
	std::cin >> q;
	std::cout << "n = " << std::flush;
	std::cin >> n;

	std::cout << "Iterative Lösung: " << power::iterative_naiv(q, n) << std::endl;
	std::cout << "Rekursive Lösung: " <<  power::recursive_naiv(q, n) << std::endl;
	std::cout << "Schnelle iterative Lösung: " << iterative_cool(q, n) << std::endl;
	std::cout << "Schnelle rekursive Lösung: " << recursive_cool(q, n) << std::endl;

	return 0;
}
