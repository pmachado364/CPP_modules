#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "--- Bureaucrat creation ---" << std::endl;
		Bureaucrat pedro("Pedro", 1);

		std::cout << "\n--- Form creation ---" << std::endl;
		ShrubberyCreationForm form("home");

		std::cout << "\n--- Before signing ---" << std::endl;
		std::cout << form << std::endl;

		std::cout << "\n--- Signing attempt ---" << std::endl;
		pedro.signForm(form);

		std::cout << "\n--- After signing ---" << std::endl;
		std::cout << form << std::endl;

		std::cout << "\n--- Executing form ---" << std::endl;
		pedro.executeForm(form);
	}
	catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}


// int main() {
// 	try {
// 		std::cout << "\n--- Bureaucrats ---" << std::endl;
// 		Bureaucrat pedro("Pedro", 1);
// 		Bureaucrat miguel("Miguel", 51);
// 		std::cout << pedro << std::endl;
// 		std::cout << miguel << std::endl;

// 		std::cout << "\n--- Forms ---" << std::endl;
// 		Form taxForm("Tax Declaration", 50, 50);
// 		Form secretForm("Top Secret File", 2, 2);
// 		std::cout << taxForm << std::endl;
// 		std::cout << secretForm << std::endl;

// 		std::cout << "\n--- Signing attempts ---" << std::endl;
// 		pedro.signForm(taxForm);
// 		miguel.signForm(secretForm);
// 		pedro.signForm(secretForm);

// 		std::cout << "\n--- Final Forms ---" << std::endl;
// 		std::cout << taxForm << std::endl;
// 		std::cout << secretForm << std::endl;
// 	}
// 	catch (const std::exception &e) {
// 	std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	return 0;
// }