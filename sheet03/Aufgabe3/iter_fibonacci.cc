#include <iostream>

long int fibonacci_iter (int number)
{
	long int f1 = 0;
	long int f2 = 1;
	long int fn;

	if (number <= 1) {
		return 0;
	}

	for (int i = 1; i < number; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	
	return f1;
}

int main(int argc, char* argv[]) {
	// abort programm if no input is given
	if(argc == 1) {
		std::cout << argv[0] << " <number>" << std::endl;
		return 0;
	}
	
	int n = atoi(argv[1]);	// convert char array to integer
	std::cout << "Iterative Lösung: " << fibonacci_iter(n) << std::endl;
	return 0;
}