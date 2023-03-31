#include "class.hh"     // eigene header Datei einfügen

int Class::answer(std::string s){
    foo = 31;
    return 42;
}

void Class::first(std::string s) {
    std::cout << "Class::first " << s << std::endl; 
}

int Class::second(std::string question) {
    return answer("");
}
