#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
	const ScalarConverter::Typeinfo arrayTypes[] =
	{
		{"char", ScalarConverter::validateChar, ScalarConverter::convertChar},
		{"int", ScalarConverter::validateInt, ScalarConverter::convertInt},
		{"float", ScalarConverter::validateFloat, ScalarConverter::convertFloat},
		{"double", ScalarConverter::validateDouble, ScalarConverter::convertDouble}
	};
	for (int i = 0; i < 4; i++){
		if (arrayTypes[i].isType(literal)) {
			arrayTypes[i].printType(literal);
			return;
		}
	}
	std::cout << "Error: Invalid literal" << std::endl;
}
