 #include "BitcoinExchange.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <limits>
#include <iostream> // for std::cout

bool BitcoinExchange::validateDate(const std::string& date) const {
	//format chek YYYY-MM-DD
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
		
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	
	for (size_t i = 0; i < yearStr.length(); ++i)
		if (!std::isdigit(yearStr[i])) return false;
	for (size_t i = 0; i < monthStr.length(); ++i)
		if (!std::isdigit(monthStr[i])) return false;
	for (size_t i = 0; i < dayStr.length(); ++i)
		if (!std::isdigit(dayStr[i])) return false;

	std::istringstream y(yearStr);
	std::istringstream m(monthStr);
	std::istringstream d(dayStr);
	int year, month, day;
	y >> year;
	m >> month;
	d >> day;
	
	if (y.fail() || m.fail() || d.fail())
		return false;
	if (year < 0)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	return true;
}

bool BitcoinExchange::validateRate(const std::string& rate) const {
	std::istringstream valStream(rate);
	float fRate = 0.0f;
	valStream >> fRate;
	if (valStream.fail())
	return false;
	if (!valStream.eof()) // extra characters after number
	return false;
	if (fRate < 0.0f) // no need to check against max since .fail would catch it
	return false;
	return true;
}

std::string BitcoinExchange::trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return ""; // string is all whitespace so it should be captured as empty in the parse function
	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
	//substr(first, last - first + 1) = first becomes the starting index
	//last - first + 1 becomes the length of the substring
}

void BitcoinExchange::printBadInput(const std::string& line) const {
	std::cout << "Error: bad input => " << line << std::endl;
}
void BitcoinExchange::printNotPositive() const {
	std::cout << "Error: not a positive number." << std::endl;
}
void BitcoinExchange::printTooLarge() const {
	std::cout << "Error: too large a number." << std::endl;
}
bool BitcoinExchange::stringToFloat(const std::string& str, float& out) const {
    if (str.empty())
        return false;
    std::istringstream ss(str);
    ss >> out;
    // Extraction must not fail
    if (ss.fail())
        return false;
    // No leftover characters allowed
    if (!ss.eof())
        return false;
    return true;
}

float BitcoinExchange::getRate(const std::string& date) const {
	std::map<std::string, float>::const_reverse_iterator rev_it;

	for (rev_it = _db.rbegin(); rev_it != _db.rend(); ++rev_it) {
		if (rev_it->first <= date) {
			return rev_it->second; // first points to the date and second to the rate in that pair
		}
	}
	return _db.begin()->second; // if no previous date found, return the earliest rate
}