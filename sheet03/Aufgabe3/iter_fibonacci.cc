#include <iostream>

int32_t fibonacci_iter (int32_t number)
{
	int32_t f1 = 0;
	int32_t f2 = 1;
	int32_t fn;

	if (number <= 1) {
		return 0;
	}

	for (int i = 1; i < number; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
	}
	
	return f2;
}

int main(int argc, char* argv[]) {
	// abort programm if no input is given
	if(argc == 1) {
		std::cout << argv[0] << " <number>" << std::endl;
		return 0;
	}
	
	int n = atoi(argv[1]);	// convert char array to integer
	std::cout << fibonacci_iter(n) << std::endl;
	return 0;
}