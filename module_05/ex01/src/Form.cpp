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

Form::Form(const Form& other)
	:	name(other.name),
		isSigned(other.isSigned),
		grdToSign(other.grdToSign),
		grdToExec(other.grdToExec) {
	std::cout << "Form " << this->name << ", was copied from Form " << other.name << "." << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned; //name, grdToSign and grdToExec are const
	}
	std::cout << "Form " << this->name << " was assigned a new signed status: " << this->isSigned << std::endl;
	return *this;
}

Form::~Form() {
	std::cout << "Form " << this->name << " was destroyed." << std::endl;
}

const std::string& Form::getName() const {
	return this->name;
}

bool Form::getSignedStatus() const {
	return this->isSigned;
}

int Form::getGrdToSign() const {
	return this->grdToSign;
}

int Form::getGrdToExec() const {
	return this->grdToExec;
}

void Form::beSigned(const Bureaucrat& b) {
	if(b.getGrade() <= this->grdToSign) {
		this->isSigned = true;
		std::cout << "Form " << this->name << " can be signed by Bureaucrat " << b.getName() << "." << std::endl;
	} else {
		std::cout << "Form " << this->name << " cannot be signed by Bureaucrat " << b.getName() << " due to low grade." << std::endl;
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
	if(f.getSignedStatus())
		out << "Form " << f.getName() << " is signed. ";
	else
		out << "Form " << f.getName() << " is not signed. ";
	out << "Grade required to sign: " << f.getGrdToSign() << ". ";
	out << "Grade required to execute: " << f.getGrdToExec() << ".";
	return out;
}