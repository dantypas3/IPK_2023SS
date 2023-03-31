#ifndef HISTOGRAM
#define HISTOGRAM

#include <vector>

class Histogram {
    private:
        std::vector<double> data;

        std::vector<double> get_intervals(unsigned int bin_count);

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
};

#endif