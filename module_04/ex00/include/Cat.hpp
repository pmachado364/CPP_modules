#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
	private:

	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();

		Cat& operator=(const Cat &copy);

		void makeSound() const; // override the pure virtual function from Animal
};

#endif