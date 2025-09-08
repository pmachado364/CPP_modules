#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {
	std::cout << "HumanA " << name << " destroyed" << std::endl;
}

void HumanA::attack() const {
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}
