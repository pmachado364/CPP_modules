#include "BitcoinExchange.hpp"
#include <fcntl.h> // for open
#include <stdexcept> // for std::runtime_error
#include <unistd.h> // for close, read
#include <fstream> // for std::ifstream
#include <sstream> // for std::istringstream

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

void BitcoinExchange::readDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str()); // similar to std::cin but source is a file instead
	if (!file.is_open()) {
		throw std::runtime_error("Could not open database file: " + filename);
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		if (!line.empty())
			this->parseDataBaseLine(line);
	}
	file.close();
}

void BitcoinExchange::parseDataBaseLine(const std::string& line) const {
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
}