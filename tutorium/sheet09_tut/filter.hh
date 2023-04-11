class Filter {
public:
    // takes the input data and returns a transformed
    // version (e.g. capitalizes all letters)
    Data transform(const Data& data);

    // decides whether the input letter or word should be
    // removed from the statistics (not added to the map)
    bool remove(const Data& data);
};
