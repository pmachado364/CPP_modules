#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

double getCurrentTime();

class PmergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_timeVector;
		double				_timeDeque;

		void parseInput(int ac, char** av);

		void printContainerV(const std::vector<int>& container) const;
		void printContainerC(const std::deque<int>& container) const;

		void FJsortVector(std::vector<int>& vec);
		void sortPairs(
						const std::vector<int>& vec,
						std::vector<int>& main,
						std::vector<int>& pending,
						bool& leftover,
						int& last);
		void insertPending(std::vector<int>& main, const std::vector<int>& pending);
		std::vector<size_t> buildJacobsthalOrder(size_t n);
		void binaryInsert(std::vector<int>& main, int value);
		
		void FJsortDeque(std::deque<int>& deq);
		void sortPairsDQ(
							const std::deque<int>& deq,
							std::deque<int>& main,
							std::deque<int>& pending,
							bool& leftover,
							int& leftoverElement);
		void insertPendingDQ(std::deque<int>& main, const std::deque<int>& pending);
		void binaryInsertDQ(std::deque<int>& main, int value);

		void printTimeVector() const;
		void printTimeDeque() const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void execute(int ac, char** av);
};

#endif