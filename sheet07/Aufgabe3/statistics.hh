#ifndef SHEET07_STATISTICS_H
#define SHEET07_STATISTICS_H

#include <vector>
#include <algorithm>  
#include <cmath>

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

#endif
