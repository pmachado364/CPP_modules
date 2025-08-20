/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:56:27 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/20 17:10:10 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include "../include/Utils.hpp"
#include <iostream>
#include <iomanip>

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
	int slot = nextSlot;
	std::string first, last, nick, phone, secret;
	
	first  = get_input("First name: ");
	if (first.empty() && std::cin.eof()) return;
	last   = get_input("Last name: ");
	if (last.empty() && std::cin.eof()) return;
	nick   = get_input("Nickname: ");
	if (nick.empty() && std::cin.eof()) return;
	phone  = get_input_nb("Phone number: ");
	if (phone.empty() && std::cin.eof()) return;
	secret = get_input("Darkest secret: ");
	if (secret.empty() && std::cin.eof()) return;

	contacts[slot].setIndex(slot);
	contacts[slot].setFirstName(first);
	contacts[slot].setLastName(last);
	contacts[slot].setNickname(nick);
	contacts[slot].setPhoneNumber(phone);
	contacts[slot].setDarkestSecret(secret);

	if (count < 8) count++;
	nextSlot = (nextSlot + 1) % 8;
	std::cout << "Saved in slot " << slot << ".\n";
}

void PhoneBook::search() const {
    if (count == 0) {
        std::cout << "Try adding contacts first.\n";
        return;
    }
    printTable();
    promptAndShow();
}

void PhoneBook::printTable() const {
    std::cout << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME" << "|\n";

    for (int contactIndex = 0; contactIndex < count; contactIndex++) {
        std::string firstName = contacts[contactIndex].getFirstName();
        std::string lastName  = contacts[contactIndex].getLastName();
        std::string nickname  = contacts[contactIndex].getNickname();

        if (firstName.size() > 10) firstName = firstName.substr(0, 9) + ".";
        if (lastName.size()  > 10) lastName  = lastName.substr(0, 9) + ".";
        if (nickname.size()  > 10) nickname  = nickname.substr(0, 9) + ".";

        std::cout << std::setw(10) << contactIndex << "|"
                  << std::setw(10) << firstName    << "|"
                  << std::setw(10) << lastName     << "|"
                  << std::setw(10) << nickname     << "|\n";
    }
}

void PhoneBook::promptAndShow() const {
    std::string chosenIndex = get_input_nb("Enter index: ");
    if (chosenIndex.empty() && std::cin.eof())
        return;

    int index = stringToInt(chosenIndex);

    if (index < 0 || index >= count) {
        std::cout << "Invalid index.\n";
        return;
    }

    contacts[index].printContact();
}
