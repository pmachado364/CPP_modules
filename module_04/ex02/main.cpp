#include "include/Animal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"
#include "include/Brain.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(NULL)); // seed for random number generation

    /* Animal a;
    Animal a.makeSound();

    Dog rex;
    rex.setIdea(0, " want to play");
    Dog copyRex = rex; // deep copy test
    rex.think(0);
    copyRex.think(0);
    // change the idea in copyRex and see if it affects rex
    copyRex.setIdea(0, " screams AAAAA");
    rex.think(0);
    copyRex.think(0);
    // if we don't have a deep copy, rex.think(0) will print " screams AAAAA" */

    std::cout << "\n=== Brain and deep copy tests ===" << std::endl;
    Dog Ruperto;
    Ruperto.makeSound();
    Ruperto.setIdea(0, " wants a treat.");
    Ruperto.think(0);

    Cat Felicia;
    Felicia.makeSound();
    Felicia.think(66);
    Felicia.setIdea(66, " wants to chase a laser pointer.");
    Felicia.think(66);

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int size = 2;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        animals[i]->makeSound();
        animals[i]->think(rand()%100);
        delete animals[i];
    }
    return 0;
}