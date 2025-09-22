#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	catBrain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) { // call the base class copy constructor to copy the type
	std::cout << "Cat copy constructor called" << std::endl;
	catBrain = new Brain(*copy.catBrain);
	// deep copy of the Brain.
	// If we just did catBrain = copy.catBrain, both Cats would share the same Brain.
	// leading to double deletion when both destructors are called.
	// and changes to one Cat's Brain would affect the other Cat's Brain.
	// Thats what a deep copy prevents.
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete catBrain;
}

Cat& Cat::operator=(const Cat &copy) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy); // call the base class copy assignment operator to copy the type
		delete catBrain; // delete the existing Brain to prevent memory leak
		catBrain = new Brain(*copy.catBrain); // deep copy of the Brain
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow Meow" << std::endl;
}

void Cat::think(int index) const {
	std::cout << "Cat " << catBrain->getIdea(index) << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
	catBrain->setIdea(index, idea);
}
