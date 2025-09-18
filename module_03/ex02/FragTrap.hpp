#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:
		bool handIsUp; // own special method

	public:
		explicit FragTrap(const std::string& name); // constructor
		FragTrap(const FragTrap& source); // copy constructor
		~FragTrap(); // destructor

		FragTrap& operator=(const FragTrap& other); // copy assignment operator

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif