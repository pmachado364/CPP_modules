#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>

void PmergeMe::FJsortVector(std::vector<int>& vec) {
	std::vector <int> mainChain;
	std::vector <int> pendingChain;

	if (vec.size() <= 1)
		return;
	if (vec.size() == 2) {
		if (vec[0] > vec[1])
			std::swap(vec[0], vec[1]);
		return;
	}
	makePairs(_vec, mainChain, pendingChain);
	sortPairs(mainChain);
	// Step 1: pair creation
    // Step 2: sort pairs internally
    // Step 3: make main/pending chains
    // Step 4: recursively sort main chain
    // Step 5: insert pending into sorted main
    // Step 6: insert leftover if exists
}

