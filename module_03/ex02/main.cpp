#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap a("Jorge");
    FragTrap b(a);        // copy constructor
    FragTrap c("Carlos");
    c = a;                // copy assignment
    std::cout << "\n--- Start of Simulation ---\n" << std::endl;
    a.attack("Training Dummy");
    a.highFivesGuys();     // first high five
    a.highFivesGuys();     // should say hand already up
    a.takeDamage(50);
    a.beRepaired(20);
    b.attack("Rocky");
    c.highFivesGuys();
    std::cout << "\n--- End of Simulation ---" << std::endl;
    return 0;
}