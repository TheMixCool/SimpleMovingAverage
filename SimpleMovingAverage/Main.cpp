#include "SimpleMovingAverage.h"
#include <deque>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <limits>

#define SIZE 1000

template<class T>
void InputData(std::deque<T>& v, T min, T max);

template<class T>
void PrintData(std::deque<T>& v);

template<class T>
void EnterLeftRight(T& left, T& right);

short SetChoice();


int main() {

	srand((unsigned int)time(0));

	std::deque<float> v;
	double left = 0, right = 0;

	EnterLeftRight(left, right);

	InputData(v, (float)left, (float)right);

	short choice = SetChoice();

	SimpleMovingAverage(v,choice);

	PrintData(v);
}

template<class T>
void PrintData(std::deque<T>& v) {
	std::cout << std::fixed;
	for (auto& el : v) {
		std::cout << el << '\n';
	}
}

template<class T>
void InputData(std::deque<T>& v, T min, T max) {
	for (int i = 0; i != SIZE; ++i) {
		T temp = (T)(rand()) / RAND_MAX * (max - min) + min;
		v.push_back(temp);
	}
}

template<class T>
void EnterLeftRight(T& left, T& right) {
	std::cout << "Enter left limit: ";
	std::cin >> left;
	std::cout << "Enter right limit: ";
	std::cin >> right;
}

short SetChoice() {

	short choice = 0;

	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) {
		std::cout << "Enter window size:\n";
		std::cout << "1. 4 \n";
		std::cout << "2. 8 \n";
		std::cout << "3. 16 \n";
		std::cout << "4. 32 \n";
		std::cout << "5. 64 \n";
		std::cout << "6. 128 \n";
		std::cout << "Enter choice: ";

		std::cin >> choice;

		if (choice < 1 || choice > 6) {
			std::cout << "\n Wrong choice \n";
		}
	}

	if (choice == 1) {
		return 4;
	}
	if (choice == 2) {
		return 8;
	}
	if (choice == 3) {
		return 16;
	}
	if (choice == 4) {
		return 32;
	}
	if (choice == 5) {
		return 64;
	}
	if (choice == 6) {
		return 128;
	}
}