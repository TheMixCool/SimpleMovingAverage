#include <vector>
#include <iostream>
#pragma once

template<class T>
void SimpleMovingAverage(std::vector<T>& v, int windowSize = 4) {
	for (auto& el : v) {
		std::cout << el << '\n';
	}
}