#include "include/Animal.hpp"
#include "include/WrongAnimal.hpp"
#include "include/Dog.hpp"
#include "include/Cat.hpp"
#include "include/WrongCat.hpp"

int main() {
    std::cout << "=== Correct polymorphism (Animal, Dog, Cat) ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl; // Dog
    std::cout << i->getType() << std::endl; // Cat
    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal fallback

    delete meta;
    delete j;
    delete i;

    std::cout << std::endl;
    std::cout << "=== Wrong polymorphism (WrongAnimal, WrongCat) ===" << std::endl;
    const WrongAnimal* ab = new WrongAnimal(); // heap allocation
    const WrongAnimal* c = new WrongCat(); // heap allocation
    WrongCat cat; // stack allocation

    std::cout << c->getType() << std::endl;
    c->makeSound();   // prints WrongAnimal sound
    ab->makeSound();  // WrongAnimal sound
    cat.makeSound();  // prints WrongCat sound

    delete ab;
    delete c;
    return 0;
}