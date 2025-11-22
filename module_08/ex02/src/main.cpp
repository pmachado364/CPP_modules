#include <iostream>
#include "MutantStack.hpp"
#include <algorithm>

int main()
{
	std::cout << "--- Basic push/pop test ---" << std::endl;

	MutantStack<char> cstack;
	cstack.push('a');
	cstack.pop();
	cstack.push('b');
	cstack.push('c');
	cstack.pop();
	cstack.pop();
	cstack.push('d');
	if(cstack.empty())
		std::cout << "cstack is empty." << std::endl;
	else {
		std::cout << "Top of cstack: " << cstack.top() << std::endl;
		std::cout << "Size of cstack: " << cstack.size() << std::endl;
	}
	std::cout << "\n--- Alphabet ---" << std::endl;

	MutantStack<char> alfaStack;
	for (char c = 'a'; c <= 'z'; ++c)
		alfaStack.push(c);

	std::cout << "Size of alfaStack: " << alfaStack.size() << std::endl;
	std::cout << "Top of alfaStack: " << alfaStack.top() << std::endl;

	MutantStack<char>::iterator it1 = alfaStack.begin(); // the point of the ex02, to create a mutated stack
	MutantStack<char>::iterator ite2 = alfaStack.end(); // that can be iterated through

	std::cout << "\nIterating through alfaStack:" << std::endl;
	for (; it1 != ite2; ++it1) {
		std::cout << *it1 << ' ';
	}
	std::cout << std::endl;

	MutantStack<char>::iterator it3 = std::find(alfaStack.begin(), alfaStack.end(), 'm');
	if (it3 != alfaStack.end()) {
		std::cout << "'m' found in alfaStack." << std::endl;
	} else {
		std::cout << "'m' not found in alfaStack." << std::endl;
		std::cout << "In position: " << std::distance(alfaStack.begin(), it3) << std::endl;
	}

	for (MutantStack<char>::reverse_iterator it4 = alfaStack.rbegin(); it4 != alfaStack.rend(); ++it4) {
		*it4 = std::toupper(*it4);
	}

	std::cout << "\nAlfaStack after converting to uppercase using reverse iterator:" << std::endl;
	for (MutantStack<char>::iterator it5 = alfaStack.begin(); it5 != alfaStack.end(); ++it5) {
		std::cout << *it5 << ' ';
	}
	std::cout << std::endl;

	return 0;
}
