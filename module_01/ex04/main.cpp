#include "Replace.hpp"

int main(int ac, char **av) {
	if (ac != 4 ) {
		std::cout << "Usage: ./ex04 <filename> <string1> <string2>" << std::endl;
		return 1;
	}
	ReplaceString test(av[1], av[2], av[3]);
	test.replaceInFile();
	return 0;
}