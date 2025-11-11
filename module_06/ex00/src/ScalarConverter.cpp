#include "ScalarConverter.hpp"

#include <limits.h>
#include <cctype>  // isdigit, isprint
//std::numeric_limits

/* static void ScalarConverter::convert(const std::string& literal) {
	ScalarConverter::Typeinfo arrayTypes[] =
	{
		{"char", ScalarConverter::isChar() , }
	}
} */

bool ScalarConverter::isChar(const std::string& literal) {
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])); //if all true, it's a char
};

bool ScalarConverter::isInt(const std::string& literal) {
	if (literal.empty())
		return false;
	size_t i = 0;
	if(literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == literal.length())
		return false;
	for(; i < literal.length(); i++) {
		if(!std::isdigit(literal[i]))
			return false;
	}
	return true;
};

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    	return true;
	if (literal.empty() || literal.back() != 'f')
		return false;
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	bool pointFound = false;
	for (; i < literal.length() - 1; i++) {
		if (!std::isdigit(literal[i])) { //if not a digit
			if (literal[i] == '.' && !pointFound) { //if it's a point and we haven't found one yet
				if(i == 0 || i == literal.length() - 2
					|| (i <= 1 && (literal[0] == '-' || literal[0] == '+'))) //point can't be the first or last character
					return false;
				pointFound = true;
			}
			else //if it's not a digit and or we already found a point
				return false;
		}
	}
	return pointFound;
};

bool ScalarConverter::isDouble(const std::string& literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	if(literal.empty() || literal.find('.') == std::string::npos)
		return false;
	size_t i = 0;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	bool pointFound = false;
	for(; i < literal.length(); i++) {
		if(!std::isdigit(literal[i])) {  // again, if not a digit
			if(literal[i] == '.' && !pointFound) { // if its a point and it hasnt been marked yet
				if(i == 0 || i == literal.length() - 1 
					|| (i <= 1 && (literal[0] == '-' || literal[0] == '+')))
					return false;
				pointFound = true;
			}
			else // if not a digit and pointFound alrd true
				return false;
		}
	}
	return pointFound;
}