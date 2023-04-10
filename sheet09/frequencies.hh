#ifndef FREQUENCIES
#define FREQUENCIES


// Aufgabe b)
// Klasse von a) für Buchstaben und Wörter
template<typename Map, class Filter>
class Frequencies {

typedef typename Map::key_type data_type;

private:
Map _map;
Filter _filter;

public:
    Frequencies(Filter filter) { 
        _filter = filter;
    }

    // Processes all letters obtained from source
    template<typename Source>
    void readData(Source& source) {
        while (true) {
            auto data = source.next();
            // check if data valid
            if (not data.second)
                break;
        
            // work with actual data
            if (_filter.remove(data.first))
            {
                //Add it to map if it does not exist and increment the counter by 1
                data_type temp = _filter.transform(data.first);
                _map[temp] += 1;
            }
        }
    }


    // does the statistics and prints to stdout
    void printStatistics() {
        double sum = 0;
        std::cout << "The number of each letter is: " << std::endl;

        //Iterate through the pairs saved in the maps
        for(auto i : _map) {
            std::cout << i.first << "--->" << i.second << std::endl;
            //Sum all counters
            sum += i.second;
        }
        std::cout << "The sum of all letters is: " << sum << std::endl;

        //Calculate the relative frequency of each letter
        std::cout << "The frequency of each letter is: " << std::endl;
        for(auto j: _map) {
            double p = (static_cast<double>(j.second) / sum) * 100;
            std::cout << j.first << ": " << p << " %" << std::endl;
        }
    }
};

#endif
