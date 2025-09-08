#include "HumanB.hpp"

HumanB::HumanB (const std::string& name) : name(name), weapon(NULL) {}

HumanB::~HumanB() {
	std::cout << "HumanB " << name << " destroyed" << std::endl;
}

void HumanB::attack() const {
	if (weapon)
		std::cout << name << " attacks with " << weapon->getType() << std::endl;
	else
		std::cout << name << " can't attack with its fragile hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}
