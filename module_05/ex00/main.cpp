#include "Bureaucrat.h"

int main() {
	try {
		Bureaucrat Pedro("Pedro", 151); //invalido
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Miguel("Miguel", 0); // This should also throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat Rita("Rita", 2);
		std::cout << Rita << std::endl;
		Rita.increment();
		std::cout << "After increment: " << Rita << std::endl;
		Rita.decrement();
		std::cout << "After decrement: " << Rita << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}