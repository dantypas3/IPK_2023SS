#include "histogram.hh"
#include <vector>
#include <iostream>



        // default-constructible
        Histogram::Histogram() {

        }

        // add new number to data set
        void Histogram::insert(double x) {
            data.push_back(x);
        }

        // return size of data set
        unsigned int Histogram::size() const {
            return data.size();
        }

        // return smallest value in data set
        double Histogram::min() const {
            if(data.size() == 0) return 0;
            if(data.size() == 1) return data[0];

            double min = data[0];
            for(double x : data){
                if(x < min) min = x;
            }

            return min;
        }

        // return largest value in data set
        double Histogram::max() const {
            if(data.size() == 0) return 0;
            if(data.size() == 1) return data[0];

            double max = data[0];
            for(double x : data){
                if(x > max) max = x;
            }

            return max;
        }
        
        // classify the data into bin_count bins and
        // print the histogram for the data set to stdout
        void Histogram::print(unsigned int bin_count) {
            std::cout << std::fixed;
            std::cout.precision(2); // set length of double to 2
            std::cout << "Histogram of " << this->size() << " entries, min = " << this->min() << ", max = " << this->max() << std::endl;

            std::vector<double> intervals = get_intervals(bin_count);
            std::vector<int> anzahl(bin_count);

            for(int i = 0; i < bin_count-1; i++) {
                for(double element : data) {
                    if(intervals[i] <= element && element < intervals[i+1]) {
                        anzahl[i]++;
                    }
                }
            }

            // last bin has <= on upper bound
            for(double element : data) {
                    if(intervals[bin_count-1] <= element && element <= intervals[bin_count]) {
                        anzahl[bin_count-1]++;
                    }
                }


            // output data
            for(int i = 0; i < bin_count; i++) {
                std::cout << intervals[i] << " -- " << intervals[i+1] << ": " << anzahl[i] << std::endl;
            }
        }

        std::vector<double> Histogram::get_intervals(unsigned int bin_count) {
            double _min = min();
            double _max = max();
            double temp = (_max - _min) / bin_count;
            std::vector<double> intervals;

            for(int m = 1; m <= bin_count; m++) {
                intervals.push_back(_min + (m-1) * temp);
            }
            intervals.push_back(_min + bin_count * temp);

            return intervals;
        }

