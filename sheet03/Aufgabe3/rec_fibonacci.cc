#include <iostream>

long int fibonacci_rec (int number)
{
	if (number <= 1) return 0;
	if (number == 2) return 1;
	return fibonacci_rec(number - 1) + fibonacci_rec(number - 2);
}

int main(int argc, char* argv[]) {
	// abort programm if no input is given
	if(argc == 1) {
		std::cout << argv[0] << " <number>" << std::endl;
		return 0;
	}

	int n = atoi(argv[1]);	// convert char array to integer
	std::cout << "Rekursive Lösung: " << fibonacci_rec(n) << std::endl;
	return 0;
}