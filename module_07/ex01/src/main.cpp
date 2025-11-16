#include "Iter.hpp"
#include <iostream>

void increment(int& x) {
	x += 1;
}

void square(int& x) {
	x = x * x;
}

void swap2ndAnd3rd(std::string& str) {
	if (str.length() >= 3) {
		std::swap(str[1], str[2]);
	}
}

void delete2ndChar(std::string& str) {
	if (str.length() >= 2) {
		str.erase(1, 1);
	}
}

template <typename T>
void display(const T& x) {
	std::cout << x << " ";
}

int main() {
	int arr[5] = {1,2,3,4,5};
	std::cout << "Original array:" << std::endl;
	iter(arr, 5, display<int>);
	iter(arr, 5, increment);
	std::cout << "\nAfter using increment function:" << std::endl;
	iter(arr, 5, display<int>);
	iter(arr, 5, square);
	std::cout << "After squaring the elements:" << std::endl;
	iter(arr, 5, display<int>);

	std::string strArr[6] = {"Hello", "World", "This", "Is", "C++", "Module_07"};
	std::cout << std::endl << "Original string array:" << std::endl;
	iter(strArr, 6, display<std::string>);
	std::cout << std::endl << "After swapping 2nd and 3rd characters:" << std::endl;
	iter(strArr, 6, swap2ndAnd3rd);
	iter(strArr, 6, display<std::string>);
	std::cout << std::endl << "After deleting 2nd character:" << std::endl;
	iter(strArr, 6, delete2ndChar);
	iter(strArr, 6, display<std::string>);
	std::cout << std::endl;
	return 0;
}