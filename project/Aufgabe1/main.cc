#include "histogram.hh"

int main() {
    Histogram hist;
    hist.insert(1);
    hist.insert(2);
    hist.insert(3);
    hist.insert(4);
    hist.insert(5);
    hist.insert(4.5);

    hist.print(5);
    return 0;
}