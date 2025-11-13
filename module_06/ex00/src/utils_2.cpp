#include "ScalarConverter.hpp"
#include <cctype>  // isdigit, isprint
#include <cstdlib> // strtol, strtof, strtod
#include <limits>
#include <iomanip>
#include <cmath>

void ScalarConverter::convertChar(const std::string& literal) {
	char c = literal[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;

	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}

void ScalarConverter::convertInt(const std::string& literal) {
	long value = std::strtol(literal.c_str(), NULL, 10);
	std::cout << std::fixed << std::setprecision(1);

	if (value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min()) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			float f = static_cast<float>(value);
			double d = static_cast<double>(value);
			std::cout << "float: " << f << "f"<< std::endl;
			std::cout << "double: " << d << std::endl;
			return;
		}
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);
	
	if (i > std::numeric_limits<char>::max() ||
		i < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" <<std::endl;
	std::cout << "double: " << d << std::endl;

	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);
}

void ScalarConverter::convertFloat(const std::string& literal) {
	std::cout << std::fixed << std::setprecision(1);
	float f = strtof(literal.c_str(), NULL);

	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || std::isnan(f)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		return;
	}
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);
	if (f > std::numeric_limits<char>::max() ||
		f < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (f > std::numeric_limits<int>::max() ||
		f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6);	
}

void ScalarConverter::convertDouble(const std::string& literal) {
	std::cout << std::fixed << std::setprecision(1);
	double d = strtod(literal.c_str(), NULL);

	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << d << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (d > std::numeric_limits<char>::max() ||
		d < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if(!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (d > std::numeric_limits<int>::max() ||
		d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	std::cout.unsetf(std::ios::fixed);
	std::cout << std::setprecision(6); 
}