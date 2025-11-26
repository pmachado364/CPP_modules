#include "BitcoinExchange.hpp"
#include <sstream> // for std::istringstream
#include <fstream> // for std::ifstream
#include <iostream> // for std::cout

void BitcoinExchange::readInputFile(const std::string& filename) {
	std::ifstream file (filename.c_str()); // similar to std::cin but source is a file instead
	if (!file.is_open())
		throw std::runtime_error("Could not open input file: " + filename);
	
	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		if (!line.empty())
			this->parseInputFileLine(line);
	}
	file.close();
}

void BitcoinExchange::parseInputFileLine(const std::string& line) {
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos)
        return printBadInput(line);

    // Split into date & value
    std::string dateStr, valueStr;
    dateStr = trim(line.substr(0, pipePos));
	valueStr = trim(line.substr(pipePos + 1));
	
    // Validate date
    if (!validateDate(dateStr))
		return printBadInput(line);

    // Convert value safely
    float value;
    if (!stringToFloat(valueStr, value))
        return printNotPositive();
    // Range checks
    if (value < 0)
        return printNotPositive();
    if (value > 1000)
        return printTooLarge();

    float rate = getRate(dateStr);
    std::cout << dateStr << " => "
              << value << " = " << (rate * value)
              << std::endl;
}

