#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	dogBrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) { // call the base class copy constructor to copy the type
	std::cout << "Dog copy constructor called" << std::endl;
	dogBrain = new Brain(*copy.dogBrain);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete dogBrain;
}

Dog& Dog::operator=(const Dog &copy) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy); // call the base class copy assignment operator to copy the type
		delete dogBrain;
		dogBrain = new Brain(*copy.dogBrain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark Bark Bark" << std::endl;
}

void Dog::think(int index) const {
	std::cout << "Dog " << dogBrain->getIdea(index) << std::endl;
}

void Dog::setIdea(int index, const std::string& idea) {
	dogBrain->setIdea(index, idea);
}
