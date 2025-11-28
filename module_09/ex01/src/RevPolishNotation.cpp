#include "RevPolishNotation.hpp"

#include <stdexcept>

RevPolishNotation::RevPolishNotation() {
	_operatorsMap['+'] = &RevPolishNotation::operatorAdd;
	_operatorsMap['-'] = &RevPolishNotation::operatorSubtract;
	_operatorsMap['*'] = &RevPolishNotation::operatorMultiply;
	_operatorsMap['/'] = &RevPolishNotation::operatorDivide;
}

RevPolishNotation::RevPolishNotation(const RevPolishNotation &other) : _operatorsMap(other._operatorsMap) {}

RevPolishNotation &RevPolishNotation::operator=(const RevPolishNotation &other) {
	if (this != &other) {
		_operatorsMap = other._operatorsMap;
	}
	return *this;
}

RevPolishNotation::~RevPolishNotation() {}

int RevPolishNotation::operatorAdd(int a, int b) const {
	return a + b;
}
int RevPolishNotation::operatorSubtract(int a, int b) const {
	return a - b;
}
int RevPolishNotation::operatorMultiply(int a, int b) const {
	return a * b;
}
int RevPolishNotation::operatorDivide(int a, int b) const {
	if (b == 0)
		throw std::runtime_error("Division by zero");
	return a / b;
}

int	RevPolishNotation::calculate(const std::string &input) {
	_stack = std::stack<int>();

	for (size_t i = 0; i < input.length(); ++i) {
		char c = input[i];
		if (checkWhitespace(c))
			continue;
		if (isdigit(c))
			_stack.push(c - '0'); // Convert char digit to int
		else if (checkOperator(c)) {
			if (_stack.size() < 2)
				throw std::runtime_error("Insufficient operands for operation");

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			operatorPtr opFunc = _operatorsMap[c]; // get the pointer to member function from the map
			int result = (this->*opFunc)(a, b); // call the member function pointer
			_stack.push(result); // push the result back onto the stack
		}
		else {
			throw std::runtime_error(std::string("Invalid character '") + c + "'");
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("invalid RPN expression");
	return _stack.top();
}

bool RevPolishNotation::checkWhitespace(char c) const {
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

bool RevPolishNotation::checkOperator(char c) const {
	if (_operatorsMap.find(c) != _operatorsMap.end())
		return true;
	return false;
}