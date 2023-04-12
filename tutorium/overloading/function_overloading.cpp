#include <iostream>

int sum (int a, int b)
{
	return a+b;
}

double sum (double a, double b)
{
	return a + b;
}

int main()
{
	int a = 2;
	int b = 3;
	double c = 3.8;
	double d = 8.5;

	std::cout << "Print int sum"  << sum(a, b) << std::endl;
	std::cout << "Print double sum" << sum (c, d) << std::endl;

	return 0;
}