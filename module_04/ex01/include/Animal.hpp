#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &copy);
		virtual ~Animal(); // if not virtual, only the base class destructor is called, so the derived class part is not destroyed properly = memory leak, undefined behavior

		Animal& operator=(const Animal &copy);
		
		const std::string& getType() const; // getter for protected member type
		virtual void makeSound() const; // virtual function = can be overridden in derived classes
		virtual void think(int index) const; // 
};

#endif