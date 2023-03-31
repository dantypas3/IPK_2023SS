#include "statistics.h"     // include own header
// define the functions declared in io.h

// mittelwert des vektors
double mean(const std::vector<double>& v){
    if(v.size() == 0) return 0;
    double sum = 0;

    for(double entry : v) {
        sum += entry;
    }
    return sum / v.size();
}

// median - mittlerster wert
double median(const std::vector<double>& v){
    // if vector is empty, there is no median
    if(v.size() == 0) return 0;

    std::vector<double> temp = v;
    std::sort(temp.begin(), temp.end());

    if(temp.size() % 2 == 1) {      // falls ungerade
        int index = temp.size() / 2;
        return temp[index];
    }
    else {                          // falls gerade
        int index = (temp.size() / 2) -1;
        return (temp[index] + temp[index+1]) / 2;
    }
}

// moment - frag nicht
double moment(const std::vector<double>& v, int k){
    double sum = 0;

    for(double element : v) {
        sum += std::pow(element, k);
    }
    return sum / v.size();
}


double standard_deviation(const std::vector<double>& v){
    double mittelwert = mean(v);
    std::vector<double> temp = v;

    double sum = 0;
    for(double& entry : temp) {
        sum += std::pow(entry - mittelwert, 2);
    }
    sum = sum / v.size();
    return std::sqrt(sum);
}
