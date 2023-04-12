#include <iostream>

class Foo{
    public:
    Foo() {
        std::cout << "Konstruktor Foo" << std::endl;
    }

    ~Foo() {
        std::cout << "Destruktor Foo" << std::endl;
    }
};


class Bar{
    Foo f;          // allocate in Stack
    //Foo* f;       // allocate in Heap
    public:
    Bar() {
        std::cout << "Konstruktor Bar" << std::endl;
        //f = new Foo;          // dinge die Dynamisch (Heap) allokiert werden
    }

    ~Bar() {
        //delete f;             // müssen wieder freigegeben werden - macht mans im Konstruktor und Destruktor ists RAII
        std::cout << "Destruktor Bar" << std::endl;
    }
};

// What is RAII https://stackoverflow.com/a/713773      https://en.cppreference.com/w/cpp/language/raii
int main() {
    Bar b;

    // bsp. für memory leak - mit htop anschauen wie der Memory verbrauch wächst
    u_int64_t* point = nullptr;
    for (int i = 0; i < 999999; i++){
        point = new u_int64_t;
        std::cout << i << " " << *point << std::endl;   // man muss was mit dem Wert machen, sonst wirds rausoptimiert
    }
    
    std::cout << "Drücke STRG + D";
    std::cin >> *point;
}
