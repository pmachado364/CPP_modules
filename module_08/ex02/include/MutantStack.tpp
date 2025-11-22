#include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& other) : std::stack<T, C>(other) {
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& other) {
	std::cout << "MutantStack assignment operator called" << std::endl;
	if (this != &other) {
		std::stack<T, C>::operator=(other); //the base class is std::stack<T, C> or simply std::stack
	}
	return *this;
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin() {
	return this->c.begin(); // 'c' is the protected member of std::stack. begin returns an iterator to the first element.
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end() {
	return this->c.end(); // end returns an iterator to one past the last element.
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::begin() const {
	return this->c.begin(); // const version of begin
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::end() const {
	return this->c.end(); // const version of end
}

template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rbegin() {
	return this->c.rbegin(); // rbegin returns a reverse iterator to the last element. This means we can iterate backwards.
}

template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rend() {
	return this->c.rend(); // rend returns a reverse iterator to one before the first element.
}

template<typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rbegin() const {
	return this->c.rbegin(); // const version of rbegin
}

template<typename T, typename C>
typename MutantStack<T, C>::const_reverse_iterator MutantStack<T, C>::rend() const {
	return this->c.rend(); // const version of rend
}
