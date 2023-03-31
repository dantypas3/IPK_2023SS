#ifndef CLASS   // header guard
#define CLASS

#include <iostream>

class Class {
    private:
    int foo = 0;
    int answer(std::string s);

    public:
    void first(std::string s);
    int second(std::string question);
    //int second(std::string& question);    // nur zum erklären von references
};

// --- referenzen ---
/*
eine lvalue reference kann links (deshalb l) von einem = Operator stehen. 
Ihm kann also ein Wert zugewiesen werden.

eine rvalue reference darf nur rechts von einem = stehen. Ihm kann kein Wert zugewiesen werden, 
da es kein Speicher belegt. Es sind direkt angegebene Werte wie z.B. bei foo(5) der wert 5.
*/

#endif  