#include <vector>
#include "statistics.h"
#include <iostream>

int test_empty() {
    std::vector<double> v;
    if(median(v) != 0) return 1;
    return 0;
}

int test_4() {
    std::vector<double> v = {{1,2,3,4}};
    if(std::abs(median(v) - 2.5) > 1e-10) return 1;
    return 0;
}

int test_5() {
    std::vector<double> v = {{1,2,3,4,5}};
    if(std::abs(median(v) - 3) > 1e-10) return 1;
    return 0;
}

int main() {
    if(test_empty() != 0) return 1;
    if(test_4() != 0) return 1;
    if(test_5() != 0) return 1;

    return 0;
}