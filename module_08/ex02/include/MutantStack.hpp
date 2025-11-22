#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>
#include <iostream>

// T as we know is the type of data the stack holds,
// and C is the underlying container type, defaulting to std::deque<T>
// ou5 stack will now be std::stack<T, C>
template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		// We have differtent types of iterators: iterator, const_iterator, reverse_iterator, const_reverse_iterator
		typedef typename C::iterator iterator; // we have to assign to the stack the iterator type of the underlying container C.
		typedef typename C::const_iterator const_iterator;
		typedef typename C::reverse_iterator reverse_iterator;
		typedef typename C::const_reverse_iterator const_reverse_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif