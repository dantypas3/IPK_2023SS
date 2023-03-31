#include <iostream>
#include <cmath>
#include <vector>

// durchsuchen des vectors nach dem größten und kleinsten element
// man könnte auch das ganze array sortieren und dann das erste und letzte element ausgeben
// ist nur ineffizienter.
std::pair<double, double> min_max (const std::vector<double>& vec)
{
	double min;
	double max;

	if (vec.size() == 0) {
		std::cout << "Der Vektor enthält keine Elemente." << std::endl;
		return std::make_pair(0.,0.);
	}
	if (vec.size() == 1) {
		std::cout << "Der Vektor enthält nur ein Element." <<std::endl;
		return std::make_pair(vec[0], vec[0]);
	}
	else {
		min = vec[0];
		max = vec[0];

		for (int i = 1; i < vec.size(); i++)
		{
			if(vec[i] < min)
			{
				min = vec[i];
			}
			if(vec[i] > max)
			{
				max = vec[i];
			}
		}
	}
	return std::make_pair(min, max);
}

std::vector<double> reversed (const std::vector<double>& vec)
{
	std::vector<double> rev;

	for(int i = 0; i < vec.size(); i++)
		rev.push_back(vec[vec.size() - 1 - i]);

	return rev;
}

void round (std::vector<double>& vec)
{
	for(auto& i: vec)			// hier auto& benutzen, da die elemente verändert werden sollen
		i = std::round(i);		// ohne &, also nur auto würde eine kopie erzeugen und die originale bleiben unverändert
}

void reversed2 (std::vector<double>& vec)
{
	if(vec.size() == 0)
		std::cout << "Der Veltor enthält keine Elemente" << std::endl;

	else if(vec.size() == 1)
		std::cout << "Der Vektor enthält nur 1 Element. Umkehr unmöglich." << std::endl;

	else {
		for (int i = 0; i < vec.size() / 2; i++)
			std::swap(vec[i], vec[vec.size() - i - 1]);
	}
}

int main()
{
	std::vector <double> v1;		// erzeugen eines leeren vektors
	std::vector <double> v2(10);	// erzeugen eines 10 stelligen Vektors mit undefinierten einträgen
	std::vector <double> v3 = {{1.2,8.9,3.6,5.87,7.3,1.9,3.5,6.2,8.25}};
	std::vector <double> v4 = {{3,74,9,5,8,3}};

	std::cout << "Leerer Vektor: ";
	for (int i = 0; i < v1.size(); i++)
		std::cout << v3[i] << " ";
	std::cout << std::endl;

	std::cout << "Vektor ohne Werte: ";
	//Range based loop
	for (auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout <<"Vector v3: ";
	for (auto i : v3)
		std::cout << i << " ";
	std::cout << std::endl;
	
	std::cout << "Kleinstes Element: " << min_max(v3).first << std::endl;
	std::cout << "Größtes Element: "  << min_max(v3).second << std::endl;

	std::cout << "Reversed: ";
	for(auto i : reversed(v3))
		std::cout << i << " ";
	std::cout << std::endl;

	round(v3);
	std::cout << "Gerundet: ";
	for (auto i : v3)
		std::cout << i << " ";
	std::cout << std::endl;

	reversed2(v3);
	std::cout << "Reversed 2, ungerade Größe: ";
	for (auto i : v3)
		std::cout << i << " ";
	std::cout << std::endl;

	reversed2(v4);
	std::cout << "Reversed 2, gerade Größe: ";
	for (auto i : v4)
		std::cout << i << " ";
	std::cout << std::endl;

	reversed2(v2);
	std::cout << "Reversed 2, leerer Vektor: ";
	for (auto i : v2)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}
