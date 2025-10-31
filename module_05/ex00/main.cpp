#include "Bureaucrat.h"

int main() {
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.increment();
		std::cout << bob << std::endl;
		bob.increment();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;
		alice.decrement();
		std::cout << alice << std::endl;
		alice.decrement();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}