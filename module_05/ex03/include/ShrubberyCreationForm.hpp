#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <string>
#include <iostream>
#include <fstream>
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
		static AForm* fetch(const std::string& target);
};

#endif