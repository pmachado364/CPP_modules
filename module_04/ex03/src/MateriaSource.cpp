#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other.inventory[i] != NULL) {
			this->inventory[i] = other.inventory[i]->clone();
		} else {
			this->inventory[i] = NULL;
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++) {
			if (other.inventory[i]) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i]) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	// std::cout << "MateriaSource destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m->clone();
			return;
		}
	}
	// If we reach here, the inventory is full, do nothing
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] && this->inventory[i]->getType() == type) {
			return this->inventory[i]->clone();
		}
	}
	return NULL; // If no materia of this type is found
}

