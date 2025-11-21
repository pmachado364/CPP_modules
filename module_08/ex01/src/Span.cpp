#include "Span.hpp"
#include <limits>

Span::Span(unsigned int maxN) : _maxN(maxN) {}

Span::Span(const Span& other) : _nbr(other._nbr), _maxN(other._maxN) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_nbr = other._nbr;
		_maxN = other._maxN;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_nbr.size() < _maxN)
		_nbr.push_back(number);
	else
		throw alrFullException();
}

int Span::longestSpan() {
	if (_nbr.size() < 2)
		throw notEnoughNbrsException();

	int min = *min_element(_nbr.begin(), _nbr.end());
	int max = *max_element(_nbr.begin(), _nbr.end());
	return max - min;
}

int Span::shortestSpan() {
	if (_nbr.size() < 2)
		throw notEnoughNbrsException();

	std::vector<int> sortedArray = _nbr;
	std::sort(sortedArray.begin(), sortedArray.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sortedArray.size() - 1; i++) {
		if (sortedArray[i + 1] - sortedArray[i] < minSpan)
			minSpan = sortedArray[i + 1] - sortedArray[i];
	}
	return minSpan;
}

const std::vector<int>& Span::getNumbers() const {
	return _nbr;
}

std::pair<int,int> Span::shortestSpanPair() const {
	if (_nbr.size() < 2)
		throw notEnoughNbrsException();

	std::vector<int> sortedArray = _nbr;
	std::sort(sortedArray.begin(), sortedArray.end());
	int minSpan = std::numeric_limits<int>::max();
	std::pair<int,int> spanPair;
	for (size_t i = 0; i < sortedArray.size() - 1; i++) {
		int currentSpan = sortedArray[i + 1] - sortedArray[i];
		if (currentSpan < minSpan) {
			minSpan = currentSpan;
			spanPair = std::make_pair(sortedArray[i], sortedArray[i + 1]);
		}
	}
	return spanPair;
}

std::pair<int, int> Span::longestSpanPair() const {
	if (_nbr.size() < 2)
		throw notEnoughNbrsException();

	int min = *min_element(_nbr.begin(), _nbr.end());
	int max = *max_element(_nbr.begin(), _nbr.end());
	return std::make_pair(min, max);
}