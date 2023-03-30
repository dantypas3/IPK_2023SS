#include <iostream>

long int fibonacci_iter (int number)
{
	long int f1 = 0;
	long int f2 = 1;
	long int fn;

	std::cout << "Die Folgen-Elemente sind: " << 0 << " ";

	if (number <= 1) {
		std::cout << std::endl;
		return 0;
	}

	for (int i = 1; i < number; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
		std::cout << f1 << " ";
	}

	std::cout << std::endl;

	return f1;
}

long int fibonacci_rec (int number)
{
	if (number <= 1) return 0;
	if (number == 2) return 1;
	return fibonacci_rec(number - 1) + fibonacci_rec(number - 2);
}


int main()
{
	int n;
	std::cout << "N: " << std::flush;
	std::cin >> n;
	
	int result = fibonacci_iter(n);			// gibt output in der Funktion aus
	std::cout << "iterative Lösung: " << result << std::endl;
	std::cout << "rekursive Lösung: " << fibonacci_rec(n) << std::endl;

	return 0;
}