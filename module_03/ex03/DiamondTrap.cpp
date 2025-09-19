#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), // Initialize ClapTrap with modified name
	  ScavTrap(name), // Initialize ScavTrap part
	  FragTrap(name), // Initialize FragTrap part
	  name(name) // Initialize own name
	  {
	this->hitPoints = FragTrap::hitPoints; // FragTrap hit points
	this->energyPoints = ScavTrap::energyPoints; // ScavTrap energy points
	this->attackDamage = FragTrap::attackDamage; // FragTrap attack damage
	this->maxHitPoints = FragTrap::maxHitPoints; // FragTrap max hit points
	std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), // copy base class part
	  ScavTrap(other), // copy ScavTrap part
	  FragTrap(other), // copy FragTrap part
	  name(other.name) // copy own private attribute
	  {
	std::cout << "DiamondTrap copy constructor called for " << other.name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other); // assign base class part
		ScavTrap::operator=(other); // assign ScavTrap part
		FragTrap::operator=(other); // assign FragTrap part
		this->name = other.name; // assign own private attribute
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target); // Use ScavTrap's attack method
}

void DiamondTrap::whoAmI() {
	if (!this->isWorking()) {
		std::cout << "DiamondTrap " << this->name << " got hit so hard it became a philosopher: Who am I?" << std::endl;
		return;
	}
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
	handleEnergy(-1);
}
