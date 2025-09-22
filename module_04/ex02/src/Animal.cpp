#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type) { // copy the type from the copied object type = copy.type
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &copy) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->type = copy.type; // copy the type from the copied object type = copy.type
	}
	return *this;
}

const std::string& Animal::getType() const {
	return this->type;
}

// makeSound and think are pure virtual functions
// so they don't have implementations here.