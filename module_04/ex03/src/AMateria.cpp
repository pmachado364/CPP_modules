#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"
#include <iostream>

AMateria::AMateria () : type ("default") {
	//std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria (const AMateria& other) : type (other.type) {
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria () {
	//std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	(void)other;
	return *this;
}

AMateria::AMateria(std::string const & type) : type(type) {
	// std::cout << "AMateria parameterized constructor called" << std::endl;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	//func to make some other class use the materia on the target (probably)
}

//AMateria* clone is pure virtual, so no implementation here