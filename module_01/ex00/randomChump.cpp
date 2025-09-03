#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie a(name); // a funcao cria um zombie na stack
	a.announce(); //o zombie a diz "Braiiiiiiinnnssss..."
} // a funcao termina e o zombie a é destruido
