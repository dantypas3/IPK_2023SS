#include <iostream>
#include "class.hh"     // "" nötig, da sonst nicht im Projektordner gesucht wird

int main() {
    Class c;
    //c.foo = 5;
    c.first("test");
    int answer = c.second("Give me the answer to life, the universe and everything else.");
    
    std::cout << "the answer is: " << answer << std::endl;
    return 0;
}
