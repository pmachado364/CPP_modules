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
		void FJsortDeque(std::deque<int>& deq);

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