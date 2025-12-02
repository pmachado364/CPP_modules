#include "PmergeMe.hpp"
#include <limits>

void PmergeMe::parseInput(int ac, char** av) {
	for (int i = 0; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			if (av[i][j] < '0' || av[i][j] > '9') {
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		}
		long num = strtol(av[i], NULL, 10);
		if (num > std::numeric_limits<int>::max() || num <= 0) {
			std::cerr << "Error" << std::endl;
			exit(1);
	}
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

void PmergeMe::printContainerV(const std::vector<int>& container) const {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printContainerC(const std::deque<int>& container) const {
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << std::endl;
}
