#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character() : name("Default") {
	// std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : name(name) {
	// std::cout << "Character parameterized constructor called" << std::endl;
	for(int i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

Character::Character(const Character& other) : name(other.name) {
	// std::cout << "Character copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++) {
		if(other.inventory[i] != NULL) {
			inventory[i] = other.inventory[i]->clone();
		} else {
			inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		for(int i = 0; i < 4; i++) {
			if (inventory[i]) {
				delete inventory[i];
				inventory[i] = NULL;
			}
		}
		this->name = other.name;
		for(int i = 0; i < 4; i++) {
			if(other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for(int i = 0; i < 4; i++) {
		if(inventory[i]) {
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	//std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	if(!m)
		return;
	for(int i = 0; i < 4; i++) {
		if(!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if(idx < 0 || idx > 3)
		return;
	inventory[idx] = NULL;
}

AMateria* Character::getMateriaSlot(int idx) const {
	if (idx < 0 || idx > 3)
		return NULL;
	return inventory[idx];
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return;
	if(inventory[idx])
		inventory[idx]->use(target);
}