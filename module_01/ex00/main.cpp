#include "Zombie.hpp"

int main () {
	std::cout << "[ Creating a new Zombie on the stack...]" << std::endl;
	Zombie a("Rita");
	a.announce();
	std::cout << "[ Creating a new Zombie on the stack using randomChump...]" << std::endl;
	randomChump("Pedro");
	std::cout << "[ Creating a new Zombie on the heap using newZombie...] " << std::endl;
	Zombie* b = newZombie("Bafome");
	b->announce();
	std::cout << "[ Zombie still alive, lets delete it...]" << std::endl;
	delete b;
	std::cout << "[ program is still running so there's still one zombie on the stack...]" << std::endl;
	return 0;
}