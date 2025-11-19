#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> //std::find
#include <exception>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Element not found in the container";
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	//we call std::find to search for the integer n in the container
	//and the function returns an iterator to the found element
	//or the end of the container if not found
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if(it == container.end()) 
		throw NotFoundException(); //throw an exception if not found
	return it; 
}


// template <typename T>
// typename T::iterator easyfind(T& container, int n) {
// 	typename T::iterator it = std::find(container.begin(), container.end(),n);
// 		return it; //we let the caller handle the not found case
// }

#endif