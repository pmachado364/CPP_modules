#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

int main() {
	srand(time(0)); //seed for random generator
	try {
		std::cout << "Creating Bureaucrats..." << std::endl;
		Bureaucrat pedro("Pedro", 1);
		Bureaucrat miguel("Miguel", 146);
		Bureaucrat jose("Jose", 70);
		Bureaucrat rita("Rita", 10);

		std::cout << "\nCreating Forms ..." << std::endl;
		ShrubberyCreationForm form("house"); //target can be someone or something
		RobotomyRequestForm form2("Another human brain");
		PresidentialPardonForm form3("Somebody");
		//we cant create an abstract form: AForm form("Generic", 50, 50); so we have to use a derived class

		std::cout << "\nBefore signing :" << std::endl;
		std::cout << form << std::endl; //grade cannot be changed, so it will always be the same
		std::cout << form2 << std::endl;

		std::cout << "\nSigning attempt :" << std::endl;
		miguel.signForm(form2); //should fail
		pedro.signForm(form);
		jose.signForm(form2); //should succeed

		std::cout << "\nAfter signing :" << std::endl;
		std::cout << form << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "\nExecuting form :" << std::endl;
		jose.executeForm(form2);
		pedro.executeForm(form);
		rita.executeForm(form2);
		pedro.executeForm(form3); //should fail because not signed
		pedro.signForm(form3);
		pedro.executeForm(form3); //should succeed
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