#include "freq_functions.h"

int main()
{
	std::map<char, int> frequencies = get_frequencies();
	print_frequencies(frequencies);

	return 0;
}