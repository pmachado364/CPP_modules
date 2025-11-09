#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

int main() {
	srand(time(0)); //seed for random generator
	try {
		Bureaucrat pedro("Pedro", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			pedro.signForm(*rrf);
			pedro.executeForm(*rrf);
			delete rrf;
		}
		Intern anotherIntern;
		AForm* rrf2;
		rrf2 = anotherIntern.makeForm("presidential pardon", "Pedro");
		if(rrf2) {
			std::cout << *rrf2 << std::endl;
			pedro.signForm(*rrf2);
			pedro.executeForm(*rrf2);
			delete rrf2;
		}
		Bureaucrat rita("Rita", 10);
		AForm* anotherPointer;
		anotherPointer = anotherIntern.makeForm("shrubbery creation", "Jose");
		if(anotherPointer) {
			std::cout << *anotherPointer << std::endl;
			rita.signForm(*anotherPointer);
			rita.executeForm(*anotherPointer);
			delete anotherPointer;
		}
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