#ifndef AFORM_H
#define AFORM_H

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int grdToSign;
		const int grdToExec;
	public:
		AForm(const std::string& name, int grdToSign, int grdToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool getSignedStatus() const;
		int getGrdToSign() const;
		int getGrdToExec() const;

		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() { return "Grade is too high."; }
		};

		class GradeTooLowException : public std::exception {
    		public:
    		    virtual const char* what() const throw() { return "Grade is too low."; }
    	};

		class FormNotSigned : public std::exception {
			public:
				virtual const char* what() const throw() { return "Form is not signed."; }
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif