#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int grdToSign;
		const int grdToExec;
	public:
		Form(const std::string& name, int grdToSign, int grdToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string& getName() const;
		bool getSignedStatus() const;
		int getGrdToSign() const;
		int getGrdToExec() const;

		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high."; }
		};

		class GradeTooLowException : public std::exception {
    		public:
    		    virtual const char* what() const throw() { return "Grade is too low."; }
    	};
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif