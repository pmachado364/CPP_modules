#include "PmergeMe.hpp"
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_vec = other._vec;
	_deq = other._deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::execute(int ac, char** av) {
	try {
		parseInput(ac, av);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << std::endl;
		return;
	}
	std::cout << "Before: ";
	printContainerV(_vec);
	//printContainerC(_deq); //DEBUG

	double startV = getCurrentTime();
	FJsortVector(_vec); //sort vec + time it
	double endV = getCurrentTime();
	_timeVector = endV - startV;

	double startD = getCurrentTime();
	FJsortDeque(_deq); //sort deq + time it
	double endD = getCurrentTime();
	_timeDeque = endD - startD;

	std::cout << "After: ";
	printContainerV(_vec);
	//printContainerC(_deq); //DEBUG
	printTimeVector();
	printTimeDeque();
}