#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private:
		Brain* dogBrain;
	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

		Dog& operator=(const Dog &copy);
		
		void makeSound() const; // override the pure virtual function from Animal
		void think(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif