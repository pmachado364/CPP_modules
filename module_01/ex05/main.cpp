#include "Harl.hpp"

int main() {
	Harl harl;
	std::cout << "testing invalid key words: debg" << std::endl;
	harl.complain("debg");
	std::cout << "testing invalid key words: empty string" << std::endl;
	harl.complain("");
	std::cout << "testing valid key words: DEBUG" << std::endl; 
	harl.complain("DEBUG");
	std::cout << "testing valid key words: INFO" << std::endl;
	harl.complain("INFO");
	std::cout << "testing valid key words: WARNING" << std::endl;
	harl.complain("WARNING");
	std::cout << "testing valid key words: ERROR" << std::endl;
	harl.complain("ERROR");
	return 0;
}