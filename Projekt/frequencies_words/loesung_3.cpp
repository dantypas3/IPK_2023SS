#include "wfreq_functions.hh"


int main()
{
	//Test mit map oder unordered map. Check comments of wfreq_functions.hh
	std::map<std::string, int> ordered_freq = get_frequencies();

	//Test mit map oder unordered map. Check comments of wfreq_functions.hh
	print_frequencies(ordered_freq);

	return 0;
}