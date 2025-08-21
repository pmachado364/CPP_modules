/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:54:50 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/21 11:57:10 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 1) {
		std::cout << "Usage: " << av[0] << std::endl;
		return 1;
	}
	PhoneBook phonebook;
	phonebook.run();
	return 0;
}