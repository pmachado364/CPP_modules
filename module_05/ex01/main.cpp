#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::cout << "\n--- Bureaucrats ---" << std::endl;
	Bureaucrat pedro("Pedro", 1);
	Bureaucrat miguel("Miguel", 51);
	std::cout << pedro << std::endl;
	std::cout << miguel << std::endl;

	std::cout << "\n--- Forms ---" << std::endl;
	Form taxForm("Tax Declaration", 50, 50);
	Form secretForm("Top Secret File", 2, 2);
	std::cout << taxForm << std::endl;
	std::cout << secretForm << std::endl;

	std::cout << "\n--- Signing attempts ---" << std::endl;
	pedro.signForm(taxForm);
	miguel.signForm(secretForm);
	pedro.signForm(secretForm);

	std::cout << "\n--- Final Forms ---" << std::endl;
	std::cout << taxForm << std::endl;
	std::cout << secretForm << std::endl;

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