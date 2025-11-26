#include "BitcoinExchange.hpp"
#include <iostream> // for std::cout

BitcoinExchange::BitcoinExchange() : _db() {
	readDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_db = other._db;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::execute(const std::string& inputFilename) {
    readDatabase("data.csv");
    readInputFile(inputFilename);
}

// std::istringstream ss(line); // allows parsing a string without the need to manually split it
// std::string date;
// std::string rate;
// std::getline(ss, date, ',');
// std::getline(ss, rate);
// this->trim(date);
// this->trim(rate);
// this->validateDate(date);
// this->validateValue(rate);
// _db[date] = std::stof(rate); // convert rate to float and store