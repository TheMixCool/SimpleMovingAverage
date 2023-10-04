#include <deque>
#pragma once

template<class T>
std::deque<T> EnterFirstValues(std::deque<T>& v, int windowSize, T &currentValue) {

	std::deque<T> result;

	for (int i = 0; i != windowSize; ++i) {
		currentValue += v[i];
		result.push_back(currentValue / (i+1));
	}

	return result;
}

template<class T>
std::deque<T> SimpleMovingAverage(std::deque<T>& data, int windowSize) {

	T currentValue = 0;

	std::deque<T> result = EnterFirstValues(data, windowSize, currentValue);

	for (int i = windowSize; i != data.size(); ++i) {
		currentValue -= data[i - windowSize];
		currentValue += data[i];
		result.push_back(currentValue / windowSize);
	}

	return result;
}

