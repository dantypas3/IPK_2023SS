#include "freq_functions.h"


std::map<char, int> get_frequencies()
{
    //Map where each letter with its frequency is saved
	std::map <char, int> freq;

    //Iterate through input
	while(true) {

		unsigned char c;
        std::cin >> c;

        //End loop when there is no input
		if (not std::cin)
			break;
        //If c is a letter
		if (std::isalpha(c))
		{
            //Convert c to upper case
			c = std::toupper(c);
            //Add it to map if it does not exist and increment the counter by 1
			freq[c]++;
		}
	}
	return freq;
}

void print_frequencies(const std::map<char, int>& frequencies)
{
	double sum = 0;

	std::cout << "The number of each letter is: " << std::endl;

	//Iterate through the pairs saved in the maps
    for(auto i : frequencies)
	{
		std::cout << i.first << "--->" << i.second << std::endl;
        //Sum all counters
		sum += i.second;
	}

	std::cout << "The sum of all letters is: " << sum << std::endl;

	 double p;

	std::cout << "The frequency of each letter is: " << std::endl;

    //Calculate the relative frequency of each letter
	 for(auto j: frequencies)
	 {
		 p = (static_cast<double>(j.second) / sum) * 100;
		 std::cout << j.first << ": " << p << " %" << std::endl;
	 }



}