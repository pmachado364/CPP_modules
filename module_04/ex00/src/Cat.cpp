#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) { // call the base class copy constructor to copy the type
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy); // call the base class copy assignment operator to copy the type
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}