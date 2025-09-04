#include "Zombie.hpp"

Zombie::Zombie() {
	ZombieName = "Unknown Zombie";
}

Zombie::Zombie(std::string name) {
	ZombieName = name;
}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << ZombieName << " disappeared." << std::endl;
}

void Zombie::announce() const {
	std::cout << ZombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ) {
	ZombieName = name;
}
