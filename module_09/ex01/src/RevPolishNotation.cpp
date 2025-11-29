#include "RevPolishNotation.hpp"

#include <stdexcept>

RevPolishNotation::RevPolishNotation() {
	_operators[0].op = '+';
	_operators[0].func = &RevPolishNotation::operatorAdd;

	_operators[1].op = '-';
	_operators[1].func = &RevPolishNotation::operatorSubtract;

	_operators[2].op = '*';
	_operators[2].func = &RevPolishNotation::operatorMultiply;

	_operators[3].op = '/';
	_operators[3].func = &RevPolishNotation::operatorDivide;
}

RevPolishNotation::RevPolishNotation(const RevPolishNotation &other) {
	for (int i = 0; i < 4; ++i)
		_operators[i] = other._operators[i];
}

RevPolishNotation &RevPolishNotation::operator=(const RevPolishNotation &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i)
			_operators[i] = other._operators[i];
	}
	return *this;
}

RevPolishNotation::~RevPolishNotation() {}

int RevPolishNotation::calculate(const std::string& input) {
	for (size_t i = 0; i < input.length(); i++) {
		char c = input[i];
		if (checkWhitespace(c))
			continue;
		if (isdigit(c))
			_stack.push(c - '0');
		else if (checkOperator(c)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Too few operands");

			int b = _stack.top(); _stack.pop();
			int a = _stack.top(); _stack.pop();

			OperatorPtr opPtr;
			bool found = false;
			for (int j = 0; j < 4; ++j) {
				if (c == _operators[j].op) {
					opPtr = _operators[j];
					found = true;
					break;
					
				}
			}
			if (!found)
				throw std::runtime_error(std::string("Invalid operator: ") + c);
			int result = (this->*opPtr.func)(a, b);
			_stack.push(result);
		}
		else
			throw std::runtime_error(std::string("Invalid character: ") + c);
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return _stack.top();
}