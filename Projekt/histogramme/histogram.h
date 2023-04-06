#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <fstream>


class Histogram {

private:
	//Vector with all values
	std::vector<double> set;

public:
	// default-constructible
	Histogram();
	// add new number to data set
	void insert(double x);
	// return size of data set
	unsigned int size() const;
	// return smallest value in data set
	double min() const;
	// return largest value in data set
	double max() const;
	// classify the data into bin_count bins and
	// print the histogram for the data set to stdout
	void print(unsigned int bin_count);
	 //print the normalized values
	void print_normalized(unsigned int bin_count);
};
