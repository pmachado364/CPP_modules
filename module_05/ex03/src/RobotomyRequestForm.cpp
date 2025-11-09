#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
		std::cout << "RobotomyRequest form was created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {
		std::cout << "RobotomyRequestForm copied." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSignedStatus())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getGrdToExec())
		throw AForm::GradeTooLowException();
	int random = rand() % 2;
	if(random == 0)
		std::cout << "\n*** drilling noises *** " << target << " has been robotomized successfully by Bureaucrat " << executor.getName() << ".\n" << std::endl;
	else
		std::cout << "\nThe robotomy attempt by Bureaucrat " << executor.getName() << " failed on " << target << ".\n" << std::endl;
}

AForm* RobotomyRequestForm::fetch(const std::string& target) {
	return new RobotomyRequestForm(target);
}
