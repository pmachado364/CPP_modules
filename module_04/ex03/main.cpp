#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

// int main() {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

int main() {

    MateriaSource src;
    src.learnMateria(new Ice());
    src.learnMateria(new Cure());

    Character alice("Alice");
    Character bob("Bob");

    AMateria* tmp;
    tmp = src.createMateria("ice");
    alice.equip(tmp);

    tmp = src.createMateria("cure");
    alice.equip(tmp);

    std::cout << "\n--- Alice uses her Materias on Bob ---" << std::endl;
    alice.use(0, bob);
    alice.use(1, bob);

    std::cout << "\n--- Unequip and manual cleanup ---" << std::endl;
    AMateria* dropped = alice.getMateriaSlot(0); // helper function to store the pointer before using unequip
    alice.unequip(0);

    if (dropped) {
        std::cout << "Alice dropped her ice materia. Deleting it manually." << std::endl;
        delete dropped; // avoid leak
    }

    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}