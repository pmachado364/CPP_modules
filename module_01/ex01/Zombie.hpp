#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string ZombieName;
	public:
		Zombie(); // constructor default
		Zombie( std::string name ); // constructor com parametro
		~Zombie( void );

		void setName( std::string name ); 
		void announce() const;
};

Zombie* zombieHorde( int N, std::string name );
//Zombie* zombieHorde( int N, char** names);

#endif