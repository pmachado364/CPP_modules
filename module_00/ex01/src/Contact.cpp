/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:32:52 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/10 16:26:14 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include <iostream>

Contact::Contact() : index(-1) {
	//constructor inicia todos os atributos para valores default
}

Contact::~Contact() {
	//destructor não faz nada específico porque nao ha alocação dinâmica
}

// ===== getters =====

const std::string& Contact::getFirstName() const {
	return firstName;
}

const std::string& Contact::getLastName() const {
	return lastName;
}

const std::string& Contact::getNickname() const {
	return nickname;
}

const std::string& Contact::getPhoneNumber() const {
	return phoneNumber;
}

const std::string& Contact::getDarkestSecret() const {
	return darkestSecret;
}

int Contact::getIndex() const {
	return index;
}

// ===== setters =====

void Contact::setFirstName(const std::string &firstName) {
	this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
	this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
	this->darkestSecret = darkestSecret;
}

void Contact::setIndex(int index) {
	this->index = index;
}

// ===== Print full contact =====
void Contact::printContact() const {
	std::cout << "Index: " << index << std::endl
		<< "First Name: " << firstName << std::endl
		<< "Last Name: " << lastName << std::endl
		<< "Nickname: " << nickname << std::endl
		<< "Phone Number: " << phoneNumber << std::endl
		<< "Darkest Secret: " << darkestSecret << std::endl;
}
