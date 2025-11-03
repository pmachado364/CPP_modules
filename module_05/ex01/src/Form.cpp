#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int grdToSign, int grdToExec)
	:	name(name),
		isSigned(false),
		grdToSign(grdToSign),
		grdToExec(grdToExec)
{
	if(grdToSign < 1 || grdToExec < 1) {
		std::cout << "Error: Form "<< this->name << " couldn't be created." << std::endl;
		throw GradeTooHighException();
	}
	if(grdToSign > 150 || grdToExec > 150) {
		std::cout << "Error: Form "<< this->name << " couldn't be created." << std::endl;
		throw GradeTooLowException();
	}
	std::cout << "Form " << this->name << " was created." << std::endl;
	std::cout << "Grade required to sign: " << this->grdToSign << std::endl;
	std::cout << "Grade required to execute: " << this->grdToExec << std::endl;
}

