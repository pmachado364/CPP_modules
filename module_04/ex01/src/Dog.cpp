#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) { // call the base class copy constructor to copy the type
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy); // call the base class copy assignment operator to copy the type
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark Bark Bark" << std::endl;
}