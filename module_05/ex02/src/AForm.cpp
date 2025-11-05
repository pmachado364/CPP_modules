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
	// std::cout << "AForm " << this->name << " was created." << std::endl;
	// std::cout << "Grade required to sign: " << this->grdToSign << std::endl;
	// std::cout << "Grade required to execute: " << this->grdToExec << std::endl;
}

AForm::AForm(const AForm& other)
	:	name(other.name),
		isSigned(other.isSigned),
		grdToSign(other.grdToSign),
		grdToExec(other.grdToExec) {
		//std::cout << "AForm " << this->name << ", was copied from AForm " << other.name << "." << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned; //name, grdToSign and grdToExec are const
	}
	// std::cout << "AForm " << this->name << " was assigned a new signed status: " << this->isSigned << std::endl;
	return *this;
}

AForm::~AForm() {
	// std::cout << "AForm " << this->name << " was destroyed." << std::endl;
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
	if(b.getGrade() <= this->grdToSign) {
		this->isSigned = true;
		std::cout << "AForm " << this->name << " can be signed by Bureaucrat " << b.getName() << "." << std::endl;
	} else {
		std::cout << "AForm " << this->name << " cannot be signed by Bureaucrat " << b.getName() << " due to low grade." << std::endl;
		throw GradeTooLowException();
	}
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