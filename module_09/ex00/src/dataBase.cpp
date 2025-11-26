#include "BitcoinExchange.hpp"
#include <sstream> // for std::istringstream
#include <fstream> // for std::ifstream

void BitcoinExchange::readDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str()); // similar to std::cin but source is a file instead
	if (!file.is_open())
		throw std::runtime_error("Could not open database file: " + filename);

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		if (!line.empty())
			this->parseDataBaseLine(line);
	}
	file.close();
}

void BitcoinExchange::parseDataBaseLine(const std::string& line){
	std::istringstream ss(line); // allows parsing a string without the need to manually split it
	std::string date, rateStr;

	if (!std::getline(ss, date, ',')) // read until comma
		return;
	if (!std::getline(ss, rateStr)) // read until end of line
		return;

	date = this->trim(date); // remove whitespace
	rateStr = this->trim(rateStr); // remove whitespace

	if (!this->validateDate(date) || !this->validateRate(rateStr))
		return;

	std::istringstream numStream(rateStr); // create a stream that reads from the string
	float newRate = 0.0f;
	if (!stringToFloat(rateStr, newRate))
		return;
	_db[date] = newRate; // convert rate to float and store
}

