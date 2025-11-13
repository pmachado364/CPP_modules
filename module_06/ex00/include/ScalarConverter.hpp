#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
	private:

		struct Typeinfo {
			std::string type;
			bool (*isType)(const std::string&);
			void (*printType)(const std::string&);
		};

		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		
		//---Functions to verify type---//
		static bool validateChar(const std::string& literal);
		static bool validateInt(const std::string& literal);
		static bool validateFloat(const std::string& literal);
		static bool validateDouble(const std::string& literal);
		//---functions to print type---//
		static void convertChar(const std::string& literal);
		static void convertInt(const std::string& literal);
		static void convertFloat(const std::string& literal);
		static void convertDouble(const std::string& literal);

	public:
		static void convert(const std::string& literal);
};

#endif