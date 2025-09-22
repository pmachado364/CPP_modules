#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for(int i = 0; i < nIdeas; i++) {
		this->ideas[i] = " just staring at the wall.";
	}
	addRandomThoughts();
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy; //use the assignment operator to copy the ideas
}

Brain& Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy) {
		for(int i = 0; i < nIdeas; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl; 
}

const std::string& Brain::getIdea(int index) const {
	if(index < 0 || index >= nIdeas) {
		std::cout << "Not a valid index." << std::endl;
		static const std::string empty = "";
		return empty;
	}
	return this->ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
	if(index < 0 || index >= nIdeas) {
		std::cout << "Not a valid index." << std::endl;
		return; 
	}
	this->ideas[index] = idea;
}

void Brain::addRandomThoughts() {
	std::string thoughts[] = {
		" needs to learn C++ fast.",
		" is hungry.",
		" wants to play.",
		" is tired.",
		" doesnt want to do anything.",
		" is confused.",
		" is bored.",
		" is happy.",
		" is sad.",
		" is excited.",
		" doesnt understand humans.",
		" wants to learn about pointers.",
		" doesnt understand references.",
		" wants to learn about inheritance from module 03.",
		" wants to learn about polymorphism from module 04.",
		" wants to learn about encapsulation from module 01 or 02.",
		" wants to learn about abstract classes.",
		" wants to learn about operator overloading.",
		" wants to learn about interfaces.",
		" needs belly rubs.",
		" wants to chase something.",
		" wants to nap.",
		" wants cuddles.",
		" wants to go outside.",
		" wants to explore.",
		" wants to dig.",
		" wants to swim.",
		" wants to be an astronaut.",
		" wants to be a chef.",
		" wants to be a musician.",
		" wants to be an artist.",
		" wants to be a scientist.",
		" wants to be a writer.",
		" wants to be a teacher."};
	
	int arraySize = sizeof(thoughts) / sizeof(thoughts[0]); // total memory size / single element memory size. This case: 34 / 1 = 34
	bool usedPosition[nIdeas] = {false}; //track used positions
	
	for(int i = 0; i < arraySize; i++) {
		int pos = rand() % nIdeas; //random position in ideas array
		if(!usedPosition[pos]) { //if position not used yet
			usedPosition[pos] = true; //mark position as used
		} else { //if position already used, find next available position
			for(int j = 0; j < nIdeas; j++) {
				if(!usedPosition[j]) {
					pos = j;
					usedPosition[j] = true; //mark position as used
					break;
				}
			}
		}
		this->ideas[pos] = thoughts[i];
	}
}