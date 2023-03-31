#include <iostream>
#include <vector>
#include "io.h"         // "" nötig da es im gleichen Ordner liegt
#include "statistics.h"

int main() {
    std::vector<double> vec = IPK::normal_distribution(0, 5, 0.0, 10.0);

    std::cout << "Vektor: " << std::endl;
    for(double entry : vec) {
        std::cout << entry << std::endl;
    }

    std::cout <<  std::endl;
    std::cout << "Mittelwert " << mean(vec) << std::endl;
    std::cout << "Median " << median(vec) << std::endl;
    std::cout << "Moment " << moment(vec, 2) << std::endl;
    std::cout << "Standardabweichung " << standard_deviation(vec) << std::endl;

    std::cout <<  std::endl;
    std::cout << "Test der Relation" << std::endl;
    std::cout << std::pow(standard_deviation(vec), 2) << " = " << moment(vec, 2) - std::pow(mean(vec), 2) << std::endl;
    
    return 0;
}
