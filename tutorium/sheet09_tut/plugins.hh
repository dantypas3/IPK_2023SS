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


