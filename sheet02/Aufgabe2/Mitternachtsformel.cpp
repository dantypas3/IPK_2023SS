#include <iostream>
#include <cmath>

double diskriminante (double a, double b, double c)
{
	double d = b*b - 4*a*c;
	return d;
}

double x1 (double a, double b, double c, double d)
{
	double x = (-b + std::sqrt(d)) / 2*a;
	return x;
}

double x2 (double a, double b, double c, double d)
{
	double x = (-b - std::sqrt(d)) / 2*a;
	return x;
}

int main()
{
	double a, b, c;
	std::cout << "a = " << std::flush;
	std::cin >> a;
	std::cout << "b = " << std::flush;
	std::cin >> b;
	std::cout << "c = " << std::flush;
	std::cin >> c;

	double d = diskriminante(a,b,c);

	if (a == 0 && b == 0)
	{
		std::cout << "Es gibt keine eindeutige Lösung. x = 0" << std::endl;
	}
	else if (d < 0)
	{
		std::cout << "Die Lösung ist komplex." << std::endl;
	}
	else if (d == 0)
	{
		std::cout << "Es git nur eine Lösung. x = " << x(a,b,c,d) << std::endl;
	}
	else
	{
		std::cout << "x1 = " << x1(a,b,c,d) << std::endl;
		std::cout << "x2 = " << x2(a,b,c,d) << std::endl;
	}

	return 0;
}
