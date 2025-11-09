#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int grdToSign, int grdToExec)
	:	name(name),
		isSigned(false),
		grdToSign(grdToSign),
		grdToExec(grdToExec)
{
	if(grdToSign < 1 || grdToExec < 1) {
		//std::cout << "Error: AForm "<< this->name << " couldn't be created." << std::endl;
		throw GradeTooHighException();
	}
	if(grdToSign > 150 || grdToExec > 150) {
		//std::cout << "Error: AForm "<< this->name << " couldn't be created." << std::endl;
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
	:	name(other.name),
		isSigned(other.isSigned),
		grdToSign(other.grdToSign),
		grdToExec(other.grdToExec) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned; //name, grdToSign and grdToExec are const
	}
	return *this;
}

AForm::~AForm() {
}

const std::string& AForm::getName() const {
	return this->name;
}

bool AForm::getSignedStatus() const {
	return this->isSigned;
}

int AForm::getGrdToSign() const {
	return this->grdToSign;
}

int AForm::getGrdToExec() const {
	return this->grdToExec;
}

void AForm::beSigned(const Bureaucrat& b) {
	if(b.getGrade() > this->grdToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
	if(f.getSignedStatus())
		out << "AForm " << f.getName() << " is signed. ";
	else
		out << "AForm " << f.getName() << " is not signed. ";
	out << "Grade required to sign: " << f.getGrdToSign() << ". ";
	out << "Grade required to execute: " << f.getGrdToExec() << ".";
	return out;
}