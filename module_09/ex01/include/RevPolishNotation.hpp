#ifndef REVPOLISHNOTATION_HPP
#define REVPOLISHNOTATION_HPP

#include <stack>
#include <string>
#include <map>

class RevPolishNotation {
	private :
		std::stack<int>	_stack;

		typedef int (RevPolishNotation::*opFunc)(int, int) const;
		//pointer to a member function that takes (int, int) arguments and returns an int.
		struct OperatorPtr {
			char op;
			opFunc func;
		}; // the struct will tie an operator character to its corresponding member function.
		OperatorPtr	_operators[4]; // array of 4 operators.

		int operatorAdd(int a, int b) const;
		int operatorSubtract(int a, int b) const;
		int operatorMultiply(int a, int b) const;
		int operatorDivide(int a, int b) const;

		// auxialiary
		bool checkWhitespace(char c) const;
		bool checkOperator(char c) const;
	public :
		RevPolishNotation();
		~RevPolishNotation();
		RevPolishNotation(const RevPolishNotation &other);
		RevPolishNotation &operator=(const RevPolishNotation &other);

		int	calculate(const std::string &input);
};

#endif