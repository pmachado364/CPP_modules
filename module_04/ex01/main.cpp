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

    std::cout << "\n=== Brain and deep copy tests ===" << std::endl;
    Dog Ruperto;
    Ruperto.makeSound();
    Ruperto.setIdea(0, " wants a treat.");
    Ruperto.think(0);
    {
        Dog tmp = Ruperto; // copy constructor
        tmp.think(42);
        tmp.setIdea(12, " wants to go for a walk.");
        tmp.think(12);
    } // tmp goes out of scope here, destructor called
    Ruperto.think(0); // should still have its original idea

    Cat Felicia;
    Felicia.makeSound();
    Felicia.think(66);
    Felicia.setIdea(66, " wants to chase a laser pointer.");
    Felicia.think(66);

    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int size = 6;
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