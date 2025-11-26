#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
	private : 
		//database functions
		std::map<std::string, float> _db;
		void readDatabase(const std::string& filename); // read the database file into _db
		void parseDataBaseLine(const std::string& line); //parse a line from the database

		//input file functions
		void readInputFile(const std::string& filename); //parse the input file
		void parseInputFileLine(const std::string& line); // parse a line from the database and store it in _db
		
		//validation functions
		bool validateDate(const std::string& date) const; //validate date format
		bool validateRate(const std::string& rate) const; //validate DB rate format
		bool validateValue(const std::string& value) const; //validate input value
		
		//util functions
		std::string trim(const std::string& str); //trim whitespace from a string
		float getRate(const std::string& date) const; //get the rate on a specific date or the closest previous date
		void printBadInput(const std::string& line) const;
		void printNotPositive() const;
		void printTooLarge() const;
		bool stringToFloat(const std::string& str, float& out) const;

		public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void execute(const std::string& filename); // parse the input file and output the results
};

#endif