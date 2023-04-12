#include <iostream>
#include <vector>

class Vektor{
private:
	std::vector<int> _v;
public:

	Vektor(std::vector<int> v) : _v(v) {};

	void print()
	{
		for(auto& i : _v)
			std::cout << i << " ";
		std::cout << std::endl;
	}

	//Overloading of operator + to add to vectors without changing their value
	Vektor operator +(Vektor& other)
	{
		//Use of default copy-constructor
		Vektor tmp(*this);

		for(int i=0; i < _v.size(); i++)
		{
			tmp._v[i] = this->_v[i] + other._v[i];
		}
		return tmp;
	}
	 //Overloading of operator - to perform decrement operation of the vector
	void operator -()
	{
		for(auto& i : _v)
			i--;
	}
};

int main()
{
	std::vector<int>v1{1,2,3};
	std::vector<int>v2{4,5,6};
	std::vector<int>v3;

	Vektor a(v1);
	Vektor b(v2);
	Vektor c(v3);

	c = a+b;

	std::cout << "Vector a: ";
	a.print();
	std::cout << "Vector b: ";
	b.print();
	std::cout << "Vector c (a+b): ";
	c.print();
	//Decrement c by 1
	-c;
	std::cout << "New values of vector c: ";
	c.print();

}