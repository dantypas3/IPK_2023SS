#include <iostream>

bool isPrime(int number) {
    if(number <= 1) return false;    // 1 ist nicht prim, negative zahlen sind nicht prim

    for(int i = 2; i < number; i++) {
        if(number % i == 0) {       // falls number restlos geteilt wird, ist die zahl nicht prim
            return false;
        }
    }
    return true;
}

void printPrimes(int upto) {
    if (upto <= 1) {
        std::cout << upto << " ist zu klein, um Primzahlen auszugeben." << std::endl;
        return;
    }
    for (int i = 2; i <= upto; i++) {
        if(isPrime(i)) std::cout << i << std::endl;
    }
}

int main() {
    std::cout << "Test printPrime() negative:" << std::endl;
    printPrimes(-31);

    std::cout << "Test printPrime() zero:" << std::endl;
    printPrimes(0);

    std::cout << "Test printPrime():" << std::endl;
    printPrimes(30);

    std::cout << "Test printPrime() big:" << std::endl;
    printPrimes(100);

    return 0;
}