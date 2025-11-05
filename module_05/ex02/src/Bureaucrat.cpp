#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if(grade < 1){ 
		std::cout << "Error creating Bureaucrat " << this->name << " with grade " << this->grade << std::endl;
		throw GradeTooHighException();
	}
	if(grade > 150) {
		std::cout << "Error creating Bureaucrat " << this->name << " with grade " << this->grade << std::endl;
		throw GradeTooLowException();
	}
	std::cout << "Bureaucrat " << this->name << " with grade " << this->grade << " was created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
	std::cout << "Bureaucrat " << this->name << " was copied" << std::endl;
	//their name will be the same, grade too
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name << " was destroyed." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if(this != &other) {
		this->grade = other.grade;
	} //name is not changed because it's const
	std::cout << "Bureaucrat " << this->name << " was assigned a new grade: " << this->grade << std::endl;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::increment() {
	if(this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrement() {
	if(this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(Form& f) {
	try {
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& c) {
	//<name>, bureaucrat grade <grade>.
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << ".";
	return out;
}
