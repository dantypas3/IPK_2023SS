#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
#include "d_frequencies.hh"
#include "include/frequencysource.hh"
#include "filter.hh"
#include "plugins.hh"
#include <memory>

void test_cin() {
    Filter<char> temp;
    Frequencies<std::map<char,int>, Filter<char>> frequencies(temp);
    auto source = streamLetterSource(std::cin);           // war in letterfrequencies.hh - sinnvoll??
    frequencies.addPlugin(std::make_shared<PrintTotalCount<std::map<char,int>>>());
    frequencies.addPlugin(std::make_shared<PrintFrequencies<std::map<char,int>>>());
    frequencies.readData(source);
    frequencies.printStatistics();
}

void test_files(int argc, char* argv[]) {
    Filter<char> temp;
    Frequencies<std::map<char,int>, Filter<char>> frequencies(temp);        // test with ordered and unordered
    //LetterFrequencies<std::unordered_map<char,int>> frequencies;

    for (int i = 1 ; i < argc ; ++i) {
        std::ifstream f(argv[i]);
        auto source = streamLetterSource(f);
        frequencies.readData(source);
    }

    frequencies.addPlugin(std::make_shared<PrintTotalCount<std::map<char,int>>>());
    frequencies.addPlugin(std::make_shared<PrintFrequencies<std::map<char,int>>>());
    frequencies.printStatistics();
}

void test_cin_string() {
    Filter<std::string> temp;
    Frequencies<std::map<std::string,int>, Filter<std::string>> frequencies(temp);
    auto source = streamWordSource(std::cin);           // war in letterfrequencies.hh - sinnvoll??
    frequencies.readData(source);

    frequencies.addPlugin(std::make_shared<PrintTotalCount<std::map<std::string,int>>>());
    frequencies.addPlugin(std::make_shared<PrintFrequencies<std::map<std::string,int>>>());
    frequencies.printStatistics();
}

void test_files_string(int argc, char* argv[]) {
    Filter<std::string> temp;
    Frequencies<std::map<std::string,int>, Filter<std::string>> frequencies(temp);        // test with ordered and unordered
    //LetterFrequencies<std::unordered_map<std::string,int>> frequencies;

    for (int i = 1 ; i < argc ; ++i) {
        std::ifstream f(argv[i]);
        auto source = streamWordSource(f);
        frequencies.readData(source);
    }

    frequencies.addPlugin(std::make_shared<PrintTotalCount<std::map<std::string,int>>>());
    frequencies.addPlugin(std::make_shared<PrintFrequencies<std::map<std::string,int>>>());
    frequencies.printStatistics();
}

int main(int argc, char* argv[]) {
    test_cin();
    //test_files(argc, argv);

    //test_cin_string();
    //test_files_string(argc, argv);
}