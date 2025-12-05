#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>

void PmergeMe::FJsortVector(std::vector<int>& vec) {
	std::vector <int>	mainChain;
	std::vector <int>	pendingChain;
	bool				leftover = false;
	int					leftoverElement = 0;

	if (vec.size() <= 1)
		return;
	if (vec.size() == 2) {
		if (vec[0] > vec[1])
			std::swap(vec[0], vec[1]);
		return;
	}
	sortPairs(vec, mainChain, pendingChain, leftover, leftoverElement);
	FJsortVector(mainChain);
	insertPending(mainChain, pendingChain);
	if (leftover)
		binaryInsert(mainChain, leftoverElement);
	vec = mainChain;
}

void PmergeMe::sortPairs(const std::vector<int>& vec, std::vector<int>& main, std::vector<int>& pending, bool& leftover, int& last) {
	leftover = false;
	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		int a = vec[i];
		int b = vec[i + 1];
		if (a < b)
			std::swap(a, b);

		main.push_back(a);
		pending.push_back(b);
	}
	if (vec.size() % 2 != 0) {
		leftover = true;
		last = vec.back(); //we use .back to get the last element and assign it to last
	}
}

void PmergeMe::insertPending(std::vector<int>& main, const std::vector<int>& pending) {
	if (pending.empty())
		return;
	std::vector<size_t> order = buildJacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t index = order[i];
		int value = pending[index];
		binaryInsert(main, value);
	}
}

std::vector<size_t> PmergeMe::buildJacobsthalOrder(size_t n) {
	std::vector<size_t> order;
	if (n == 0)
		return order;

	std::vector<char> seen(n, 0); // initiate seen vector with n size values set to 0

	size_t j_prev = 1; // J(1)
	size_t j_curr = 1; // J(2)
	size_t idx = j_curr - 1; // zero-based index

	if (idx < n) {
		order.push_back(idx); // add first Jacobsthal number index which is 1 or in our case idx 0
		seen[idx] = 1; // mark the index as seen
	}

	while (true) {
		size_t j_next = j_curr + 2 * j_prev; // J(k) = J(k-1) + 2*J(k-2)
		j_prev = j_curr;
		j_curr = j_next;
		idx = j_curr - 1; // this will give us the next Jacobsthal index in zero-based format. The initial sequence is 0, 2, 4 , 10, 22, ...
		if (idx >= n)
			break; //if the index number we got above is higher than n, we stop the loop
		if (!seen[idx]) {
			order.push_back(idx);
			seen[idx] = 1;
		} // if the index has not been seen, we add it to the order and mark it as seen
	}

	for (size_t i = 0; i < n; ++i) {
		if (!seen[i])
			order.push_back(i);
	}
	// for example:
	// for an n = 7 we get the order: 0, 2, 4, 6, 1, 3, 5
	return order;
}

void PmergeMe::binaryInsert(std::vector<int>& main, int value) {
	std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
	main.insert(it, value);
	// lower bound finds the first position where value can be inserted.
	// Scans for the first element not less than value and returns an iterator to it
	// then we insert value at that position
}