#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
	private:

	public:
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

		Dog& operator=(const Dog &copy);
		
		void makeSound() const; // override the pure virtual function from Animal
};

#endif