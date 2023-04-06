#include "histogram.h"


Histogram::Histogram() {}

void Histogram::insert(double x) { set.push_back(x); }

unsigned int Histogram::size() const { return set.size(); }

double Histogram::min() const {
	//In case no values are given
	if (set.size() == 0){
		std::cout << "The vector is empty." << std::endl;
		return 0;
	}
	//In case only one value is given
	else if (set.size() == 1){
		std::cout << "The vector has one element." << std::endl;
		return set[0];
	}
	else {
		double minimum = set[0];
		for (int i = 1; i < set.size(); i++){
			  if (minimum > set[i])
				  minimum = set[i];
		}
		return minimum;
	}
}

double Histogram::max() const {
	//In case no values are given
	if (set.size() == 0) {
		std::cout << "The vector is empty." << std::endl;
		return 0;
	}
	//In case only one value is given
	else if (set.size() == 1){
		std::cout << "The vector has one element." << std::endl;
		return set[0];
	}
	else {
		double max = set[0];
		for (int i = 1; i < set.size(); i++){
			if (max < set[i])
				max = set[i];
		}
		return max;
	}
}

void Histogram::print(unsigned int bin_count) {
	int M = bin_count;
	int m = 1;
	//Vector with all the intervals
	std::vector< std::array<double, 3> >intervals;

	//Calculate the Im and and initialize a counter with value 0
	for(int i = 0; i < M-1; i++, m++) {
		intervals.push_back(std::array<double, 3> { min() + (m - 1) * ((max() - min()) / M),
													min() + m * ((max() - min()) / M ), 0});
	}
	//Last interval
	intervals.push_back(std::array<double, 3> {min() + (M-1) * ((max() - min()) / M), max(), 0});

	//Count the elements of each bucket
	for (auto& i : set) {

		 for (auto& j : intervals) {
			 if (i >= j[0] && i <= j[1]) {
				 j[2]++;
				 break;
			 }
		 }
	}

	std::cout << "Histogram of " << set.size() << " entries, min = " << min() << ", max = " << max() << std::endl;

	for(auto& k : intervals)
		std::cout << k[0] << "--" << k[1] <<": " << static_cast<int>(k[2]) << std::endl;
}

void Histogram::print_normalized(unsigned int bin_count) {

	int M = bin_count;
	int m = 1;

	//Same as in print
	std::vector< std::array<double, 3> >intervals;

	//Same as in print
	for(int i = 0; i < M-1; i++, m++) {
		intervals.push_back(std::array<double, 3> { min() + (m - 1) * ((max() - min()) / M),
													min() + m * ((max() - min()) / M ), 0});
	}
	//Same as in print
	intervals.push_back(std::array<double, 3> {min() + (M-1) * ((max() - min()) / M), max(), 0});

	//Same as in print
	for (auto& i : set) {

		for (auto& j : intervals) {
			if (i >= j[0] && i <= j[1]) {
				j[2]++;
				break;
			}
		}
	}

	int entries = set.size();
	std::cout << "Histogram of " << entries << " entries, min = " << min() << ", max = " << max() << std::endl;

	for(auto& k : intervals)
	{
		std::cout << k[0] << "--" << k[1] << ": " << k[2] / entries << std::endl;
	}
}