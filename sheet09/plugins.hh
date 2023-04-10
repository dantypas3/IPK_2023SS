#ifndef PLUGIN
#define PLUGIN

template<typename Map>
class AnalysisPlugin {
public:
    using Data = typename Map::key_type;

    // always add virtual destructor
    virtual ~AnalysisPlugin() {}

    // returns the name of the plugin
    virtual std::string name() const = 0;

    // does some statistics on the map and prints it to stdout
    virtual void printStatistics(const Map& map)
    {
        // do nothing by default
    }
};


template<typename Map>
class PrintTotalCount : public AnalysisPlugin<Map>
{ 
    std::string name() const override {
        return "print total count";
    }

    void printStatistics(const Map& map) override {
        double sum = 0;

        //Iterate through the pairs saved in the maps
        for(auto i : map) {
            //Sum all counters
            sum += i.second;
        }
        std::cout << "The total count is: " << sum << std::endl;
    }
};


template<typename Map>
class PrintFrequencies : public AnalysisPlugin<Map>
{ 
    std::string name() const override {
        return "print frequencies";
    }

    void printStatistics(const Map& map) override {
        //Iterate through the pairs saved in the maps
        for(auto i : map) {
            std::cout << i.first << "--->" << i.second << std::endl;
        }
    }
};


#endif
