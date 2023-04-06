#include "wfreq_functions.hh"
#include "sanitizeword.h"

#include <iostream>


std::map<std::string, int> get_frequencies()
{
    //String for each word
	std::string word;
    //Map where each word with its frequency is saved
    std::map<std::string, int> freq;

    //Iterate through input
    while(true)
	{
		std::cin >> word;
        //End loop when there is no input
        if(std::cin.fail())
			break;

		//Remove unwanted characters
        word = IPK::sanitize_word(word);

        //If the string is not empty add it to the map and increment its counter by 1
		if (word.size() != 0)
			freq[word]++;
		
	}

	return freq;
}

/*Does the same as above using an unordered map
std::unordered_map<std::string, int> get_frequencies()
{
	std::string word;
	std::unordered_map<std::string, int> freq;

	while(true)
	{
		std::cin >> word;
		if(std::cin.fail())
			break;

		word = IPK::sanitize_word(word);

		if (word.size() != 0)
			freq[word]++;

	}

	return freq;
} */

void print_frequencies(const std::map<std::string, int>& frequencies)
{
	int sum = 0;

    //Iterate through the pairs saved in the maps
	for(auto i : frequencies)
	{
        //Sum all counters
        sum += i.second;
	}

    //Calculate the relative frequency of each letter
    for (auto j : frequencies)
	{
		double rel_freq = j.second / static_cast<double>(sum);
		std::cout << j.first << "--->" << j.second << "  Frequency: " << rel_freq * 100 << "%" << std::endl;
	}
}

/* Same print function as above. Takes unordered map as input
void print_frequencies(const std::unordered_map<std::string, int>& frequencies)
{
	int sum = 0;

	for(auto i : frequencies)
	{
		sum += i.second;
	}

	for (auto j : frequencies)
	{
		double rel_freq = j.second / static_cast<double>(sum);
		std::cout << j.first << "--->" << j.second << "  Frequency: " << rel_freq * 100 << "%" << std::endl;
	}
}
 */