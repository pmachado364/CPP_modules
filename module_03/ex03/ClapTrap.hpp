#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
		unsigned int maxHitPoints;
	
	public:
		explicit ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& source);
		virtual ~ClapTrap();
		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;

		ClapTrap& operator=(const ClapTrap& other);
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		bool isWorking() const; // check hitPoints and energyPoints, if either is 0, return false
		void handleDamage(unsigned int amount); // helper function to decrease hitPoints
		void handleEnergy(int amount); // helper function to change energyPoints
		void handleHealing(unsigned int amount); // helper function to increase hitPoints
};

#endif
