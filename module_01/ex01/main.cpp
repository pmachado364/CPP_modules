#include "Zombie.hpp"

int main() {
	std::cout << "Lets create a horde of 5 zombies:" << std::endl;
	Zombie* horde = zombieHorde(5, "Zombie Ludovico");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	std::cout << "Horde will be destroyed now." << std::endl;
	delete[] horde;
	return 0;
}

// 	int N = ac - 1;
// 	Zombie* horde = new Zombie[N];
// 	for (int i = 0; i < N; i++) {
// 		horde[i].setName(av[i + 1]);
// 		horde[i].announce();
// 	}
// 	delete[] horde;
// 	return 0;
// }

// int main (int ac, char **av) {
// 	if (ac < 2) {
// 		std::cout << "Usage: ./zombieHorde <name of zombies>" << std::endl;
// 		return 1;
// 	}

// 	int N = ac - 1;
// 	Zombie* horde = zombieHorde( N, av + 1 );
// 	for (int i = 0; i < N; i++) {
// 		horde[i].announce();
// 	}
// 	delete[] horde;
// 	return 0;
// }