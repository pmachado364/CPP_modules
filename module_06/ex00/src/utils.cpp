#include "ScalarConverter.hpp"
#include <cctype>  // isdigit, isprint
#include <cstdlib> // strtol, strtof, strtod


bool ScalarConverter::validateChar(const std::string& literal) {
	if(literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return true;
	return false;
}

bool ScalarConverter::validateInt(const std::string& literal) {
	if (literal.empty())
		return false;

	size_t i = 0;
	size_t len = literal.length();
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == len)
		return false;
	for (; i < len; i++) {
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::validateFloat(const std::string& literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (literal.empty() || literal.back() != 'f')
		return false;

	size_t i = 0;
	size_t len = literal.length();
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == len)
		return false;
	bool point = false;
	for (; i < len - 1; i++) {
		if (!std::isdigit(literal[i])) {
			if (literal[i] == '.' && !point) {
				if (i == 0 || i == len - 2
					|| (i <= 1 && (literal[0] == '-' || literal[0] == '+')))
					return false;
				point = true;
			}
			else
				return false; 
		}
	}
	return point;
}

bool ScalarConverter::validateDouble(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if (literal.empty())
		return false;

	size_t i = 0;
	size_t len = literal.length();
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == len)
		return false;
	bool point = false;
	for (; i < len; i++) {
		if (!std::isdigit(literal[i])) {
			if (literal[i] == '.' && !point) {
				if (i == 0 || i == len - 1
					|| (i <= 1 && (literal[0] == '+' || literal[0] == '-')))
					return false;
				point = true;
			}
			else
				return false;
		}
	}
	return point;
}