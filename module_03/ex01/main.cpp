#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void printstatus(const ClapTrap& obj) {
	std::cout << "Status of " << obj.getName() << ": "
			  << obj.getHitPoints() << " hit points, "
			  << obj.getEnergyPoints() << " energy points, "
			  << obj.getAttackDamage() << " attack damage."
			  << std::endl;
}

int main() {
	ClapTrap a("Dummy Lina");
	ScavTrap b("Angelica");
	ScavTrap c(b);
	c = b;
	std::cout << "\n --- start of simulation --- \n" << std::endl;
	a.attack("Angelica, but misses badly");
	b.takeDamage(a.getAttackDamage());
	b.attack("Lina");
	a.takeDamage(b.getAttackDamage());
	b.guardGate();

	printstatus(a);
	printstatus(b);

	std::cout << "\n The copy joins in the fight! \n" << std::endl;
	c.attack("Angelica");
	a.beRepaired(5);
	a.attack("Angelica, and hits this time");
	b.takeDamage(20);
	b.beRepaired(20);
	b.guardGate();
	std::cout << " \n --- end of simulation --- \n" << std::endl;

	return 0;
}