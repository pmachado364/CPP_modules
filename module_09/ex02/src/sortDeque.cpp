#include "PmergeMe.hpp"

void PmergeMe::FJsortDeque(std::deque<int>& deq) {
	std::deque <int>	mainChain;
	std::deque <int>	pendingChain;
	bool				leftover = false;
	int					leftoverElement = 0;

	if (deq.size() <= 1)
		return;
	if (deq.size() == 2) {
		if (deq[0] > deq[1])
			std::swap(deq[0], deq[1]);
		return;
	}
	sortPairsDQ(deq, mainChain, pendingChain, leftover, leftoverElement);
	FJsortDeque(mainChain);
	insertPendingDQ(mainChain, pendingChain);
	if (leftover)
		binaryInsertDQ(mainChain, leftoverElement);
	deq = mainChain;
}

void PmergeMe::sortPairsDQ(const std::deque<int>& deq, std::deque<int>& main, std::deque<int>& pending, bool& leftover, int& leftoverElement) {
	leftover = false;
	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		int a = deq[i];
		int b = deq[i + 1];
		if (a < b)
			std::swap(a, b);

		main.push_back(a);
		pending.push_back(b);
	}
	if (deq.size() % 2 != 0) {
		leftover = true;
		leftoverElement= deq.back(); //we use .back to get the last element and assign it to last
	}
}

void PmergeMe::insertPendingDQ(std::deque<int>& main, const std::deque<int>& pending) {
	if (pending.empty())
		return;
	std::vector<size_t> order = buildJacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i) {
		size_t index = order[i];
		int value = pending[index];
		binaryInsertDQ(main, value);
	}
}

void PmergeMe::binaryInsertDQ(std::deque<int>& main, int value) {
	std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
	main.insert(it, value);
}