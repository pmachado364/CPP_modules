#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern was created" << std::endl;
}

Intern::Intern(const Intern &other) {
	(void)other;
	std::cout << "Redundant copy of Intern built." << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	std::cout << "Redundant assignment of Intern." << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern was destroyed" << std::endl;
}

struct FormInfo {
	const std::string name;
	AForm* (*fetch)(const std::string& target);
};

AForm* Intern::makeForm(const std::string &formName, const std::string &target) {
	FormInfo array[] = 
	{
		{"robotomy request", &RobotomyRequestForm::fetch},
		{"presidential pardon", &PresidentialPardonForm::fetch},
		{"shrubbery creation", &ShrubberyCreationForm::fetch}
	};
	int arrSize = sizeof(array) / sizeof(array[0]);
	for(int i = 0; i < arrSize; i++) {
		if(formName == array[i].name) {
			std::cout << "Intern will create " << formName << " form." << std::endl;
			return array[i].fetch(target);
		}
	}
	std::cout << "Intern can't create : " << formName << " . No form matches" << std::endl;
	return NULL;
}