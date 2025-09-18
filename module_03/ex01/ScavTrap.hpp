#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool gateKeeperMode; // own special attribute

	public:
		explicit ScavTrap(const std::string& name); // constructor
		ScavTrap(const ScavTrap& source); // copy constructor
		~ScavTrap(); // destructor

		ScavTrap& operator=(const ScavTrap& other); // copy assignment operator

		void attack(const std::string& target); // override attack method
		void guardGate(); // new method
};

#endif