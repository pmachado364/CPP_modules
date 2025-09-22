#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* catBrain;
	public:
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();

		Cat& operator=(const Cat &copy);

		void makeSound() const; // override the pure virtual function from Animal
		void think(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif