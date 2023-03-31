#ifndef STATISTICS
#define STATISTICS
// only declare the funcitons
#include <vector>
#include <algorithm>    // for std::sort()
#include <cmath>        // for std::pow()

double mean(const std::vector<double>& v);
double median(const std::vector<double>& v);
double moment(const std::vector<double>& v, int k);
double standard_deviation(const std::vector<double>& v);

#endif