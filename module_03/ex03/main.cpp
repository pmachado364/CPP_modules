#include "DiamondTrap.hpp"


int main() {
    std::cout << "\n--- DiamondTrap Simulation ---\n" << std::endl;

    DiamondTrap d1("Athena");    // constructor
    d1.attack("Target Dummy");   // ScavTrap attack
    d1.whoAmI();                 // show both names

    std::cout << "\n--- Copy Construction ---\n" << std::endl;
    DiamondTrap d2(d1);          // copy constructor
    d2.whoAmI();

    std::cout << "\n--- Assignment ---\n" << std::endl;
    DiamondTrap d3("SpareBot");  // new bot
    d3 = d1;                     // copy assignment
    d3.whoAmI();

    std::cout << "\n--- Destruction Order ---\n" << std::endl;
    return 0;
}
