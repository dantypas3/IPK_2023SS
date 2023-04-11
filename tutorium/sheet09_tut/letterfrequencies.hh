template<typename Map>
class LetterFrequencies {

public:

    // Processes all letters obtained from source
    template<typename Source>
    void readData(Source& source);

    // does the statistics and prints to stdout
    void printStatistics();

};


/*  read from Source

        while (true) {
            auto data = source.next();
            // check if data valid
            if (not data.second)
                break;
        
            // work with actual data
            ...
            _map[data.first] += 1;
        }
*/