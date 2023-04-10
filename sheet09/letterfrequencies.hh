#ifndef LETTER_FREQUENCIES
#define LETTER_FREQUENCIES

// Aufgabe a)
// nur für Buchstaben
template<typename Map>
class LetterFrequencies {

private:
Map _map;

public:
    // Processes all letters obtained from source
    template<typename Source>
    void readData(Source& source) {
        while (true) {
            auto data = source.next();
            // check if data valid
            if (not data.second)
                break;
        
            // work with actual data
            if (std::isalpha(data.first))
            {
                //Convert c to upper case
                unsigned char c = std::toupper(data.first);
                //Add it to map if it does not exist and increment the counter by 1
                _map[c] += 1;
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
