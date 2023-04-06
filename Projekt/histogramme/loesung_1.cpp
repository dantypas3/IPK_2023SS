#include "histogram.h"
#include "io.h"

int main()
{
	int seed = IPK::random_seed();
	auto vec = IPK::normal_distribution(seed, 1000000, 50, 10);

	//create histogram
	Histogram h;

	//Push generated values to histogram
	for(auto i : vec)
	{
		h.insert(i);
	}

	//Print Histogam with absolute number
	h.print(10);
	//Print Histogram with normalized print
	h.print_normalized(10);

	return 0;
}