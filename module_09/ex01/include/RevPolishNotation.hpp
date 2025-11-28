#ifndef REVPOLISHNOTATION_HPP
#define REVPOLISHNOTATION_HPP

#include <stack>
#include <string>
#include <map>

class RevPolishNotation {
	private :
		std::stack<int>	_stack;

		//pointer to a member function of RevPolishNotation that takes two ints and returns an int
		// typedef allows us to create an alias for this complex type
		// Now we can use 'operatorPtr' as a type
		typedef int (RevPolishNotation::*operatorPtr)(int, int) const;
		std::map<char, operatorPtr> _operatorsMap; // we link the key (char) to the value (pointer to member function)

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