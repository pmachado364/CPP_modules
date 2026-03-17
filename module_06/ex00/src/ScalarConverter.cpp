#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) {
	const ScalarConverter::Typeinfo arrayTypes[] =
	{
		{"char", ScalarConverter::validateChar, ScalarConverter::convertChar},
		{"int", ScalarConverter::validateInt, ScalarConverter::convertInt},
		{"float", ScalarConverter::validateFloat, ScalarConverter::convertFloat},
		{"double", ScalarConverter::validateDouble, ScalarConverter::convertDouble}
	};
	const size_t size = sizeof(arrayTypes) / sizeof(arrayTypes[0]);
	for (size_t i = 0; i < size; i++){
		if (arrayTypes[i].isType(literal)) {
			arrayTypes[i].printType(literal);
			return;
		}
	}
	std::cout << "Error: Invalid literal" << std::endl;
}
