/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:20:45 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/11 19:01:14 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

#include <iostream>

std::string get_input(const std::string &prompt) {
	std::string s;
	while (true) {
		std::cout << prompt;

		// ler o input do utilizador
		if (!std::getline(std::cin, s)) {
			// Se ocorrer um erro de leitura, verificar se é EOF
			if(std::cin.eof())
				return ""; // EOF -> sair
			std::cin.clear(); // Clear no error state
			std::cout << "Invalid input..." << std::endl;
			continue; // Retry input
		}
		//se estiver tudo bem
		if(std::cin.good() && !s.empty()) {
			tabsToSpaces(s);
			return s;
		}
		std::cout << "Invalid input..." << std::endl;
	}
}
