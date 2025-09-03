#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie* b = new Zombie(name); // com o new estamos a alocar memoria dinamicamente para o objecto e o constructor é chamado
	return b; //vamos retornar um pointer para o objecto que foi criado
}