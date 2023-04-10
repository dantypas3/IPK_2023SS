#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
#include "letterfrequencies.hh"
#include "include/frequencysource.hh"       // vorgegebene dateien sind in ./include 

void test_cin() {
    LetterFrequencies<std::map<char,int>> frequencies;
    auto source = streamLetterSource(std::cin);           // war in letterfrequencies.hh - sinnvoll??
    frequencies.readData(source);
    frequencies.printStatistics();
}

void test_files(int argc, char* argv[]) {
    LetterFrequencies<std::map<char,int>> frequencies;        // test with ordered and unordered
    //LetterFrequencies<std::unordered_map<char,int>> frequencies;

    for (int i = 1 ; i < argc ; ++i) {
        std::ifstream f(argv[i]);
        auto source = streamLetterSource(f);
        frequencies.readData(source);
    }
    frequencies.printStatistics();
}

int main(int argc, char* argv[]) {
    //test_cin();
    test_files(argc, argv);
}