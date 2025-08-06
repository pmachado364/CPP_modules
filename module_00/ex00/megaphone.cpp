/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:46:07 by pmachado          #+#    #+#             */
/*   Updated: 2025/08/06 11:38:41 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av){
	if(ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++){
		for (int j = 0; av[i][j]; j++) {
			std::cout << (char)std::toupper(av[i][j]);
		}
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
