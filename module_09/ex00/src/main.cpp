#include "BitcoinExchange.hpp"
#include <iostream> // for std::cout, std::cerr
#include <exception> // for std::runtime_error

int main (int argv, char** argc) {
	if (argv != 2) {
		std::cout << "Usage: " << argc[0] << " <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange btcExch;
	try {
		btcExch.execute(argc[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}