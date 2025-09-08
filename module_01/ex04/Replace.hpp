#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class ReplaceString{
	private:
		std::string filename;
		std::string s1;
		std::string s2;

	public:
		ReplaceString(const std::string& f, const std::string& s1, const std::string& s2);
		~ReplaceString();

		void replaceInFile();
};

#endif