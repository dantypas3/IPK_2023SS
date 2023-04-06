#include <string>
#include <iostream>
#include <cmath>

bool is_numeric_ascii(char& c) {
	return c >= 48 && c <= 57;
}

std::pair<int, int> parse_int(std::string number) {
	bool negative = false;
	int parsed_number = 0;
	int start_index = 0;
	int end_index = number.size();

	for (unsigned int i = 0; i < end_index; i++) {
		char c = number[i];

		if (!is_numeric_ascii(number[i])) {
			switch (number[i]) {
				case '-':
					if (i > start_index) {
						end_index = i;
					} else {
						negative = true;
						start_index = i + 1;
					}
					break;
				case '+':
					if (i > start_index) {
						end_index = i;
					} else {
						negative = false;
						start_index = i + 1;
					}
					break;
				case ' ':
					if (start_index == i) {
						start_index++;
					} else {
						end_index = i;
					}
					break;
				default:
					if (i <= start_index) {
						std::string str;
						str += "Number cannot begin with '";
						str += number[i];
						str += "'";
						throw std::invalid_argument(str);
					}
					end_index = i;
					break;
			}
		}
	}

	int const length = end_index - start_index;
	for (int i = start_index; i < end_index; i++) {
		char const& symbol = number[i];
		int digit = symbol - 48;
		int place_exponent = pow(10, end_index - i - 1);
		parsed_number += digit * place_exponent;
	}

	parsed_number *= negative ? -1 : +1;
	return std::make_pair(parsed_number, end_index);
}

int main (int argc, char** argv) {
	std::cout << "Please enter a number: ";
	std::string input;
	std::getline(std::cin, input);
	auto result = parse_int(input);
	std::cout << "Parsed number: " << result.first << "   End index: " << result.second << std::endl;
}