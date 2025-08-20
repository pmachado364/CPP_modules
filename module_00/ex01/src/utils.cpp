/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:20:45 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/20 17:12:02 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Utils.hpp"

#include <iostream>
#include <cctype>

std::string get_input(const std::string& prompt) {
	std::string s;
	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, s)) {
			if (std::cin.eof())
				return "";               // caller can check std::cin.eof()
			std::cin.clear();             // clear fail state
			std::cout << "Input error, try again.\n";
		}
		else if (std::cin.good() && !s.empty()) {	
			tabs_replace(s);
			return s;                     // valid non-empty input
		}
		else {
			std::cout << "Empty input. Try again?" << std::endl;
		}
	}
}

std::string get_input_nb(const std::string& prompt) {
    std::string s;
    while (true) {
        std::cout << prompt;

        if (!std::getline(std::cin, s)) {
            if (std::cin.eof())
                return "";   // EOF -> caller decides to exit
            std::cin.clear();
            std::cout << "Input error, try again.\n";
        }
        else if (std::cin.good() && is_number(s)) {
            return s;       // valid number string
        }
        else {
            std::cout << "Only digits allowed.\n";
        }
    }
}

bool is_number(const std::string& s) {
    if (s.empty()) return false;
    for (std::size_t i = 0; i < s.size(); i++) {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}


void tabs_replace(std::string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '\t')
			s[i] = ' ';
	}
}

int stringToInt(const std::string& s) {
    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}
