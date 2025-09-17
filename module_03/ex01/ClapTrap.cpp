#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("No name"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	std::cout << "Copy constructor called for " << source.name << std::endl;
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ClapTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!"
				  << std::endl;
		this->energyPoints--;
	} else {
		if (this->energyPoints < 1)
			std::cout << "ClapTrap " << this->name << " has no energy points left to attack." << std::endl;
		if (this->hitPoints < 1)
			std::cout << "ClapTrap " << this->name << " has no hit points left to attack." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ClapTrap " << this->name
				  << " repairs itself. It recovers "
				  << amount << " hit points."
				  << std::endl;
		this->energyPoints--;
		this->hitPoints = this->hitPoints + amount;
	} else {
		if (this->energyPoints < 1)
			std::cout << "ClapTrap " << this->name << " has no energy points left to repair itself." << std::endl;
		if (this->hitPoints < 1)
			std::cout << "ClapTrap " << this->name << " has no hit points left to repair itself." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0) {
		std::cout << "ClapTrap " << this->name
				  << " takes " << amount
				  << " points of damage."
				  << std::endl;
		if(amount >= this->hitPoints) {
			this->hitPoints = 0;
			std::cout << "ClapTrap " << this->name << " has been defeated" << std::endl;
		} else
			this->hitPoints -= amount;
		if (this->hitPoints - amount <= 0) {
			std::cout << "ClapTrap " << this->name << " has been defeated" << std::endl;
			this->hitPoints = 0;
		}
	} else
		std::cout << "ClapTrap " << this->name << " has no hit points left to take damage." << std::endl;
}
