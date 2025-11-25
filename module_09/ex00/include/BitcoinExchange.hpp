#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	private : 
		std::map<std::string, float> _db;
		void readDatabase(const std::string& filename); // read the database file into _db
		float getRate(const std::string& date) const; //get the rate on a specific date or the closest previous date
		bool validateDate(const std::string& date) const; //validate date format
		bool validateValue(const std::string& value) const; //validate value format
		void parseDataBaseLine(const std::string& line) const; //parse a line from the database
		void parseLine(const std::string& line); // parse a line from the database and store it in _db
		std::string trim(const std::string& str) const; //trim whitespace from a string

	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void parseInputFile(const std::string& filename) const; // parse the input file and output the results
};

#endif