#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	zombieName = name;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << zombieName << " was erased" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


//Zombie* newZombie( std::string name );
//void randomChump( std::string name );

