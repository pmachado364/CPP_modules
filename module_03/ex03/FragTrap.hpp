#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap { //virtual inheritance needed, only the most derived class (DiamondTrap) should initialize the ClapTrap instance
	private:
		bool handIsUp; // own special method

	public:
		explicit FragTrap(const std::string& name); // constructor
		FragTrap(const FragTrap& source); // copy constructor
		~FragTrap(); // destructor

		FragTrap& operator=(const FragTrap& other); // copy assignment operator

		void attack(const std::string& target);
		void highFivesGuys(void); // new method
};

#endif