#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return this->name;
}
int Bureaucrat::getGrade() const {
	return this->grade;
}
void Bureaucrat::increment() {
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}
void Bureaucrat::decrement() {
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	//<name>, bureaucrat grade <grade>.
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
