#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

double getCurrentTime() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1e6) + tv.tv_usec;
}

void PmergeMe::printTimeVector() const {
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << _timeVector << " us" << std::endl;
}

void PmergeMe::printTimeDeque() const {
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque : " << _timeDeque << " us" << std::endl;
}