#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") { //initiating the base class part
	//std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& copy) : AMateria(copy) { //copy the base class part
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& copy) {
	if(this != &copy)
		AMateria::operator=(copy); //assign the base class part
	return *this;
}

Cure::~Cure() {
	//std::cout << "Cure destructor called" << std::endl;
}

Cure* Cure::clone() const {
	return new Cure(*this); // copy constructor is used to create a new Cure object
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}