#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0), maxHitPoints(30) {
	std::cout << "Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) {
	std::cout << "Copy constructor called for " << source.name << std::endl;
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	this->maxHitPoints = source.maxHitPoints;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called for " << this->name << std::endl;
}

std::string ClapTrap::getName() const {
	return this->name;
}

int ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return this->attackDamage;
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
	if (!this->isWorking()) {
		std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	handleEnergy(-1);
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->isWorking()) {
		std::cout << "ClapTrap " << this->name << " cannot repair itself." << std::endl;
		return;
	}
	handleHealing(amount);
	handleEnergy(-1);
	std::cout << "ClapTrap " << this->name
			  << " repairs itself. It recovers "
			  << amount << " hit points."
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " has been defeated" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name
			  << " takes " << amount << " points of damage."
			  << std::endl;
	handleDamage(amount);
}

bool ClapTrap::isWorking() const {
	if(this->hitPoints > 0 && this->energyPoints > 0)
		return true;
	return false;
}

void ClapTrap::handleDamage(unsigned int amount) {
	if(amount >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has been defeated" << std::endl;
	}
	else
		this->hitPoints -= amount;
}

void ClapTrap::handleEnergy(int amount) {
	int energy = static_cast<int>(this->energyPoints) + amount;
	if (energy < 0)
		this->energyPoints = 0;
	else
		this->energyPoints = static_cast<unsigned int>(energy);
}

void ClapTrap::handleHealing(unsigned int amount) {
	this->hitPoints += amount;
	if (this->hitPoints > this->maxHitPoints)
		this->hitPoints = this->maxHitPoints;
}
