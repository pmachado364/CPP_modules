#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target) {
	std::cout << "PresidentialPardon form was created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {
	std::cout << "PresidentialPardonForm copied from " << other.target << " to " << target << std::endl; 
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if(this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if(!getSignedStatus())
		throw AForm::FormNotSigned();
	if(executor.getGrade() > getGrdToExec())
		throw AForm::GradeTooLowException();
	std::cout << "\n*** Presidential Pardon *** : " << executor.getName() << " executed PresidentialPardonForm. And " 
	          << this->target << " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
}