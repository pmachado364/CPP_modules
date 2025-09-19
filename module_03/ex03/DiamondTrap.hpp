#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string name; // own special attribute
	public:
		explicit DiamondTrap(const std::string& name); // constructor
		DiamondTrap(const DiamondTrap& other); //copy constructor
		~DiamondTrap(); // destructor

		DiamondTrap& operator=(const DiamondTrap& other); // copy assignment operator

		void attack(const std::string& target); // override attack method
		void whoAmI(); // new method
};

#endif