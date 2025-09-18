#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name), handIsUp(false) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->maxHitPoints = 50;
	std::cout << "FragTrap " << this->name << " constructed" << std::endl; 
}

FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source), handIsUp(source.handIsUp) {
	std::cout << "FragTrap copy constructor called for " << source.name << std::endl;
}

FragTrap::~FragTrap() {
		std::cout << "FragTrap " << this->name << " destructed." << std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if(this != &other) {
		ClapTrap::operator=(other);
		this->handIsUp = other.handIsUp;
	}
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if(!this->isWorking()) {
		std::cout << "FragTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	handleEnergy(-1);
	std::cout << "FragTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (!this->handIsUp && this->isWorking()) {
		std::cout << "FragTrap " << this->name << " is requesting a high five!" << std::endl;
		this->handIsUp = true;
	} else
		std::cout << "FragTrap " << this->name << " already has their hand up!" << std::endl;
	handleEnergy(-1);
}
