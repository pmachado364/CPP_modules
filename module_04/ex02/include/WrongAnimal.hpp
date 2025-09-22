#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(); //and in Claptrap we didnt make it virtual because we werent dealing with pointers of base class, so it was not necessary. But its good practice to make the base class destructor virtual

		WrongAnimal& operator=(const WrongAnimal &copy);
		
		const std::string& getType() const;
		void makeSound() const; //not virtual on purpose so that it demonstrates the wrong behavior

};

#endif