#include <iostream>

template<typename T>
void swap(T& first, T& second){
    T temp = first;
    first = second;
    second = temp;
}

int main() {
    int a = 1;
    int b = 2;
    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a,b);
    std::cout << "a = " << a << " b = " << b << std::endl << std::endl;

    double c = 3;
    double d = 4;
    std::cout << "c = " << c << " d = " << d << std::endl;
    swap(c,d);
    std::cout << "c = " << c << " d = " << d << std::endl;
    return 0;
}