/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:56:27 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/19 16:48:18 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string> 

static std::string get_input(const std::string &prompt);
static void tabs_replace(std::string &s);

PhoneBook::PhoneBook() {
	count = 0;
	nextSlot = 0;
}

PhoneBook::~PhoneBook() {
}


// ------------------ main loop ------------------

void PhoneBook::run() {
	std::string input;
	
	printInstructions();
	while (true) {
		input = get_input("> ");
		if (input.empty() && std::cin.eof()) break; // EOF -> sair
		if (input == "ADD")
			add();
		else if (input == "SEARCH")
			search();
		else if (input == "EXIT")
			break;
		else {
			std::cout << "Try a valid command\n";
			printInstructions();
		}
	}
}

// ------------------ helpers ------------------

static std::string get_input(const std::string& prompt) {
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

static void tabs_replace(std::string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '\t')
			s[i] = ' ';
	}
}

// ------------------ placeholder ------------------

void PhoneBook::printInstructions() const {
std::cout << "** PhoneBook (CPP.ex01) **" << std::endl
		<< "Commands:" << std::endl
		<< "  ADD    - add a new contact" << std::endl
		<< "  SEARCH - list contacts and show one by index" << std::endl
		<< "  EXIT   - quit" << std::endl
		<< "------------------------------------------------" << std::endl;
}

void PhoneBook::add() {
	std::cout << "[ADD] not implemented yet.\n";
}

void PhoneBook::search() const {
	std::cout << "[SEARCH] not implemented yet.\n";
}
