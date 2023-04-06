#include <iostream>
#include <cmath>


std::pair <int, int> parse_int(std::string number)
{
	int res = 0;
	char c;
	int start = 0;
	int end = number.size();
	bool positive = true;
	
	for(int i = 0; i < end; i++) {
		c = number[i];
		if(not [](char c) {return c>= 48 && c <= 57; }(c))
			switch (number[i]) {
				case '+':
					if(i > start)
						end = i;
					else {
						start++;
						positive = true;
					}
					break;
				case'-':
					if( i > start)
						end = i;
					else {
						start++;
						positive = false;
					}
					break;
				case' ':
					if (start == i)
						start ++;
					else
						end = i;
					break;
				default:
					if (i <= start) {
						std::string s;
						s += "Number cannot begin with '";
						s += number[i];
						s +="'";
						throw std::invalid_argument(s);
					}
					end = i;
					break;
			}
		}

	for(start; start < end; start++) {
		c = number[start] - '0';
		int power = std::pow(10, end - start - 1);
		res += power * c;
	}

	res *= positive ? +1 : -1;

	return std::make_pair(res, start);
}

int main()
{
	std::cout << "Please type a number: " << std::flush;
	std::string number;
	std::cin >> number;
	auto value = parse_int(number);
	std::cout << "The number is: " << value.first << std::endl;
	std::cout << "Reading the number stopped at index: " << value.second << std::endl;

	return 0;
}