#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

void addMultipleNumbers(std::vector<int>& vec, unsigned int count) {
	for (unsigned int i = 0; i < count; ++i)
		vec.push_back(rand() % 1000);
}

int main() {
	srand(time(NULL));

	std::cout << "======= SUBJECT TESTS =======" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		sp.addNumber(10); //exception test
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "======= ADDITIONAL TESTS =======" << std::endl;
	try {
		std::cout << "Lets create a Span with capacity of 10000 and fill it with 5 random numbers" << std::endl;
		Span sp(10000);
		sp.addNumber(42);
		sp.addNumber(7);
		sp.addNumber(13);
		sp.addNumber(99);
		sp.addNumber(0);
		std::cout << "Current numbers in the array : " << std::endl;
		const std::vector<int>& numbers = sp.getNumbers();
		for (size_t i = 0; i < numbers.size(); ++i) {
			std::cout << numbers[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "Now adding a range of 100 numbers" << std::endl;
		std::vector<int> moreNumbers;
		addMultipleNumbers(moreNumbers, 100);
		sp.addRange(moreNumbers.begin(), moreNumbers.end());
		std::cout << "Now the container has " << sp.getNumbers().size() << " numbers: " << std::endl;
		for (size_t i = 0; i < 50; ++i) {
			std::cout << sp.getNumbers()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "... " << std::endl;

		std::cout << "Shortest span is: " << sp.shortestSpan() << "(" << sp.shortestSpanPair().first << ", " << sp.shortestSpanPair().second << ")" << std::endl;
		std::cout << "Longest span is: " << sp.longestSpan() << "(" << sp.longestSpanPair().first << ", " << sp.longestSpanPair().second << ")" << std::endl;

		std ::cout << "Now trying to add a range +[9950] that exceeds the capacity" << std::endl;
		std::vector<int> tooManyNumbers;
		addMultipleNumbers(tooManyNumbers, 9950); // This will exceed the capacity
		sp.addRange(tooManyNumbers.begin(), tooManyNumbers.end());
	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}