#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), gateKeeperMode(false) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->maxHitPoints = 100;
	std::cout << "ScavTrap " << this->name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source), gateKeeperMode(source.gateKeeperMode) {
	std::cout << "ScavTrap copy constructor called for " << source.name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called for " << other.name << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->gateKeeperMode = other.gateKeeperMode;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->isWorking()) {
		std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	handleEnergy(-1);
	std::cout << "ScavTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!"
			  << std::endl;
}
void ScavTrap::guardGate() {
	if (!this->isWorking()) {
		std::cout << "ScavTrap " << this->name << " cannot enter Gate Keeper mode." << std::endl;
		return;
	}
	if (this->gateKeeperMode == true) {
		std::cout << "ScavTrap " << this->name << " is already in Gate Keeper mode." << std::endl;
	} else {
		this->gateKeeperMode = true;
		std::cout << "ScavTrap " << this->name << " has entered Gate Keeper mode." << std::endl;
	}
}