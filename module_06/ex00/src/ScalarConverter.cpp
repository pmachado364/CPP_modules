#include "ScalarConverter.hpp"

#include <limits.h>

void ScalarConverter::convert(const std::string& literal) {
	ScalarConverter::Typeinfo arrayTypes[] =
	{
		{"char", ScalarConverter::validateChar, ScalarConverter::convertChar},
		{"int", ScalarConverter::validateInt, ScalarConverter::convertInt},
		{"float", ScalarConverter::validateFloat, ScalarConverter::convertFloat},
		{"double", ScalarConverter::validateDouble, ScalarConverter::convertDouble}
	};
	//
}
