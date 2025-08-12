/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:58:25 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/11 14:47:31 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int count; //Quantos contactos estao armazenados
	int nextSlot; //Proximo slot a ser preenchido

	void printTable() const;
	void promptAndShow() const;

public:
    PhoneBook();
	~PhoneBook();

	void run(); // Main loop para receber o input do utilizador (ADD | SEARCH | EXIT )
	void printInstructions() const; // mensagem de instruções
    void add(); // Adiciona um novo contacto
    void search() const; // Pesquisa e mostra contactos
};

#endif