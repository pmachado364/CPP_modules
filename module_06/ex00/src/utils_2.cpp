#include "ScalarConverter.hpp"
#include <cctype>  // isdigit, isprint
#include <cstdlib> // strtol, strtof, strtod
#include <limits>

void ScalarConverter::convertChar(const std::string& literal) {
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);
	if(std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string& literal) {
	long nbr = std::strtol(literal.c_str(), NULL, 10);
	if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min()) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	int i = static_cast<int>(nbr);
	char c = static_cast<char>(nbr);
	double d = static_cast<double>(nbr);
	float f = static_cast<float>(i);

	if(i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}