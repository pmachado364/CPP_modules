#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Lina");
	ClapTrap b("Angelica");

	a.attack("Angelica, but misses badly");
	b.takeDamage(0);
	a.attack("Angelica again, but this time it also misses");
	b.takeDamage(0);
	for(int i = 0; i < 11; i++) {
		b.attack("the air");
	}
	return 0;
}