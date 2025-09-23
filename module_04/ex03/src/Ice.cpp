#include "../include/Ice.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") { //initiating the base class part
	//std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice (const Ice& other) : AMateria(other) { //copy the base class part
	//std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if(this != &other)
		AMateria::operator=(other); //assign the base class part
	return *this;
}

Ice::~Ice() {
	//std::cout << "Ice destructor called" << std::endl;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone() const {
	return new Ice(*this); //use copy constructor to create a new Ice object
}