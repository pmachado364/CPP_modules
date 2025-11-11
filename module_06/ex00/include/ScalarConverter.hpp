#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

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
		
		//---Functions to check type---//
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		//---fucntions to print type---//
		static void printChar(const std::string& literal);
		static void printInt(const std::string& literal);
		static void printFloat(const std::string& literal);
		static void printDouble(const std::string& literal);

	public:
		static void convert(const std::string& literal);
};

#endif