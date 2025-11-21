#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span {
	private:
		std::vector<int>	_nbr; // Container to hold the numbers
		unsigned int		_maxN; //max ints allowed
	public:
		explicit Span(unsigned int maxN);
		//The explicit tag prevents implicit conversions.
		// if not explicit we would be able to do Span sp('A'); or Span sp(true);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		std::pair<int,int> shortestSpanPair() const;
		std::pair<int,int> longestSpanPair() const;

		const std::vector<int>& getNumbers() const;

		template<typename It>
		void addRange(It start , It end) {
			size_t rangeSize = std::distance(start, end);
			if (_nbr.size() + rangeSize > _maxN)
				throw alrFullException();
			_nbr.insert(_nbr.end(), start, end);
		}

		class alrFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Container already full";
				}
			};
		
		class notEnoughNbrsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers to find a span";
				}
			};
};

#endif