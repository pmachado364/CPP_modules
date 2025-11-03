#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat {
	private: 
		const std::string name;
		int grade;

	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		const std::string& getName() const;
		int	getGrade() const;
		void increment();
		void decrement();
		

		class GradeTooHighException : public std::exception {
    		public:
    		    virtual const char* what() const throw() { return "Grade is too high."; }
    	};
		
    	class GradeTooLowException : public std::exception {
    		public:
    		    virtual const char* what() const throw() { return "Grade is too low."; }
    	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& c);

#endif