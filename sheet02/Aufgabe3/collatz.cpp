#include <iostream>

void collatz(int number)
{
	std::cout << "Die Zahlenfolge ist: " << number <<" ";

	//Wiederhole bis number == 1 oder 0 oder -1 oder -5 oder -17
	while(number!=1 && number!=0 && number!=-1 && number!=-5 && number!=-17)
	{
		//Ist number gerade?
		if (number % 2 == 0)
		{
			//Teile number durch 2
			number = number / 2;
			std::cout << number << " ";
		}
		//Ist number ungerade?
		else
		{
			//Multipliziere number mit 3 und addiere 1
			number = (number*3) + 1;
			std::cout << number << " ";
		}
	}
	std::cout << std::endl;
}

int main()
{
	int num;
	std::cout << "Nummer: " << std::flush;
	std::cin >> num;

	collatz(num);

	return 0;
}

/* Alternative

A)
while ((number == 1 || number == 0 || number == -1 || number == -5 || number == -17) == false) {
	...
}

B)
while (!(number == 1 || number == 0 || number == -1 || number == -5 || number == -17)) {
	...
}

c)
bool number_in_list (int number, int[] list) {

}
*/