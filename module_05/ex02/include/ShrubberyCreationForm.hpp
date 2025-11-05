#ifndef SRUBBERYCREATIONFORM_H
#define SRUBBERYCREATIONFORM_H

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target;
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;
};

#endif