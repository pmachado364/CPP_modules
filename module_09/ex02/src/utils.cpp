#include "PmergeMe.hpp"
#include <limits>
#include <cstdlib>

void PmergeMe::parseInput(int ac, char** av) {
	for (int i = 0; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (av[i][j] < '0' || av[i][j] > '9')
				throw std::invalid_argument("Non-integer input");
		}
		long num = strtol(av[i], NULL, 10);
		if (num > std::numeric_limits<int>::max() || num <= 0)
			throw std::out_of_range("Integer out of range");
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

void PmergeMe::printContainerV(const std::vector<int>& container) const {
	size_t limit = 10;
	size_t n = container.size();
	for (size_t i = 0; i < n && i < limit; ++i) {
		std::cout << container[i] << " ";
	}
	if (n > limit)
		std::cout << "[...]";
	std::cout << std::endl;
}

void PmergeMe::printContainerC(const std::deque<int>& container) const {
	size_t limit = 10;
	size_t n = container.size();
	for (size_t i = 0; i < n && i < limit; ++i) {
		std::cout << container[i] << " ";
	}
	if (n > limit)
		std::cout << "[...]";
	std::cout << std::endl;
}