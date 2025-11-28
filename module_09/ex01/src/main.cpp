#include "RevPolishNotation.hpp"

#include <iostream> // for std::cout, std::cerr
#include <exception> // for std::runtime_error

int main (int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: '" << argv[0]
				  << "' + mathematical expression such as \"1 2 +\""
				  << std::endl;
		return 1;
	}

	RevPolishNotation rpn;

	try {
		int result = rpn.calculate(argv[1]);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}