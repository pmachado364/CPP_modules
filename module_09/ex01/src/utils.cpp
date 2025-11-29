#include "RevPolishNotation.hpp"
#include <stdexcept>

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

bool RevPolishNotation::checkWhitespace(char c) const {
	if (c == ' ' || c == '\t' || c == '\n')
		return true;
	return false;
}

bool RevPolishNotation::checkOperator(char c) const {
	for (int i = 0; i < 4; ++i) {
		if (c == _operators[i].op)
			return true;
	}
	return false;
}