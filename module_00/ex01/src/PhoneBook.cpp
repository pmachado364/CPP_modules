/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:56:27 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/10 18:55:34 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	count = 0;
	nextSlot = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::printInstructions() const {
std::cout << "** PhoneBook (42 Module 00) **" << std::endl
		<< "Commands:" << std::endl
		<< "  ADD    - add a new contact" << std::endl
		<< "  SEARCH - list contacts and show one by index" << std::endl
		<< "  EXIT   - quit" << std::endl
		<< "------------------------------------------------" << std::endl;
}

// ========== MAIN LOOP ==========
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
		else
			std::cout << "Please input a valid command\n";
	}
}