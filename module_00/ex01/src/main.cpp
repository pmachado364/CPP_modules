/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:54:50 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/10 13:01:19 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int main() {
    Contact c;
    c.setIndex(0);
    c.setFirstName("Alice");
    c.setLastName("Smith");
    c.setNickname("Ally");
    c.setPhoneNumber("123456789");
    c.setDarkestSecret("Eats cereal with water");

    c.printContact();
}
