#ifndef SHEET07_STATISTICS_H
#define SHEET07_STATISTICS_H

#include <vector>
#include <algorithm>  
#include <cmath>
#include <map>
#include <unordered_map>

template <class T2> auto mean(const T2& v)
{
	using T1 = typename T2::value_type;
	if(v.size() == 0) return (T1)0;
	T1 sum = 0;

	for(auto& entry : v) {
		sum += entry;
	}
	return (T1)(sum / v.size());
}

template <class T1, class T2> T1 median(const T2& v)
{
	if(v.size() == 0) return 0.0;

	T2 temp = v;
	std::sort(temp.begin(), temp.end());

	if(temp.size() % 2 == 1) {      // falls ungerade
		int index = temp.size() / 2;
		return temp[index];
	}
	else {                          // falls gerade
		int index = (temp.size() / 2) -1;
		return (temp[index] + temp[index+1]) / 2;
	}
}
template <class T1, class T2> T1 moment(const T2 & v, int k)
{
	T1 sum = 0;

	for(auto& element : v) {
		sum += std::pow(element, k);
	}
	return sum / v.size();
}


template <class T1, class T2> T1 standard_deviation(const T2& v)
{
	T1 mittelwert = mean(v);
	T2 temp = v;

	T1 sum = 0;
	for(auto& entry : temp) {
		sum += std::pow(entry - mittelwert, 2);
	}
	sum = sum / v.size();
	return std::sqrt(sum);
}


template <typename Container>  typename Container::value_type robust_median(const Container& c)
{
	using val = typename Container::value_type; //Name alias for the value type of the container
	std::vector<val> values;  //Vector which stores the values of the container


	values.resize(c.size());
	int size = values.size();
	
	std::copy(c.begin(), c.end(), values.begin());
	std::sort(values.begin(), values.end());

	//Median wird berechnet
	if(size % 2 == 0)
		return (values [size / 2 - 1] + values[size / 2]) / 2;
	else
		return values[size / 2];

}

#endif
