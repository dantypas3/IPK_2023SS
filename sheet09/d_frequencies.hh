#ifndef FREQUENCIES
#define FREQUENCIES

#include <vector>
#include <memory>
#include "plugins.hh"

// Aufgabe b)
// Klasse von a) für Buchstaben und Wörter
template<typename Map, class Filter>
class Frequencies {

typedef typename Map::key_type data_type;
using Plugin = AnalysisPlugin<Map>;

private:
Map _map;
Filter _filter;
// abstract Plugin base type
std::vector<std::shared_ptr<Plugin>> _plugins;

public:
    Frequencies(Filter filter) { 
        _filter = filter;
    }


    // add a new plugin
    void addPlugin(const std::shared_ptr<Plugin> plugin) {
        _plugins.push_back(plugin);
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


    // iterate over plugins 
    void printStatistics() {
        for(auto& plugin : _plugins) {
            std::cout << plugin->name() << std::endl;
            plugin->printStatistics(_map);
        }
    }
};

#endif
