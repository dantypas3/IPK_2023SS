#include <iostream>

class A {
	public:
	A()
	{
		std::cout << "Konstruktor A" << std::endl;
	}
	
	~A()
	{
		std::cout << "Destruktor A" << std::endl;
	}
};


class B : public A {
	public:
	B()
	{
		std::cout << "Konstruktor B" << std::endl;
	}
	
	~B()
	{
		std::cout << "Destruktor B" << std::endl;
	}
};


int main() {
	B b;
}
