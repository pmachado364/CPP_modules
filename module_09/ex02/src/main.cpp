#include "PmergeMe.hpp"

int main (int ac, char** av) {
	if (ac < 2) {
		std::cerr << "Error : Not enough arguments" << std::endl;
		std::cerr << "Usage: ./PmergeMe <list of positive integers>" << std::endl;
		return 1;
	}
	PmergeMe test;
	test.execute(ac - 1, av + 1);
	return 0;
}