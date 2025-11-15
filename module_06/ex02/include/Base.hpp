#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
	public:
		virtual ~Base();
};

Base * generate(void); // generate a random instance of A, B, or C
void identify(Base* p); // prints the actual type of the object pointed to by p
void identify(Base& p); // prints the actual type of the object referred to by p

#endif