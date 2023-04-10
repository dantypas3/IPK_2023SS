#ifndef FILTER
#define FILTER

#include <string>
#include "./include/sanitizeword.h"

template<typename Data>
class Filter {
public:
    // takes the input data and returns a transformed
    // version (e.g. capitalizes all letters)
    Data transform(const Data& data);

    // decides whether the input letter or word should be
    // removed from the statistics (not added to the map)
    bool remove(const Data& data);
};


// Maybe there is a more elegant way to provide template specialisations...
// specialisations for char
template<>
class Filter<char> {
public:
    // takes the input data and returns a transformed
    // version (e.g. capitalizes all letters)
    char transform(const char& data){
        //Convert c to upper case
        return std::toupper(data);
    }

    // decides whether the input letter or word should be
    // removed from the statistics (not added to the map)
    bool remove(const char& data) {
        // check if data is a letter, discard punctuation etc.
        return std::isalpha(data);
    }
};


// specialisations for std::string
template<>
class Filter<std::string> {
public:
    // takes the input data and returns a transformed
    // version (e.g. capitalizes all letters)
    std::string transform(const std::string& data){
        return IPK::sanitize_word(data);
    }

    // decides whether the input letter or word should be
    // removed from the statistics (not added to the map)
    bool remove(const std::string& data) {
        if(data.size() != 0) return true;
        return false;
    }
};

#endif
