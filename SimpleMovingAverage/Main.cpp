#include "SimpleMovingAverage.h"
#include <deque>
#include <iostream>
#include <ctime>
#include <time.h>

#define SIZE 1000000

template<class T>
void InputData(std::deque<T>& data, T leftDataLimit, T rightDataLimit);

template<class T>
void PrintData(std::deque<T>& data);

template<class T>
void EnterLeftRight(T& leftDataLimit, T& rightDataLimit);

short SetChoice();


int main() {

	srand(time(0));

	std::deque<float> dataInput, dataOutput;

	float leftDataLimit = 0, rightDataLimit = 0;
	EnterLeftRight(leftDataLimit, rightDataLimit);

	short windowSize = SetChoice();

	InputData(dataInput, leftDataLimit, rightDataLimit);
	
	clock_t startCalculationsTime = clock();

	dataOutput = SimpleMovingAverage(dataInput,windowSize);

	std::cout << "Runtime = " << (clock() - startCalculationsTime) / 1000.0;
	return 0;
}

template<class T>
void PrintData(std::deque<T>& data) {
	std::cout << std::fixed;
	for (auto& element : data) {
		std::cout << element << '\n';
	}
}

template<class T>
void InputData(std::deque<T>& data, T leftDataLimit, T rightDataLimit) {
	for (int i = 0; i != SIZE; ++i) {
		T temp = (T)(rand()) / RAND_MAX * (rightDataLimit - leftDataLimit) + leftDataLimit;
		data.push_back(temp);
	}
}

template<class T>
void EnterLeftRight(T& leftDataLimit, T& rightDataLimit) {
	std::cout << "Enter left limit: ";
	std::cin >> leftDataLimit;
	std::cout << "Enter right limit: ";
	std::cin >> rightDataLimit;
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