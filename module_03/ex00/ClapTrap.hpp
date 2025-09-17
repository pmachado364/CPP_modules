#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:

	std::string name;
	unsigned int hitPoints;
	int energyPoints;
	int attackDamage;
	
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& source);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif